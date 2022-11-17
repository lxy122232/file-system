#ifndef HEAD_H
#define HEAD_H

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>   //
#include <string.h>
#include <time.h>

#define BLOCKSIZE 1024   //磁盘块大小
#define SIZE 1024000     //虚拟磁盘空间大小
#define END 65535        //文件结束标志
#define FREE 0           //盘块空闲标志
#define ROOTBLOCKNUM 2   //根目录区所占盘块总数
#define MAXOPENFILE 10   //最多同时打开最大文件数
#define MAX_TEXT_SIZE 10000 //?

typedef struct FCB {
    char filename[8];   //文件名
    char exname[3];     //文件扩展名
    unsigned char attribute; // 值为0时表示目录文件，值为1时表示数据文件
    unsigned short time;//文件创建时间
    unsigned short date;//文件创建日期
    unsigned short first;//文件起始盘块号
    unsigned short length;//文件长度（字节数）
    char free;  //表示目录项是否为空，若值为0，表示空，值为1，表示已分配
} fcb;

typedef struct FAT {
    unsigned short id;
} fat;

typedef struct USEROPEN {
    char filename[8];//文件名
    char exname[3];//文件扩展名
    unsigned char attribute;//文件属性：值为0时表示目录文件，值为1时表示数据文件
    unsigned short time;//文件创建时间
    unsigned short date;//文件创建日期
    unsigned short first;//文件起始盘块号
    unsigned short length;//文件长度（对数据文件是字节数，对目录文件可以是目录项个数）
    char free;//表示目录项是否为空，若值为0，表示空，值为1，表示已分配.前面内容是文件的FCB中的内容。
    int dirno; // 父目录文件起始盘块号  //相应打开文件的目录项在父目录文件中的盘块号
    int diroff; // 该文件对应的 fcb 在父目录中的逻辑序号 // 相应打开文件的目录项在父目录文件的dirno盘块中的目录项序号
    char dir[MAXOPENFILE][80]; // 全路径信息 //相应打开文件所在的目录名，这样方便快速检查出
                                //指定文件是否已经打开

    int count;//读写指针在文件中的位置
    char fcbstate;  //是否修改了文件的FCB的内容，如果修改了置为1，否则为0
    char topenfile; //表示该用户打开表项是否为空，若值为0，表示为空，否则表示已被某打开文件占据

} useropen;

typedef struct BLOCK {   //引导块内容
    char magic_number[8];//魔数
    char information[200];//存储一些描述信息，如磁盘块大小、磁盘块数量、最多打开文件数等
    unsigned short root;//根目录文件的起始盘块号
    unsigned char *startblock;//虚拟磁盘上数据区开始位置
} block0;

extern unsigned char *myvhard; //指向虚拟磁盘的起始地址
// useropen *ptrcurdir;  //指向用户打开文件表中的当前目录所在打开文件表项的位置
extern useropen openfilelist[MAXOPENFILE];//用户打开文件表数组
extern int currfd;
//char currentdir[80]; //记录当前目录的目录名（包括目录的路径）
extern unsigned char *startp; // 记录虚拟磁盘上数据区开始位置  老师有,前人没有
//extern char *FILENAME;
extern unsigned char buffer[SIZE];


/* sysfile func */
void my_startsys();

void my_format();

void my_cd(char *dirname);

int do_read(int fd, int len, char *text);

int do_write(int fd, char *text, int len, char wstyle);

int my_read(int fd);

int my_write(int fd);

void my_exitsys();

//void my_cd(char* dirname);       多余的定义
int my_open(char *filename);

int my_close(int fd);

void my_mkdir(char *dirname);

void my_rmdir(char *dirname);

int my_create(char *filename);

void my_rm(char *filename);

void my_ls();

void help(char *command);

int get_free_openfilelist();

unsigned short int get_free_block();

extern char *FILENAME;

#endif