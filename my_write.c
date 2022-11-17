#include "head.h"

int my_write(int fd)
{
    if (fd < 0 || fd >= MAXOPENFILE) {
        printf("my_write: no such file\n");
        return -1;
    }
    int wstyle;
    while (1) {
        // 1: 截断写，清空全部内容，从头开始
        // 2. 覆盖写，从文件指针处开始写
        // 3. 追加写，在最后开始续写
        printf("1:Truncation  2:Coverage  3:Addition\n");
        scanf("%d", &wstyle);
        if (wstyle > 3 || wstyle < 1) {
            printf("input error\n");
        } else {
            break;
        }
    }
    char text[MAX_TEXT_SIZE] = "\0";
    char texttmp[MAX_TEXT_SIZE] = "\0";
    printf("please input data, line feed ,finally input CTR+Z to end file\n");
    getchar();
    while (gets(texttmp)) {
        if (strcmp(texttmp, "CTR+Z") == 0) {
            break;
        }
        texttmp[strlen(texttmp)] = '\n';
        strcat(text, texttmp);
    }

    text[strlen(text)] = '\0';
    do_write(fd, text, strlen(text) + 1, wstyle);
    openfilelist[fd].fcbstate = 1;
    return 1;        //返回实际写入的字节数 还没实现
}

