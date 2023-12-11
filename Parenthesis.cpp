#include<bits/stdc++.h>

using namespace std;

struct Stack
{
    int top;
    char *data;
};
typedef struct Stack stackkk;

void push(stackkk *s, char value)
{
    s->top++;
    s->data[s->top] = value;
}

char pop(stackkk *s)
{
    char temp = s->data[s->top];
    s->top--;

    return temp;
}

int main()
{
    stackkk s;
    s.top = -1;

    string str;
    cout<<"Enter a Expression: ";
    getline(cin, str);

    s.data = new char[str.length()];

    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] =='(' || str[i] =='{' || str[i] =='[')
        {
            push(&s, str[i]);
        }
        else if(str[i] ==')' && s.data[s.top] == '(' ||
                str[i] =='}' && s.data[s.top] == '{' ||
                str[i] ==']' && s.data[s.top] == '[' )
        {
               pop(&s);
        }   
        else
        {
            push(&s, str[i]);
        }
    }

    if(s.top == -1 || s.top == 0)
    {
        cout<<"Valid Parenthesis.\n";
    }
    else
    {
        cout<<"Invalid Parenthesis.\n";
    }

    return 0;
    
}