#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int insert()
{
}
int count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("empty");
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
    }
    return (count);
}

void printlist(struct node *head)
{
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->link;
    }
}

void add_at_end(struct node *head, num)
{
}

int main()
{
    struct node *head = NULL;                          // initialising a pointer to be equal to head
    head = (struct node *)malloc(sizeof(struct node)); // dynamically allocatiing memory using malloc struct node is the data type so for both data and link
    head->data = 45;                                   // data in the first node is 45
    head->link = NULL;                                 // address of the next pointer

    struct node *current = malloc(sizeof(struct node)); // points to the second node
    current->data = 98;
    current->link = NULL;
    head->link = current; // link of first node has the address of second node which is current

    current = malloc(sizeof(struct node));
    current->data = 9;
    current->link = NULL;

    head->link->link = current;

    printf("%d %d", head->data, current->data);
    printlist(head);
    return 0;
}
