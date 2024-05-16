#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Selection_sort(int a[], int n) {
    int i, j, num;
    for (i = 1; i < n; i++) {
        num = a[i];
        j = i - 1;
        while (j >= 0 && num < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = num;
    }
}

void Bubble_sort(int a[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main() {
    int choice, size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            Bubble_sort(arr, size);
            printf("Sorted array in ascending order by Bubble Sort:\n");
            printArray(arr, size);
            break;
        case 2:
            Selection_sort(arr, size);
            printf("Sorted array in ascending order by Selection Sort:\n");
            printArray(arr, size);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
