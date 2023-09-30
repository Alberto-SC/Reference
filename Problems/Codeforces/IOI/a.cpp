#include <bits/stdc++.h>
using namespace std;
#define print(a)for(auto c:a)cout<<c<<"  ";
#define printM(a)for(auto c:a){print(c);cout<<endl;}
bool comp(vector<int> a,vector<int> b){
    if(a[2]==b[2])return a[1]<b[1];
    return a[2]<b[2];
}
int main(){
    int n,type,r,c;
    cin>>n>>type;
    vector<vector<int>> s(n);
    for(int i = 0;i<n;i++){
        cin>>r>>c;
        s[i].push_back(i+1);
        s[i].push_back(r);
        s[i].push_back(c);
    }
    sort(s.begin(),s.end(),comp);
    // printM(s);
    bool yes = true;
    for(int i = 0;i<n-1;i++)
        if(abs(s[i][1]-s[i+1][1]) != 1 &&abs(s[i][2]-s[i+1][2]) != 1)yes = false;
    if(yes){
        cout<<"YES\n";
        for(int i = 0;i<n;i++)
            cout<<s[i][0]<<"\n";
    }
    else cout<<"No\n";
    return 0;
}