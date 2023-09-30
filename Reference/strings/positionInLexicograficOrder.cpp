/**
 * Author: Alberto Silva
 * Description: Get the position of a string in the lexicografic order with respect to all permutations of the string
 * Time: $O(n)$
 * Status: stress-tested
 */

#include <bits/stdc++.h>
using namespace std;

int fact(int n){ 
    return (n<=1)?1:n*fact(n-1); 
} 

int findRank(string s) { 
    int n = s.size(); 
    int mul = fact(n); 
    int position = 1, i; 
    vector<int> count(256);

    for (int i = 0; s[i]; ++i) count[s[i]]++; 
    for (int i = 1; i < 256; ++i) count[i] += count[i - 1]; 

    for (i = 0; i < n; ++i) { 
        mul /= n - i; 
        position += count[s[i] - 1] * mul; 
        for (int j = s[i]; j < 256; j++)count[j]--; 
    } 
    return position; 
} 
int main(){
    int n;
    string s;
    cin>>s;
    cout<<findRank(s);
}