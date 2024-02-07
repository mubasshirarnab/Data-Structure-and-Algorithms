#include<iostream>
#include<string>

using namespace std;

void isPalindrome(string s){
    if(s.length() == 1){
        cout<<"Palindrome"<<endl;
        return;
    }

    if(s.length() == 2){
        if(s[0]==s[1]){
            cout<<"Palindrome"<<endl;
            return;
        }
        else{
            cout<<"Not Palindrome"<<endl;
            return;
        }
    }

    if(s[0] == s[s.length()-1]){
        string str = s.substr(1, s.length()-2);
        isPalindrome(str);
    }
    else{
        cout<<"Not Palindrome"<<endl;
        return;
    }
}

int main(){

    isPalindrome("abcd");
    return 0;
}
