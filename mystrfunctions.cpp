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
	printf("%s\n", MyStrncpy(a, st, 2));
	char* p = MyStrdup(s);
	printf("%s %x\n", p, p);
	printf("%s\n", MyFgets(a, 3, stdin));
	free(p);
	ClearBuffer();
	char* t;
	MyGetline(t, 5, '\n');
	printf("%s", t);
	return 0;
}

int MyPuts(const char *str)
{
	if (!str)
		return EOF;
	printf("%s\n", str);
	return 1;
}

size_t MyStrlen (const char *str)  //prints without '\0'!
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
	size_t ln = MyStrlen(s2);
	size_t i = 0;
	while(i < ln)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
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


char* MyFgets (char* str, size_t n, FILE * stream)
{
	int i = 0;
	int ch;
	
	while (((ch = fgetc(stream)) != '\n') && (ch != EOF) && (ch) && (i < n))
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
	
}

char* MyStrdup (const char *src)
{
	char * ptr;
	ptr = (char*) malloc(sizeof(char) * (MyStrlen(src) + 1));
	MyStrcpy(ptr, src);
	return ptr;
}

void MyGetline(char* str, int strsize, char sep)
{
	int i = 0;
	int ch;
	while (((ch = fgetc(stdin)) != sep) && (i < strsize))
	{
		*(str + i++) = ch;
	}
	*(str + i) = '\0';
	return;
}

void ClearBuffer(void)
{
	int ch;
	while(((ch = getchar()) != '\n') && (ch != EOF)){
		continue;
	}
}