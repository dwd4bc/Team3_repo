#include <stdio.h>
#include<stdlib.h>

struct node {
  int *data;
  struct node *next;
} *start = NULL;
void input()
  {
    int number;
  printf("How many elements : \n ");
 scanf(" %d", &number);
do
  {
   	struct node *new_item, *current_item;
	new_item = (struct node *)malloc(sizeof(struct node));
	printf("Enter element: \n ");
    	 scanf("%d", &new_item ->data);
	 new_item->next = NULL;
 if(start == NULL){
   start=new_item;
   current_item=new_item;
 }
 else 
  {
    current_item->next=new_item;
    current_item=new_item;
  }
 number--;
	   
  }while(number>0);
  }
  

       
      
  

					 

void output()   
{
  struct node *new_item;
    printf("The List: \n"); 
  new_item=start;
  while(new_item!=NULL)
    {
      printf("%d \n", new_item->data);
      new_item =new_item->next;
    }
  printf("Done \n");
  free(new_item);
}
  
	
  
  
				      				
int main (){

   input();
   output();
  // int x=12;
  // printf("Enter a number");
  // scanf(" %d",&x);
  //printf("x = %d", x);

}
