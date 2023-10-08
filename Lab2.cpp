#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void printDetails(int data[], int n);
void insertion_sort(int data[], int n);
void bubble_sort(int data[], int n);
void selection_sort(int data[], int n);


int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int data[1000];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 100 + 1;
    }

    cout << "Before sorting: " << endl;
    printDetails(data, n);

    cout << endl <<"After Insertion sort: " << endl;
    insertion_sort(data,n);
    printDetails(data, n);

    cout << endl <<"After Bubble sort  : " << endl;
    bubble_sort(data, n);
    printDetails(data, n);

    cout << endl <<"After Selection sort  : " << endl;
    selection_sort(data, n);
    printDetails(data, n);
    
    return 0;
}

void printDetails(int data[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< data[i] << " ";
    }
    
}

void insertion_sort(int data[], int n){
    int i, j, temp;

    for ( i = 1; i < n; i++)
    {
        temp = data[i];
        j = i-1;

        while (j >= 0 && data[j] > temp)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;  
    }
}

void bubble_sort(int data[], int n){
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

void selection_sort(int data[], int n){
    int i, j, temp, min = data[0], min_index = 0;

    for ( i = 0; i < n; i++)
    {
        for ( j = i; j < n; j++)
        {
            if (data[j] < min)
            {
                min = data[j];
                min_index = j;
            }  
        }
        temp = data[i];
        data[i] = data[min_index];
        data[min_index] = temp;
        
        min = data[j]; 
    } 
}