    #include <stdio.h>
    #include <conio.h>
    #include <stdlib.h>

    typedef struct Node
    {
        int data;
        struct Node *next;
    }Node;

    Node *head = NULL;
    Node *tail = NULL;

    //function to search as we have to search a node to insert after and  insert before the element so it will
    // be required there to search the element and it will take the data to search it will return the searched element

    Node* searchNode(int x)
    {
        Node *current;
        if(!head)
            return NULL;

        current = head;
        while(current != tail && current->data != x)
        {
            current = current->next;
        }
        if(current->data == x)
        {
            return current;
        }

        return NULL;
    }

    int acceptNumber(char str[])
    {
        int element;
        printf("%s",str);
        scanf("%d",&element);
        return element;
    }

    Node* createNode()
    {
        Node* pnode;
        pnode = (Node*)malloc(sizeof(Node));
        if(pnode)
        {
            pnode->data = acceptNumber("\n Enter Data : ");
            pnode->next = NULL;
        }

        return pnode;
    }


    void insertAtBeg()
    {
        Node* pnode = createNode();
        if(pnode)
        {
            if(head == NULL)
            {
                head = tail = pnode;
            }
            else{
                pnode->next = head;
                head = pnode;
                
            }
            tail->next = head;
            printf("\n Node inserted");
        }
    }

    void insertAtEnd()
    {
        Node* pnode = createNode();
        
        if(pnode)
        {
            if(head == NULL)
            {
                head = tail = pnode;
            }
            else
            {
                tail->next = pnode;
                tail = pnode;
            }
            tail->next = head;
            printf("\n Node inserted");
        }
    }

    void insertAfter()
    {
        Node* pnode =  createNode();
        int element ;
        element = acceptNumber("\n Enter number after which u wanna insert the node : ");
        Node* current;
        current = searchNode(element);


        if(pnode)
        {
            if(current == tail)
            {
                tail->next = pnode;
                tail = pnode;
                tail->next = head;
            }
            else{
                pnode->next = current->next;
                current->next = pnode;
            }

            printf("\n node inserted");
        }
    }

    void insertBefore()
    {
        Node* pnode =  createNode();
        Node* current,*follow;

        int element ;
        element = acceptNumber("\n Enter number after which u wanna insert the node : ");

        current = head;
        follow = NULL;

        if(pnode)
        {
            while(current != tail && current->data != element)
            {
                follow = current;
                current = current->next;
            }
            if(current->data != element)
            {
                printf("\nElement Not found");
                free(pnode);
                return;
            }
            pnode->next = current;
            if(current = head)
            {
                head = pnode;
                tail->next = head;
            }
            else{
                follow->next = pnode;
            }

            printf("\n Element inserted");

        }
    }

    void deleteFromBeg()
    {
        Node* current;
        if(!head)
        {
            printf("\n List is empty !");
            return;
        }

        current = head;

        if(current == tail)
        {
            head = tail = NULL;
        }
        else{
            head = head->next;
            tail->next = head;
        }

        printf("\n Deleted : %d",current->data);
        free(current);
    }



    void deleteFromEnd()
    {
        Node *current,*follow;

        if(!head)
        {
            printf("\n List is empty !");
            return;
        }
        current = head;
        follow = NULL;
        while(current != tail)
        {
            follow = current;
            current = current->next;
        }

        if(head == tail)
        {
            head= tail = NULL;
        }else{
            tail = follow;
            tail->next= head;
        }

        printf("\n Deleted : %d",current->data);
        free(current);
    }

    void deleteElement()
    {
        int element;
        Node *current,*follow;

        if(!head)
        {
            printf("\n Empty list");
            return;
        }

        element = acceptNumber("\n Enter Number to delete: ");
        current = head;
        follow = NULL;

        while(current != tail && current->data !=element)
        {
            follow = current;
            current = current->next;
        }
        if(current->data != element)
        {
            printf("\n Element Not found");
            return;
        }
        if(current == head && current == tail)
        {
            head = tail = NULL;
        }
        if(current == head)
        {
            head = head->next;
            tail->next = head;
        }
        else if(current == tail)
        {
            tail = follow;
            tail->next = head;
        }
        else{
            follow->next = current->next;
        }

        printf("\n Node deleted");
        free(current);
    }

    void search()
    {
        int element;
        element = acceptNumber("\n Enter Element ot search: ");

        Node *snode = searchNode(element);

        if(snode)
            printf("\n Element Found!!");
        else
            printf("\n Element Not found!!");
    }

    void Show()
    {
        Node* current;

        if(!head)
        {
            printf("\n List is empty nohing to diap;lay");
            // free(current);
            return;
        }

        current = head;
        printf("\n List constains: ");
        while(current != tail)
        {
            printf("%d ",current->data);
            current = current->next;
        }
        printf("%d",tail->data);
    }

    void reverse()
    {
        Node *current,*follow,*ahead;
        if(!head)
        {
            printf("\n list is empty");
            return;
        }

        tail->next = NULL;

        current = head;
        follow = NULL;

        while(current!= NULL)
        {
            ahead = current->next;
            current->next = follow;
            follow = current;
            current = ahead;
        }
 
        tail = head;
        head = follow;
        tail->next = head;

        printf("\n List reversed!!");
    }

    void main()
    {
        int choice;

        while (1)
        {
            printf("\n ------ MENU ------");
            printf("\n1.Insert At Begining\n2.Insert At End\n3.Insert After\n4.Insert Before");
            printf("\n5.Delete Element from Begining\n6.Delete Element from End\n7.delete Element\n8.Show list\n9.Reverse List\n10.Search\n11.Exit");

            printf("\n Enter Choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    insertAtBeg();
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
                    deleteFromBeg();
                    break;

                case 6:
                    deleteFromEnd();
                    break;

                case 7:
                    deleteElement();
                    break;

                case 8:
                    Show();
                    break;

                case 9:
                    reverse();
                    break;

                case 10:
                    search();
                    break;

                case 11:
                    exit(EXIT_SUCCESS);
            }
        }
    }