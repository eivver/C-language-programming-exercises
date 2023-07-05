#include <stdio.h>
#include <string.h>
char str[100][100];
int len;
int k=0;
int main()
{
    printf("请输入句子以.结束\n");
    while(scanf("%s",*(str+k)))
    {
        len = strlen(*(str+k));
        if(*(*(str+k))>='A'&&*(*(str+k))<='Z')
            for(int i=0;i<len;i++)
            {
                if(*(*(str+k)+i)>='a'&&*(*(str+k)+i)<='z')
                    *(*(str+k)+i)+=('A'-'a');
            }

        if(*(*(str+k))>='a'&&*(*(str+k))<='z')
            for(int i=0;i<len;i++)
            {
                if(*(*(str+k)+i)>='A'&&*(*(str+k)+i)<='Z')
                    *(*(str+k)+i)-=('A'-'a');
            }

        printf("%s ",*(str+k));
        if(*(*(str+k)+len-1)=='.')
            break;
        k++;
    }
    return 0;
}