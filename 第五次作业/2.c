#include <stdio.h>
#include <string.h>

int main()
{

    FILE *pFILEA = fopen("../A.txt","r");
    char strA[999],strB[999],*strC;

    if(pFILEA == NULL)
    {
        printf("不存在文件A");
        return 0;
    }

    FILE *pFILEB = fopen("../B.txt","r");
    if(pFILEB == NULL)
    {
        printf("不存在文件B");
        return 1;
    }

    FILE *pFILEC = fopen("C.txt","w");

    fscanf(pFILEA, "%s", strA);
    fscanf(pFILEB, "%s", strB);

    strC = strcat(strA, strB);

    fprintf(pFILEC, "%s", strC);

    fclose(pFILEA);
    fclose(pFILEB);
    fclose(pFILEC);

    return 0;
}