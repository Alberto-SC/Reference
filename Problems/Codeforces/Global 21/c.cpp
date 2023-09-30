#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        cin>>k;
        vector<int> b(k);
        for(auto &c:b)cin>>c;
        vector<pair<int,int>> V;
        for(int i = 0;i<n;i++){
            int x = a[i];
            int cont = 0;
            while(x%m==0){
                x/=m;
                cont++;
            }
            if(i && V.back().first == x)V.back().second+=pow(m,cont);
            else
                V.push_back({x,pow(m,cont)});
        }
        int idx = 0;
        bool flag = true;
        set<int> st;
        int x = m;
        st.insert(1);
        while(x<1e12){
            st.insert(x);
            x*=m;
        }
        int N = V.size();
        for(int i = 0;i<k;i++){
            if(idx>=N){
                flag = false;
                break;
            }
            if(b[i]>=V[idx].first){
                int p = b[i]/V[idx].first;
                if(!st.count(p)|| p>V[idx].second || p*V[idx].first != b[i]){
                    flag = false;
                    break;
                }
                V[idx].second-=p;
                if(V[idx].second==0)idx++;
            }
            else flag = false;
        }
        if(idx!= N)flag = false;
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}  