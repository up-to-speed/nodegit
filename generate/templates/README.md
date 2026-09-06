# Manual templates

  Manual templates override generated code from bungit while generating source code. They really should be avoid untill absolutely necessary.

## Why?

  #### 1. Performance
  > Everytime the library switches between C land and the javascript thread, there is a penalty in performance. If in practice the usage of a method in libgit2 requires crossing the c/javascript boundary frequently, it might be better option to use manual templates. An example being ```Revwalk::FastWalk```.

  #### 2. Saftey
  > The generated code sometimes does not handle structures that are interdependent. An example would be ```git_patch``` and ```git_diff```. A ```git_patch```'s memory is owned by ```git_diff```, and that includes all of the children of ```git_patch```, as well. So a ```git_diff_hunk```, ```git_diff_line```, and ```git_patch``` all are owned by a ```git_diff```, and when that ```git_diff``` is deleted, all the memory for any patches, hunks, or lines that are in use as NodeGitWrappers are now corrupted. Further, a ```git_diff``` keeps a file handle open for its entire lifespan, which can lead to NodeGit holding onto file locks in Windows. Due to both of these compounding issues, we wrote manual templates to shift ownership away from a ```git_diff``` to ```git_patch```, ```git_diff_hunk```, and ```git_diff_line``` and also shorten the lifespan of a diff.

  #### 3. Odd cases
  > If a new pattern exists in libgit that would be difficult to implement using generated code, manual templates can be used for one-off cases. Typically generated code takes care of most patterns seen in libgit, but if function signatures do not follow typical pattern, manual templates could be used. Example: ```git_filter``` and ```git_remote_ls```.

<br />
-----
## Implementing manual templates

#### 1. Write manual .cc and .h files to *generate/templates/manual/*
    *.cc files -> /generate/templates/manual/src/
    *.h files -> /generate/templates/manual/include/

#### 2. Remove all references from /generate configuration files
    
#### 3. Add references to binding.gyp template
    location: /generate/templates/templates/binding.gyp

    Do not put # comments in this template. The render is passed through
    js-beautify, which lexes it as JavaScript: a # comment is joined with the
    line that follows it, swallowing whatever that line declared, and an
    apostrophe inside one opens a string that never closes. Explain the
    reasoning in the util the setting calls instead.

#### 4. Add headers to bungit.cc template
    location: /generate/templates/templates/bungit.cc

#### 5. Add new wrapper to bungit.js template
    use rawApi.ManualWrapper reference to add _ManualWrapper
    add any js wrapper (if any) via importExtension

