#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
    char write_msg[BUFFER_SIZE] = "I am Here";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    int fd2[2];
    pid_t pid;
    /*create the pipe*/
    if(pipe(fd)==-1){
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    if(pipe(fd2)==-1)
    {
        fprintf(stderr, "Pipe failed");
    }
    /*fork a child process*/
    pid = fork();
    if(pid<0)
    {/*fork failed*/
        fprintf(stderr, "Fork failed");
        return 1;
    }
    if(pid>0){
        close(fd[READ_END]);
        write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
        close(fd[WRITE_END]);
        wait(NULL);
        close(fd2[WRITE_END]);
        read(fd2[READ_END], read_msg, BUFFER_SIZE);
        printf("parent receive:%s\n", read_msg);
        close(fd2[READ_END]);
    }
    else
    {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("child recieve:%s\n", read_msg);
        strcpy(read_msg, "i AM hERE");
        close(fd[READ_END]);
        close(fd2[READ_END]);
        write(fd2[WRITE_END], read_msg, strlen(read_msg)+1);
        close(fd2[WRITE_END]);
        return 0;
    }
    return 0;
}

// #include<sys/types.h>
// #include<stdio.h>
// #include<string.h>
// #include<unistd.h>
// #include<stdlib.h>

// #define BUFFER_SIZE 25
// #define READ_END 0
// #define WRITE_END 1

// int main()
// {
//     char write_msg[BUFFER_SIZE] = "I am Here";
//     char read_msg[BUFFER_SIZE]="silly";
//     printf("%p\n", read_msg);
//     int fd[2];
//     int fd2[2];
//     pid_t pid;
//     /*create the pipe*/
//     if(pipe(fd)==-1){
//         fprintf(stderr, "Pipe failed");
//         return 1;
//     }
//     if(pipe(fd2)==-1)
//     {
//         fprintf(stderr, "Pipe failed");
//     }
//     /*fork a child process*/
//     pid = fork();
//     if(pid<0)
//     {/*fork failed*/
//         fprintf(stderr, "Fork failed");
//         return 1;
//     }
//     if(pid>0){
//         close(fd[READ_END]);
//         write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
//         close(fd[WRITE_END]);
//         wait(NULL);
//         fflush(stdout);
//         printf("%p:", read_msg);
//         printf("%c\n", *read_msg);
//         fflush(stdout);
//         close(fd2[WRITE_END]);
//         read(fd2[READ_END], read_msg, BUFFER_SIZE);
//         printf("%p:parent receive:%s\n", read_msg,read_msg);
//         close(fd2[READ_END]);
//         printf("%s", write_msg);
//     }
//     else
//     {
//         close(fd[WRITE_END]);
//         read(fd[READ_END], read_msg, BUFFER_SIZE);
//         printf("child recieve:%s", read_msg);
//         strcpy(read_msg, "i AM hERE");
//         printf(":%p\n",read_msg);
//         close(fd[READ_END]);
//         close(fd2[READ_END]);
//         write(fd2[WRITE_END], read_msg, strlen(read_msg)+1);
//         printf("%s\n", read_msg);
//         fflush(stdout);
//         close(fd2[WRITE_END]);
//         return 0;
//     }
//     return 0;
// }

// #include<sys/types.h>
// #include<stdio.h>
// #include<string.h>
// #include<unistd.h>
// #include<stdlib.h>

// #define BUFFER_SIZE 25
// #define READ_END 0
// #define WRITE_END 1

// int main()
// {
//     char write_msg[BUFFER_SIZE] = "I am Here";
//     char* read_msg=(char*)malloc((sizeof(char))*BUFFER_SIZE);
//     strcpy(read_msg, "silly");
//     printf("%p:", read_msg);
//     printf("%s\n", read_msg);
//     int fd[2];
//     int fd2[2];
//     pid_t pid;
//     /*create the pipe*/
//     if(pipe(fd)==-1){
//         fprintf(stderr, "Pipe failed");
//         return 1;
//     }
//     if(pipe(fd2)==-1)
//     {
//         fprintf(stderr, "Pipe failed");
//     }
//     /*fork a child process*/
//     pid = fork();
//     if(pid<0)
//     {/*fork failed*/
//         fprintf(stderr, "Fork failed");
//         return 1;
//     }
//     if(pid>0){
//         close(fd[READ_END]);
//         write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
//         close(fd[WRITE_END]);
//         wait(NULL);
//         fflush(stdout);
//         printf("%p:", read_msg);
//         printf("%s\n", read_msg);
//         fflush(stdout);
//         close(fd2[WRITE_END]);
//         read(fd2[READ_END], read_msg, BUFFER_SIZE);
//         printf("%p:parent receive:%s\n", read_msg,read_msg);
//         close(fd2[READ_END]);
//         printf("%s", write_msg);
//     }
//     else
//     {
//         close(fd[WRITE_END]);
//         read(fd[READ_END], read_msg, BUFFER_SIZE);
//         printf("%p:child recieve:%s\n", read_msg,read_msg);
//         strcpy(read_msg, "i AM hERE");
//         printf("%p:", read_msg);
//         printf("%s\n", read_msg);
//         close(fd[READ_END]);
//         close(fd2[READ_END]);
//         write(fd2[WRITE_END], read_msg, strlen(read_msg)+1);
//         fflush(stdout);
//         close(fd2[WRITE_END]);
//         return 0;
//     }
//     return 0;
// }