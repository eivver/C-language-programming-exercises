#include <stdio.h>
int n;      //��Ʊ����
int money;  //Ʊ��
int main()
{
    scanf("%d",&n);
    if(n >= 20)
        money = n * 15; //����Ʊ
    else 
        money = n * 25; //����Ʊ

    printf("%d",money);
    return 0;
}