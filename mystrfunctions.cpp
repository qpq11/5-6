#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include "mystrheader.h"

int main(){
	const char* s = "MEOW";
	const char* st = "WOOF";
	char a[40] = "q";
	int c = 'O';
	printf("%d\n", s[2] == c);
	printf("%s\n", MyStrchr(st, c));
	printf("%d\n", MyStrlen(s));
	printf("%s\n", MyStrcat(a, st));
	printf("%s\n", MyStrncat(a, s, 3));
	printf("%p %x\n", MyStrdup(s), MyStrdup(s));
	return 0;
}

void MyPuts(const char *str)
{
	printf("%s\n", str);
}

int MyStrlen (const char *str)  //prints without '\0'!
{
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}
	
char *MyStrchr(const char *str, int c)
{
	int i = 0;
	while ((str[i]) && (str[i] != c))
		i++;
	if (str[i] == c) 
		return (char*) str+i;
	return NULL;
}

char *MyStrcpy (char *s1, const char *s2)
{
	for(size_t i = 0; i < MyStrlen(s2); i++)
	{
		s1[i] = s2[i];
	}
	return s1;
}

char *MyStrncpy (char *s1, const char *s2, size_t n)
{
	for(size_t i = 0; i < n; i++)
	{
		if (i<MyStrlen(s2))
			s1[i] = s2[i];
		else
			s1[i] = '\0';
	}
	return s1;
}

char* MyStrcat (char* s1, const char *s2)
{
	char* ptr = s1;
	while (*ptr)
		ptr++;
	int i = 0;
	while (*(s2 + i))
	{
		*(ptr++) = *(s2 + i++);
	}
	*ptr = '\0';
	return s1;
}


char* MyStrncat (char* s1, const char *s2, size_t n)
{
	char* ptr = s1;
	while (*ptr)
		ptr++;
	int i = 0;
	while (i < n)
	{
		*(ptr++) = *(s2 + i++);
	}
	*ptr = '\0';
	return s1;
}

/*
char* MyFgets (char* str, size_t n, FILE * stream)
{
	FILE * fp;
	fp = fopen(stream, "r");
	int i = 0;
	int ch;
	
	while (((ch = fgetc(fp)) != '\n') && (ch != EOF) && (ch) && (i<n))
	{
		*(str + i++) = ch;
	}
	
	if (i < n)
	{
		*(str + i++) = '\n';
	}
	
	*(str + i) = '\0';
	
	if (ch == EOF)
		return NULL;
	
	return str;
	
}*/

char* MyStrdup (const char *src)
{
	char * ptr = (char *) malloc(sizeof(*src));
	return ptr;
}

