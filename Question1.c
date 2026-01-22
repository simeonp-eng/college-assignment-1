#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float totalMarks;
};

int main() {
    struct Student s1, s2;
    float average;
    printf("Enter details of Student 1:\n");
    printf("Name: ");
    scanf(" %[^\n]", s1.name);
    printf("Age: ");
    scanf("%d", &s1.age);
    printf("Total Marks: ");
    scanf("%f", &s1.totalMarks);
    printf("\nEnter details of Student 2:\n");
    printf("Name: ");
    scanf(" %[^\n]", s2.name);
    printf("Age: ");
    scanf("%d", &s2.age);
    printf("Total Marks: ");
    scanf("%f", &s2.totalMarks);
    printf("\n--- Student Information ---\n");
    printf("Student 1: %s | Age: %d | Marks: %.2f\n", s1.name, s1.age, s1.totalMarks);
    printf("Student 2: %s | Age: %d | Marks: %.2f\n", s2.name, s2.age, s2.totalMarks);
    average = (s1.totalMarks + s2.totalMarks) / 2;
    printf("\nAverage Total Marks = %.2f\n", average);

    return 0;
}
