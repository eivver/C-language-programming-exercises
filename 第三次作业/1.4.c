#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[50];         //城市名
    int population;         //人口
    float civilization;     //文明度
} census;

census city[5];

void Swap(census *x, census *y);
void CitySort(census *p, int n, int mod);

//功能:排序,mod表示排序关键字 1:按城市名 2:按城市人口数 3:按城市文明度
//入口:p城市结构体 n城市数量 mod排序关键字
void CitySort(census *p, int n, int mod)
{
    if(mod == 1)
    {
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(strcmp((p+i)->name,(p+j)->name)>0)
                    Swap(p+i,p+j);
    }
    if(mod == 2)
    {
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if((p+i)->population < (p+j)->population)
                    Swap(p+i,p+j);
    }
    if(mod == 3)
    {
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if((p+i)->civilization < (p+j)->civilization)
                    Swap(p+i,p+j);
    }
}

//功能: 交换x,y
void Swap(census *x, census *y)
{
    census tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}


int main()
{
    printf("请输入5个城市的城市名,城市人口,城市文明度\n");
    for(int i=0;i<5;i++)
    {
        printf("请输入第%d个城市信息",i+1);
        scanf("%s%d%f%%",city[i].name,&city[i].population,&city[i].civilization);
    }
    
    CitySort(city,5,1);
    printf("根据城市名排序顺序如下:\n");
    for(int i=0;i<5;i++)
    {
        printf("%s %d %f\n",city[i].name,city[i].population,city[i].civilization);
    }

    CitySort(city,5,2);
    printf("根据城市人口数排序顺序如下:\n");
    for(int i=0;i<5;i++)
    {
        printf("%s %d %f\n",city[i].name,city[i].population,city[i].civilization);
    }

    CitySort(city,5,3);
    printf("根据城市文明度排序顺序如下:\n");
    for(int i=0;i<5;i++)
    {
        printf("%s %d %f\n",city[i].name,city[i].population,city[i].civilization);
    }

    return 0;
}

/*测试样例
aaaa 20102 70%
abcd 78372 80%
abds 27489 76%
sccs 75892 90%
asfv 83572 99%
*/