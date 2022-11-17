#include "head.h"

void my_startsys()
{
    /**
     * 如果存在文件系统（存在 FILENAME 这个文件 且 开头为魔数）则
	 * 将 root 目录载入打开文件表。
	 * 否则，调用 my_format 创建文件系统，再载入。
	 */
    myvhard = (unsigned char*)malloc(SIZE);   //虚拟磁盘空间大小
    FILE* file;
    if ((file = fopen(FILENAME, "r")) != NULL) {
        fread(buffer, SIZE, 1, file);   //读取文件到buffer里面,第二个参数是每块的大小,第三个参数是读取的块数,如果读取成功,返回实际读取的块数.
        fclose(file);
        if (memcmp(buffer, "10101010", 8) == 0) {   //两个内存块字节相同
            memcpy(myvhard, buffer, SIZE);
            printf("myfsys file read successfully\n");
        } else {
            printf("invalid myfsys magic num, create file system\n");
            my_format();
            memcpy(buffer, myvhard, SIZE);
        }
    } else {
        printf("myfsys not find, create file system\n");
        my_format();
        memcpy(buffer, myvhard, SIZE);
    }

    fcb* root;
    root = (fcb*)(myvhard + 5 * BLOCKSIZE);
    strcpy(openfilelist[0].filename, root->filename);
    strcpy(openfilelist[0].exname, root->exname);
    openfilelist[0].attribute = root->attribute;
    openfilelist[0].time = root->time;
    openfilelist[0].date = root->date;
    openfilelist[0].first = root->first;
    openfilelist[0].length = root->length;
    openfilelist[0].free = root->free;

    openfilelist[0].dirno = 5;
    openfilelist[0].diroff = 0;
    strcpy(openfilelist[0].dir, "/root/");
    openfilelist[0].count = 0;
    openfilelist[0].fcbstate = 0;
    openfilelist[0].topenfile = 1;

    startp = ((block0*)myvhard)->startblock;
    currfd = 0;
    return;
}
