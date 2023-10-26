#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void printArray(int *data, int n);
void quickSort(int *data, int pivot, int l);

int main()
{
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    int data[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 100 + 1;
    }

    cout << "\nBefore sorting: \n";
    printArray(data, n);

    quickSort(data, 0, n-1);
    cout << "\nAfter sorting: \n";
    printArray(data, n);

    return 0;
}

void printArray(int *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
}

void quickSort(int *data, int pivot, int l)
{
    int i, j, temp;

    if (pivot < l)
    {
        i = pivot + 1;
        j = l;
        while (i <= j)
        {
            while ((i <= l) && data[pivot] >= data[i])
            {
                i++;
            }

            while ((j >= pivot) && data[pivot] < data[j])
            {
                j--;
            }

            if (i > j)
            {
                break;
            }
            

            temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            i++;
            j--;
        }

        temp = data[pivot];
        data[pivot] = data[j];
        data[j] = temp;

        quickSort(data, pivot, j - 1);
        quickSort(data, j + 1, l);
    }
}