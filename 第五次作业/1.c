#include <stdio.h>
#include <string.h>

int main()
{

    FILE *pFILE = fopen("test.txt","w");
    char str[100];
    int len;


    printf("�������ַ�����!����\n");
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
    printf("ת������ѱ�����test.txt��!");
    fclose(pFILE);
    return 0;
}