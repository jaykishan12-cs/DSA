#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next; 
}Node;

Node *head = NULL;
Node *tail = NULL;

int acceptNumber(char str[]){
    int element;
    printf("%s",str);
    scanf("%d",&element);
    return element;
}

Node* createNode(){
    Node* pnode;
    pnode = (Node*)malloc(sizeof(Node));
    if(pnode){
        pnode->data = acceptNumber("\n Enter Data : ");
        pnode->next = NULL;
    }
    return pnode;
}

void insertAtEnd(){
    Node* pnode = createNode();
    if(pnode){
        if(head == NULL){
            head = tail = pnode;
        } else {
            tail->next = pnode;
            tail = pnode;
        }
        printf("\n Node inserted");
    }
}

void connect(int element){
    Node *curr = head;
    while(curr != NULL && curr->data != element){
        curr = curr->next;
    }
    if(curr == NULL){
        printf("\n Element not valid!!");
        return;
    }
    tail->next = curr;
}

int count(Node **head){
    Node *slow,*fast;
    slow = fast = *head;
 
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            int count = 1;
            fast = fast->next;
            while(slow != fast)
            {
                count++;
                fast = fast->next;
            }
                return count;
        }
    }
   
}

int main(){
    int n,connectElement;
    printf("\n Enter no of nodes in list: ");
    scanf("%d",&n);

    printf("\n Enter %d nodes one by one",n);
    for(int i = 0;i<n;i++){
        printf("\n Enter %d node",i+1);
        insertAtEnd();
    }

    printf("\n Enter element to which you want to connect last node : ");
    scanf("%d",&connectElement);
    connect(connectElement);

    int res = count(&head);
    printf("\n No of Nodes in cycle is %d",res);
    
    return 0;
}
