//�ó���ɽ�mes.txt�ڵı������û��趨����Կ�������ֽ������ܲ������XOR_mes.txt��

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char KEY[20];               //��Կ
char Text[9999];            //�ļ�����
int KeyLength,TextLength;

int main() 
{
    //���ļ�
    FILE* inputFile = fopen("../mes.txt", "rb");
    if(inputFile == NULL)
    {
        printf("�޷����ļ�\n");
        return 1;
    }

    FILE* outputFile = fopen("XOR_mes.txt", "wb");
    if(outputFile == NULL)
    {
        printf("�޷������ļ�\n");
        return 1;
    }

    //������Կ
    printf("��������Կ:\n");
    scanf("%s",KEY);
    KeyLength = strlen(KEY);
    
    // ���м���
    int bytesRead;
    int KeyIndex = 0;
    unsigned char buffer[1024];
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0)
    {
        // �Զ�ȡ�����ݽ��м���
        for (int i = 0; i < bytesRead; i++)
        {
            buffer[i] = buffer[i] ^ KEY[KeyIndex];
            KeyIndex = (KeyIndex + 1) % KeyLength;
        }

        // �����ܺ������д�����ļ�
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // �ر��ļ�
    fclose(inputFile);
    fclose(outputFile);

    printf("������ɣ�\n");
    return 0;
}
