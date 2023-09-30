#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
int main(){__
    int t = 1,n,a;
    cin>>n;   
    set<pair<int,int>> st;
    for(int i = 0;i<n;i++){
        cin>>a;
        if(a)
            st.insert({a,-i});
    }
    auto it = st.end();
    it--;
    while(it->x){
        cout<<"HI "<<it->x<<endl;
        auto ed = st.end();
        ed--;
        auto f = st.begin();
        while(-ed->second<-f->second && f)ed--;
        break;
    }
    for(auto c:st)cout<<c.first<<" "<<c.second<<endl;
    return 0;
}

 