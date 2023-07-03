#include <stdio.h>
/*********
90~100  A
80~89   B
70~79   C
60~69   D
0~59    F
**********/
int score;
int main()
{
    scanf("%d",&score);
    switch (score/10)
    {
    case 10:
    case 9:
        printf("A");
        break;
    case 8:
        printf("B");
        break;
    case 7:
        printf("C");
        break;
    case 6:
        printf("D");
        break;
    default:
        printf("F");
        break;
    }
    return 0;
}