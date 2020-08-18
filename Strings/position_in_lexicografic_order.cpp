#include <bits/stdc++.h>
using namespace std;

int fact(int n){ 
    return (n<=1)?1:n*fact(n-1); 
} 
void cnt(int * count,string s) { 
    for (int i = 0; s[i]; ++i) 
        ++count[s[i]]; 
    for (int i = 1; i < 256; ++i) 
        count[i] += count[i - 1]; 
} 
void update(int * count,char s){ 
    int i; 
    for (i = s; i < 256; ++i) 
        --count[i]; 
} 
int findRank(string s) { 
    int n = s.size(); 
    int mul = fact(n); 
    int position = 1, i; 
    int count[256] = {0};
    cnt(count,s); 
    for (i = 0; i < n; ++i) { 
        mul /= n - i; 
        position += count[s[i] - 1] * mul; 
        update(count,s[i]); 
    } 
    return position; 
} 
int main(){
    int n;
    string s;
    cin>>s;
    cout<<findRank(s);
}