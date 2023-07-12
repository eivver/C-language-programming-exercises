#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    //������
    char name[50];                    //����
    char gender[10];                  //�Ա�
    float programming_score;          //����������Գɼ�
    //ָ����
    struct Student *pNext;            
}NODE,*PNODE;

//����һ������
PNODE creat_list(void)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("error!");
    }
    return pHead;
}

//����:���һ���µ�ѧ��
PNODE add_student(PNODE pTail)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        printf("error!");
    }

    printf("������ѧ������: ");
    fgets(pNew->name, sizeof(pNew->name), stdin);
    strtok(pNew->name, "\n"); // �Ƴ������ַ����еĻ��з�
    
    printf("������ѧ���Ա�: ");
    fgets(pNew->gender, sizeof(pNew->gender), stdin);
    strtok(pNew->gender, "\n"); // �Ƴ��Ա��ַ����еĻ��з�

    printf("������ѧ���������ѵ���ɼ�: ");
    scanf("%f", &pNew->programming_score);

    pTail->pNext = pNew;
    pNew->pNext = NULL;

    return pNew;
}

//����:ɾ��ѧ����Ϣ
void delete_student(PNODE pHead)
{
    char delete_student_name[50];

    printf("������Ҫɾ����ѧ������: ");
    fgets(delete_student_name, sizeof(delete_student_name), stdin);
    strtok(delete_student_name, "\n"); // �Ƴ������ַ����еĻ��з�

    int found = 0;
    char operate[5];
    for(PNODE p = pHead; p->pNext !=NULL; p = p->pNext)
    {
        if (strcmp(delete_student_name, p->pNext->name) == 0)
        {
            found = 1;
            printf("��ȷ���Ƿ�ɾ��[Yes/No]");
            fgets(operate, sizeof(operate), stdin);
            strtok(operate, "\n"); // �Ƴ������ַ����еĻ��з�

            if (strcmp(operate, "Yes") == 0)
            {
                PNODE tmp = p->pNext;
                p->pNext = p->pNext->pNext;
                free(tmp);
                printf("�ɹ�ɾ����ѧ����Ϣ!\n");
            }
            
            break;
        }
    }
    
    if (!found) 
    {
        printf("δ�ҵ�ƥ���ѧ����\n");
    }
}

//����:��ʾ����ѧ����Ϣ
void display_student(PNODE pHead)
{
    int i=0;
    for(PNODE p = pHead->pNext; p !=NULL; p = p->pNext)
    {
        i++;
        printf("��%d��ѧ����Ϣ: \n", i);
        printf("����: %s\n", p->name);
        printf("�Ա�: %s\n", p->gender);
        printf("�������ѵ���ɼ�: %.2f\n", p->programming_score);
        printf("\n");
    }
}

//����:�Գɼ���������
void score_sort(PNODE pHead)
{
    for(PNODE p = pHead->pNext; p !=NULL; p = p->pNext)
        for(PNODE q = p->pNext; q != NULL; q = q->pNext)
        {
            if(p->programming_score < q->programming_score)
            {
                int tmp_score;
                tmp_score = p->programming_score;
                p->programming_score = q->programming_score;
                q->programming_score = tmp_score;

                char tmp_name[50];
                strcpy(tmp_name, p->name);
                strcpy(p->name,q->name);
                strcpy(q->name,tmp_name);

                char tmp_gender[10];
                strcpy(tmp_gender, p->gender);
                strcpy(p->gender,q->gender);
                strcpy(q->gender,tmp_gender);
            }
        }

    printf("�����˳������:\n");
    display_student(pHead);
}

//����:�޸�ѧ����Ϣ
void modify_student(PNODE pHead) 
{
    if (pHead->pNext == NULL) 
    {
        printf("û��ѧ�����Ͽ��޸ģ�\n");
        return;
    }
    
    char search_name[50];
    printf("������Ҫ�޸ĵ�ѧ������: ");
    fgets(search_name, sizeof(search_name), stdin);
    strtok(search_name, "\n"); // �Ƴ���ѯ�����ַ����еĻ��з�
    
    int found = 0;
    for (PNODE p = pHead->pNext; p !=NULL; p = p->pNext)
    {
        if (strcmp(search_name, p->name) == 0)
        {
            printf("�ҵ�ƥ���ѧ�����ϣ�\n");
            
            printf("������ѧ������(ԭֵΪ %s): ", p->name);
            fgets(p->name, sizeof(p->name), stdin);
            strtok(p->name, "\n"); // �Ƴ������ַ����еĻ��з�
            
            printf("������ѧ���Ա�(ԭֵΪ %s): ", p->gender);
            fgets(p->gender, sizeof(p->gender), stdin);
            strtok(p->gender, "\n"); // �Ƴ��Ա��ַ����еĻ��з�

            printf("������ѧ���������ѵ���ɼ�(ԭֵΪ %.2f): ", p->programming_score);
            scanf("%f", &p->programming_score);
            
            printf("�ɹ��޸�ѧ�����ϣ�\n");

            found = 1;
            break;
        }
    }
    
    if (!found)
    {
        printf("δ�ҵ�ƥ���ѧ�����ϣ�\n");
    }
}

int main() 
{
    PNODE pHead = creat_list();
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    int choice;
    
    while (1) 
    {
        printf("ѧ���ɼ�����ϵͳ\n");
        printf("1. ����ѧ������\n");
        printf("2. ɾ��ѧ������\n");
        printf("3. �޸�ѧ������\n");
        printf("4. �Գɼ���������\n");
        printf("5. ��ʾ����ѧ������\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);
        getchar(); // ��ȡѡ�������Ļ��з�
        
        switch (choice) 
        {
            case 1:
                pTail = add_student(pTail);
                break;
            case 2:
                delete_student(pHead);
                break;
            case 3:
                modify_student(pHead);
                break;
            case 4:
                score_sort(pHead);
                break;
            case 5:
                display_student(pHead);
                break;
            case 0:
                printf("��лʹ��ѧ���ɼ�����ϵͳ��\n");
                return 0;
            default:
                printf("��Ч��ѡ��\n");
                break;
        }
        
        printf("\n");
    }
}