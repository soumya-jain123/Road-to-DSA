#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode Node;

// Function to merge two sorted linked lists
Node* merge(Node* l1, Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to perform Merge Sort on a linked list
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Find the middle of the list
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    Node* second_half = slow->next;
    slow->next = NULL;

    // Recursively sort the two halves
    Node* sorted_first_half = mergeSort(head);
    Node* sorted_second_half = mergeSort(second_half);

    // Merge the sorted halves
    return merge(sorted_first_half, sorted_second_half);
}

// Function to create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create an unsorted linked list
    Node* head = newNode(3);
    head->next = newNode(1);
    head->next->next = newNode(4);
    head->next->next->next = newNode(2);

    printf("Original list:\n");
    printList(head);

    // Sort the linked list
    head = mergeSort(head);

    printf("\nSorted list:\n");
    printList(head);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}
