#include <stdio.h>
#include <string.h>

void Sort(int *Array,int n)
{
    int tmp;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(*(Array+i)>*(Array+j))
            {
                tmp = *(Array+i);
                *(Array+i) = *(Array+j);
                *(Array+j) = tmp;
            }
        }
}
int a[100][100];
int M,N;
int main()
{
    printf("������M:");
    scanf("%d",&M);
    printf("������N:");
    scanf("%d",&N);
    printf("����������a:");
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            scanf("%d",*(a+i)+j);

    for(int i=0;i<N;i++)
    {
        Sort(*(a+i),N);
    }

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            printf("%d ",*(*(a+i)+j));
        printf("\n");
    }
       
    return 0;
}