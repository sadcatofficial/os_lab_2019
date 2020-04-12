#include "revert_string.h"
#include <stdio.h>
void RevertString(char *str)
{
int i;
char reverse[strlen(str)];
for (i=0;i<strlen(str);i++)
reverse[i]=str[strlen(str)-i-1];
reverse[strlen(str)] = '\0';
for (i=0;i<strlen(str);i++)
str[i] = reverse[i] ;

}

