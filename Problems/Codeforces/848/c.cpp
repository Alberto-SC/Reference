#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


string u;
void makeCombiUtil(vector<vector<char> >& ans,vector<char>& tmp, int n, int left, int k){
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
    for (int i = left; i < n; i++){
        tmp.push_back(u[i]);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        string a,b;
        cin>>a>>b;

        set<char> st;
        u = "";
        for(int i = 0;i<a.size();i++){
            if(st.count(a[i]))continue;
            u+=a[i];
            st.insert(a[i]);
        }
        
        if(k>=st.size()){
            cout<<(n*(n+1))/2<<endl;
            continue;
        }
        vector<vector<char>> _all;
        vector<char> tmp;
        makeCombiUtil(_all,tmp,u.size(),0,k);

        int ans = 0;
        for(auto chars: _all){
            int len = 0;
            int res = 0;
            set<char> S(chars.begin(),chars.end());

            for(int i = 0;i<n;i++){
                if(a[i]== b[i])
                    len++;    
                else if(S.count(a[i]))len++;
                else {
                    res+=(len*(len+1))/2;
                    len = 0;
                }
            }
            res+=(len*(len+1))/2;
            ans = max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}