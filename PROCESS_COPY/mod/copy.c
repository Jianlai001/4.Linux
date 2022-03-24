#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char** argv)
{
  int sfd;
  int dfd;
  int pos = atoi(argv[3]);
  int block_size = atoi(argv[4]);
  int read_len;
  char buffer[block_size];
  bzero(buffer,sizeof(buffer));

 sfd = open(argv[1],O_RDONLY);
 dfd = open(argv[2],O_RDWR|O_CREAT,0666);

 lseek(sfd,pos,SEEK_SET);
 lseek(dfd,pos,SEEK_SET);

  read_len = read(sfd,buffer,sizeof(buffer));
  write(dfd,buffer,read_len);

  close(sfd);
  close(dfd);


  printf("chile %d cpoy success. copy_pos: %d copy_size: %d \n",getpid(),pos,block_size);

  return 0;
}
