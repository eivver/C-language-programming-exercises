#include <stdio.h>
#include <string.h>
//指针数组
char *week[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
char str[1000];
int ans;
int main()
{
    printf("请输入一个字符串,STOP表示停止输入\n");
    while(1)
    {
        ans=-1;
        scanf("%s",str);
        if(strcmp(str,"STOP")==0)
            break;
        for(int i=0;i<7;i++)
        {
            if(strcmp(str,*(week+i))==0)
                ans=i+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}