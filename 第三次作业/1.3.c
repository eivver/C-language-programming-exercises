#include <stdio.h>
#include <math.h>

//功能: 求数值型二维数组的上三角各元素的平方根的和
//入口: matrix二维数组 n数组大小
int UpperTriangleSquareSum(int *matrix, int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++)
            sum+=pow(matrix[i*n+j],2);
    
    return sum;
}
int main()
{
    int A[5][5]={{15,45,56,73,11},
                 {34,74,85,54,70},
                 {56,98,56,89,67},
                 {98,54,83,12,59},
                 {77,87,74,48,33}};

    int ans = UpperTriangleSquareSum(*A,5);

    printf("%d",ans);

    return 0;
}