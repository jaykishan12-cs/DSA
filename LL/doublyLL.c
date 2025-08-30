#include<stdio.h>
#include<stdlib.h>
#define null NULL

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head = null;
Node* tail = null;

int acceptNumber(char str[])
{
    int element;
    printf("\n %s",str);
    scanf("%d",&element);
    return element;
}

Node* createNode()
{
    Node* pnode;
    pnode = (Node*)malloc(sizeof(Node));
    if(pnode)
    {
        pnode->data = acceptNumber("Enter Data: ");
        pnode->prev = pnode->next = null;
    }
    return pnode;
}

Node* searchNode(int x)
{   
    Node *curr;
    curr = head;

    if(!head)
        return NULL;

    curr = head;
    while(curr != null && curr->data != x)
        curr = curr->next;

    return curr;
}
void insertAtBegining()
{
    Node* pnode;
    pnode = createNode();
    if(!pnode)
        return;

    if(!head)
        head = tail = pnode;
    else{    
        pnode->next = head;
        head->prev = pnode;
        head = pnode;
    }

    printf("\n Node inserted");
}
void insertAtEnd()
{
    Node* pnode;
    pnode = createNode();

    if(!pnode)
        return;

    if(!head)
        head = tail = pnode;
    else{
        pnode->prev = tail;
        tail->next = pnode;
        tail = pnode;
    }
    printf("\n Node inserted");
}
void insertAfter()
{
    Node *pnode,*curr;
    int element;
    pnode = createNode();
    if(!pnode)
        return;

    if(!head)   
    {
        printf("\n List is empty");
        return;
    }
    
    element = acceptNumber("\n Enter element after which u want to insert Node: ");
    curr = searchNode(element);

    if(!curr)
    {
        printf("\n Element0 Not found:");
        return;
    }

    if(curr == tail)
    {
        pnode->prev = tail;
        tail->next = pnode;
        tail = pnode;
    }
    else{
        pnode->next = curr->next;
        pnode->prev = curr;
        curr->next->prev = pnode;
        curr->next = pnode;
    }
    printf("\n Node Inserted");
}
void insertBefore()
{
    
    Node *curr,*pnode;
    int element;
     if(!head)   
    {
        printf("\n List is empty");
        return;
    }
    pnode = createNode();

    if(!pnode)
        return;
    
    element = acceptNumber("\n Enter Element before which u want to insert Node: ");
    curr = searchNode(element);

    if(!curr)
    {
        printf("\n Element not found!!");
        free(pnode);
        return;
    }

    if(curr == head)
    {
        pnode->next = head;
        head->prev = pnode;
        head=pnode;
        // tail->next = head;
    }
    else{
        pnode->next = curr;
        pnode->prev = curr->prev; 
        curr->prev->next = pnode;
        curr->prev = pnode;
    }
    printf("\n Node Inserted");
}

void deleteFromBegining()
{
    Node* curr;
    if(!head)
    {
        printf("\n List is empty");
        // free(curr77);
        return;
    }

    curr = head;
    if(head == tail)
        head = tail = null;
    else{
        head = head->next;
        head->prev = null;
    }
    printf("\n Deleted Node - %d",curr->data);
    free(curr);
}

void deleteFromEnd()
{
    Node* curr;
    if(!head)
    {
        printf("\n List is Empty : ");
        return;
    }

    curr = tail;
    
    if(head == tail)
    {
        head = tail = null;
    }else{
        tail = tail->prev;
        tail->next = null;
    }
    printf("\n Deleted Node - %d",curr->data);
    free(curr);
}
void deleteElement()
{
    int element;
    Node *curr;

    if(!head)
    {
        printf("\n List is empty");
        return;
    }
    element = acceptNumber("\n Enter Data to delete: ");
    curr = searchNode(element);

    if(!curr)
    {
        printf("\n Node not found");
        return;
    }

    if(head == tail)
        head = tail = null;
    else if(curr == head)
    {
        head = head->next;
        head->prev = null;
    }
    else if(curr == tail)
    {
        tail = tail->prev;
        tail->next = null;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    printf("\n Deleted Node - %d",curr->data);
    free(curr);
}

void search()
{
    if(!head)
    {
        printf("\n List is empty");
        return;
    }
    int element;
    Node *curr;

    element = acceptNumber("\n Enter Number to search");
    curr =  searchNode(element);
    if(curr)
        printf("\n Element Found");
    else    
        printf("\n Element Not found");

}
void printForward()
{
    if(!head)
    {
        printf("\n List is Empty");
        return;
    }

    Node *curr;
    curr = head;
    while(curr != null)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
}

void printBackward()
{
    if(!head)
    {
        printf("\n List is Empty");
        return;
    }

    Node *curr;
    curr = tail;
    while(curr != null )
    {
        printf("%d ",curr->data);
        curr = curr->prev;
    }
}
int main()
{
    int choice;
    
    while(1)
    {
        printf("\n ------ MENU ------");
        printf("\n1.Insert At Begining\n2.Insert At End\n3.Insert After\n4.Insert Before");
        printf("\n5.Delete Element from Begining\n6.Delete Element from End\n7.delete Element\n8.Print forward \n9.Printf Backwards \n10.Search\n11.Exit");
        
         printf("\n Enter Choice : ");
         scanf("%d",&choice);

         switch(choice)
         {
            case 1:
                insertAtBegining();
                break;

            case 2:
                insertAtEnd();
                break;

            case 3:
                insertAfter();
                break;

            case 4:
                insertBefore();
                break;

            case 5:
                deleteFromBegining();
                    break;

            case 6:
                deleteFromEnd();
                break;

            case 7: 
                deleteElement();
                break;

            case 8: 
                printForward();
                break;

            case 9:
                printBackward();
                break;
            
            case 10 :
                search();
                break;

            case 11:
                exit(EXIT_SUCCESS);
         }
    }

}