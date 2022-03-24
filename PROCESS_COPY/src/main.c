#include"process_copy.h"



int main(int argc, char** argv)
{
  int pro_num;
  int block_size;
  if(argv[3]== NULL)
  {
    pro_num = 5;
  }
  else
  {
    pro_num = atoi(argv[3]);
  }

  check_pram(argc,argv[1],pro_num);

  block_size  =  block_cut(argv[1],pro_num);

  process_create(pro_num,argv[1],argv[2],block_size);

    return 0;
}
