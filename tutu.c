#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void printList(struct node* newnode) {
    struct Node* last;
    while (newnode != NULL) {
        printf(" %d ", newnode->data);
        last = newnode;
        newnode = newnode->next;
    }
    printf("NULL\n");

    // Traverse in reverse direction
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}