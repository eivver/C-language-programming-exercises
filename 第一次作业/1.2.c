#include <stdio.h>
int year;
int main()
{
    scanf("%d",&year);
    //年份非100倍数判断是否为4倍数，100倍数判断是否为400倍数
    if((year%4 == 0 && year%100 !=0) || (year%400 == 0 && year%100 ==0 ))   
        printf("Yes");
    else
        printf("No");
    return 0;
}