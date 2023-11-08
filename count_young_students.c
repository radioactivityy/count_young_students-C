#include <stdio.h>

// Define the Student structure
struct Student {
    char name[10];
    int age;
    float points;
    struct Student* bestfriend;
};

// Define the student_init function
void student_init(struct Student* student, int age, const char* name) {
    snprintf(student->name, sizeof(student->name), "%s", name);
    student->age = age;
    student->points = 0.0;
    student->bestfriend = NULL;
}

int count_young_students(struct Student students[], int count, int maxAge) {
    int youngStudentCount = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].age <= maxAge) {
            youngStudentCount++;
        }
    }

    return youngStudentCount;
}

int main() {
    struct Student students[3];

    // Initialize students
    student_init(&students[0], 18, "Alice");
    student_init(&students[1], 19, "Bob");
    student_init(&students[2], 16, "Charlie");

    int youngStudentCount = count_young_students(students, 3, 18);
    printf("Number of young students: %d\n", youngStudentCount);

    return 0;
}