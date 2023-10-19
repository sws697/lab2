#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>

#include<sys/mman.h>
#include<unistd.h>
#include<math.h>
/*gcc homework2.c -o homework2 -lm*/
int main(int argc,char* argv[])
{
    /*name of the shared memory object*/
    const char *name = "OS";
    const int SIZE = 4096;
    /*pointer to shared memory object*/
    char *ptr;
    int N = atoi(argv[1]);
    /*shared memory file descriptor*/
    int fd;
    /*create the shared memory object*/
    fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    /*configure the size of the shared memory object*/
    ftruncate(fd, SIZE);
    
    /*memory map the shared memory object*/
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    pid_t pid;
    pid = fork();
    if(pid==0){
        while(N!=1)
        {
            sprintf(ptr, "%d ", N);
            ptr += ((int)(log10(N))+2);
            if (N % 2 == 0)
            {
                N = N / 2;
            }
            else if (N % 2 != 0)
            {
                N = 3 * N + 1;
            }
        }
        sprintf(ptr, "%d", N);
        ptr += 1;
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("%s", (char *)ptr);
        shm_unlink(name);
    }
    else
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    return 0;
}