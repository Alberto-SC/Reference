#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    int x = (n*(n+1))/2;
    if(x&1)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int need = x/2;
        int id = n;
        set<int> a;
        set<int> b;
        for(int i = 1;i<=n;i++)
            b.insert(i);
        while(need){
            if(need-id>=0){
                need-=id;
                a.insert(id);
                b.erase(id);
            }
            id--;
        }
        cout<<a.size()<<endl;
        for(auto c:a)cout<<c<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for(auto c:b)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}