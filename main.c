#include "head.h"

//debug func
void test()
{
    int openfile_num = 0;
    int i;
    printf("debug area ############\n");
    // print open file number
    for (i = 0; i < MAXOPENFILE; i++) {
        if (openfilelist[i].topenfile == 1) {
            openfile_num++;
        }
    }
    printf("  open file number: %d\n", openfile_num);
    printf("  curr file name: %s\n", openfilelist[currfd].filename);
    printf("  curr file length: %d\n", openfilelist[currfd].length);

    printf("debug end  ############\n");
}

int main(void)
{

    char dict[13][20] = {        //注意这个20表示的是这里面命令字符个数不超过20

            "mkdir", "rmdir", "ls", "cd", "create",
            "rm", "open", "close", "write", "read",
            "exit", "help", "test"
    };
    char command[30], *sp;
    int cmd_idx, i;
    printf("**************** file system start ***************\n");
    my_startsys();

    while (1) {
        printf("%s> ", openfilelist[currfd].dir);    //   值为  /root/>
        gets(command);
        cmd_idx = -1;
        if (strcmp(command, "") == 0) {   //字符串比较函数,如果输入为空,返回0,仅仅换行,继续等待用户输入
            printf("\n");
            continue;
        }
        sp = strtok(command, " ");  //因为命令中存在用空格隔开的情况,需要把字符串分割
        for (i = 0; i < 13; i++) {            //先取出第一个命令,与预先定义好的命令数组dict比较是否存在
            if (strcmp(sp, dict[i]) == 0) {
                cmd_idx = i;
                break;
            }
        }
        switch (cmd_idx) {  //实现逻辑需要改,不能俩空格还能搞
            case 0: // mkdir  //实现逻辑需要改,不能俩空格还能搞
                sp = strtok(NULL, " ");   //提取后部分命令
                if (sp != NULL)                     //如果不为空说明后部分命令为要新建的文件(夹)?
                    my_mkdir(sp);           //建
                else
                    printf("mkdir error\n");  //为空说明没指定,创建错误
                 sp = strtok(NULL, " ");   //后面还多了个参数格式错误
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_mkdir  dir_name\n");
                break;
            case 1: // rmdir   //实现逻辑需要改,不能俩空格还能搞
                sp = strtok(NULL, " ");     //后部分命令不为空,则删除对应文件夹,为空报错.
                if (sp != NULL)
                    my_rmdir(sp);
                else
                    printf("rmdir error\n");
                sp = strtok(NULL, " ");             //多余命令报错
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_rmdir dir_name\n");
                break;
            case 2: // ls
                my_ls();
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_ls\n");
                break;
            case 3: // cd          //实现逻辑需要改,不能俩空格还能搞
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    my_cd(sp);
                else
                    printf("cd error\n");
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_cd dir_name\n");
                break;
            case 4: // create
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    my_create(sp);
                else
                    printf("create error\n");
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_create file_name\n");
                break;
            case 5: // rm
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    my_rm(sp);
                else
                    printf("rm error\n");
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_rm file_name\n");
                break;
            case 6: // open
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    my_open(sp);
                else
                    printf("open error\n");
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_open file_name\n");
                break;
            case 7: // close
                if (openfilelist[currfd].attribute == 1)   //已有文件打开
                    my_close(currfd);
                else
                    printf("there is not openning file\n");
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_close fd\n");
                break;
            case 8: // write
                if (openfilelist[currfd].attribute == 1)
                    my_write(currfd);
                else
                    printf("please open file first, then write\n");
                break;
            case 9: // read
                if (openfilelist[currfd].attribute == 1)
                    my_read(currfd);
                else
                    printf("please open file first, then read\n");
                break;
            case 10: // exit
                my_exitsys();   //见exit就退,后面空格跟啥都退
                return 0;
                //break;       不可达,我把他注释了
            case 11: // help
                sp = strtok(NULL, " ");    //他这个help挺奇怪的,必须要help all才能打开全部帮助
                if (sp != NULL)                       //然后help my_对应功能才行,
                    help(sp);
                else
                    printf("rm error\n");
                sp = strtok(NULL, " ");
                if (sp != NULL)
                    printf("\nwarning:you only need to INPUT my_help function_name\n");
                break;
            case 12: // test
                test();
                break;
            default:
                printf("wrong command: %s\n", command);
                break;
        }
    }
    return 0;
}
