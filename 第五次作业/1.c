#include <stdio.h>
#include <string.h>

int main()
{

    FILE *pFILE = fopen("test.txt","w");
    char str[100];
    int len;


    printf("请输入字符串以!结束\n");
    scanf("%s",str);
    len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] += 'A'-'a';
        }
    }
    fprintf(pFILE, "%s", str);
    printf("转化结果已保存至test.txt中!");
    fclose(pFILE);
    return 0;
}