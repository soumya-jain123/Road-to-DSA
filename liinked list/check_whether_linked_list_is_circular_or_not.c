#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
};

void insertNode(struct node** head, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL)
        *head = newNode;
    else{
        struct node* current = *head;
        while(current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    
}

void makeCircular(struct node* head){
    if(head == NULL)
        return;
    struct node* current = head;
    while(current->next != NULL)
        current = current->next;
    current->next = head;
}

bool isCircular(struct node* head){
    if(head == NULL)
        return false;
    struct node* slow = head;
    struct node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        if(slow==fast)
            return true;
        slow = slow -> next;
        fast = fast->next->next;
    }
    return false;
}

int main(){
    struct node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);

    makeCircular(head);

    printf("Is the linked list circular? %s\n", isCircular(head) ? "yes":"no");

    return 0;
}