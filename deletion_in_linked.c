#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void insert(node** , int);
void display(node*);
void delete(node**, int);

int main(){
    node* p;
    int n;

    p = NULL;
    insert(&p, 1);
    insert(&p, 2);
    insert(&p, 3);
    insert(&p, 4);

    display(p);
    printf("Enter the position from which you want to delete node: ");
    scanf("%d", &n);

    delete(&p, n);
    display(p);
}

void insert(node** q, int data){
    struct node* temp, *r;
    if(*q == NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = data;
        temp -> next = NULL;
        *q = temp;
    }else{
        temp = *q;
        while(temp -> next != NULL)
            temp = temp -> next;
            r = (struct node*)malloc(sizeof(struct node));
            r -> data = data;
            r -> next = NULL;
            temp -> next = r;
    }   
}

void display(node* q){
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

void delete(node** q, int position){
    node* temp;
    node* prev;
    temp = *q;
    prev = *q;

    for(int i = 0; i< position; i++){
        if(i == 0 && position == 1){
            *q = (*q)->next;
            free(temp);
        }else{
            if(i==position -1 && temp){
                prev->next = temp-> next;
                free(temp);
            }else{
                prev = temp;
                if(prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}