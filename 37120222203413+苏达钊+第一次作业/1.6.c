#include <stdio.h>
#include <math.h>
int n,x;
float ans=1;
int factorial(int n)
{
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1; i<=n; i++)
    {
        ans += pow(x,i)/factorial(i);
    }
    printf("%f",ans);
    return 0;
}