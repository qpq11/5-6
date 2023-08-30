#include <stddef.h>
#include <stdio.h>
void MyPuts(const char * str);

char *MyStrchr(const char * str, int c);

int MyStrlen (const char * str);

char *MyStrcpy (char * s1, const char * s2);

char *MyStrncpy (char * s1, const char * s2, size_t n);

char * MyStrcat (char* sl, const char* s2);

char * MyStrncat (char * sl, const char * s2, size_t n);

//char* MyFgets (char * str, size_t n, FILE *stream);

char* MyStrdup (const char *src);