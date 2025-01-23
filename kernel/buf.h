struct buf {
  int valid;   // has data been read from disk?
  int disk;    // does disk "own" buf?
  uint dev;  //存储设备
  uint blockno; //块号
  struct sleeplock lock;
  uint refcnt; //引用计数，表示当前缓冲区被多少个进程引用
//  struct buf *prev; // LRU cache list
  struct buf *next;
  uchar data[BSIZE]; //缓冲区数据

  uint lastuse;     //用于跟踪LRU-buf
};

