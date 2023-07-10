#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];          //����
    char gender[10];        //�Ա�
    float english_score;    //Ӣ��ɼ�
    float math_score;       //��ѧ�ɼ�
    float c_score;          //C���Գɼ�
    float total_score;      //�ܷ�
    float average_score;    //ƽ����
};

struct Student students[100];
int num_students = 0;

//����:���һ���µ�ѧ��
void add_student(void) 
{
    struct Student new_student;
    
    printf("������ѧ������: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    strtok(new_student.name, "\n"); // �Ƴ������ַ����еĻ��з�
    
    printf("������ѧ���Ա�: ");
    fgets(new_student.gender, sizeof(new_student.gender), stdin);
    strtok(new_student.gender, "\n"); // �Ƴ��Ա��ַ����еĻ��з�
    
    printf("������ѧ��Ӣ��ɼ�: ");
    scanf("%f", &new_student.english_score);
    
    printf("������ѧ����ѧ�ɼ�: ");
    scanf("%f", &new_student.math_score);
    
    printf("������ѧ��C���Գɼ�: ");
    scanf("%f", &new_student.c_score);
    
    new_student.total_score = new_student.english_score + new_student.math_score + new_student.c_score;
    new_student.average_score = new_student.total_score / 3;
    
    students[num_students++] = new_student;
    
    printf("�ɹ����ѧ�����ϣ�\n");
}

//����:��ʾѧ������
void print_student(const struct Student *student)
{
    printf("����: %s\n", student->name);
    printf("�Ա�: %s\n", student->gender);
    printf("Ӣ��ɼ�: %.2f\n", student->english_score);
    printf("��ѧ�ɼ�: %.2f\n", student->math_score);
    printf("C���Գɼ�: %.2f\n", student->c_score);
    printf("�ܷ�: %.2f\n", student->total_score);
    printf("ƽ����: %.2f\n", student->average_score);
}

//����:��ʾѧ������
void display_students() 
{
    if (num_students == 0)
    {
        printf("û��ѧ�����Ͽ���ʾ��\n");
        return;
    }
    
    printf("ѧ�������б�:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("ѧ�� %d:\n", i+1);
        print_student(&students[i]);
        printf("\n");
    }
}

//����:��ѯѧ������
void search_student() 
{
    if (num_students == 0)
    {
        printf("û��ѧ�����Ͽɲ�ѯ��\n");
        return;
    }
    
    char search_name[50];
    printf("������Ҫ��ѯ��ѧ������: ");
    fgets(search_name, sizeof(search_name), stdin);
    strtok(search_name, "\n"); // �Ƴ���ѯ�����ַ����еĻ��з�
    
    int found = 0;
    for (int i = 0; i < num_students; i++) 
    {
        if (strcmp(search_name, students[i].name) == 0) 
        {
            printf("�ҵ�ƥ���ѧ�����ϣ�\n");
            print_student(&students[i]);
            printf("\n");
            found = 1;
            break;
        }
    }
    
    if (!found) 
    {
        printf("δ�ҵ�ƥ���ѧ�����ϣ�\n");
    }
}

//�޸�ѧ������
void modify_student() 
{
    if (num_students == 0) 
    {
        printf("û��ѧ�����Ͽ��޸ģ�\n");
        return;
    }
    
    char search_name[50];
    printf("������Ҫ�޸ĵ�ѧ������: ");
    fgets(search_name, sizeof(search_name), stdin);
    strtok(search_name, "\n"); // �Ƴ���ѯ�����ַ����еĻ��з�
    
    int found = 0;
    for (int i = 0; i < num_students; i++) 
    {
        if (strcmp(search_name, students[i].name) == 0) 
        {
            printf("�ҵ�ƥ���ѧ�����ϣ�\n");
            print_student(&students[i]);
            printf("\n");
            
            struct Student modified_student;
            modified_student = students[i];
            
            printf("������ѧ������(ԭֵΪ %s): ", modified_student.name);
            fgets(modified_student.name, sizeof(modified_student.name), stdin);
            strtok(modified_student.name, "\n"); // �Ƴ������ַ����еĻ��з�
            
            printf("������ѧ���Ա�(ԭֵΪ %s): ", modified_student.gender);
            fgets(modified_student.gender, sizeof(modified_student.gender), stdin);
            strtok(modified_student.gender, "\n"); // �Ƴ��Ա��ַ����еĻ��з�
            
            printf("������ѧ��Ӣ��ɼ�(ԭֵΪ %.2f): ", modified_student.english_score);
            scanf("%f", &modified_student.english_score);
            
            printf("������ѧ����ѧ�ɼ�(ԭֵΪ %.2f): ", modified_student.math_score);
            scanf("%f", &modified_student.math_score);
            
            printf("������ѧ��C���Գɼ�(ԭֵΪ %.2f): ", modified_student.c_score);
            scanf("%f", &modified_student.c_score);
            
            modified_student.total_score = modified_student.english_score + modified_student.math_score + modified_student.c_score;
            modified_student.average_score = modified_student.total_score / 3;
            
            students[i] = modified_student;
            
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
    int choice;
    
    while (1) 
    {
        printf("ѧ���ɼ�����ϵͳ\n");
        printf("1. ����ѧ������\n");
        printf("2. ��ѯѧ������\n");
        printf("3. �޸�ѧ������\n");
        printf("4. ��ʾѧ������\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);
        getchar(); // ��ȡѡ�������Ļ��з�
        
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
                printf("��лʹ��ѧ���ɼ�����ϵͳ��\n");
                return 0;
            default:
                printf("��Ч��ѡ��\n");
                break;
        }
        
        printf("\n");
    }
}