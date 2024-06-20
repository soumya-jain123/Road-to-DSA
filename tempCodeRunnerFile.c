#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL)
        (*headRef)->prev = newNode;
    *headRef = newNode;
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

void insertBefore(struct Node** headRef, struct Node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("Next node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = nextNode->prev;
    nextNode->prev = newNode;
    newNode->next = nextNode;
    if (newNode->prev != NULL)
        newNode->prev->next = newNode;
    else
        *headRef = newNode; // Update head if newNode is the new head
}

void reverse(struct Node** headRef) {
    struct Node* temp = NULL;
    struct Node* current = *headRef;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        *headRef = temp->prev;
}

void deleteFromBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    if (*headRef != NULL)
        (*headRef)->prev = NULL;
    free(temp);
}

void deleteFromEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL)
        current = current->next;
    if (current->prev != NULL)
        current->prev->next = NULL;
    else
        *headRef = NULL;
    free(current);
}

void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Invalid operation: Previous node or node to be deleted does not exist.\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = prevNode;
    free(temp);
}

void deleteBefore(struct Node** headRef, struct Node* nextNode) {
    if (nextNode == NULL || nextNode->prev == NULL) {
        printf("Invalid operation: Next node or node to be deleted does not exist.\n");
        return;
    }
    struct Node* temp = nextNode->prev;
    if (temp->prev != NULL)
        temp->prev->next = nextNode;
    else
        *headRef = nextNode; // Update head if temp is the head
    nextNode->prev = temp->prev;
    free(temp);
}

void freeList(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    struct Node* prevNode;
    struct Node* nextNode;

    do {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");
        printf("5. Reverse\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete After\n");
        printf("9. Delete Before\n");
        printf("10. Display\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data after which you want to insert: ");
                scanf("%d", &data);
                prevNode = head;
                while (prevNode != NULL && prevNode->data != data)
                    prevNode = prevNode->next;
                insertAfter(prevNode, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data before which you want to insert: ");
                scanf("%d", &data);
                nextNode = head;
                while (nextNode != NULL && nextNode->data != data)
                    nextNode = nextNode->next;
                insertBefore(&head, nextNode, data);
                break;
            case 5:
                reverse(&head);
                printf("List reversed.\n");
                break;
            case 6:
                deleteFromBeginning(&head);
                printf("Node deleted from beginning.\n");
                break;
            case 7:
                deleteFromEnd(&head);
                printf("Node deleted from end.\n");
                break;
            case 8:
                printf("Enter data after which you want to delete: ");
                scanf("%d", &data);
                prevNode = head;
                while (prevNode != NULL && prevNode->data != data)
                    prevNode = prevNode->next;
                deleteAfter(prevNode);
                printf("Node deleted after specified node.\n");
                break;
            case 9:
                printf("Enter data before which you want to delete: ");
                scanf("%d", &data);
                nextNode = head;
                while (nextNode != NULL && nextNode->data != data)
                    nextNode = nextNode->next;
                deleteBefore(&head, nextNode);
                printf("Node deleted before specified node.\n");
                break;
            case 10:
                display(head);
                break;
            case 11:
                freeList(&head);
                printf("Memory freed. Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    } while (choice != 11);

    return 0;
}
