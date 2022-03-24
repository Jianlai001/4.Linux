#include"process_copy.h"

int block_cut(const char* src_file,int pro_num)
{
	int file_size;
	int fd;


	if((fd = open(src_file,O_RDONLY)) == -1)
	{
		str_err("block_cut >> open call failed\n",-1);
	}
  // 获得文件大小
	if((file_size = lseek(fd,0,SEEK_END))== -1)
	{
		str_err("block_cut >> lseek call failed\n",-1);
	}
	close(fd);


  //返回切片大小
	if(file_size % pro_num == 0)
	{
		return file_size/pro_num;
	}
	else
	{
		return file_size/pro_num + 1;
  }
  printf("block_cut call success\n");
}
