#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *head = NULL;

int isEmpty()
{
    return head  == NULL;
}
//to accept the data and the user will pass the string 
int accept(char *str)
{
    int num;
    printf("\n%s",str);
    scanf("%d",&num);
    return num;
}

//funciton to create new node which returns the newNode pointer
Node* createNode()
{
    int element;
    Node* pnode = (Node*)malloc(sizeof(Node));
    if(pnode == NULL)
    {
        printf("Memory Overflow ! cannot allocate");
        return NULL;
    }

    element = accept("Enter Data: ");
    pnode->data= element;
    pnode->next= NULL;

    return pnode;//newNode ponter
}

//to insert node at the begning of list
void insertAtBegining()
{
    Node *pnode = createNode();
    if(pnode != NULL)
    {
        pnode->next = head;
        head = pnode;
        printf("\n Node Inserted");
    }
}

//to insert node at the end of list
void insertAtEnd()
{
    Node* current;
    Node* pnode = createNode();
    

    if(pnode != NULL)
    {
        if(head == NULL)
        {
            head = pnode;
        }
        else{
            current = head;
            while(current->next != NULL)
                current = current->next;

            current->next = pnode;
            printf("\n Node inserted");
        }
        
    }
}

//to insert after a certian element
void insertAfter()
{
    Node* current;
    Node* pnode = createNode();

    int element = accept("Enter eement after which you u want to enter the new node: ");
    current = head;
    while(current != NULL && current->data != element)
    {
        current = current->next;
    }

    if(current == NULL)
    {
        printf("\n Element Not Found");
        free(pnode);
    }
    else{
        pnode->next = current->next;
        current->next = pnode;
        printf("\n Node Inserted");
    }
}

//to inseert before a specific element 
void insertBefore()
{
    Node* current;
    current = head;
    int element;
    element = accept("Enter element to insert new node before: ");

    Node* pnode = createNode();
    Node* follow;
    if(pnode != NULL)
    {
        current = head;
        follow = NULL;

        while(current != NULL && current->data != element)
        {
            follow = current;
            current = current->next;
        }

        if(current == NULL)
        {
            printf("\n Element Not found");
            free(pnode);
            return;
        }
        pnode->next = current;
        
        if(follow == NULL)
            head = pnode;
        else{
            follow->next = pnode;
            printf("\n Node Inserted");
        }
    }
}

//to delete node form begining
void deleteFromBegining()
{
    Node* current;
    if(isEmpty())
    {
        printf("\n List is emptyt Nothing to delete");
        return;
    }
    current = head;
    printf("\n Deleteing : %d",head->data);
    head = head->next;
    free(current);
}

//to delete form end of list 
void deleteFromEnd()
{
    Node *current,*follow;
    if(isEmpty())
    {
        printf("\n EMpty list nothing to delete");
        return;
    }

    current = head;
    follow = NULL;
    while(current->next != NULL)
    {
        follow = current;
        current = current->next;
    }
    if(follow == NULL)
    {
        head = NULL;
    }else
    {
        follow->next = NULL;
    }

    printf("\n Deleting %d",current->data);
    free(current); 
}

void deleteElement()
{
    Node *current,*follow;
    int element = accept("\n Enter Element to delete: ");
    if(isEmpty())
    {
        printf("\n List is Empty");
        return;
    }

    current = head;
    follow = NULL;

    while(current != NULL && current->data != element)
    {
        follow = current;
        current = current->next;
    }

    if(current == NULL)
    {
        printf("\n ELement not found");
        return;
    }

    if(follow == NULL)
        head = head->next;
    else
        follow->next = current->next;

    printf("\n Deleted element : %d",element);
    free(current);
    
}
//to reverse a linked list using three pointer approach
void reverse()
{
    Node *current,*follow,*ahead;
    if(isEmpty())
    {
        printf("\n List is empty ! nothing to reverse");
        return;
    }

    current = head;
    follow = NULL;
    

    while(current != NULL)
    {
        ahead = current->next;
        current->next = follow;
        follow= current;
        current = ahead;
    }

    head = follow;
    printf("\n List Reversed");
}
//to search a node in linked list
void search()
{
    Node *current;
    int key;
    key = accept("\nEnter data to search : ");
    if(isEmpty())
    {
        printf("\n List is Empty nothing to search");
        return;
    }

    current = head;
    while(current != NULL && current->data != key)
    {
        current = current->next;
    }

    if(current == NULL)
    {
        printf("\n Element NOt found");
        return;
    }
    printf("\n %d found",key);

}
//to traerse / display a linked list
void traverse()
{
    Node *current;
    if(isEmpty())
    {
        printf("\n List is empty!!");
        return;
    }

    current = head;
    printf("\n List Contains: ");
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
}

void divide()
{
    Node *slow,*fast;
    Node *current1,*current2;
    slow = fast = head;
    if(!head)
    {
        printf("\n List is empty!");
        return;
    }
    while(fast!=NULL && fast->next !=NULL)
    {
        slow= slow->next;
        fast = fast->next->next;
    }
    current1 = head;
    current2 = slow;

    printf("\n First Half :");
    while(current1 != slow)
    {
        printf("%d ",current1->data);
        current1 = current1->next;
    }

    printf("\n Second Half :");
    while(current2 != NULL)
    {
        printf("%d ",current2->data);
        current2 = current2->next;
    }
}
int main()
{
    int choice;
    
    while(1)
    {
        printf("\n ------ MENU ------");
        printf("\n1.Insert At Begining\n2.Insert At End\n3.Insert After\n4.Insert Before");
        printf("\n5.Delete Element from Begining\n6.Delete Element from End\n7.delete Element\n8.Show list\n9.Reverse List\n10.Search\n11.Divide\n12.Exit");
        
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
                traverse();
                break;

            case 9:
                reverse();
                break;
            
            case 10 :
                search();
                break;

            case 11:
                divide();
                break;
            case 12:
                exit(EXIT_SUCCESS);
         }
    }

}