#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node node;

struct Stack
{
    node *head;
};

typedef struct Stack staack;

int menu();
void push(staack *s, int value);
int pop(staack *s);
int isEmpty(staack *s);
int top(staack *s);
int stackSize(staack *s);
int display(staack *s);

int main()
{
    staack *s1 = new staack;
    s1->head = NULL;

    int choice = menu();

    while (choice!=0)
    {
        if (choice == 1)
        {
            int value;
            cout<<"Enter a value to push ";
            cin>>value;

            push(s1, value);
        }
        else if (choice == 2)
        {
            cout<< pop(s1) << " popped\n";
        }
        else if (choice == 3)
        {
            cout<<"Stack Size: " << stackSize(s1);
        }
        else if (choice == 4)
        {
            cout<<"The top element of the stack is " << top(s1);
        }
        else if (choice == 5)
        {
            display(s1);
        }
        else
        {
            cout<<"Invalid choice. Enter a valid choice. *_*\n";
        }
        
        choice = menu();
    }
    

    return 0;
}

int menu(){
    cout<<"\n1. Push: \n";
    cout<<"2. Pop: \n";
    cout<<"3. Stack Size: \n";
    cout<<"4. Top element: \n";
    cout<<"5. Print Stack: \n";
    cout<<"0. Exit: \n";

    int choice;
    cout<<"Enter your Choice-> ";
    cin>>choice;

    return choice;
}

int isEmpty(staack *s)
{
    if (s->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(staack *s, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (s->head == NULL)
    {
        s->head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = s->head;
        s->head = newNode;
    }
}
int pop(staack *s)
{
    node *temp;
    int popingValue;
    if (!isEmpty(s))
    {
        popingValue = s->head->data;
        temp = s->head;
        s->head = temp->next;
 
        free(temp);
    }
    else
    {
        cout << "The Stack is Empty.\n";
    }

    return popingValue;
}

int top(staack *s)
{
    return s->head->data;
}

int stackSize(staack *s)
{
    node *ptr;
    ptr = s->head;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}
int display(staack *s)
{
    node *ptr;
    ptr = s->head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}