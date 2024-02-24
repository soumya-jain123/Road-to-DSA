#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node**, int);
int count(struct node*);
void display(struct node* );
void reverse(struct node** );

int main(){
    struct node* p;
    int n;
    p = NULL;

    printf("No. of Elements in the genrated linked list = %d\n", count(p));
    insert(&p, 1);
    insert(&p, 2);
    insert(&p, 3);
    insert(&p, 4);

    display(p);

    reverse(&p);

    display(p);
    
}

void insert(struct node** q, int data){
    struct node* temp, *r;
    if(*q == NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = data;
        temp -> next = NULL;
        *q = temp;
    }else{
        temp = *q;
        while(temp-> next != NULL)
            temp = temp -> next;
        r = (struct node*)malloc(sizeof(struct node));
        r -> data = data;
        r -> next = NULL;
        temp -> next = r;
    }
}
int count(struct node* q){
    int count =0;
    while(q != NULL){
        q = q->next;
        count++;
    }
    return count;
}
void display(struct node* q){
    while(q != NULL){
        printf("%d ", q -> data);
        q = q -> next;
    }
    printf("\n");
}
void reverse(struct node** q){
    struct node* prev = NULL;
    struct node* current = *q;
    struct node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *q = prev;
}