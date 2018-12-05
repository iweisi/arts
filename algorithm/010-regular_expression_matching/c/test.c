#ifndef bool
#define bool int
#endif

#include "solution.h"
#include <assert.h>

int main(int argc, char* argv[])
{
  assert(!isMatch("ab", ".*c"));
  assert(isMatch("aaa", "ab*a*c*a"));
  assert(isMatch("aabaadddqq", ".*d..q*"));
  return 0;
}