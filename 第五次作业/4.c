//该程序可将mes.txt内的本文以用户设定的密钥进行逐字节异或加密并输出至XOR_mes.txt中

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char KEY[20];               //密钥
char Text[9999];            //文件内容
int KeyLength,TextLength;

int main() 
{
    //打开文件
    FILE* inputFile = fopen("../mes.txt", "rb");
    if(inputFile == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }

    FILE* outputFile = fopen("XOR_mes.txt", "wb");
    if(outputFile == NULL)
    {
        printf("无法创建文件\n");
        return 1;
    }

    //输入密钥
    printf("请输入密钥:\n");
    scanf("%s",KEY);
    KeyLength = strlen(KEY);
    
    // 进行加密
    int bytesRead;
    int KeyIndex = 0;
    unsigned char buffer[1024];
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0)
    {
        // 对读取的数据进行加密
        for (int i = 0; i < bytesRead; i++)
        {
            buffer[i] = buffer[i] ^ KEY[KeyIndex];
            KeyIndex = (KeyIndex + 1) % KeyLength;
        }

        // 将加密后的数据写入新文件
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // 关闭文件
    fclose(inputFile);
    fclose(outputFile);

    printf("加密完成！\n");
    return 0;
}
