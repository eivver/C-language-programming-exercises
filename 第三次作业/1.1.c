#include <stdio.h>

//�ж��Ƿ�Ϊ������(1:�� 0:�� -1:�Ƿ�����)
int palindrome(int n)
{
    //ȡ����ֵ
    if(n<0)
        n=-n;

    //�ж�n�Ƿ�Ϸ�
    if(n<10000||n>99999)
        return -1;

    //����洢n�ĸ���λ��
    int num[5];
    for(int i=0;i<5;i++)
    {
        *(num+i)=n%10;
        n/=10;
    }

    //�ж��Ƿ�Ϊ������
    if(*num==*(num+4)&&*(num+1)==*(num+3))
        return 1;
    else
        return 0;
}
int main()
{
    int cnt;//����������

    //����������λ��
    for(int i=10000;i<=99999;i++)
        if(palindrome(i)==1)
            cnt++;

    printf("%d",cnt);
    return 0;
}