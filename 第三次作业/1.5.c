#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];          //姓名
    char gender[10];        //性别
    float english_score;    //英语成绩
    float math_score;       //数学成绩
    float c_score;          //C语言成绩
    float total_score;      //总分
    float average_score;    //平均分
};

struct Student students[100];
int num_students = 0;

//功能:添加一个新的学生
void add_student(void) 
{
    struct Student new_student;
    
    printf("请输入学生姓名: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    strtok(new_student.name, "\n"); // 移除姓名字符串中的换行符
    
    printf("请输入学生性别: ");
    fgets(new_student.gender, sizeof(new_student.gender), stdin);
    strtok(new_student.gender, "\n"); // 移除性别字符串中的换行符
    
    printf("请输入学生英语成绩: ");
    scanf("%f", &new_student.english_score);
    
    printf("请输入学生数学成绩: ");
    scanf("%f", &new_student.math_score);
    
    printf("请输入学生C语言成绩: ");
    scanf("%f", &new_student.c_score);
    
    new_student.total_score = new_student.english_score + new_student.math_score + new_student.c_score;
    new_student.average_score = new_student.total_score / 3;
    
    students[num_students++] = new_student;
    
    printf("成功添加学生资料！\n");
}

//功能:显示学生资料
void print_student(const struct Student *student)
{
    printf("姓名: %s\n", student->name);
    printf("性别: %s\n", student->gender);
    printf("英语成绩: %.2f\n", student->english_score);
    printf("数学成绩: %.2f\n", student->math_score);
    printf("C语言成绩: %.2f\n", student->c_score);
    printf("总分: %.2f\n", student->total_score);
    printf("平均分: %.2f\n", student->average_score);
}

//功能:显示学生资料
void display_students() 
{
    if (num_students == 0)
    {
        printf("没有学生资料可显示！\n");
        return;
    }
    
    printf("学生资料列表:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("学生 %d:\n", i+1);
        print_student(&students[i]);
        printf("\n");
    }
}

//功能:查询学生资料
void search_student() 
{
    if (num_students == 0)
    {
        printf("没有学生资料可查询！\n");
        return;
    }
    
    char search_name[50];
    printf("请输入要查询的学生姓名: ");
    fgets(search_name, sizeof(search_name), stdin);
    strtok(search_name, "\n"); // 移除查询姓名字符串中的换行符
    
    int found = 0;
    for (int i = 0; i < num_students; i++) 
    {
        if (strcmp(search_name, students[i].name) == 0) 
        {
            printf("找到匹配的学生资料：\n");
            print_student(&students[i]);
            printf("\n");
            found = 1;
            break;
        }
    }
    
    if (!found) 
    {
        printf("未找到匹配的学生资料！\n");
    }
}

//修改学生资料
void modify_student() 
{
    if (num_students == 0) 
    {
        printf("没有学生资料可修改！\n");
        return;
    }
    
    char search_name[50];
    printf("请输入要修改的学生姓名: ");
    fgets(search_name, sizeof(search_name), stdin);
    strtok(search_name, "\n"); // 移除查询姓名字符串中的换行符
    
    int found = 0;
    for (int i = 0; i < num_students; i++) 
    {
        if (strcmp(search_name, students[i].name) == 0) 
        {
            printf("找到匹配的学生资料：\n");
            print_student(&students[i]);
            printf("\n");
            
            struct Student modified_student;
            modified_student = students[i];
            
            printf("请输入学生姓名(原值为 %s): ", modified_student.name);
            fgets(modified_student.name, sizeof(modified_student.name), stdin);
            strtok(modified_student.name, "\n"); // 移除姓名字符串中的换行符
            
            printf("请输入学生性别(原值为 %s): ", modified_student.gender);
            fgets(modified_student.gender, sizeof(modified_student.gender), stdin);
            strtok(modified_student.gender, "\n"); // 移除性别字符串中的换行符
            
            printf("请输入学生英语成绩(原值为 %.2f): ", modified_student.english_score);
            scanf("%f", &modified_student.english_score);
            
            printf("请输入学生数学成绩(原值为 %.2f): ", modified_student.math_score);
            scanf("%f", &modified_student.math_score);
            
            printf("请输入学生C语言成绩(原值为 %.2f): ", modified_student.c_score);
            scanf("%f", &modified_student.c_score);
            
            modified_student.total_score = modified_student.english_score + modified_student.math_score + modified_student.c_score;
            modified_student.average_score = modified_student.total_score / 3;
            
            students[i] = modified_student;
            
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
    int choice;
    
    while (1) 
    {
        printf("学生成绩管理系统\n");
        printf("1. 输入学生资料\n");
        printf("2. 查询学生资料\n");
        printf("3. 修改学生资料\n");
        printf("4. 显示学生资料\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);
        getchar(); // 读取选择操作后的换行符
        
        switch (choice) 
        {
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                modify_student();
                break;
            case 4:
                display_students();
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