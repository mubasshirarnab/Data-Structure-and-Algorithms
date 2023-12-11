#include <iostream>

using namespace std;

struct Queue
{
    int front;
    int rear;
    int n;
    int size;
    int *data;
};

typedef struct Queue queuee;

int menu();
void enQueue(queuee *Q, int value);
void deQueue(queuee *Q);
int isFull(queuee *Q);
int isEmpty(queuee *Q);
int queueSize(queuee *Q);
void printQueue(queuee *Q);

int main()
{
    queuee *q1;
    q1->front = -1;
    q1->rear = -1;
    q1->n = 10;
    q1->size = 0;
    q1->data = (int *)malloc(q1->n * sizeof(int));

    int choice = menu();

    while (choice != 0)
    {
        if (choice == 1)
        {
            int value;
            cout << "Enter a value to EnQueue ";
            cin >> value;

            enQueue(q1, value);
        }
        else if (choice == 2)
        {
            deQueue(q1);
        }
        else if (choice == 3)
        {
            cout << "Queue Size: " << queueSize(q1);
        }
        else if (choice == 4)
        {
            printQueue(q1);
        }
        else
        {
            cout << "Invalid choice. Enter a valid choice. *_*\n";
        }

        choice = menu();
    }

    return 0;
}

int menu()
{
    cout << "\n1. EnQueue: \n";
    cout << "2. DeQueue: \n";
    cout << "3. Queue Size: \n";
    cout << "4. Print Queue: \n";
    cout << "0. Exit: \n";

    int choice;
    cout << "Enter your Choice-> ";
    cin >> choice;

    return choice;
}

void enQueue(queuee *Q, int value)
{
    if (!isFull(Q))
    {
        if (Q->rear == Q->n - 1)
        {
            Q->rear = 0;
        }
        Q->data[++Q->rear] = value;
        Q->size++;
    }
    else
    {
        cout << "The Queue is Full.\n";
    }
}

void deQueue(queuee *Q)
{
    int temp;
    if (!isEmpty(Q))
    {
        temp = Q->data[++Q->front];
        Q->size--;
        if (Q->front == Q->n - 1)
        {
            Q->front = 0;
        }

        cout << temp << " deQueued.\n";
    }
    else
    {
        cout << "The Queue is Empty.\n";
    }
}

int isFull(queuee *Q)
{
    if (Q->front == 0 && Q->rear == (Q->n - 1) ||
        Q->front == (Q->rear + 1) % Q->n)
    {
        return 1;
    }
    return 0;
}

int isEmpty(queuee *Q)
{
    if (Q->size == 0)
    {
        return 1;
    }
    return 0;
}

int queueSize(queuee *Q)
{
    return Q->size;
}

void printQueue(queuee *Q)
{
    for (int i = 0; i < Q->n; i++)
    {
        cout << Q->data[i] << " ";
    }
}