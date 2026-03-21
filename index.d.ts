/**
 * Type declarations for bungit (Bun-compatible libgit2 bindings).
 * https://github.com/up-to-speed/nodegit
 */
declare module "bungit" {
  class Oid {
    static fromString(hex: string): Oid;
    tostrS(): string;
    equal(other: Oid): boolean;
    iszero(): boolean;
  }

  namespace Object {
    enum TYPE {
      ANY = -2,
      BAD = -1,
      COMMIT = 1,
      TREE = 2,
      BLOB = 3,
      TAG = 4,
    }
  }

  /** A libgit2 object returned by Revparse.single. Use .id() to get the Oid. */
  class GitObject {
    id(): Oid;
  }

  class OdbObject {
    type(): Object.TYPE;
    size(): number;
  }

  class Odb {
    static hash(
      data: string | Buffer,
      len: number,
      type: Object.TYPE,
    ): Promise<Oid>;

    read(oid: Oid | string): Promise<OdbObject>;
    write(
      data: string | Buffer,
      len: number,
      type: Object.TYPE,
    ): Promise<Oid>;
    addMempackBackend(backend: Mempack, priority: number): Promise<void>;
  }

  class Mempack {
    static create(): Promise<Mempack>;
    reset(): Promise<void>;
  }

  class Ignore {
    static pathIsIgnored(repo: Repository, path: string): Promise<number>;
    static addRule(repo: Repository, rules: string): Promise<void>;
    static clearInternalRules(repo: Repository): Promise<void>;
  }

  namespace Filter {
    enum MODE {
      TO_WORKTREE = 0,
      SMUDGE = 0,
      TO_ODB = 1,
      CLEAN = 1,
    }

    enum FLAG {
      DEFAULT = 0,
      ALLOW_UNSAFE = 1,
      NO_SYSTEM_ATTRIBUTES = 2,
      ATTRIBUTES_FROM_HEAD = 4,
      ATTRIBUTES_FROM_COMMIT = 8,
    }
  }

  class FilterList {
    static load(
      repo: Repository,
      blob: Blob | null,
      path: string,
      mode: Filter.MODE,
      flags: Filter.FLAG,
    ): Promise<FilterList | null>;

    applyToFile(repo: Repository, path: string): Promise<string | Buffer>;
    applyToData(data: string): Promise<string | Buffer>;
  }

  class Reference {
    static nameToId(repo: Repository, name: string): Promise<Oid>;
    static lookup(
      repo: Repository,
      name: string,
      len?: number,
    ): Promise<Reference>;
    static list(repo: Repository): Promise<string[]>;

    name(): string;
    target(): Oid;
    isBranch(): boolean;
    isTag(): boolean;
    isRemote(): boolean;
    isSymbolic(): boolean;
    symbolicTarget(): string;
    resolve(): Promise<Reference>;
  }

  class Submodule {
    static lookup(repo: Repository, name: string): Promise<Submodule>;
    static foreach(
      repo: Repository,
      callback: (submodule: Submodule, name: string) => number,
    ): Promise<void>;

    headId(): Oid | null;
    indexId(): Oid | null;
    wdId(): Oid | null;
    path(): string;
  }

  class Config {
    getBool(name: string): Promise<boolean>;
    getInt32(name: string): Promise<number>;
    getInt64(name: string): Promise<number>;
    getString(name: string): Promise<string>;
    setString(name: string, value: string): Promise<number>;
    setBool(name: string, value: boolean): Promise<number>;
    setInt32(name: string, value: number): Promise<number>;
    setInt64(name: string, value: number): Promise<number>;
  }

  class Repository {
    static open(path: string): Promise<Repository>;
    static init(path: string, isBare: number): Promise<Repository>;

    workdir(): string | null;
    path(): string;
    odb(): Promise<Odb>;
    config(): Promise<Config>;
    hashfile(
      path: string,
      type: Object.TYPE,
      asPath?: string,
    ): Promise<Oid>;
    refreshIndex(): Promise<Index>;
  }

  class Index {
    static create(): Promise<Index>;
    static open(path: string): Promise<Index>;

