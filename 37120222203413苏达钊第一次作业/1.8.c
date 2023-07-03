#include <stdio.h>
int M,K;
int Monkey[10000]={0};  //猴子状态，0：未出列，1：已出列
int Monkey_Count = 0;   //指向第几只猴子，从0开始是因为第一只猴子需要报数
int Cnt = 0;            //出列猴子数
int tmp_k;              //暂存K
int main()
{
    scanf("%d%d",&M,&K);

    while(M - Cnt > 1)  
    {
        tmp_k = K;
        while(tmp_k > 0)
        {
            Monkey_Count++;
            if(Monkey_Count > M)
                Monkey_Count = 1;           //回到第一只猴子形成环
            if(Monkey[Monkey_Count]==0)     //报数
            {
                tmp_k --;
            }
            if(tmp_k==0)                    //出列
            {
                Monkey[Monkey_Count]=1;
                Cnt++;
            }
        }
    }
    for(int i=1;i<=M;i++)
    {
        if(Monkey[i]==0)
            printf("%d",i);
    }
    return 0;
}