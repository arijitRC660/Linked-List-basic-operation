/*linked list basic operation*/
#include <stdio.h>
#include <stdlib.h>
/*createing node type structure*/
struct node {
    int data;
    struct node *next;
};

typedef struct node node; //doing abstructions
node *start = NULL , *head;
void addNode()
{
    head = (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&head->data);
    if(start !=NULL)
    {
        node *temp = start; //taking a temp pointer to get the address of last node
        while(temp->next !=NULL)
        temp = temp->next;

        head->next = temp->next;
        temp->next = head;

        
    }
    else 
    {
        head->next = start;
        start = head; 
        /*storing address of the first node inside start*/
    }
}
void displayList()
{
    node *temp = start;
    printf("Elements inside the node: ");
    while(temp)
    {
        printf("%d ",temp->data); //displaying element
        temp=temp->next; //updating temp
    }
}
int main()
{ again:   int ch;
    printf("1 -create node and insert data\n");
    printf("2 -display elements of linked list\n");
    printf("3 -clear screen\n");
    printf("0 -exit the program\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : addNode(); break;
            case 2 : displayList(); break;
            case 0 : exit(0); break; 
            case 3 : system("cls"); goto again;
            default : printf("Invalid choice\n");
        }
        printf("\n");

    }
    return 0;
}


