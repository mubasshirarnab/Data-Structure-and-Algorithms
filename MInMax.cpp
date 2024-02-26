#include <iostream>
#include<time.h>

using namespace std;

struct MinMax
{
    int max;
    int min;
};

typedef struct MinMax minMax;

minMax maximumMinimum(int *data, int low, int high)
{
    minMax maxMin, leftMinMax, righMinMax, finalMinMax;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (low == high)
        {
            maxMin.max = data[low];
            maxMin.min = data[low];

            return maxMin;
        }
        else{
            leftMinMax = maximumMinimum(data, low, mid);
            righMinMax = maximumMinimum(data, mid+1, high);
        }

        if (leftMinMax.max > righMinMax.max)
        {
            finalMinMax.max = leftMinMax.max;
        }
        else{
            finalMinMax.max = righMinMax.max;
        }

        if (leftMinMax.min < righMinMax.min)
        {
            finalMinMax.min = leftMinMax.min;
        }
        else{
            finalMinMax.min = righMinMax.min;
        }

        return finalMinMax;
        
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
    
    minMax MinimumMaximum = maximumMinimum(arr, 0, n-1);

    cout<<"\nMaximum: " << MinimumMaximum.max << endl;
    cout<<"Minimum: " << MinimumMaximum.min << endl;

    return 0;
}