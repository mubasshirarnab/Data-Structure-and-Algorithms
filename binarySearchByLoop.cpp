#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void printArray(int data[], int n);
void sort(int data[], int n);
int binarySearch(int data[], int n, int key);

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
    
    printArray(data, n);
    sort(data, n);

    int key;
    cout<< endl
    
    <<"Enter a value to search: ";
    cin >> key;


    if (binarySearch(data, n, key) == 1)
    {
        cout <<"Found" << endl;
    }
    else{
        cout <<"Not Found" << endl;
    }

    return 0;
}

void printArray(int data[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< data[i] << " ";
    }
    
}

void sort(int data[], int n){
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

int binarySearch(int data[], int n, int key){
    int low = 0, high = n-1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (data[mid] == key)
        {
            return 1;
        }
        else if (data[mid] > key)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
    }
    return 0; 
}