#include"process_copy.h"

void zombie_wait()
{
  int status;
  pid_t pid;
  while((pid =  waitpid(-1,&status,WNOHANG)) != -1 )
  {
    if(pid > 0)//如果回收僵尸进程成功
    {

     if(WIFEXITED(status))
     {
      printf("chile %d exit success, exitcode is %d\n",pid,  WEXITSTATUS(status));
     }
     if(WIFSIGNALED(status))
     {
      printf("chile %d was killed by  SIG: %d\n",pid, WTERMSIG(status));
     }
    }
  }
  printf("all chile wait success\n");

}
