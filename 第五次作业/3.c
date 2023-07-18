//该程序可将mes.txt内的本文以用户设定的密钥进行移位加密并输出至encrypt_mes.txt中

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char KEY[20];               //密钥
char Text[9999];            //文件内容
char Text_encrypt[9999];    //加密后文件内容
int KeyLength,TextLength;

int main() 
{
    //打开文件
    FILE* inputFile = fopen("../mes.txt", "r");
    if(inputFile == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }
    fgets(Text, 9999, inputFile);

    FILE* outputFile = fopen("encrypt_mes.txt", "w");
    if(outputFile == NULL)
    {
        printf("无法创建文件\n");
        return 1;
    }

    //输入密钥
    printf("请输入密钥:\n");
    scanf("%s",KEY);
    KeyLength = strlen(KEY);
    TextLength = strlen(Text);
    //printf("%d %d ",KeyLength,TextLength);
    if(TextLength % KeyLength)
    {
        printf("密钥长度与文本长度不匹配,文本长度为:%d\n",TextLength);
        printf("请保证密钥长度能被文本长度整除\n");
        printf("加密失败！\n");
        return 0;
    } 
    
    // 进行加密
    int cnt = 0;
    while(cnt * KeyLength <= TextLength)
    {
        for(int i=0; i<KeyLength; i++)
        {
            Text_encrypt[cnt * KeyLength + (KEY[i] - '1') ] = Text[cnt * KeyLength + i];
        }
        cnt++;
    }

    fputs(Text_encrypt,outputFile);

    // 关闭文件
    fclose(inputFile);
    fclose(outputFile);

    printf("加密完成！\n");
    return 0;
}
