# Test Results: Node vs Bun

Generated: 2026-03-13

## Summary

| Runtime | Passing | Failing | Pending | Total |
|---------|---------|---------|---------|-------|
| Node    | 430 | 0 | 18 | 448 |
| Bun     | 389 | 53 | 19 | 461 |

## Bun-Only Failures (pass in Node, fail in Bun)

- Checkout > can checkout a branch
- Checkout > can checkout a branch with a long file path
- Checkout > can checkout an index with conflicts
- Checkout > can checkout by tree
- Clone > can clone twice with https using same config object
- Clone > can clone using nested function
- Clone > can clone with https
- Clone > can clone with https and default throttled progress
- Clone > can clone with https and explicitly throttled progress
- Clone > can clone with ssh
- Clone > can clone with ssh while manually loading a key
- Clone > can clone with ssh while manually loading an encrypted key
- Clone > can clone without waiting for callback results
- Clone > will not segfault when accessing a url without username
- Commit > amendWithSignature > can amend with signature
- Commit > amendWithSignature > will respects overridden arguments
- Diff > can diff index to workdir
- Diff > can diff the workdir with index
- Diff > can diff with a null tree
- Filter > FilterSource > a FilterSource has an async repo getter
- Index > can remove entries from the index
- Remote > can fetch from a private repository
- Remote > can reject fetching from private repository without valid credentials
- Repository > can be cleaned
- Repository > can get a reference commit
- Repository > can get the head commit
- Repository > can obtain statistics from a valid constant repository
- Repository > gets extended statuses
- Repository > gets statuses with StatusFile
- Revwalk > can get the history of a file
- Revwalk > can yield information about renames in a file history walk
- Stash > can save a stash with no message and drop it
- Stash > can save and drop a stash
- Stash > can save multiple stashes and pop an arbitrary stash
- Stash > gets no stashes on clean working directory
- Status > gets a status on changing file directory
- Status > gets no statuses on clean working directory
- Status > gets status with options
- StatusList > gets status with deltas
- TreeBuilder > Can create a treebuilder from the latest commit tree

## Failures in Both Runtimes

None

## Node-Only Failures

None

## Tests Only in Node (not in Bun)

None

## Tests Only in Bun (not in Node)

- [FAIL] Checkout
- [FAIL] Clone
- [FAIL] Commit
- [FAIL] Diff
- [FAIL] Filter
- [FAIL] Index
- [FAIL] Remote
- [FAIL] Repository
- [FAIL] Revwalk
- [FAIL] Stash
- [FAIL] Status
- [FAIL] StatusList
- [FAIL] TreeBuilder

## All Tests

