#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
    int count=0;
    int N=atoi(argv[1]);
    pid_t pid;
    while (1)
    {
        pid = fork();
        count++;
        
        /*fork child process*/
        if (pid == 0)
        {
            if (N % 2 == 0)
            {
                printf("%d ", N);
                fflush(stdout);
                N = N / 2;
            }
            else if (N % 2 != 0)
            {
                if (N == 1)
                {
                    printf("%d ", N);
					fflush(stdout);
                    break;
                }
                else
                {
                    printf("%d ", N);
                    fflush(stdout);
                    N = 3 * N + 1;
                }
            }
        }
        else if (pid > 0)
        {
            wait(NULL);
			fflush(stdout);
            break;
        }
        else
        {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
    }
    return 0;
}