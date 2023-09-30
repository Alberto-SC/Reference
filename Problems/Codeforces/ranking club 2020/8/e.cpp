#include <bits/stdc++.h>
using namespace std;
bool is_vowel(char a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s; 
    int j = 0;
    for(int i = 0;i<n;i = j){
        j = i;
        if(is_vowel(s[j])){
            while(is_vowel(s[j])){j++;}
        }
        else{
            j++;
        }
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}