    add(entry: IndexEntry): Promise<void>;
    addByPath(path: string): Promise<void>;
    entryCount(): number;
    getByIndex(idx: number): IndexEntry;
    entries(): IndexEntry[];
    write(): Promise<void>;
    writeTree(): Promise<Oid>;
    writeTreeTo(repo: Repository): Promise<Oid>;
    clear(): Promise<void>;
  }

  class IndexEntry {
    path: string;
    id: Oid;
    mode: number;
    fileSize: number;
    flags: number;
    flagsExtended: number;
  }

  class Tree {
    static lookup(repo: Repository, id: string | Oid | Tree): Promise<Tree>;

    entryCount(): number;
    entryByIndex(idx: number): TreeEntry;
    entryByName(name: string): TreeEntry;
    entryByPath(path: string): Promise<TreeEntry>;
    entries(): TreeEntry[];
    builder(): Treebuilder;
  }

  class TreeEntry {
    name(): string;
    path(): string;
    oid(): Oid;
    id(): Oid;
    filemode(): number;
    isFile(): boolean;
    isTree(): boolean;
    isBlob(): boolean;
    getBlob(): Promise<Blob>;
    getTree(): Promise<Tree>;
  }

  class Treebuilder {
    static create(
      repo: Repository,
      source?: Tree | null,
    ): Promise<Treebuilder>;

    insert(filename: string, id: Oid, filemode: number): Promise<TreeEntry>;
    write(): Promise<Oid>;
    entrycount(): number;
    get(filename: string): TreeEntry | null;
    remove(filename: string): Promise<void>;
    clear(): void;
  }

  class Blob {
    static lookup(repo: Repository, oid: Oid): Promise<Blob>;

    content(): Buffer;
    rawsize(): number;
  }

  class Commit {
    static lookup(repo: Repository, oid: Oid): Promise<Commit>;

    sha(): string;
    summary(): string;
    author(): Signature;
    date(): Date;
    parentcount(): number;
    parentId(n: number): Oid;
    getTree(): Promise<Tree>;
  }

  class Signature {
    name(): string;
    email(): string;
  }

  namespace Revparse {
    function single(repo: Repository, spec: string): Promise<GitObject>;

    enum MODE {
      SINGLE = 1,
      RANGE = 2,
      MERGE_BASE = 4,
    }
  }

  class Revwalk {
    static create(repo: Repository): Revwalk;

    sorting(sort: number): void;
    push(oid: Oid): void;
    pushHead(): void;
    hide(oid: Oid): void;
    next(): Promise<Oid>;
    getCommits(count: number): Promise<Commit[]>;
  }

  namespace Revwalk {
    const SORT: {
      NONE: 0;
      TOPOLOGICAL: 1;
      TIME: 2;
      REVERSE: 4;
    };
  }

  namespace Merge {
    function base(repo: Repository, one: Oid, two: Oid): Promise<Oid>;
  }

  namespace Graph {
    function aheadBehind(
      repo: Repository,
      local: Oid,
      upstream: Oid,
    ): Promise<{ ahead: number; behind: number }>;
  }

  class Remote {
    static lookup(repo: Repository, name: string): Promise<Remote>;

    url(): string;
    name(): string;
  }

  namespace Branch {
    function upstream(ref: Reference): Promise<Reference>;
  }

  const _default: {
    Repository: typeof Repository;
    Oid: typeof Oid;
    Odb: typeof Odb;
    Object: typeof Object;
    GitObject: typeof GitObject;
    Index: typeof Index;
    IndexEntry: typeof IndexEntry;
    Tree: typeof Tree;
    TreeEntry: typeof TreeEntry;
    Treebuilder: typeof Treebuilder;
    Blob: typeof Blob;
    Commit: typeof Commit;
    Mempack: typeof Mempack;
    Ignore: typeof Ignore;
    Filter: typeof Filter;
    FilterList: typeof FilterList;
    Config: typeof Config;
    Reference: typeof Reference;
    Submodule: typeof Submodule;
    Revparse: typeof Revparse;
    Revwalk: typeof Revwalk;
    Merge: typeof Merge;
    Graph: typeof Graph;
    Remote: typeof Remote;
    Branch: typeof Branch;
    Signature: typeof Signature;
  };

  export = _default;
}
