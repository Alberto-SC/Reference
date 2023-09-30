#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        for(auto &x:c)cin>>x;
        int last = a[0];
        vector<int> p;
        p.push_back(last);
        for(int i = 1;i<n;i++){
            if(i == n-1){
                if(a[i] != last && a[i]!= p[0])last = a[i];
                else if(b[i]!= last && b[i]!= p[0]) last = b[i];
                else if(c[i] != last && c[i]!= p[0])last = c[i];
                p.push_back(last);
            }
            else {

                if(a[i] != last)last = a[i];
                else if(b[i]!= last)last = b[i];
                else if(c[i] != last)last = c[i];
                p.push_back(last);
            }
        }  

        for(auto c:p)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}

