#include <stdio.h>
int A1[5][6]={{0,0,2,0,5,0},
              {0,1,0,9,0,0},
              {0,0,0,0,0,20},
              {11,0,0,0,0,0},
              {0,0,8,0,0,0}};
int B1[100][3];
int A2[100][100]={0};
int B2[4][3]={{5,2,9},
              {3,6,8},
              {1,4,6},
              {2,3,7}};
int cnt=0;
int main()
{
    //A1->B1
    for(int i=0;i<5;i++)
        for(int j=0;j<6;j++)
        {
            if(A1[i][j]!=0)
            {
                B1[cnt][0]=i+1;
                B1[cnt][1]=j+1;
                B1[cnt][2]=A1[i][j];
                cnt++;
            }
        }
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",B1[i][j]);
        }
        printf("\n");
    }
    //B2->A2
    for(int i=0;i<4;i++)
        A2[B2[i][0]-1][B2[i][1]-1] = B2[i][2];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("%d ",A2[i][j]);
        }
        printf("\n");
    }    

    return 0;
}