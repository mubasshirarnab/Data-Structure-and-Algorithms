#include <iostream>
#include <string.h>

using namespace std;

struct Stack
{
    int top;
    char *data;
};
typedef struct Stack stackk;

void push(stackk *s, char value)
{
    s->top++;
    s->data[s->top] = value;
}

char pop(stackk *s)
{
    char temp = s->data[s->top];
    s->top--;
    return temp;
}

int main()
{
    stackk s;
    s.top = -1;

    string str;
    cout<<"Enter the String: ";
    getline(cin, str);

    cout<<str<<endl;

    s.data = new char[str.length()];

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            push(&s, str[i]);
        }
        else
        {
            while (s.top >= 0)
            {
                cout << pop(&s);
            }
            cout << " ";
        }
    }

    while (s.top != -1)
    {
        cout << pop(&s);
    }

    return 0;
}