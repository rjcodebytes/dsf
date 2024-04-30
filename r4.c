#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *create(char data) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void dispFront(struct node *head) {
    printf("Forward List:");
    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}

void dispBack(struct node *tail) {
    printf("Backward List:");
    while (tail != NULL) {
        printf("%c", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

void insFront(char data[]){
 for(int i = strlen(data)-1 ; i>=0; i--){
   struct node *newNode = create(data[i]);
   if(head == NULL){
    head = tail = newNode;
   }
   else{
     newNode -> next = head;
     newNode -> prev = head -> prev;
     head -> prev = newNode;
     head = newNode;
   }
 }
}

void delEnd(){
  if(tail == NULL){
    printf("List is empty\n");
  }
 struct node *temp = tail;
 tail = tail -> prev;
 if(tail != NULL){
   tail -> next = NULL;
 }
 free(temp);
}

int main() {
    char data[100];
    int ch;
    printf("Enter a string: ");
    scanf("%s", data);

    for (int i = 0; i < strlen(data); i++) {
        struct node *newNode = create(data[i]);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    while (1) {
        printf("\n\n1.Display");
        printf("\n2.Insert at front");
        printf("\n3.Delete from end");
        printf("\n4.Exit\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                dispFront(head);
                dispBack(tail);
                break;
            
            case 2:printf("Enter a string to insert at front: ");
              scanf("%s",data);
              insFront(data);
              break;
            
            case 3:
              delEnd();
              break;
            
            case 4:
                exit(0);

            default:
                printf("Wrong choice.\n");
        }
    }

    return 0;
}

