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

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* follow ;

    while(curr != NULL)
    {
        follow = curr->next;
        curr->next = prev;
        prev = curr;
        curr = follow;
    }
    return prev; 
}
int checkPalindrome()
{
    if(head == NULL || head->next == NULL)
        return 1;

    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *first = head;
    Node *second;
    second = reverse(slow);

    while(second != NULL)
    {
        if(first->data != second->data)
            return 0; 
        first = first->next;
        second = second->next;
    }

    return 1;
}
void main()
{
    int n,res;
    printf("\n Enter Number of NOdes in list: ");
    scanf("%d",&n);

    for(int i =0;i<n;i++)
    {
        printf("\nNode %d",i+1);
        insertAtEnd();
    }
    res = checkPalindrome();
    if(res)
        printf("\n ---------Palindrome-----------");
    else   
        printf("\n ---------Not Palindrome--------");

}