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

  class Repository {
    static open(path: string): Promise<Repository>;
    static init(path: string, isBare: number): Promise<Repository>;

    workdir(): string | null;
    path(): string;
    odb(): Promise<Odb>;
    hashfile(
      path: string,
      type: Object.TYPE,
      asPath?: string,
    ): Promise<Oid>;
    refreshIndex(): Promise<Index>;
    free(): void;
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
    content(): Buffer;
    rawsize(): number;
  }

  const _default: {
    Repository: typeof Repository;
    Oid: typeof Oid;
    Odb: typeof Odb;
    Object: typeof Object;
    Index: typeof Index;
    IndexEntry: typeof IndexEntry;
    Tree: typeof Tree;
    TreeEntry: typeof TreeEntry;
    Treebuilder: typeof Treebuilder;
    Blob: typeof Blob;
    Mempack: typeof Mempack;
    Ignore: typeof Ignore;
  };

  export = _default;
}
