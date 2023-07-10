#include <stdio.h>

void ReverseOrder(int *vector, int n);
void Swap(int *x, int *y);

//����: ��������
//���: vectorΪ�������� nΪ���鳤��
void ReverseOrder(int *vector, int n)
{
    for(int i=0;i<n/2;i++)
    {
        Swap(vector+i, vector+n-1-i);
    }
}

//����: ����x,y
void Swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int m,num[1000];

    printf("���������鳤��:");
    scanf("%d",&m);

    printf("����������\n");
    for(int i=0;i<m;i++)
        scanf("%d",&num[i]);
    
    //��������
    ReverseOrder(num,m);

    //���
    printf("��ת�������Ϊ:\n");
    for(int i=0;i<m;i++)
        printf("%d ",num[i]);

    return 0;
}