#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    //数据域
    char name[50];                    //姓名
    char gender[10];                  //性别
    float programming_score;          //程序设计语言成绩
    //指针域
    struct Student *pNext;            
}NODE,*PNODE;

//创建一个链表
PNODE creat_list(void)
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("error!");
    }
    return pHead;
}

//功能:添加一个新的学生
PNODE add_student(PNODE pTail)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        printf("error!");
    }

    printf("请输入学生姓名: ");
    fgets(pNew->name, sizeof(pNew->name), stdin);
    strtok(pNew->name, "\n"); // 移除姓名字符串中的换行符
    
    printf("请输入学生性别: ");
    fgets(pNew->gender, sizeof(pNew->gender), stdin);
    strtok(pNew->gender, "\n"); // 移除性别字符串中的换行符

    printf("请输入学生程序设计训练成绩: ");
    scanf("%f", &pNew->programming_score);

    pTail->pNext = pNew;
    pNew->pNext = NULL;

    return pNew;
}

//功能:删除学生信息
void delete_student(PNODE pHead)
{
    char delete_student_name[50];

    printf("请输入要删除的学生姓名: ");
    fgets(delete_student_name, sizeof(delete_student_name), stdin);
    strtok(delete_student_name, "\n"); // 移除姓名字符串中的换行符

    int found = 0;
    char operate[5];
    for(PNODE p = pHead; p->pNext !=NULL; p = p->pNext)
    {
        if (strcmp(delete_student_name, p->pNext->name) == 0)
        {
            found = 1;
            printf("请确认是否删除[Yes/No]");
            fgets(operate, sizeof(operate), stdin);
            strtok(operate, "\n"); // 移除操作字符串中的换行符

            if (strcmp(operate, "Yes") == 0)
            {
                PNODE tmp = p->pNext;
                p->pNext = p->pNext->pNext;
                free(tmp);
                printf("成功删除该学生信息!\n");
            }
            
            break;
        }
    }
    
    if (!found) 
    {
        printf("未找到匹配的学生！\n");
    }
}

//功能:显示所有学生信息
void display_student(PNODE pHead)
{
    int i=0;
    for(PNODE p = pHead->pNext; p !=NULL; p = p->pNext)
    {
        i++;
        printf("第%d个学生信息: \n", i);
        printf("姓名: %s\n", p->name);
        printf("性别: %s\n", p->gender);
        printf("程序设计训练成绩: %.2f\n", p->programming_score);
        printf("\n");
    }
}

//功能:对成绩进行排序
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

    printf("排序后顺序如下:\n");
    display_student(pHead);
}

//功能:修改学生信息
void modify_student(PNODE pHead) 
{
    if (pHead->pNext == NULL) 
    {
        printf("没有学生资料可修改！\n");
        return;
    }
    
    char search_name[50];
    printf("请输入要修改的学生姓名: ");
    fgets(search_name, sizeof(search_name), stdin);
    strtok(search_name, "\n"); // 移除查询姓名字符串中的换行符
    
    int found = 0;
    for (PNODE p = pHead->pNext; p !=NULL; p = p->pNext)
    {
        if (strcmp(search_name, p->name) == 0)
        {
            printf("找到匹配的学生资料：\n");
            
            printf("请输入学生姓名(原值为 %s): ", p->name);
            fgets(p->name, sizeof(p->name), stdin);
            strtok(p->name, "\n"); // 移除姓名字符串中的换行符
            
            printf("请输入学生性别(原值为 %s): ", p->gender);
            fgets(p->gender, sizeof(p->gender), stdin);
            strtok(p->gender, "\n"); // 移除性别字符串中的换行符

            printf("请输入学生程序设计训练成绩(原值为 %.2f): ", p->programming_score);
            scanf("%f", &p->programming_score);
            
            printf("成功修改学生资料！\n");

            found = 1;
            break;
        }
    }
    
    if (!found)
    {
        printf("未找到匹配的学生资料！\n");
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
        printf("学生成绩管理系统\n");
        printf("1. 插入学生资料\n");
        printf("2. 删除学生资料\n");
        printf("3. 修改学生资料\n");
        printf("4. 对成绩进行排序\n");
        printf("5. 显示所有学生资料\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);
        getchar(); // 读取选择操作后的换行符
        
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
                printf("感谢使用学生成绩管理系统！\n");
                return 0;
            default:
                printf("无效的选择！\n");
                break;
        }
        
        printf("\n");
    }
}