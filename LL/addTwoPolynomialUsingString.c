#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SS 50
typedef struct Node{
    int coeff;
    int power;
    struct Node* next;
}Node;

Node *head1 = NULL;
Node *head2 = NULL;
Node *res = NULL;

Node* createNode(int coefficient, int power)
{
    Node* pnode = (Node*)malloc(sizeof(Node));
    if(pnode == NULL)
    {
        printf("Memory Overflow ! cannot allocate");
        return NULL;
    }
    pnode->coeff = coefficient;
    pnode->power = power;
    pnode->next= NULL;
    return pnode;
}

void insert(Node **head, int coefficient, int power)
{
    Node* current;
    Node* pnode = createNode(coefficient, power);
    if(pnode != NULL)
    {
        if(*head == NULL)
        {
            *head = pnode;
        }
        else{
            current = *head;
            while(current->next != NULL)
                current = current->next;
            current->next = pnode;
        }   
    }
}

void inputPolynomial(Node **head)
{
    int n, coeff, power;
    printf("\n Enter no of terms in Polynomial: ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        printf("\nTerm %d ",i+1);
        printf("\n Enter coefficient: ");
        scanf("%d",&coeff);
        printf(" Enter power: ");
        scanf("%d",&power);
        insert(head, coeff, power);
    }
}

void addPolynomial(Node **head1,Node **head2,Node **res)
{
    Node *curr1,*curr2;
    curr1 = *head1;
    curr2 = *head2;
    int sum;
    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->power == curr2->power)
        {
            sum = curr1->coeff + curr2->coeff;
            insert(res,sum,curr1->power);
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }else if(curr1->power > curr2->power)
        {
            insert(res,curr1->coeff,curr1->power);
            curr1 = curr1->next;

        }
        else{
            insert(res,curr2->coeff,curr2->power);
            curr2 = curr2->next;
        }
    }

    while(curr1 != NULL)
    {
        insert(res, curr1->coeff, curr1->power);
        curr1 = curr1->next;
    }
    while(curr2 != NULL)
    {
        insert(res, curr2->coeff, curr2->power);
        curr2 = curr2->next;
    }
}

void display(Node **head)
{
    if(!*head)
    {
        printf("\n List is empty");
        return;
    }
    Node *curr;
    curr = *head;
    while(curr != NULL)
    {
        printf("%d^%d",curr->coeff,curr->power);
        if(curr->next != NULL)
            printf(" + ");
        curr = curr->next;
    }
}
void extractString(Node **head,char str[])
{
    // int len = strlen(str);
    int i =0;
    while(str[i] != '\0')
    {

        if(str[i] == '+')
        {

        }
        else if(str[i] == '-')
        {

        }

        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            i++;
        }
        
    }
}
int main()
{
    char str1[SS],str2[SS];
    printf("\nEnter first polynomial:");
    scanf("%s",&str1);
    extractString(&head1,str1);

    printf("\nEnter second polynomial:");
    scanf("%s",&str1);
    extractString(&head2,str2);

    addPolynomial(&head1,&head2,&res);
    printf("\nResult Polynomial: ");
    display(&res);

    return 0;
}
