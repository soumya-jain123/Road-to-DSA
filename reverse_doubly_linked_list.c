#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void insert (struct node** head, int new_data){
    struct node* new__node = (struct node* )malloc(sizeof(struct node));
    new__node->data = new_data;
    new__node->prev = NULL;
    new__node->next = (*head);
    if((*head) != NULL){
        (*head)->prev = new__node;
    }

    (*head) = new__node;
}

void display(struct node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void revrse(struct node** head){
    struct node* temp = NULL;
    struct node* current = *head;

    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL){
        *head = temp->prev;
    }
}

int main(){
    struct node* node = NULL;
    insert(&node, 1);
    insert(&node, 2);
    insert(&node, 3);
    insert(&node, 4);
    insert(&node, 5);

    printf("\nOriginal list: ");
    display(node);

    revrse(&node);

    printf("\nReverse List: ");
    display(node);
}