#include <stdio.h>
int n;
int sum1 = 0;   //正数之和
int sum2 = 0;   //负数之和
int main()
{
    while(scanf("%d",&n) &&  n != 0)
    {   
        if(n > 0)
            sum1 += n;
        else    
            sum2 += n;
    }
    printf("正数之和:%d\n负数之和:%d\n",sum1,sum2);
    
    return 0;
}