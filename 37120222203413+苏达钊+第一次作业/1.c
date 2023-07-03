#include <stdio.h>
int n;      //购票数量
int money;  //票款
int main()
{
    scanf("%d",&n);
    if(n >= 20)
        money = n * 15; //团体票
    else 
        money = n * 25; //零售票

    printf("%d",money);
    return 0;
}