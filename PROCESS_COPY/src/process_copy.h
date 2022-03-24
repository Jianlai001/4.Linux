#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

void zombie_wait();
void str_err(const char* str_err,int err_code);
int process_create(int pro_num,const char* src_file,const char* des_file,int block_size);
int check_pram(int argv,const char* src_file,int pro_num);
int block_cut(const char* src_file,int pro_num);
