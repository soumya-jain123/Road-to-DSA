#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void deleteNode(struct node** head, struct node* del){
    if(*head == NULL || del == NULL)
        return;
    if(*head == del)
        *head = del->next;
    if(*head != NULL)
        del->next->prev = del->prev;
    if(del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

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

void display(struct node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    display(head);

    deleteNode(&head, head); /*delete first node*/
    deleteNode(&head, head->next); /*delete middle node*/
    deleteNode(&head, head->next); /*delete last node*/

    printf("\nModified linked list\n");
    display(head);

}