| Test | Node | Bun |
|------|------|-----|
| **AnnotatedCommit** | | |
| AnnotatedCommit > can create an AnnotatedCommit from a ref | PASS | PASS |
| AnnotatedCommit > can lookup an AnnotatedCommit after creating it | PASS | PASS |
| AnnotatedCommit > can lookup an AnnotatedCommit from a fetchhead | PASS | PASS |
| AnnotatedCommit > can lookup an AnnotatedCommit from a revspec | PASS | PASS |
| **Attr** | | |
| Attr > can add a macro definition | PASS | PASS |
| Attr > can flush the attr cache | PASS | PASS |
| Attr > can lookup the value of a git attribute | PASS | PASS |
| **Blame** | | |
| Blame > can initialize blame without options | PASS | PASS |
| **Blob** | | |
| Blob > can determine if a blob is not a binary | PASS | PASS |
| Blob > can get a blob with an Oid object | PASS | PASS |
| Blob > can provide content as a buffer | PASS | PASS |
| Blob > can provide content as a string | PASS | PASS |
| **Blob > createFromBuffer** | | |
| Blob > createFromBuffer > creates a new blob from the buffer | PASS | PASS |
| Blob > createFromBuffer > creates blob with content equal to length | PASS | PASS |
| Blob > createFromBuffer > throws an error when buffer is null | PASS | PASS |
| Blob > createFromBuffer > throws an error when no length is provided | PASS | PASS |
| Blob > createFromBuffer > throws an error when repository is null | PASS | PASS |
| **Blob > createFromDisk** | | |
| Blob > createFromDisk > creates a new blob from the file | PASS | PASS |
| Blob > createFromDisk > throws an error when path is null | PASS | PASS |
| Blob > createFromDisk > throws an error when repository is null | PASS | PASS |
| Blob > createFromDisk > throws an error when the file cannot be found | PASS | PASS |
| **Blob > createFromWorkdir** | | |
| Blob > createFromWorkdir > creates a blob from the file | PASS | PASS |
| Blob > createFromWorkdir > throws an error when path is null | PASS | PASS |
| Blob > createFromWorkdir > throws an error when repository is null | PASS | PASS |
| Blob > createFromWorkdir > throws an error when the file cannot be found | PASS | PASS |
| **Blob > filter** | | |
| Blob > filter > retrieves the filtered content | PASS | PASS |
| Blob > filter > returns blob when not checking binary on binary blob | PASS | PASS |
| Blob > filter > returns non-binary filtered content when checking binary | PASS | PASS |
| Blob > filter > returns nothing when checking binary blob | PASS | PASS |
| Blob > filter > throws an error when the path is null | PASS | PASS |
| **Blob > filteredContent (DEPRECATED)** | | |
| Blob > filteredContent (DEPRECATED) > retrieves the filtered content | PASS | PASS |
| Blob > filteredContent (DEPRECATED) > returns blob when not checking binary on binary blob | PASS | PASS |
| Blob > filteredContent (DEPRECATED) > returns non-binary filtered content when checking binary | PASS | PASS |
| Blob > filteredContent (DEPRECATED) > returns nothing when checking binary blob | PASS | PASS |
| Blob > filteredContent (DEPRECATED) > throws an error when the blob is null | PASS | PASS |
| Blob > filteredContent (DEPRECATED) > throws an error when the flag is undefined | PASS | PASS |
| Blob > filteredContent (DEPRECATED) > throws an error when the path is null | PASS | PASS |
| **Branch** | | |
| Branch > can create a branch | PASS | PASS |
| Branch > can create branch from annotated commit | PASS | PASS |
| Branch > can delete a branch | PASS | PASS |
| Branch > can get the name of a branch | PASS | PASS |
| Branch > can get the remote name of a branch | PASS | PASS |
| Branch > can lookup a branch | PASS | PASS |
| Branch > can rename a branch | PASS | PASS |
| Branch > can see if the branch is pointed to by head | PASS | PASS |
| Branch > can set an upstream for a branch | PASS | PASS |
| Branch > cannot get remote name from a non-remote branch | PASS | PASS |
| **Root** | | |
| Checkout | N/A | FAIL |
| **Checkout** | | |
| Checkout > can checkout a branch | PASS | FAIL |
| Checkout > can checkout a branch with a long file path | PASS | FAIL |
| Checkout > can checkout an index with conflicts | PASS | FAIL |
| Checkout > can checkout by tree | PASS | FAIL |
| Checkout > can checkout the head | PASS | PASS |
| Checkout > can force checkout a single file | PASS | PASS |
| Checkout > cannot checkout long path file if core.longpaths is not set on win32 | PENDING | PENDING |
| **Cherrypick** | | |
| Cherrypick > can cherrypick a commit onto another specified commit | PASS | PASS |
| Cherrypick > can cherrypick a commit onto the index | PASS | PASS |
| Cherrypick > can cherrypick a stash to apply it | PASS | PASS |
| **Root** | | |
| Clone | N/A | FAIL |
| **Clone** | | |
| Clone > can clone twice with https using same config object | PASS | FAIL |
| Clone > can clone using nested function | PASS | FAIL |
| Clone > can clone with filesystem | PASS | PASS |
| Clone > can clone with git | PENDING | PENDING |
| Clone > can clone with http | PENDING | PENDING |
| Clone > can clone with https | PASS | FAIL |
| Clone > can clone with https and default throttled progress | PASS | FAIL |
| Clone > can clone with https and explicitly throttled progress | PASS | FAIL |
| Clone > can clone with ssh | PASS | FAIL |
| Clone > can clone with ssh while manually loading a key | PASS | FAIL |
| Clone > can clone with ssh while manually loading an encrypted key | PASS | FAIL |
| Clone > can clone without waiting for callback results | PASS | FAIL |
| Clone > will not segfault when accessing a url without username | PASS | FAIL |
| **Root** | | |
| Commit | N/A | FAIL |
| **Commit > Commit's Author** | | |
| Commit > Commit's Author > has a name | PASS | PASS |
| Commit > Commit's Author > has an email | PASS | PASS |
| Commit > Commit's Author > is available | PASS | PASS |
| **Commit > Commit's Body** | | |
| Commit > Commit's Body > non-null when body exists | PASS | PASS |
| Commit > Commit's Body > null if only summary | PASS | PASS |
| **Commit > Commit's Committer** | | |
| Commit > Commit's Committer > has a name | PASS | PASS |
| Commit > Commit's Committer > has an email | PASS | PASS |
| Commit > Commit's Committer > is available | PASS | PASS |
| **Commit > Commit's Signature** | | |
| Commit > Commit's Signature > Can be optionally skipped to create without signature | PASS | PASS |
| Commit > Commit's Signature > Can create a signed commit in a repo | PASS | PASS |
| Commit > Commit's Signature > Can create a signed commit in a repo and update existing ref | PASS | PASS |
| Commit > Commit's Signature > Can create a signed commit in bare a repo and update non-existent ref | PASS | PASS |
| Commit > Commit's Signature > Can create a signed commit raw | PASS | PASS |
| Commit > Commit's Signature > Can retrieve the gpg signature from a commit | PASS | PASS |
| Commit > Commit's Signature > Will throw if the signing cb returns an error code | PASS | PASS |
| **Commit > amendWithSignature** | | |
| Commit > amendWithSignature > can amend with signature | PASS | FAIL |
| Commit > amendWithSignature > can optionally skip signing process | PASS | PASS |
| Commit > amendWithSignature > will respects overridden arguments | PASS | FAIL |
| Commit > amendWithSignature > will throw if signing callback returns an error code | PASS | PASS |
| **Commit** | | |
| Commit > can amend commit | PASS | PASS |
| Commit > can amend commit and update reference separately | PASS | PASS |
| Commit > can call getTree on a parent commit | PASS | PASS |
| Commit > can create a commit | PASS | PASS |
| Commit > can create a commit as a buffer | PASS | PASS |
| Commit > can fetch a single parent | PASS | PASS |
| Commit > can fetch all of its parents | PASS | PASS |
| Commit > can fetch parents of a merge commit | PASS | PASS |
| Commit > can fetch the master branch HEAD | PASS | PASS |
| Commit > can find nth gen ancestor | PASS | PASS |
| Commit > can get header fields | PASS | PASS |
| Commit > can get the commit diff | PASS | PASS |
| Commit > can get the commit diff without whitespace | PASS | PASS |
| Commit > can lookup using a short id | PASS | PASS |
| Commit > can retrieve and walk a commit tree | PASS | PASS |
| Commit > can specify a parents limit | PASS | PASS |
| Commit > can specify limit higher than actual parents | PASS | PASS |
| Commit > can walk its repository's history | PASS | PASS |
| Commit > does not leak | PASS | PASS |
| Commit > duplicates signature | PASS | PASS |
| Commit > has a date | PASS | PASS |
| Commit > has a message | PASS | PASS |
| Commit > has a message encoding | PASS | PASS |
| Commit > has a parent count | PASS | PASS |
| Commit > has a raw message | PASS | PASS |
| Commit > has a sha | PASS | PASS |
| Commit > has a summary | PASS | PASS |
| Commit > has a time | PASS | PASS |
| Commit > has a time offset | PASS | PASS |
| Commit > has an owner | PASS | PASS |
| Commit > will fail with an invalid sha | PASS | PASS |
| **Config** | | |
| Config > can get and set a global value | PASS | PASS |
| Config > can get and set a repo config value | PASS | PASS |
| **Config > getPath** | | |
| Config > getPath > can get path for a given config | PASS | PASS |
| **Config > openOnDisk** | | |
| Config > openOnDisk > opens the config and can change a value | PASS | PASS |
| Config > openOnDisk > opens the same config as the repo | PASS | PASS |
| **Config** | | |
| Config > will reject when getting value of non-existent config key | PASS | PASS |
| **ConvenientLine** | | |
| ConvenientLine > can get a line that contains ascii | PASS | PASS |
| ConvenientLine > can get a line that contains unicode | PASS | PASS |
| ConvenientLine > can parse the byte length of a ascii string | PASS | PASS |
| ConvenientLine > can parse the byte length of a unicode string | PASS | PASS |
| **Cred** | | |
| Cred > can create credentials using agent | PASS | PASS |
| Cred > can create credentials using plaintext | PASS | PASS |
| Cred > can create credentials using username | PASS | PASS |
| Cred > can create default credentials | PASS | PASS |
| Cred > can create ssh credentials using passed keys | PASS | PASS |
| Cred > can create ssh credentials using passed keys in memory | PASS | PASS |
| Cred > can return 0 if a username does not exist | PASS | PASS |
| Cred > can return 1 if a username exists | PASS | PASS |
| **Root** | | |
| Diff | N/A | FAIL |
| **Diff** | | |
| Diff > can diff index to workdir | PASS | FAIL |
| Diff > can diff the contents of a file to a string | PASS | PASS |
| Diff > can diff the contents of a file to a string with unicode characters | PASS | PASS |
| Diff > can diff the initial commit of a repository | PASS | PASS |
| Diff > can diff the workdir with index | PASS | FAIL |
| Diff > can diff tree to index | PASS | PASS |
| Diff > can diff with a null tree | PASS | FAIL |
| Diff > can find similar files in a diff | PENDING | PENDING |
| Diff > can merge two commit diffs | PASS | PASS |
| Diff > can pass undefined pathspec as option to indexToWorkdir | PASS | PASS |
| Diff > can resolve individual line changes from the patch hunks | PASS | PASS |
| Diff > can walk an Array<Diff> | PASS | PASS |
| **Diff > merge between commit diff and workdir and index diff** | | |
| Diff > merge between commit diff and workdir and index diff > can merge a diff from a commit into a diff from a work dir and index | PASS | PASS |
| Diff > merge between commit diff and workdir and index diff > can merge a diff from a workdir and index into a diff from a commit | PASS | PASS |
| **Root** | | |
| Filter | N/A | FAIL |
| **Filter > Apply** | | |
| Filter > Apply > applies the filter data on checkout | PASS | PASS |
| Filter > Apply > applies the filter data on checkout with gc | PASS | PASS |
| Filter > Apply > applies the filter data on commit | PASS | PASS |
| Filter > Apply > applies the filter data on commit with gc | PASS | PASS |
| Filter > Apply > can run async callback on checkout without deadlocking | PENDING | PENDING |
| Filter > Apply > can run sync callback on checkout without deadlocking | PASS | PASS |
| Filter > Apply > does not apply when GIT_PASSTHROUGH is returned | PASS | PASS |
| Filter > Apply > should apply filter when check succeeds | PASS | PASS |
| Filter > Apply > should not apply when check returns GIT_PASSTHROUGH | PASS | PASS |
| **Filter > FilterSource** | | |
| Filter > FilterSource > a FilterSource has an async repo getter | PASS | FAIL |
| **Filter > Manually Apply** | | |
| Filter > Manually Apply > applies the filters for a path on demand | PASS | PASS |
| Filter > Manually Apply > applies the filters to a blob on demand | PASS | PASS |
| Filter > Manually Apply > applies the filters to a buffer on demand | PASS | PASS |
| **Filter > Register** | | |
| Filter > Register > can register a filter | PASS | PASS |
| Filter > Register > can register multiple filters | PASS | PASS |
| Filter > Register > cannot register the same filter twice | PASS | PASS |
| **Filter > Unregister** | | |
| Filter > Unregister > can unregister the filter | PASS | PASS |
| Filter > Unregister > cannot unregister the filter twice | PASS | PASS |
| **Graph** | | |
| Graph > can get commits ahead/behind for 2 different commits | PASS | PASS |
| Graph > can tell if a commit is a descendant of another | PASS | PASS |
| Graph > can tell if a commit is not a descendant of another | PASS | PASS |
| Graph > can tell if a commit is reachable from any of a list of commits | PASS | PASS |
| Graph > descendantOf will error if provided bad commits | PASS | PASS |
| **Ignore** | | |
| Ignore > can determine if a path is ignored | PASS | PASS |
| **Root** | | |
| Index | N/A | FAIL |
| **Index** | | |
| Index > can add a conflict to the index | PASS | PASS |
| Index > can add all entries to the index | PASS | PASS |
| Index > can find the prefix when a file shares the name | PASS | PASS |
| Index > can find the specified file in the index | PASS | PASS |
| Index > can find the specified prefix in the index | PASS | PASS |
| Index > can get a conflict from the index | PASS | PASS |
| Index > can get the index of a repo and examine entries | PASS | PASS |
| Index > can remove entries from the index | PASS | FAIL |
| Index > can update entries in the index | PASS | PASS |
| Index > cannot find the directory in the index | PASS | PASS |
| Index > cannot find the specified file in the index | PASS | PASS |
| Index > cannot find the specified prefix in the index | PASS | PASS |
| **Mempack** | | |
| Mempack > can add mempack backend to ODB and write objects in memory | PASS | PASS |
| Mempack > can create a mempack backend | PASS | PASS |
| Mempack > can reset the mempack backend | PASS | PASS |
| Mempack > can write a tree via in-memory index without disk writes | PASS | PASS |
| **Merge** | | |
| Merge > can cleanly merge 2 files | PASS | PASS |
| Merge > can fast-forward using the convenience method | PASS | PASS |
| Merge > can merge --ff-only a fast-forward using the convenience method | PASS | PASS |
| Merge > can merge --no-ff a fast-forward using the convenience method | PASS | PASS |
| Merge > can merge --no-ff a non-fast-forward using the convenience method | PASS | PASS |
| Merge > can merge --no-ff a non-fast-forward using the convenience method with custom merge message via async callback | PASS | PASS |
| Merge > can merge --no-ff a non-fast-forward using the convenience method with custom merge message via sync callback | PASS | PASS |
| Merge > can merge 2 branchs with conflicts on a single file | PASS | PASS |
| Merge > can merge cleanly using the convenience method | PASS | PASS |
| Merge > can retrieve error code on if common merge base not found | PASS | PASS |
| Merge > doesn't merge --ff-only a non-fast-forward using the convenience method | PASS | PASS |
| Merge > leaves repo in MERGE state after a standard merge with conflicts fails | PASS | PASS |
| **Note** | | |
| Note > can be created | PASS | PASS |
| Note > can be read | PASS | PASS |
| Note > can be removed | PASS | PASS |
| Note > can iterate all notes | PASS | PASS |
| **Odb** | | |
| Odb > can read objects directly from the odb using a string | PASS | PASS |
| Odb > can read raw objects directly from the odb using an OID | PASS | PASS |
| Odb > can write raw objects to git | PASS | PASS |
| **Odb.hash** | | |
| Odb.hash > can hash a buffer without writing to ODB | PASS | PASS |
| Odb.hash > does not mutate the ODB when hashing a buffer | PASS | PASS |
| **Oid** | | |
| Oid > can check the equality of two different oids | PASS | PASS |
| Oid > can check the equality of two identical oids | PASS | PASS |
| Oid > can compare the first chunk of two different oids | PASS | PASS |
| Oid > can compare the first chunk of two identical oids | PASS | PASS |
| Oid > can compare two different oids | PASS | PASS |
| Oid > can compare two identical oids | PASS | PASS |
| Oid > can convert a string to an oid | PASS | PASS |
| Oid > can convert an oid to a string | PASS | PASS |
| Oid > can convert strings to oids in parameters | PASS | PASS |
| Oid > does not leak constructed Oid | PASS | PASS |
| Oid > does not leak owned Oid | PASS | PASS |
| Oid > provides a custom inspect method to improve debugging | PASS | PASS |
| **Packbuilder** | | |
| Packbuilder > can be initialized | PASS | PASS |
| **Patch** | | |
| Patch > can generate patch from blobs | PASS | PASS |
| Patch > can generate patch from blobs without 'old_blob' | PASS | PASS |
| Patch > can generate patch from blobs without arguments | PASS | PASS |
| Patch > retrieve the line stats of a patch | PASS | PASS |
| **Pathspec** | | |
| Pathspec > can accept just about anything against a * pathspec | PASS | PASS |
| Pathspec > can handle dirs | PASS | PASS |
| Pathspec > can take a * in an array | PASS | PASS |
| Pathspec > can take a single file | PASS | PASS |
| Pathspec > can take files in an array | PASS | PASS |
| **Rebase** | | |
| Rebase > beforeFinishFn async callback receives correct rebase data | PASS | PASS |
| Rebase > beforeFinishFn sync callback receives correct rebase data | PASS | PASS |
| Rebase > can abort an in-progress rebase | PASS | PASS |
| Rebase > can cleanly fast-forward via rebase | PASS | PASS |
| Rebase > can cleanly rebase a branch in-memory | PASS | PASS |
| Rebase > can cleanly rebase a branch onto another branch | PASS | PASS |
| Rebase > can fast-forward a merge commit via rebase using the convenience methods that has a beforeFinishFn | PASS | PASS |
| Rebase > can fast-forward via rebase using the convenience methods | PASS | PASS |
| Rebase > can optionally skip signing commits | PASS | PASS |
| Rebase > can rebase 2 branches with conflicts on a single file | PASS | PASS |
| Rebase > can rebase using the convenience method | PASS | PASS |
| Rebase > can rebase with conflicts using the convenience methods | PASS | PASS |
| Rebase > can sign commits during the rebase | PASS | PASS |
| Rebase > rebase signs correctly if rebaseOptions are re-used | PASS | PASS |
| Rebase > will not throw on patch already applied errors | PASS | PASS |
| Rebase > will throw if commit signing cb returns an error code | PASS | PASS |
| **Reference** | | |
| Reference > can check that reference is valid | PASS | PASS |
| Reference > can compare two different references | PASS | PASS |
| Reference > can compare two identical references | PASS | PASS |
| Reference > can determine if the reference is not symbolic | PASS | PASS |
| Reference > can determine if the reference is symbolic | PASS | PASS |
| Reference > can look up a reference | PASS | PASS |
| Reference > can look up the HEAD sha | PASS | PASS |
| Reference > can rename a reference | PASS | PASS |
| Reference > can return refName when casting toString | PASS | PASS |
| Reference > will return undefined looking up the symbolic target if not symbolic | PASS | PASS |
| **Root** | | |
| Remote | N/A | FAIL |
| **Remote** | | |
| Remote > can create and load a new remote | PASS | PASS |
| Remote > can delete a remote | PASS | PASS |
| Remote > can download from a remote | PASS | PASS |
| Remote > can fetch from a private repository | PASS | FAIL |
| Remote > can fetch from a remote | PASS | PASS |
| Remote > can fetch from all remotes | PASS | PASS |
| Remote > can get the default branch of a remote | PASS | PASS |
| Remote > can load a remote | PASS | PASS |
| Remote > can monitor transfer progress while downloading | PASS | PASS |
| Remote > can monitor transfer progress while pushing | PASS | PASS |
| Remote > can monitor transfer progress while pushing with throttling | PASS | PASS |
| Remote > can read the remote name | PASS | PASS |
| Remote > can read the remote url | PASS | PASS |
| Remote > can reject fetching from private repository without valid credentials | PASS | FAIL |
| Remote > can rename a remote | PASS | PASS |
| Remote > can retrieve the list of references advertised by a remote | PASS | PASS |
| Remote > can set a remote | PASS | PASS |
| Remote > cannot push to a repository with invalid credentials | PENDING | PENDING |
| Remote > has an empty pushurl by default | PASS | PASS |
| Remote > is kept alive by refspec | PASS | PASS |
| Remote > will error when retrieving reference list if not connected | PASS | PASS |
| Remote > will reject if credentials promise rejects | PENDING | PENDING |
| **Root** | | |
| Repository | N/A | FAIL |
| **Repository** | | |
| Repository > can be cleaned | PASS | FAIL |
| Repository > can commit on head on a empty repo with createCommitOnHead | PASS | PASS |
| Repository > can create a repo using initExt | PASS | PASS |
| Repository > can discover if a path is part of a repository, empty ceiling | PASS | PASS |
| Repository > can discover if a path is part of a repository, null ceiling | PASS | PASS |
| Repository > can get a reference commit | PASS | FAIL |
| Repository > can get all merge heads in a repo with mergeheadForeach | PASS | PASS |
| Repository > can get the current branch | PASS | PASS |
| Repository > can get the default signature | PASS | PASS |
| Repository > can get the head commit | PASS | FAIL |
| Repository > can initialize a repository into a folder | PASS | PASS |
| Repository > can list remotes | PASS | PASS |
| Repository > can obtain statistics from a valid constant repository | PASS | FAIL |
| Repository > can open a valid repository | PASS | PASS |
| Repository > can read the index | PASS | PASS |
| Repository > can utilize repository init options | PASS | PASS |
| Repository > cannot instantiate a repository | PASS | PASS |
| Repository > cannot open an invalid repository | PASS | PASS |
| Repository > does not try to open paths that don't exist | PASS | PASS |
| Repository > gets extended statuses | PASS | FAIL |
| Repository > gets fetch-heads | PASS | PASS |
| Repository > gets statuses with StatusFile | PASS | FAIL |
| Repository > returns null if there is no head commit | PASS | PASS |
| Repository > will throw when a repo cannot be initialized using initExt | PASS | PASS |
| **Repository.hashfile** | | |
| Repository.hashfile > can hash a file with as_path filter hint | PASS | PASS |
| Repository.hashfile > can hash a file with repository filters | PASS | PASS |
| Repository.hashfile > does not mutate the ODB when hashing a file | PASS | PASS |
| **Reset** | | |
| Reset > can perform a hard reset | PASS | PASS |
| Reset > can perform a mixed reset | PASS | PASS |
| Reset > can perform a soft reset | PASS | PASS |
| Reset > can perform an annotated hard reset | PASS | PASS |
| Reset > can perform an annotated mixed reset | PASS | PASS |
| Reset > can perform an annotated soft reset | PASS | PASS |
| Reset > can reset a file to a previous commit | PASS | PASS |
| Reset > reset fails if originating repository is not the same | PASS | PASS |
| Reset > reset fails if parameter is not a Commit object | PASS | PASS |
| **Revert** | | |
| Revert > RevertOptions is optional (null) | PASS | PASS |
| Revert > RevertOptions is optional (unspecified) | PASS | PASS |
| Revert > RevertOptions without MergeOptions should not segfault | PASS | PASS |
| Revert > revert modifies the index | PASS | PASS |
| Revert > revert modifies the working directoy | PASS | PASS |
| **Revparse** | | |
| Revparse > can revparse HEAD commit with single method | PASS | PASS |
| Revparse > will fail on invalid spec | PASS | PASS |
| Revparse > will fail without repo | PASS | PASS |
| Revparse > will fail without spec | PASS | PASS |
| **Root** | | |
| Revwalk | N/A | FAIL |
| **Revwalk** | | |
| Revwalk > can create a walker | PASS | PASS |
| Revwalk > can do a fast walk | PASS | PASS |
| Revwalk > can get a specified number of commits | PASS | PASS |
| Revwalk > can get commits until you tell it not to | PASS | PASS |
| Revwalk > can get the history of a dir | PASS | PASS |
| Revwalk > can get the history of a file | PASS | FAIL |
| Revwalk > can get the history of a file while ignoring parallel branches | PASS | PASS |
| Revwalk > can get the largest number of commits within a specified range | PASS | PASS |
| Revwalk > can hide an object | PASS | PASS |
| Revwalk > can push an object | PASS | PASS |
| Revwalk > can simplify to first parent | PASS | PASS |
| Revwalk > can yield information about renames in a file history walk | PASS | FAIL |
| Revwalk > does not leak | PASS | PASS |
| Revwalk > doesnt segfault when accessing .author() twice | PASS | PENDING |
| Revwalk > will return all commits from the revwalk if nothing matches | PASS | PASS |
| **Signature** | | |
| Signature > can be created at an arbitrary time | PASS | PASS |
| Signature > can be created now | PASS | PASS |
| Signature > can get a default signature when no user name is set | PASS | PASS |
| Signature > duplicates time | PASS | PASS |
| Signature > toString does not provide a timestamp by default | PASS | PASS |
| Signature > toString provides the correct timestamp when requested | PASS | PASS |
| **Stage** | | |
| Stage > can discard selected lines | PASS | PASS |
| Stage > can stage filemode changes for one file | PASS | PASS |
| Stage > can stage last line with no newline at EOF | PASS | PASS |
| Stage > can stage second to last line with no newline at EOF | PASS | PASS |
| Stage > can stage selected lines | PASS | PASS |
| Stage > can stage/unstage filemode changes for multiple files | PASS | PASS |
| Stage > can unstage filemode changes | PASS | PASS |
| Stage > can unstage last line with no newline at EOF | PASS | PASS |
| Stage > can unstage second to last line with no newline at EOF | PASS | PASS |
| Stage > can unstage selected lines | PASS | PASS |
| Stage > staging last hunk stages whole file if no filemode changes | PASS | PASS |
| **Root** | | |
| Stash | N/A | FAIL |
| **Stash** | | |
| Stash > can partial stash the workdir and pop it | PASS | PASS |
| Stash > can save a stash with no message and drop it | PASS | FAIL |
| Stash > can save a stash, change files, and fail to pop stash | PASS | PASS |
| Stash > can save and drop a stash | PASS | FAIL |
| Stash > can save and pop a stash | PASS | PASS |
| Stash > can save multiple stashes and pop an arbitrary stash | PASS | FAIL |
| Stash > can save, apply, then drop the stash | PASS | PASS |
| Stash > gets no stashes on clean working directory | PASS | FAIL |
| **Root** | | |
| Status | N/A | FAIL |
| **Status** | | |
| Status > gets a status on changing file directory | PASS | FAIL |
| Status > gets no statuses on clean working directory | PASS | FAIL |
| Status > gets status on non-existent file results in error | PASS | PASS |
| Status > gets status with options | PASS | FAIL |
| **StatusFile** | | |
| StatusFile > identifies the proper statuses for CURRENT | PENDING | PENDING |
| StatusFile > identifies the proper statuses for IGNORED | PASS | PASS |
| StatusFile > identifies the proper statuses for INDEX_DELETED | PASS | PASS |
| StatusFile > identifies the proper statuses for INDEX_MODIFIED | PASS | PASS |
| StatusFile > identifies the proper statuses for INDEX_NEW | PASS | PASS |
| StatusFile > identifies the proper statuses for INDEX_RENAMED | PASS | PASS |
| StatusFile > identifies the proper statuses for INDEX_TYPECHANGE | PASS | PASS |
| StatusFile > identifies the proper statuses for WT_DELETED | PASS | PASS |
| StatusFile > identifies the proper statuses for WT_MODIFIED | PASS | PASS |
| StatusFile > identifies the proper statuses for WT_NEW | PASS | PASS |
| StatusFile > identifies the proper statuses for WT_RENAMED | PASS | PASS |
| StatusFile > identifies the proper statuses for WT_TYPECHANGE | PASS | PASS |
| StatusFile > identifies the proper statuses for WT_UNREADABLE | PENDING | PENDING |
| **Root** | | |
| StatusList | N/A | FAIL |
| **StatusList** | | |
| StatusList > gets status with deltas | PASS | FAIL |
| **Submodule** | | |
| Submodule > can get submodule location | PASS | PASS |
| Submodule > can get submodule status | PASS | PASS |
| Submodule > can run async callback without deadlocking | PASS | PASS |
| Submodule > can run sync callback without deadlocking | PASS | PASS |
| Submodule > can set submodule ignore | PASS | PASS |
| Submodule > can set submodule update | PASS | PASS |
| Submodule > can set submodule url | PASS | PASS |
| Submodule > can setup and finalize submodule add | PASS | PASS |
| Submodule > can walk over the submodules | PASS | PASS |
| **Tag** | | |
| Tag > can create a Tag buffer | PASS | PASS |
| Tag > can create a Tag from a Tag buffer | PASS | PASS |
| Tag > can create a new annotated tag in a repo and delete it | PASS | PASS |
| Tag > can create a new lightweight tag in a repo and delete it | PASS | PASS |
| Tag > can create a new signed tag with Tag.annotationCreate | PASS | PASS |
| Tag > can create a new signed tag with Tag.create and delete it | PASS | PASS |
| Tag > can get a tag from a repo via the long tag name | PASS | PASS |
| Tag > can get a tag from a repo via the tag name | PASS | PASS |
| Tag > can get a tag from a repo via the tag's OID as a string | PASS | PASS |
| Tag > can get a tag from a repo via the tag's OID object | PASS | PASS |
| Tag > can get tag's owner | PASS | PASS |
| Tag > can get tag's target id | PASS | PASS |
| Tag > can list tags in a repo | PASS | PASS |
| Tag > can list tags of a pattern in a repo | PASS | PASS |
| Tag > can peel a tag | PASS | PASS |
| **Tag > createWithSignature and extractSignature** | | |
| Tag > createWithSignature and extractSignature > can create a tag with a signature and extract the signature | PASS | PASS |
| Tag > createWithSignature and extractSignature > can optionally skip the signing process | PASS | PASS |
| Tag > createWithSignature and extractSignature > will throw if signing callback returns an error code | PASS | PASS |
| **Tag** | | |
| Tag > will show a deprecation warning if createWithSignature use oid instead object | PASS | PASS |
| **Tree** | | |
| Tree > get all paths from a tree | PASS | PASS |
| Tree > gets an entry by name | PASS | PASS |
| Tree > updates a tree | PASS | PASS |
| Tree > walks its entries and returns the same entries on both progress and end | PASS | PASS |
| **Root** | | |
| TreeBuilder | N/A | FAIL |
| **TreeBuilder** | | |
| TreeBuilder > Can add a new tree to an existing tree | PASS | PASS |
| TreeBuilder > Can create a new treebuilder with no source | PASS | PASS |
| TreeBuilder > Can create a treebuilder from the latest commit tree | PASS | FAIL |
| TreeBuilder > does not leak inserts | PASS | PASS |
| **TreeEntry** | | |
| TreeEntry > can convert entry into a blob | PASS | PASS |
| TreeEntry > can convert entry into a tree | PASS | PASS |
| TreeEntry > can determine if an entry is a directory | PASS | PASS |
| TreeEntry > can determine if an entry is a file | PASS | PASS |
| TreeEntry > can determine if an entry is a submodule | PASS | PASS |
| TreeEntry > can determine if an entry is not a file | PASS | PASS |
| TreeEntry > can determine if an entry is not a submodule | PASS | PASS |
| TreeEntry > does not leak | PASS | PASS |
| TreeEntry > provides the blob representation of the entry | PASS | PASS |
| TreeEntry > provides the blob representation via callback | PASS | PASS |
| TreeEntry > provides the correct length for a file | PASS | PASS |
| TreeEntry > provides the correct sha for a file | PASS | PASS |
| TreeEntry > provides the filename | PASS | PASS |
| TreeEntry > provides the full path | PASS | PASS |
| TreeEntry > provides the full path when the entry came from a tree | PASS | PASS |
| TreeEntry > provides the tree the entry is part of | PASS | PASS |
| TreeEntry > will fail on a missing file | PASS | PASS |
| **Worker** | | |
| Worker > can kill worker thread while doing a checkout and exit gracefully | PENDING | PENDING |
| Worker > can kill worker thread while in use #0 | PENDING | PENDING |
| Worker > can kill worker thread while in use #1 | PENDING | PENDING |
| Worker > can kill worker thread while in use #2 | PENDING | PENDING |
| Worker > can kill worker thread while in use #3 | PENDING | PENDING |
| Worker > can kill worker thread while in use #4 | PENDING | PENDING |
| Worker > can perform basic functionality via worker thread | PENDING | PENDING |
| Worker > can track objects to free on context shutdown | PENDING | PENDING |
| Worker > can track objects to free on context shutdown after multiple checkouts | PENDING | PENDING |
