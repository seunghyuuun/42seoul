//#include "pipe.h"
#include <unistd.h>

void piping(char ***cmd, char **cmdpath, char **envp, int inout[2], int i)
{
    int fd[2];
    pid_t pid;

    if (!cmd[i + 1] || !cmdpath[i + 1])
    {
        dup2(inout[0], 0);
        dup2(inout[1], 1);
        execve(cmdpath[i], cmd[i], envp);
        return ;
    }
    pipe(fd);
    pid = fork();
    if (!pid)
    {
        inout[0] = fd[0];
        close(fd[1]);
        piping(cmd, cmdpath, envp, inout, i + 1);
    }
    dup2(inout[0], 0);
    dup2(fd[1], 1);
    close(fd[0]);
    execve(cmdpath[i], cmd[i], envp);
}