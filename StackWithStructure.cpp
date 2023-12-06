#include <iostream>

using namespace std;

struct Stack
{
    int top;
    int size;
    int *data;
};

typedef struct Stack stackk;

int menu();
int isFull(stackk *s);
int isEmpty(stackk *s);
void push(stackk *s, int value);
int pop(stackk *s);
int stackSize(stackk *s);
void printStack(stackk *s);

int main()
{
    stackk *s1;
    // s1.data = new int[100];
    s1->size = 10;
    s1->data = (int *)malloc(s1->size * sizeof(int));

    s1->top = -1;

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
            cout<<pop(s1) << " popped\n";
        }
        else if (choice == 3)
        {
            cout<<"Stack Size: " << stackSize(s1);
        }
        else if (choice == 4)
        {
            cout<<"The top element of the stack is " << s1->data[s1->top];
        }
        else if (choice == 5)
        {
            printStack(s1);
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

int isFull(stackk *s)
{
    if (s->top == s->size)
    {
        return 1;
    }
    return 0;
}

int isEmpty(stackk *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stackk *s, int value)
{
    if (!isFull(s))
    {
        s->top++;
        s->data[s->top] = value;
    }
    else
    {
        cout << "The Stack is Full\n";
    }
}
int pop(stackk *s)
{
    if (!isEmpty(s))
    {
        int temp = s->data[s->top];
        s->top--;

        return temp;
    }
    else
    {
        cout << "The Stack is Empty.\n";
    }
}
int stackSize(stackk *s)
{
    return s->top;
}
void printStack(stackk *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << s->data[i] << " ";
    }
    cout << endl;
}