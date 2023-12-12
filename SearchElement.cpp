#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void printArray(int *arr, int x);

int main()
{
    int n, key, flag = 0;
    cout << "Enter the size of the Array: ";
    cin >> n;
    int data[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 100 + 1;
        //cin >> data[i];
    }

    cout << "Elements: ";
    printArray(data, n);

    cout << "\nEnter the key value: ";
    cin >> key;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((data[i] - data[j]) == key)
            {
                cout << "Pair -> [" << data[i] << "," << data[j] << "]\n";
                flag = 1;
            }
        }
    }

    if(flag == 0)
    {
        cout<<"The key value is not matched *_*";
    }

    return 0;
}

void printArray(int *arr, int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
}