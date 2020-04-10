#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include <sys/wait.h>
#include<sys/types.h>


int main(int ag1, char* c[]) 
{
    int f[2];
    int size=50;
    pid_t pid;
    char readBuff[size];

    pipe(f);

    int fo = open(c[1], 0);
    int tf = open(c[2], O_CREAT|O_RDWR|O_APPEND, 0777);
    

    if (tf == -1 || fo == -1) 
    {
        printf("Not possible to append \n");
        exit(1);
    }
    pid  = fork();
    if (pid == 0) 
    {
        close(f[1]);
        while (read(f[0], readBuff, sizeof(readBuff)) > 0) 
        {
                write(tf, readBuff, strlen(readBuff) - 1);
        }
        close(f[0]);
      close(tf);
    }
    else 
    {
        close(f[0]);
        while (read(fo, readBuff, sizeof(readBuff)) > 0) 
        {
            write(f[1], readBuff, sizeof(readBuff));
            memset(readBuff, 0, size);
        }
        close(f[1]);
        close(fo);
        wait(NULL);
    }
}

                                                                                              
