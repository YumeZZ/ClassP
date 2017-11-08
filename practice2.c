#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    pid_t pid = 0;
    int ret = 0;
    char command[100];
    
    printf("\nenter command to execute or exit to leave\n");
    printf("\n\x1B[32mZong :");
    while(scanf("%s", command)) {
        if (strcmp("exit", command) == 0) {
            printf("\n Program terminated\n");
            exit(0);
        }
        pid = fork();
        if (pid == 0) {
            //execlp()會從PATH環境變量所指的目錄中查找符合參數file的文件名，找到後執行該文件，然後將第二個以後的參數當做該文件的argv[0]、argv[1]……，最後一個參數必須用空指針(NULL)作結束。
            ret = execlp(command, command, NULL);
            if (ret == -1)
                printf("\nCommand error\n");
        } else
            wait(NULL);
            printf("\n\x1B[37mZong: ");
    } exit(0);
}