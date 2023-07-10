#include <stdio.h>

//判断是否为回文数(1:是 0:否 -1:非法整数)
int palindrome(int n)
{
    //取绝对值
    if(n<0)
        n=-n;

    //判断n是否合法
    if(n<10000||n>99999)
        return -1;

    //逆序存储n的各个位数
    int num[5];
    for(int i=0;i<5;i++)
    {
        *(num+i)=n%10;
        n/=10;
    }

    //判断是否为回文数
    if(*num==*(num+4)&&*(num+1)==*(num+3))
        return 1;
    else
        return 0;
}
int main()
{
    int cnt;//回文数个数

    //遍历所有五位数
    for(int i=10000;i<=99999;i++)
        if(palindrome(i)==1)
            cnt++;

    printf("%d",cnt);
    return 0;
}