#include <stdio.h>
int year;
int main()
{
    scanf("%d",&year);
    //��ݷ�100�����ж��Ƿ�Ϊ4������100�����ж��Ƿ�Ϊ400����
    if((year%4 == 0 && year%100 !=0) || (year%400 == 0 && year%100 ==0 ))   
        printf("Yes");
    else
        printf("No");
    return 0;
}