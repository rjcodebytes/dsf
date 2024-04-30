#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
struct node *top = NULL;

void push(int data){
  struct node *newNode;
  newNode = malloc(sizeof(newNode));
  if(newNode == NULL){
    printf("Stack is empty\n");
  }
  newNode -> data = data;
  newNode -> link = NULL;
  newNode -> link = top;
  top = newNode;
  
}

int pop(){
  struct node *temp;
  int val;
  
  if(top == NULL){
    printf("Stack is empty\n");
  }
  
   temp = top;
   val = temp -> data;
   top = top -> link;
   free(temp);
   temp = NULL;
   return val;
  
}

int peek(){
  if(top == NULL){
    printf("Stack is empty\n");
  }
  return top -> data; 
}

void display(){
 struct node *temp;
 temp = top;
 if(top == NULL){
    printf("Stack is empty\n");
  }
 else{ 
  printf("Stack: ");
  while(temp!=NULL){
    printf("%d ",temp -> data);
    temp = temp -> link;
    }
    printf("\n");
  }
}

int main(){
 int ch, data;
 while(1){
    printf("\n\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display top element");
    printf("\n4.Display stack");
    printf("\n5.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    
    switch(ch){
     case 1:
         printf("Enter element to be pushed:");
         scanf("%d",&data);
         push(data);
         break;
       
     case 2:
        data = pop();
        printf("Popped element is %d",data);
        break;
       
     case 3:
         printf("Top element is %d",peek());
        break;    
        
     case 4:
        display();
        break;
        
     case 5:
        exit(1);
           
     default:
         printf("Wrong Choice");
             
    }
 }
 return 0;
}
