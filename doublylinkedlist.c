#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* prev;
	int data;
	struct node *next;
}NODE;
typedef struct dlist{
	NODE * head;
	int no_nodes;
}DLIST;
DLIST *init()
{
	DLIST *list=(DLIST*)malloc(sizeof(DLIST));
	list->head=NULL;
	list->no_nodes=0;
	return(list);
}

NODE* createnode(int ele)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	if(temp!=NULL)
	{
		temp->data=ele;
		temp->prev=temp->next=NULL;
	}
	return(temp);
}
void insertatfront(DLIST *ptr,int ele)
{
	NODE *temp=createnode(ele);
	if(ptr->head==NULL){		
		ptr->head=temp;
		ptr->no_nodes++;
	}
	else{
		NODE *first=ptr->head;
		temp->next=first;
		first->prev=temp;
		ptr->head=temp;
		ptr->no_nodes++;
	}
}
void display(DLIST *ptr)
	{
		if(ptr->head==NULL)
		{
			printf("list is empty\n");
		}
		else{
			NODE *cur=ptr->head;
			while(cur!=NULL)
			{
				printf("%d\n",cur->data);
				cur=cur->next;
			}
		}
	}
int deletefront(DLIST *ptr)
{int x;
	if(ptr->head==NULL)
		return(9999);
	NODE *first=ptr->head;
	if(first->next==NULL)
	{
		x=first->data;
		free(first);
		ptr->head=NULL;
		return(x);
	}
		
	NODE *second=first->next;
	second->prev=NULL;
	ptr->head=second;
	x=first->data;
	free(first);
	return(x);
}	
void insertatrear(DLIST *ptr,int ele)
{
	NODE *temp=createnode(ele);
	if(ptr->head==NULL)
		ptr->head=temp;
	else{
		NODE *cur=ptr->head;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=temp;
		temp->prev=cur;
	}
	ptr->no_nodes++;
}
int deleterear(DLIST*ptr)
{
	int x;
	if(ptr->head==NULL)
		return(9999);
	NODE *cur=ptr->head;
	if(cur->next==NULL)
	{
		x=cur->data;
		free(cur);
		ptr->head=NULL;
	}
	else{
		NODE *prev=NULL;
		while(cur->next!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		x=cur->data;
		free(cur);
		prev->next=NULL;
	}
	ptr->no_nodes--;
	return(x);
}
void insertatpos(DLIST *ptr,int ele,int pos)
{
	if(pos==1)
		insertatfront(ptr,ele);
	else if(pos==ptr->no_nodes+1)
		insertatrear(ptr,ele);
	else{
		NODE *temp=createnode(ele);
		int c=1;
		NODE *cur=ptr->head;
		NODE *prevn=NULL;
		while(cur!=NULL && pos!=c)
		{
			prevn=cur;
			cur=cur->next;
			c++;
		}
		prevn->next=temp;
		temp->prev=prevn;
		cur->prev=temp;
		temp->next=cur;	
		ptr->no_nodes++;
	}
}
		

int main()
{
	DLIST *list=NULL;
	list=init();
	int choice,ele,x,pos;
	while(1)
	{
		printf("1.insert at front\n 2.Insert at rear\n 3. delete at front\n 4.delete at rear\n 5.Display\n 6.Insert at particular\n 7.Delete at particular position\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the element");
			scanf("%d",&ele);			
			insertatfront(list,ele);
			break;
			case 2:printf("enter the element");
			scanf("%d",&ele);			
			insertatrear(list,ele);
			break;
			case 3:x=deletefront(list);
			if(x==9999)
				printf("list is empty\n");
			else
				printf("deleted eleemnt is %d\n",x);
			break;
			case 4:x=deleterear(list);
			if(x==9999)
				printf("list is empty\n");
			else
				printf("deleted eleemnt is %d\n",x);
			break;
			
			case 5:display(list);
				break;
			case 6:printf("enter the element and posistion\n");
				   scanf("%d%d",&ele,&pos);
				   printf("%d",list->no_nodes);
				   if(pos<1 ||pos>list->no_nodes+1)
				   {
					   printf("invalid posistion\n");
				   }
				   else
				   {
					   insertatpos(list,ele,pos);
				   }
				   break;
					
			
		}
	}
	return(0);
}