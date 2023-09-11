#include<stdio.h>
#include<stdlib.h>
 struct Node
 {
 	struct Node *next;
 	struct Node *prev;
 	int data;
 };
 void traverse(struct Node *head)
 {
 	struct Node *ptr = head;
 	do
 	{
 		printf("%d\n",ptr->data);
 		ptr = ptr->next;
	 }while(ptr!=head);
	 
 }

struct Node * insertion(struct Node *head,int data)
{
   struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
   ptr->data = data;
   
   ptr->next = head;
   ptr->prev = head->prev;
   (head->prev)->next = ptr;
   head->prev = ptr;
   head = ptr;
   return head;
}

struct Node * insertion_last(struct Node *head,int data)
{
	struct Node *p = (struct Node *) malloc(sizeof(struct Node));
	p->data = data;
	
	(head->prev)->next = p;
	p->prev = head->prev;
	p->next = head;
	head->prev = p;
  
	
	return head;
}

struct Node * deletion(struct Node *head,int item)
{
	struct Node *p = head;
	struct Node *q = head->next;
	
    
    while(q->data != item)
    {
    	p =p->next;
    	q = q->next;
	}
	 p->next = q->next;
	 (q->next)->prev = p;
	 free(q);
	return head;
}

int main()
{
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	int item;
	 
	 head = (struct Node*)malloc(sizeof(struct Node));
     second = (struct Node*)malloc(sizeof(struct Node));
	 third = (struct Node*)malloc(sizeof(struct Node));
	 fourth = (struct Node*)malloc(sizeof(struct Node));
	 
	  head->data = 3;
	  head->next = second;
	  head->prev = fourth;
	  
	  second->data = 5;
	  second->next = third;
	  second->prev = head;
	  
	  third->data = 11;
	  third->next = fourth;
	  third->prev = second;
	  
	  fourth->data = 15;
	  fourth->next = head;
	  fourth->prev = third;
	  //head = insertion(head,100);
	 // printf("enter the item to be deleted\n");
	 // scanf("%d",&item);
	 // head = deletion(head,item);
	 head = insertion_last(head,99);
	 traverse(head);
	  
	  return 0;	 
}
