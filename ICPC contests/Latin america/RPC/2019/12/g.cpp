#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int ans = -10;
    pair<int,char> impar;
    vector<int> bucket(25,0);
    int start = 0;
    for(int i = 0;i<n;i++){
        bucket[s[i]-'a']++;
        if(bucket&1)impar = {impar.first+1,s[i]};
        if(impar.first ==1||impar.first == 0)ans = max(ans,(i+1)-start);
        else {
            if(s[start] == impar.second])start++;
            else start = i; 
        }
    }
    return 0;
}