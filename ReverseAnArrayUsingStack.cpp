#include<bits/stdc++.h>

using namespace std;

struct Stack
{
    int top;
    int *data;
};
typedef struct Stack sttack;

void push(sttack *s, int value){
    s->top++;
    s->data[s->top] = value;
}

int pop(sttack *s){
    int temp = s->data[s->top];
    s->top--;
    return temp;
}

int main()
{
    int n;
    cout<<"Enter the size of the Array: ";
    cin>> n;
    int arr[n];
    sttack s1;
    s1.top = -1;
    s1.data = new int[n];

    cout<<"Enter the values of the Array: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        push(&s1, arr[i]);
    }
    cout<<"\nArray before reverse: ";
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }

    cout<<"\nArray after reverse: ";
    while (s1.top != -1)
    {
        cout<< pop(&s1) << " ";
    }

    free(s1.data);
    
    return 0;
}