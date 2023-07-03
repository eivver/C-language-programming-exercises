#include <stdio.h>
#include <string.h>
char str[1000];
int len;
int flag=0;
int main()
{
    scanf("%s",str);
    len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(str[i]!=str[len-i-1])
            flag=1;
    }
    if(flag)
        printf("No");
    else 
        printf("Yes");
    return 0;
}