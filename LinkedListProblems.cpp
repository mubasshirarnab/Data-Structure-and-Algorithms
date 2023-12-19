#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node* createNewNode(int value){
    node *newNode = new node();
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

int listSize(node *head){
    node *ptr;
    ptr = head;
    int count = 0;

    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    
    return count;
}

node *insertAtHead(node *head, int value){
    node *newNode = createNewNode(value);

    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }

    return head;
}

node *insertAtnTh(node* head, int value, int pos){
    node *newNode = createNewNode(value);
    node *tempNode;
    tempNode = head;

    if(head == NULL || pos == 1){
        head = newNode;
    }
    else if(pos == listSize(head) + 1){
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode; 
    }
    else{
        tempNode = head;
        while (pos-2 > 0)
        {
            tempNode = tempNode->next;
            pos--;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }

    return head;
}

node *insertAtTail(node *head, int value){
    node *newNode = createNewNode(value);
    node *ptr;
    ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;

    return head; 
}

node *delete_M_nodes_after_N_noads(node *head, int m, int n){
    node *temp;
    node *p;
    p = head;

    while ((m - 1) > 0)
    {
        p = p->next;
        m--;
    }
    while ((n - 1) > 0)
    {
        p = p->next;
        n--;
    }

    temp = p->next;
    p->next = temp->next;
    free(temp);
    
    return head;
}

void printList(node *head){
    node *p;
    p = head;

    while (p != NULL)
    {
        cout<<p->data << " ";
        p = p->next;
    }
    cout<<endl; 
}

int main()
{
    node *head = NULL;

    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    head = insertAtTail(head, 5);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 2);

    printList(head);

    head = insertAtnTh(head, 25, 2);
    head = insertAtnTh(head, 15, 4);

    printList(head);


    delete_M_nodes_after_N_noads(head,2,3);
    printList(head);

    return 0;
}