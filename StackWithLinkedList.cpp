#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    int pop()
    {
        if (isEmpty() == 1)
        {
            cout << "Stack is empty.\n";
            return 0;
        }

        Node *temp = top;
        int poppedData = temp->data;
        top = temp->next;
        delete temp;

        return poppedData;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        n->next = top;
        top = n;
    }

    int isEmpty()
    {
        if (top == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int peek()
    {
        if (isEmpty() == 1)
        {
            cout << "Stack is empty.\n";
            return 0;
        }
        return top->data;
    }

    void display()
    {
        Node *ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
};

int main()
{
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);
    S1.push(50);

    cout << "Elements: ";
    S1.display();

    cout << "Popped element: " << S1.pop() << "\n";
    cout << "Popped element: " << S1.pop() << "\n";

    cout << "Stack elements after pop: ";
    S1.display();

    cout << "Top element: " << S1.peek() << "\n";

    S1.push(60);
    S1.push(70);
    S1.push(80);

    cout << "Elements: ";
    S1.display();

    cout << "Popped element: " << S1.pop() << "\n";
    cout << "Popped element: " << S1.pop() << "\n";

    cout << "Elements: ";
    S1.display();

    cout << "Top element: " << S1.peek() << "\n";

    return 0;
}
