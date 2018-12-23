#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

 struct node {
  int data;
  struct node* next;
};

struct node* head=NULL;
int count=0;

void addBeg(int val){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  count++;

  temp->data = val;
  temp->next = head;
  head = temp;
  printf("\nvalue inserted %d ",val );
}

void addEnd(int val){
  struct node *t, *temp;
  t = (struct node*)malloc(sizeof(struct node));
  count++;
  if(head == NULL){
    head = t;
    head->data=val;
    head->next=NULL;
    return;
  }
  temp=head;

  while(temp->next!=NULL){
    temp=temp->next;
  }

    temp->next=t;
    t->data=val;
    t->next=NULL;

}

void display(){
  struct node *temp;

   temp= head;

   if (temp == NULL) {
      printf("Linked list is empty.\n");
      return;
   }
   else{

   printf("There are %d elements in linked list.\n", count);

   while (temp!= NULL) {
      printf("%d\n", temp->data);
      temp= temp->next;
   }
 }
  // printf("%d\n", temp->data);
}

 void delBeg(){
   struct node *temp;
   int n;
   temp=head;
   if(head==NULL){
     printf("Empty list\n");
   }
   else{
   n=head->data;
   temp=head->next;
 }
   free(temp);
   // head=temp;
   // count--;
   printf("%d deleted from beginning successfully \n",n);
 }


 void delEnd() {
   struct node *t, *u;
    int n;

    if (head == NULL) {
       printf("Linked list is already empty.\n");
       return;
    }

    count--;

    if (head->next == NULL) {
       n = head->data;
       free(head);
       head = NULL;
       printf("%d deleted from end successfully.\n", n);
       return;
    }

    t = head;

    while (t->next != NULL) {
       u = t;
       t = t->next;
    }

    n = t->data;
    u->next = NULL;
    free(t);

    printf("%d deleted from end successfully.\n", n);
 }






void main(){
  int input, data;


  while(1){
      printf("1. Insert an element at beginning of linked list.\n");
      printf("2. Insert an element at end of linked list.\n");
      printf("3. Display linked list.\n");
      printf("4. Delete element from beginning.\n");
      printf("5. Delete element from end.\n");
      printf("6. Exit\n");
      printf("Enter choice\n");

      scanf("%d", &input);
    switch (input) {
      case 1:
      printf("\nEnter value of element\n");
      scanf("%d", &data);
      addBeg(data);
      break;
      case 2:
      printf("\nEnter value of element\n");
      scanf("%d", &data);
      addEnd(data);
      break;
      case 3:
      display();
      break;
      case 4:
      delBeg();
      break;
      case 5:
      delEnd();
      break;
      default:
      printf("\nInvalid choice\n");
}
}
}
