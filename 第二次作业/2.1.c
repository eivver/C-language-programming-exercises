#include <stdio.h>
#include <string.h>

int chrn(char *s,char c)
{
    int cnt=0;
    int len = strlen(s);

    for(int i=0;i<len;i++)
        if(*(s+i)==c)
            cnt++;

    return cnt;
}
char str[100];
char ch;
int ans;
int main()
{
    printf("请输入一个字符串:\n");
    scanf("%s",str);
    printf("请输入一个字符:\n");
    scanf(" %c",&ch);
    ans = chrn(str,ch);
    printf("%d",ans);
    return 0;
}