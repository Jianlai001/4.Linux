#include"process_copy.h"

int check_pram(int argc,const char* src_file,int pro_num)
{
  if(argc < 3)
  {
    str_err("Param error:missing required param...\n",-1);
  }
  if( access(src_file,F_OK) != 0)
  {
    str_err("Param error:file does not exist...\n",-1);
  }
  if( pro_num <=0 || pro_num >100)
  {
    str_err("Param error:the number of process cant be less than 0 or greater than 100...\n",-1);
  }

  printf("check_pram call success\n");
  return 0;
}
