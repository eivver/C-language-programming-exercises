//�ó���ɽ�mes.txt�ڵı������û��趨����Կ������λ���ܲ������encrypt_mes.txt��

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char KEY[20];               //��Կ
char Text[9999];            //�ļ�����
char Text_encrypt[9999];    //���ܺ��ļ�����
int KeyLength,TextLength;

int main() 
{
    //���ļ�
    FILE* inputFile = fopen("../mes.txt", "r");
    if(inputFile == NULL)
    {
        printf("�޷����ļ�\n");
        return 1;
    }
    fgets(Text, 9999, inputFile);

    FILE* outputFile = fopen("encrypt_mes.txt", "w");
    if(outputFile == NULL)
    {
        printf("�޷������ļ�\n");
        return 1;
    }

    //������Կ
    printf("��������Կ:\n");
    scanf("%s",KEY);
    KeyLength = strlen(KEY);
    TextLength = strlen(Text);
    //printf("%d %d ",KeyLength,TextLength);
    if(TextLength % KeyLength)
    {
        printf("��Կ�������ı����Ȳ�ƥ��,�ı�����Ϊ:%d\n",TextLength);
        printf("�뱣֤��Կ�����ܱ��ı���������\n");
        printf("����ʧ�ܣ�\n");
        return 0;
    } 
    
    // ���м���
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

    // �ر��ļ�
    fclose(inputFile);
    fclose(outputFile);

    printf("������ɣ�\n");
    return 0;
}
