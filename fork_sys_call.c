/*
 *  Aim:
 *    Create a child process in a POSIX OS using the fork system call. From the child process obtain the process ID of both child and parent by using
 *    getpid and getppid system call.
 *
 *  Description: 
 *    fork()    :    fork() creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling 
 *                   process is referred to as the parent process.
 *    getpid()  :    getpid() returns the process ID (PID) of the calling process.
 *    getppid() :    getppid() returns the process ID of the parent of the calling process. This will be either the ID of the process that created this
 *                   process using fork(), or, if that process has already terminated, the ID of the process to which this process has been reparented.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    pid = fork();                               /* fork a child process */

    if (pid == 0) {                             /* child process */
        printf("parent process id: %d\n", getppid());
        printf("(child)process id: %d\n", getpid());
        sleep(1);
    } else if (pid > 0) {                       /* parent process */
        int wstatus;
        wait(&wstatus);                         /* parent waits for the child to terminate */
        printf("Child process exited with status: %d\n", WEXITSTATUS(wstatus));
    } else {                                    /* error occurred */
        perror("Fork Failed\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
