#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

typedef struct Student Student;
typedef struct studentVTable studentVTable;

struct Student {
    int age;
    char* name;
    const studentVTable *vtable;
};

struct studentVTable {
    void (*printAge)(Student* self);
    void (*printName)(Student* self);
    void (*printInfo)(Student* self);
};

void print_age(Student* student) {
    printf("%d\n", student->age);
}

void print_name(Student* student) {
    printf("%s\n", student->name);
}

void print_info(Student* student) {
    printf("Student:\n");
    printf("- Name: %s\n", student->name);
    printf("- Age: %d\n", student->age);
}

static const studentVTable vtable_student = {
    .printAge = print_age,
    .printName = print_name,
    .printInfo = print_info
};

Student* studentInit(char* newName, int newAge) {
    Student* res = (Student *) malloc(sizeof(Student));
    res->name = newName;
    res->age = newAge;
    res->vtable = &vtable_student;
    return res;
}

int main() {
    char* name = (char*) malloc(sizeof(char) * MAX_LENGTH);
    int age;
    Student* newStudent;

    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    
    newStudent = studentInit(name, age);
    newStudent->vtable->printInfo(newStudent);

    printf("Vtable: %p\n", &(vtable_student));

    printf("printAge(): %p\n", &(vtable_student.printAge));
    printf("printName(): %p\n", &(vtable_student.printName));
    printf("printInfo(): %p\n", &(vtable_student.printInfo));
    return 0;
}