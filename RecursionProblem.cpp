#include <iostream>
#include<string>

using namespace std;

string func(string s){
    if(s.length()==0){
        return "";
    }

    string s2 = s.substr(0,s.length()-1);
    string str = func(s2);

    if(s[s.length()-1]== ' '){
        return str;
    }
    else if(isupper(s[s.length()-1])){
        return str+=tolower(s[s.length()-1]);
    }
        
    return str+= s[s.length()-1];

}

int main()
{
    cout << func("ABC xy") << endl;
    return 0;
}

