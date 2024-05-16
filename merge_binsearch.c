#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *name;
    int age;
    float gpa;
};

void merge(struct student *students, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct student *L = (struct student*)malloc(n1 * sizeof(struct student));
    struct student *R = (struct student*)malloc(n2 * sizeof(struct student));

    for (i = 0; i < n1; i++)
        L[i] = students[left + i];
    for (j = 0; j < n2; j++)
        R[j] = students[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].gpa <= R[j].gpa) {
            students[k] = L[i];
            i++;
        } else {
            students[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        students[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        students[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(struct student *students, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(students, left, mid);
        mergeSort(students, mid + 1, right);
        
        merge(students, left, mid, right);
    }
}

int binarySearch(struct student *students, int left, int right, float target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (students[mid].gpa == target)
            return mid;
        if (students[mid].gpa < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n = 8;
    struct student *students = (struct student*)malloc(n * sizeof(struct student));

    for (int i = 0; i < n; i++) {
        students[i].name = (char*)malloc(50 * sizeof(char));
        printf("Enter student name, age, and GPA for student %d: ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
    }
    
    printf("\nStudent Records:\n");
    printf("SL NO.\tNAME\tAGE\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i + 1, students[i].name, students[i].age, students[i].gpa);
    }

    mergeSort(students, 0, n - 1);

    printf("\nSorted Student Records based on GPA:\n");
    printf("SL NO.\tNAME\tAGE\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i + 1, students[i].name, students[i].age, students[i].gpa);
    }
    
    float targetGPA = 3.6;
    int index = binarySearch(students, 0, n - 1, targetGPA);
    if (index != -1) {
        printf("\nStudent(s) with GPA %.2f found at index %d:\n", targetGPA, index);
        printf("NAME\tAGE\tGPA\n");
        printf("%s\t%d\t%.2f\n", students[index].name, students[index].age, students[index].gpa);
    } else {
        printf("\nNo student found with GPA %.2f\n", targetGPA);
    }

    for (int i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}

