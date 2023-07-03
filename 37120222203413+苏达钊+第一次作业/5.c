#include <stdio.h>
int cnt = 0;    //一行数字个数
int main()
{
    for(int i=1; i<=200; i++)
    {
        if(i%3)
        {
            printf("%d ",i);
            cnt++;
        }
        if(cnt >= 10)
        {
            printf("\n");
            cnt = 0;
        }
    }
    return 0;
}