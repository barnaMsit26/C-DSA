#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a new element in the middle of the linked list
void insertInMiddle(struct Node** head, int num) {
    if (*head == NULL) {
        // If the list is empty, set the new node as the head
        *head = createNode(num);
    } else {
        // Traverse the list to find the middle node and add the new node
        struct Node* slow = *head;
        struct Node* fast = *head;
        struct Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        struct Node* newNode = createNode(num);

        if (prev != NULL) {
            // If there is a previous node, update its next pointer to insert the new node
            prev->next = newNode;
        } else {
            // If there is no previous node, the list only has one element (middle node)
            *head = newNode;
        }

        newNode->next = slow;
    }
}

int main() {
    struct Node* myList = NULL; // Initialize an empty linked list

    int choice, num;

    do {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert in the Middle\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;

                // Input the number of elements in the linked list
                printf("Enter the number of elements in the linked list: ");
                scanf("%d", &n);

                // Input the elements of the linked list
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &num);

                    // Insert the element at the end of the linked list
                    struct Node* newNode = createNode(num);
                    if (myList == NULL) {
                        myList = newNode;
                    } else {
                        struct Node* temp = myList;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = newNode;
                    }
                }
                break;
            }
            case 2:
                // Display the elements of the linked list
                printf("Linked List: ");
                display(myList);
                break;
            case 3:
                // Input the element to insert in the middle
                printf("Enter the element to insert in the middle: ");
                scanf("%d", &num);

                // Insert the element in the middle of the linked list
                insertInMiddle(&myList, num);

                // Display the updated linked list
                printf("Updated Linked List: ");
                display(myList);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    // Free the memory allocated for the linked list before exiting
    while (myList != NULL) {
        struct Node* temp = myList;
        myList = myList->next;
        free(temp);
    }

    return 0;
}
