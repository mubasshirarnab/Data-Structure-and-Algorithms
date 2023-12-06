#include <iostream>

using namespace std;

int menu();
void enqueue(int *data, int value, int rear);
int dequeue(int *data, int front);

int main()
{
    int data[100], n, choice, front = 0, rear = 0, count = 0;
    cout << "Enter the Queue Size: ";
    cin >> n;

    choice = menu();
    while (choice != 0)
    {
        if (choice == 1)
        {
            if (count == n)
            {
                cout << "The queue is full.\n";
            }
            else
            {
                int value;
                cout << "Enter a value to enqueue: ";
                cin >> value;

                enqueue(data, value, rear);
                rear++;
                if (rear == n)
                {
                    rear = 0;
                }

                count++;
            }
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "The queue is empty.\n";
            }
            else
            {
                cout << data[front] << " dequeued.\n";
                front++;

                if (front == n)
                {
                    front = 0;
                }
                count--;
            }
        }
        else if (choice == 3)
        {
            cout << "The queue size is " << count << "\n";
        }
        else if (choice == 4)
        {
            if (count == 0)
            {
                count<<"The queue is empty.\n";
            }
            else{
                cout << "Top element: " << data[front] << "\n";
            }  
        }
        else
        {
            cout << "\nInvalid Choice. Try again *_*\n";
        }

        choice = menu();
    }

    return 0;
}

int menu()
{
    int choice;

    cout << "1. Enqueue: \n";
    cout << "2. Dequeue: \n";
    cout << "3. Queue Size: \n";
    cout << "4. Top Element: \n";
    cout << "0. Exit: \n";

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

void enqueue(int *data, int value, int rear)
{
    data[rear] = value;
}

int dequeue(int *data, int front)
{
    return data[front];
}




