#include <iostream>

using namespace std;

int menu();
void push(int *data, int top, int value);
int pop(int *data, int top);
void printArray(int data[], int n);
// void pushMultipleValue(int *data, int top, int noOfValue);


int main()
{
    int data[100], n, choice, top = 0;
    cout << "Enter stack size: ";
    cin >> n;


    choice = menu(); 
    while (choice != 0)
    {
        if (choice == 1)
        {
            if (top == n)
            {
                cout << "Stack is full\n";
            }
            else
            {
                cout << "Enter a value: ";
                int v;
                cin >> v;

                int value;
                for (int i = 0; i < v; i++)
                {
                    cin >> value;
                    push(data, top, value);
                    top++;
                }
            }
        }
        else if (choice == 2)
        {
            if (top == 0)
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                int temp = pop(data, top);
                top--;
                cout << temp << " poped\n\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Stack Size: " << top << "\n";
        }
        else if (choice == 4)
        {
            if (top == 0)
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "The top elemnt is " << data[--top] << "\n";
            }
        }
        else if (choice == 5){
            printArray(data, n);
            
        }
        
        else
        {
            cout << "\nInvalid choice. Enter a valid choice: ";
        }

        choice = menu();
    }

    return 0;
}

void printArray(int data[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< data[i] << " ";
    }
    
}

int menu()
{
    int x;

    cout << "\n1.Push: \n";
    cout << "2.Pop: \n";
    cout << "3.Stack Size: \n";
    cout << "4.Top Element: \n";
    cout << "0.Exit: \n";

    cout << "\nEnter your choice: ";
    cin >> x;

    return x;
}

void push(int *data, int top, int value)
{
    data[top] = value;
}

// void pushMultipleValue(int *data, int top, int noOfValue)
// {
//     int value;
//     for (int i = 0; i < noOfValue; i++)
//     {
//         cin>> value;
//         push(data,top,value);
//         top++;
//     }
// }

int pop(int *data, int top)
{

    return data[--top];
}



