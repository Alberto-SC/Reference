#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        sort(b.rbegin(),b.rend());
        vector<bool> used(n);
        for(int i = 0;i<n;i++){
            int j = 0;
            while(j<n && (used[j] || a[i]+b[j]>x)){
                j++;
            }
            if(j<n)used[j] =true;
        }
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(!used[i])flag = false;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

