#include <stdio.h>
#include <stdlib.h>
struct item {
    float weight;
    float value;
    float ppu;
};
void merge(struct item *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct item L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].ppu >= R[j].ppu) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(struct item *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printSortedppu(struct item *arr, int records) {
    mergeSort(arr, 0, records - 1);
printf("Weight Value PPU\n");
    for (int i = 0; i < records; i++) {
        printf("%5.2f %4.2f %3.2f\n", arr[i].weight, arr[i].value, arr[i].ppu);
    }
}

int fractional_knapsack(struct item *arr, int capacity, int records) {
    struct item *ptr;
ptr = (struct item *)malloc(records * sizeof(struct item));
for (int i = 0; i < records; i++) {
        printf("Enter weight, cost for item %d:\n", i + 1);
scanf("%f %f", &ptr[i].weight, &ptr[i].value);
   ptr[i].ppu = (ptr[i].value / ptr[i].weight);
    }
printf("Displaying Information:\n");
     printf("Weight Value PPU\n");
    for (int i = 0; i < records; i++) {
        printf("%5.2f %4.2f %3.2f\n", ptr[i].weight, ptr[i].value, ptr[i].ppu);
    }
    printf("\n");
printf("Sorted ppu\n");
    printSortedppu(ptr, records);
    printf("\n");
int vessel_val = 0;
    for (int i = 0; i < records; i++) {
        if (ptr[i].weight <= capacity) {
            capacity -= (ptr[i].weight);
            vessel_val += ptr[i].value;
        } else {
            vessel_val += ((ptr[i].value /ptr[i].weight) * capacity);
            capacity = 0;
            break;
        }
    }
    free(ptr);
    return vessel_val;
}
int main() {
    struct item *ptr;
    int items;
    int capacity;
printf("Enter the number of items: ");
    scanf("%d", &items);
    printf("Enter the weight capacity of vessel: ");
    scanf("%d", &capacity);
ptr = (struct item *)malloc(items * sizeof(struct item));
int vessel_value = fractional_knapsack(ptr, capacity, items);
    printf("The maximum value vessel contains: %d\n", vessel_value);
    free(ptr);
return 0;
}
