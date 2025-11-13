#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SubjectsCount 5

struct Student createStudent(const char* firstName, const char* lastName, int ID);
int averageGrade(struct Student student);
void printStudent(struct Student student);
int averageGrade();

struct Subject {
    char name[20];
    int grade;
};

struct Student {
    char firstName[20];
    char lastName[20];
    int ID;
    struct Subject subjects[SubjectsCount];
};



int main(){
    srand(time(0));
    struct Student student1 = createStudent("John", "Doe", rand() % 10000);
    struct Student student2 = createStudent("Jane", "Smith", rand() % 10000);
    struct Student student3 = createStudent("Alice", "Johnson", rand() % 10000);
    printStudent(student1);
    printStudent(student2);
    printStudent(student3);

    return 0;
}

void printStudent(struct Student student) {
    printf("Student: %s %s, ID: %d\n", student.firstName, student.lastName, student.ID);
    for (int i = 0; i < SubjectsCount; ++i) {
        printf("Subject: %s, Grade: %d\n", student.subjects[i].name, student.subjects[i].grade);
    }
    printf("Average Grade: %d\n", averageGrade(student));
}
int averageGrade(struct Student student) {
    int total = 0;
    for (int i = 0; i < SubjectsCount; ++i) {
        total += student.subjects[i].grade;
    }
    return total / SubjectsCount;
}
struct Subject createSubject() {
    char names [][20] = {"Math", "Science", "History", "Art", "Literature"};
    struct Subject sub;
    strcpy(sub.name, names[rand() % SubjectsCount]);
    sub.grade = rand() % 101;
    return sub;
}
struct Student createStudent(const char* firstName, const char* lastName, int ID) {
    struct Student s;
    strcpy(s.firstName, firstName);
    strcpy(s.lastName, lastName);
    s.ID = ID;
    for (int i = 0; i < SubjectsCount; ++i) {
        s.subjects[i] = createSubject();
    }
    return s;
}