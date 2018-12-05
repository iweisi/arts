#ifndef bool
#define bool int
#endif

#include "solution.h"
#include <assert.h>

int main(int argc, char* argv[])
{
  assert(isMatch("abc", ".*") == 1);
  return 0;
}