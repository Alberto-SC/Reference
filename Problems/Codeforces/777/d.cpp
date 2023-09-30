#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        vector<int> beautiful;
        int N = sqrt(n);
        if((n/d)%d || n<(d*d) || n%(d*d)){
            cout<<"NO"<<endl;
            continue;
        }
        int x = n/(d*d);
        int cont = 0;
        set<vector<int>> st;
        cout<<x<<endl;
        for(int i = 1;i<100;i++)
            if(i%d)cout<<i*d<<" ";
        cout<<endl;
        for(int i = 1;i*i<=x;i++){
            if(x%i==0){
                cout<<i<<" "<<x/i<<endl;
                vector<int> S;
                if(i%d)S.push_back(i*d);
                else {
                    int z = i*d;
                    while(z>1){
                        z/=d;
                        S.push_back(d);
                    }
                }
                for(auto c:S)cout<<c<<" ";
                cout<<endl;
                if((x/i)%d)S.push_back((x/i)*d);
                else {
                    int z = (x/i)*d;
                    while((z/d)%d==0){
                        z/=d;
                        S.push_back(d);
                    }
                    S.push_back(z);
                }
                sort(S.begin(),S.end());
                for(auto c:S)cout<<c<<" ";
                cout<<endl;
                st.insert(S);
            }
        }
        if(st.size()>1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}   
