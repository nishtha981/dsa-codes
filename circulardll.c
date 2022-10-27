#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node * prev;
    int data;
    struct node* next;
}NODE;

NODE * createnode()
{
    NODE * temp = (NODE *)malloc(sizeof(NODE));
    if(temp!=NULL)
        return (temp);
}

void insertatfront(NODE * ptr , int ele)
{
    NODE * first = ptr->next;
    NODE * temp = createnode();
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = first;
    first->prev = temp;
    temp->data = ele;

}
void insertatrear(NODE * ptr , int ele)
{
    NODE * temp = createnode();
    NODE * last = ptr->prev;
    temp->data = ele;
    last->next = temp;
    temp->prev = last;
    temp->next = ptr;
    ptr->prev = temp;

}
int deleteatfront(NODE * ptr)
{

    NODE * first = ptr->next;
    NODE * second = first->next;
    if(ptr->next = ptr)
        printf("Empty l̥ist");
    ptr->next = second;
    second->prev = ptr;
    int x = first->data;
    free(first);
}

void deleteatrear(NODE * ptr)
{
    NODE * last = ptr->prev;
    NODE * newlast = last->prev;
    newlast->next = ptr;
    ptr->prev = newlast;
    free(last);
}
void display(NODE * ptr)
{
    NODE * cur = ptr->next;
    while(cur!=ptr)
    {
        printf("%d\t",cur->data);
        cur = cur->next;
    }
}

int main()
{
    NODE * head = createnode();
    head->next = head->prev = head;
        int choice;
    int ele;

	for(;;)
	{
		printf("\n1.Insert at front\n 2.Insert at rear\n 3.delete at front\n 4.delete from back\n 5.display\n 6.Size of list\n 7.Search\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element\n");
				   scanf("%d",&ele);
				   insertatfront(head,ele);
				   break;
            case 2:printf("Enter the element\n");
				   scanf("%d",&ele);
				   insertatrear(head,ele);
				   break;
            case 3:deleteatfront(head);
            break;
            case 4:deleteatrear(head);
            break;

            case 5: display(head);
            break;
 

		
		}
	}
}