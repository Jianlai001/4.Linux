#include"process_copy.h"

void str_err(const char* str_err,int err_code)
{
  perror(str_err);
  exit(err_code);
}
