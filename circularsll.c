#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}NODE;

NODE * createnode()
{
    NODE * temp;
    temp = (NODE*)malloc(sizeof(NODE));
    if(temp!=NULL)
    {
        return(temp);
    }
}
void insertatfront(NODE * ptr,int ele)
{
    NODE * temp = createnode();
    temp->data=ele;
    NODE * first = ptr->link;
    ptr->link = temp;
    temp->link = first;

}
void display(NODE * ptr)
{
    NODE * cur = ptr->link;
    while(cur!=ptr)
    {
        printf("%d\t",cur->data);
        cur = cur->link;
    }
}
void insertatrear(NODE * ptr , int ele)
{
    NODE * temp = createnode();
    temp->data = ele;
    NODE * cur = ptr->link;
    while(cur->link!=ptr)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = ptr;
}
void deleteatfront(NODE * ptr)
{
    if(ptr->link == ptr)
        printf("Empty list");
    NODE * first = ptr->link;
    NODE * second = ptr->link->link;
    ptr->link = second;
    int x = first->data;
    free(first);
    printf("This is the deleted element :%d\n",x);
}
void deleteatrear(NODE * ptr)
{
    if(ptr->link == ptr)
        printf("Empty list");

    NODE * temp;
    NODE * cur = ptr->link;
    temp->link = ptr;
    
    while(cur->link!=ptr)
    {

        cur = cur->link;
    }
    int x = cur->data;
    free(cur);

}

int main()
{
    NODE * head = createnode();
    head->link = head;

    int choice;
    int ele;

	for(;;)
	{
		printf("\n1.Insert at front\n 2.Insert at rear\n 3.delete at front\n 4.delete from back\n 5.display\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element\n");
				   scanf("%d",&ele);
				   insertatfront(head,ele);
				   break;
            case 2: 
            printf("Enter the element\n");
				   scanf("%d",&ele);
                   insertatrear(head,ele);
            break;
            case 3:deleteatfront(head);
            break;
            case 4: deleteatrear(head);
            break;
            case 5:display(head);
            break;

		
		}
	}
	return(0);
}
