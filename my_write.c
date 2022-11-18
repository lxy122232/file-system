#include "head.h"

int my_write(int fd) {
    if (fd < 0 || fd >= MAXOPENFILE) {
        printf("my_write: no such file\n");
        return -1;
    }
    int wstyle;
    while (1) {
        // 1: 截断写，清空全部内容，从头开始
        // 2. 覆盖写，从文件指针处开始写
        // 3. 追加写，在最后开始续写
        printf("1:Truncation  2:Coverage  3:Addition\n");  //coverage用不了
        scanf("%d", &wstyle);
        if (wstyle > 3 || wstyle < 1) {
            printf("input error\n");   //如果忘记输入写入模式,就会疯狂报错并请求输入循环输入字符数量次
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
        texttmp[strlen(texttmp)] = '\n';   //实现换行
        strcat(text, texttmp);    //把输入的拼到text后
    }

    text[strlen(text) - 1] = '\0';         //不减1追加的时候默认会换行,减1之后,追加时需要换行,则需要直接输一个回车
    do_write(fd, text, strlen(text) + 1, wstyle);  //+1暂不知何用
    openfilelist[fd].fcbstate = 1;
    return 1;        //返回实际写入的字节数 还没实现
}

