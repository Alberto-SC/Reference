#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int zeros = 0,ones = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]== '0')zeros++;
            else ones++;
        }
        if(zeros>=ones)zeros= ones;
        else ones = zeros;
        if(ones&1)cout<<"DA"<<endl;
        else cout<<"NET"<<endl;
    }
    return 0;
}