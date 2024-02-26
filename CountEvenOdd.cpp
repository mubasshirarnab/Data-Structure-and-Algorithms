#include<iostream>
#include<time.h>

using namespace std;

struct countEvenOdd
{
    int even;
    int odd;
};

typedef struct countEvenOdd evenOdd;

evenOdd evenOddCount(int* data, int low, int high){
    evenOdd EO, leftEvenOdd, rightEvenOdd, finalEvenOdd;

    EO.even = 0;
    EO.odd = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (low == high)
        {
            if (data[low] % 2 == 0)
            {
                EO.even++;
            }
            else{
                EO.odd++;
            }

            return EO;
            
        }
        else{
            leftEvenOdd = evenOddCount(data, low, mid);
            rightEvenOdd = evenOddCount(data, mid+1, high);
        }

        finalEvenOdd.even = leftEvenOdd.even + rightEvenOdd.even;
        finalEvenOdd.odd = leftEvenOdd.odd + rightEvenOdd.odd;

        return finalEvenOdd;
        
    }
    
}


int main()
{
    int n;
    cout<<"Enter the size of the Array: ";
    cin >> n;
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    
    cout<<"Array: ";
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }

    evenOdd count = evenOddCount(arr, 0, n-1);

    cout<<"\nEven: " << count.even << endl;
    cout<<"Odd: " <<count.odd << endl;

    return 0;
}