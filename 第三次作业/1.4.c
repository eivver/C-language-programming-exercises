#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[50];         //������
    int population;         //�˿�
    float civilization;     //������
} census;

census city[5];

void Swap(census *x, census *y);
void CitySort(census *p, int n, int mod);

//����:����,mod��ʾ����ؼ��� 1:�������� 2:�������˿��� 3:������������
//���:p���нṹ�� n�������� mod����ؼ���
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

//����: ����x,y
void Swap(census *x, census *y)
{
    census tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}


int main()
{
    printf("������5�����еĳ�����,�����˿�,����������\n");
    for(int i=0;i<5;i++)
    {
        printf("�������%d��������Ϣ",i+1);
        scanf("%s%d%f%%",city[i].name,&city[i].population,&city[i].civilization);
    }
    
    CitySort(city,5,1);
    printf("���ݳ���������˳������:\n");
    for(int i=0;i<5;i++)
    {
        printf("%s %d %f\n",city[i].name,city[i].population,city[i].civilization);
    }

    CitySort(city,5,2);
    printf("���ݳ����˿�������˳������:\n");
    for(int i=0;i<5;i++)
    {
        printf("%s %d %f\n",city[i].name,city[i].population,city[i].civilization);
    }

    CitySort(city,5,3);
    printf("���ݳ�������������˳������:\n");
    for(int i=0;i<5;i++)
    {
        printf("%s %d %f\n",city[i].name,city[i].population,city[i].civilization);
    }

    return 0;
}

/*��������
aaaa 20102 70%
abcd 78372 80%
abds 27489 76%
sccs 75892 90%
asfv 83572 99%
*/