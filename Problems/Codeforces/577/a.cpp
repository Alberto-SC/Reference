#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> po(m);
    vector<string> ans(n);
    for(int i = 0;i<n;i++)
        cin>>ans[i];
    long long r = 0;
    for(int i = 0;i<m;i++)cin>>po[i];
    for(int i = 0;i<m;i++){
        vector<int> mx(5);
        for(int j = 0;j<n;j++){
            mx[ans[j][i]-'A']++;
        }
        r += *max_element(mx.begin(),mx.end())*po[i];
    }
    cout<<r<<endl;
    return 0;
}