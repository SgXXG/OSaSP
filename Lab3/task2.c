#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <wait.h>
#include <stdlib.h>

int main(){

    pid_t pid;

    printf("Parent process: %i\n", getpid());
    printf("PID\tPPID\tTime\n");

    struct timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);
                time_t sec = ts.tv_sec;
                int ms = ts.tv_nsec / 1e6;

                struct tm *tmp = localtime(&sec);
    printf("%i\t%i\t%i:%i:%i:%i\n", 
                       getpid(), getppid(), tmp->tm_hour,
                        tmp->tm_min, tmp->tm_sec, ms);
    
    printf("Child processes:\n");
    printf("PID\tPPID\tTime\n");
    for (size_t i = 0; i < 2; i++)
    {
        switch(pid = fork()){
            case 0:{    // child
                struct timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);
                time_t sec = ts.tv_sec;
                int ms = ts.tv_nsec / 1e6;

                struct tm *tmp = localtime(&sec);
                printf("%i\t%i\t%i:%i:%i:%i\n", 
                       getpid(), getppid(), tmp->tm_hour,
                        tmp->tm_min, tmp->tm_sec, ms);
                
                _exit(0);
            }
            case -1:{   // error
                fprintf(stderr, "Error while creating child process.\n");
                _exit(errno);
            }
            default:{   // parent
                break;
            }
        }   
    }

    if(pid > 0){
        system("ps -x");

        while(wait(NULL) != -1);
    }

    return 0;
}