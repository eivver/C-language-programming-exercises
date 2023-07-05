#include <stdio.h>
#include <string.h>
void sort(char (*s)[6])
{
    char tmp[6];
    for(int i=0;i<9;i++)
        for(int j=i+1;j<10;j++)
        {
            if(strcmp(*(s+i),*(s+j)) > 0)
            {
                strcpy(tmp,*(s+i));
                strcpy(*(s+i),*(s+j));
                strcpy(*(s+j),tmp);
            }
        }
}

char str[10][6];
int main()
{
    for(int i=0;i<10;i++)
    {
        printf("ÊäÈë×Ö·û´®%d:",i+1);
        scanf("%s",*(str+i));
    }
    sort(str);
    printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("×Ö·û´®%d:%s\n",i+1,*(str+i));
    }
    return 0;
}