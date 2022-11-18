#include "head.h"

void help(char* command) //test
{
    if (strcmp(command, "mkdir") == 0){
        printf("%s\n", "use 'my_mkdir + dir_name' to create a dictionary");
    }
    else if(strcmp(command, "rmdir") == 0){
        printf("%s\n", "use 'rmdir dir_name' to remove a dictionary");
    }
    else if(strcmp(command, "ls") == 0){
        printf("%s\n", "use 'ls dir_name' to list contain in dictionary");
    }
    else if(strcmp(command, "cd") == 0){
        printf("%s\n", "use 'cd dir_name' to go to the dictionary");
    }
    else if(strcmp(command, "create") == 0){
        printf("%s\n", "use 'create file_name' to create a file");
    }
    else if(strcmp(command, "my_open") == 0){
        printf("%s\n", "use 'open file_name' to open a file");
    }
    else if(strcmp(command, "my_close") == 0){
        printf("%s\n", "use 'close file_name' to close the file");
    }
    else if(strcmp(command, "my_write") == 0){
        printf("%s\n", "use 'write file_name' to write contain to the file");
    }
    else if(strcmp(command, "my_read") == 0){
        printf("%s\n", "use 'read file_name' to read the file");
    }
    else if(strcmp(command, "my_rm") == 0){
        printf("%s\n", "use 'rm file_name' to rn the file");
    }
    else if(strcmp(command, "my_exit") == 0){
        printf("%s\n", "use 'exit' to exit the system");
    }
    else if(strcmp(command, "all") == 0){
        printf("%s\n", "use 'ls dir_name' to list contain in dictionary");
        printf("%s\n", "use 'mkdir dir_name' to create a dictionary");
        printf("%s\n", "use 'rmdir dir_name' to remove a dictionary");
        printf("%s\n", "use 'cd dir_name' to go to the dictionary");
        printf("%s\n", "use 'create file_name' to create a file");
        printf("%s\n", "use 'open file_name' to open a file");
        printf("%s\n", "use 'close file_name' to close the file");
        printf("%s\n", "use 'write file_name' to write contain to the file");
        printf("%s\n", "use 'read file_name' to read the file");
        printf("%s\n", "use 'rm file_name' to rn the file");
        printf("%s\n", "use 'exit' to exit the system");
    }
    else {
        printf("%s\n", "command error");
    }
}

