
#include <stdio.h>
#include <math.h>
#include <time.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(&temp[j], &temp[j + 1]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}


void selectionSort(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (temp[j] < temp[minIndex]) {
                minIndex = j;
            }
        }
        swap(&temp[minIndex], &temp[i]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}


int partition(int arr[], int low, int high) 
{ 

    int pivot = arr[low]; 
    int i = low; 
    int j = high; 
  
    while (i < j) { 
        while (arr[i] <= pivot && i <= high - 1) { 
            i++; 
        }
        while (arr[j] > pivot && j >= low + 1) { 
            j--; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[low], &arr[j]); 
    return j; 
} 

void quick(int arr[], int low, int high) 
{ 
    if (low < high) { 
        int partitionIndex = partition(arr, low, high); 
        quick(arr, low, partitionIndex - 1); 
        quick(arr, partitionIndex + 1, high); 
    } 
} 

void quickSort(int arr[], int low, int high, int n) 
{ 
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    quick(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
} 


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    clock_t startTime, endTime;
    double timeTaken;
    
    
    int choice, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        // scanf("%d", &arr[i]);
        arr[i] = rand()/100;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Print Array\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array sorted using Bubble Sort.\n");
                startTime = clock();
                bubbleSort(arr, n);
                endTime = clock();
                timeTaken = (double) (endTime - startTime)/ CLOCKS_PER_SEC;
                printf("\nTime Take = %lf", timeTaken);
                break;
            case 2:
                printf("Array sorted using Selection Sort.\n");
                startTime = clock();
                selectionSort(arr, n);
                endTime = clock();
                timeTaken = (double) (endTime - startTime)/ CLOCKS_PER_SEC;
                printf("\nTime Take = %lf", timeTaken);
                break;
            case 3:
                printf("Array sorted using Quick Sort.\n");
                startTime = clock();
                quickSort(arr, 0, n - 1, n);
                endTime = clock();
                timeTaken = (double) (endTime - startTime)/ CLOCKS_PER_SEC;
                printf("\nTime Take = %lf", timeTaken);
                break;
            case 4:
                printf("Current Array: ");
                printArray(arr, n);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}

