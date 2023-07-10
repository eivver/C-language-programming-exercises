#include <stdio.h>

void ReverseOrder(int *vector, int n);
void Swap(int *x, int *y);

//功能: 倒序数组
//入口: vector为操作数组 n为数组长度
void ReverseOrder(int *vector, int n)
{
    for(int i=0;i<n/2;i++)
    {
        Swap(vector+i, vector+n-1-i);
    }
}

//功能: 交换x,y
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

    printf("请输入数组长度:");
    scanf("%d",&m);

    printf("请输入数组\n");
    for(int i=0;i<m;i++)
        scanf("%d",&num[i]);
    
    //倒序数组
    ReverseOrder(num,m);

    //输出
    printf("反转后的数组为:\n");
    for(int i=0;i<m;i++)
        printf("%d ",num[i]);

    return 0;
}