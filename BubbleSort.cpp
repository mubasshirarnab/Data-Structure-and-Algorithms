#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void printArray(int data[], int n);
void bubbleSortAscending(int data[], int n);
void bubbleSortDescending(int data[], int n);

int main()
{
    int size;
    cout<<"Enter the size of the Array: ";
    cin>> size;
    int data[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100 + 1;
    }

    cout<<"Before Sorting: " << endl;
    printArray(data, size);

    bubbleSortAscending(data, size);
    cout<< endl << endl <<"After Ascending Sort: " << endl;
    printArray(data, size);

    bubbleSortDescending(data, size);
    cout<< endl << endl <<"After Descending Sort: " << endl;
    printArray(data, size);
    
    return 0;
}

void printArray(int data[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< data[i] << " ";
    }
    
}

void bubbleSortAscending(int data[], int n){
    int i, j, temp;

    for ( i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (data[i] > data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }  
        }  
    }   
}

void bubbleSortDescending(int data[], int n){
    int i, j, temp;

    for ( i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (data[i] < data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }  
        }  
    }   
}