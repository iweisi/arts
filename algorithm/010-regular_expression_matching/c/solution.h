#define SINGLE_CHARACTER  1
#define MUTLI_CHARACTER   2
#define SIGNEL_ANY        3
#define MUTLI_ANY         4

bool isMatch(char* s, char* p) {
  while (*p && *s) {
    if (*p >= 'a' && *p <= 'z') {
      if (p[1] == '*') {
        // match 0 or N character
        while (*s && *s == *p) s++;
        char tmp = *p;
        p = p + 2;
        while (*p && *p == tmp) p++;
      } else {
        // match single character
        if (*s != *p) break;
        s++;
        p++;
      }
    } else if (*p == '.') {
      if (p[1] == '*') {
        // match 0 or N any character
        p = p + 2;
        while (*s && *s != *p) s++;
      } else {
        // match single any character
        s++;
        p++;
      }
    } else {
      break;
    }
  }

  return *s == '\0' && *p == '\0';
}