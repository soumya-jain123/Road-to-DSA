#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* prev;
  struct node* next;
};  
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void insertAndPrint(struct node** head_ref, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
    
}
int main(){
  struct node* head = NULL;
  insertAndPrint(&head, 1);
  insertAndPrint(&head, 2);
  insertAndPrint(&head, 3);
  insertAndPrint(&head, 4);
  insertAndPrint(&head, 5);
  printList(head);
  return 0;
  
}