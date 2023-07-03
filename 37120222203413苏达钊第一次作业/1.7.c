#include <stdio.h>
int n=1;
int main()
{
    for(int i=1;i<=9;i++)
    {
        n+=1;
        n*=2;
    }
    printf("%d",n);
    return 0;
}