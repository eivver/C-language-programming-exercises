#include <stdio.h>
int A[10];
int tmp;
int main()
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
        for(int j=i;j>0;j--)
            if(A[j-1]>A[j])
            {
                tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
            }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}