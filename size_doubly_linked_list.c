#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void insert(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    if((*head) != NULL){
        (*head)->prev = new_node;
    }
    (*head) = new_node;
}

int findSize(struct node* head){
    int res =0;
    while(head != NULL){
        res++;
        head = head->next;
    }
    return res;
}

void display(struct node* head){
    while(head != NULL){
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    
    display(head);
    printf("sieze of doubly linked list is: %d", findSize(head));

    return 0;

}