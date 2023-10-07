#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void printArray(int data[], int n);
void selectionSortAscending(int* ptr, int n);
void selectionSortDescending(int* ptr, int n);

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

    selectionSortAscending(data, size);
    cout<< endl << endl <<"After Ascending Sort: " << endl;
    printArray(data, size);

    selectionSortDescending(data, size);
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

void selectionSortAscending(int* ptr, int n){
    int i, j, min;  
      
    for (i = 0; i < n-1; i++)  
    {  
        min = i; 
          
        for (j = i+1; j < n; j++) { 
            if (ptr[j] < ptr[min]){  
                min = j;
            } 
        }  

        int temp = ptr[min];  
        ptr[min] = ptr[i];  
        ptr[i] = temp;  
    }  
}  

void selectionSortDescending(int* ptr, int n){
    int i, j, min;  
      
    for (i = 0; i < n-1; i++)  
    {  
        min = i; 
          
        for (j = i+1; j < n; j++) { 
            if (ptr[j] > ptr[min]){  
                min = j;
            } 
        }  
         
        int temp = ptr[min];  
        ptr[min] = ptr[i];  
        ptr[i] = temp;  
    }  
}  




