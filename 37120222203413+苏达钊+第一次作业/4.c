#include <stdio.h>
int n;
int sum1 = 0;   //����֮��
int sum2 = 0;   //����֮��
int main()
{
    while(scanf("%d",&n) &&  n != 0)
    {   
        if(n > 0)
            sum1 += n;
        else    
            sum2 += n;
    }
    printf("����֮��:%d\n����֮��:%d\n",sum1,sum2);
    
    return 0;
}