#include <stdio.h>
#include <string.h>
char str1[100][100],str2[100][100];
char *p = NULL;                         //ָ����ĵ���
int MaxLength = 0;
int len;
int l1 = 0, l2 = 0;
int main()
{
    printf("�������һ���ַ���:");
    while(scanf(" %s",*(str1+(++l1)))&& **(str1+l1)!='.');
    printf("������ڶ����ַ���:");
    while(scanf(" %s",*(str2+(++l2)))&& **(str2+l2)!='.');
    for(int i=0;i<l1;i++)
        for(int j=0;j<l2;j++)
        {
            if(strcmp(*(str1+i),*(str2+j))==0)
            {
                len = strlen(*(str1+i));
                if(len > MaxLength)
                {
                    MaxLength = len;
                    p = *(str1+i);
                }
            }
        }
    printf("%s",p);
    return 0;
}