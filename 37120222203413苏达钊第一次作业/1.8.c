#include <stdio.h>
int M,K;
int Monkey[10000]={0};  //����״̬��0��δ���У�1���ѳ���
int Monkey_Count = 0;   //ָ��ڼ�ֻ���ӣ���0��ʼ����Ϊ��һֻ������Ҫ����
int Cnt = 0;            //���к�����
int tmp_k;              //�ݴ�K
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
                Monkey_Count = 1;           //�ص���һֻ�����γɻ�
            if(Monkey[Monkey_Count]==0)     //����
            {
                tmp_k --;
            }
            if(tmp_k==0)                    //����
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