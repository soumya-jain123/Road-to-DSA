#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

void insert(struct node**, int);
int count(struct node* );
void display(struct node* );

int main(){
    struct node* p;
    p = NULL;

    printf("No. of elements in the generated linked list = %d\n", count(p));
    insert(&p, 9);
    insert(&p, 10);
    insert(&p, 11);

    display(p);
    printf("No. of elements in the generated linnked list = %d\n", count(p));

}

void insert(struct node** q, int num){
    struct node* temp, *r;
    if(*q == NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = num;
        temp -> next = NULL;
        *q = temp;
    }else{
        temp = *q;
        while(temp -> next != NULL)
            temp = temp -> next;
            r = (struct node*)malloc(sizeof(struct node));
            r -> data = num;
            r -> next = NULL;
            temp -> next = r;
        
    }
}

void display(struct node* q){
    while(q != NULL){
        printf("%d ", q -> data);
        q = q -> next;
    }
    printf("\n");
}

int count(struct node* q){
    int count =0;
    while(q != NULL){
        q = q->next;
        count++;
    }
    return count;
}