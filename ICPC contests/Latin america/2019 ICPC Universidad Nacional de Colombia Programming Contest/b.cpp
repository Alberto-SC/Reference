#include <bits/stdc++.h>
using namespace std;
  
bool isPalindrome(string s) { 
    int len = s.size();
    if (len == 1) 
        return true; 
    int ptr1 = 0; 
    int ptr2 = len-1; 
    while (ptr2 > ptr1) { 
        if (s[ptr1] != s[ptr2]) 
            return false; 
        ptr1++; 
        ptr2--; 
    } 
    return true; 
} 
  
int noOfAppends(string s) { 
    if (isPalindrome(s)) 
        return 0;   
    s.erase(s.begin()); 
    return 1 + noOfAppends(s); 
} 
  
int main() { 
    string s;
    cin>>s;
    string copy = s;
    int n = noOfAppends(s);
    cout<<copy;
    if (n == 0)return 0;
    for(int i = n-1;i>=0;i--){
        cout<<copy[i];
    }
    cout<<endl;
    return 0; 
} 