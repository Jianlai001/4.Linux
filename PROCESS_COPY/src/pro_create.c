#include"process_copy.h"

int process_create(int pro_num,const char* src_file,const char* des_file,int block_size)
{
  pid_t pid;
  int i =0 ;
  int pos = 0;

  char str_pos[10];
  char str_block_size[10];
  //循环创建子进程
  for(i = 0; i <pro_num; i++)
  {
    pid = fork();
    if( pid == 0)
    {
      break;
    }
  }

  //区分父子进程工作内容
  if(pid > 0)
  {
    printf("fork call success\n");
    printf("Parent %d call zombie_wait....\n",getpid());
    zombie_wait();
  }
  else if(pid == 0)
  {
    //重载拷贝程序 
    pos = i*block_size;
    sprintf(str_pos,"%d",pos);
    sprintf(str_block_size,"%d",block_size);
    execl("/home/jianlai/桌面/process/mod/copy","copy",src_file,des_file,str_pos,str_block_size,NULL);
  }
  else
  {
    str_err("process_create >> fork call failed",-1);
  }


  return 0;
}
