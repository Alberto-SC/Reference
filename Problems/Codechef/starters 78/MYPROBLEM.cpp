#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std,



int check(set<int> &v,int x,int k){
    string s = to_string(x);
    int n = s.size();
    int ac = 0;
    
    int ans = 1e18;
    bool flag = false;

    for(int i = 0;i<n;i++){
        int digit = s[i]-'0';
        if(v.count(digit))continue;

        auto nxt = v.lower_bound(digit);
        string nw = s;

        bool f = false;
        if(nxt == v.end()){
            int mn = *v.begin();
            nw[i] = char(mn+'0');
            ac=1;
            int idx = i-1;
            while(ac){
                if(idx ==-1){
                    f = true;
                    ac = 0;
                }
                else if(nw[idx]== '9'){
                    nw[idx] = char(*v.begin()+'0');
                    ac = 1;
                }
                else{
                    auto nxt = v.lower_bound((nw[idx]-'0')+1);
                    if(nxt == v.end()){
                        nw[idx] = char(*v.begin()+'0');
                        ac = 1;
                    }
                    else{
                        nw[idx] = char(*nxt+'0');
                        ac = 0;
                    }
                }
                idx--;
            }
        }
        else{
            nw[i] = char(*nxt+'0');
        }

        for(int j = i+1;j<n;j++){
            if(v.size()==k){
                nw[j] = char(*v.begin()+'0');
            }
            else nw[j] = '0';
        }
        if(f) nw = char(*v.begin()+'0')+nw;
        ans = min(ans,stoll(nw)-x);
        flag = true;
        break;
    }

    if(!flag)return 0;
    return ans;
}


signed main(){__
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        int ans = 1e18;

        set<int> st;
        set<int> v;
        string s = to_string(n);
        if(s[0]=='9')v = {9};
        else v = {(s[0]-'0')+1};
        ans = min(ans,check(v,n,k)); 
        for(int i = 0;i<s.size();i++){
            if(st.size()==k)break;  
            st.insert(s[i]-'0');
            ans = min(ans,check(st,n,k));
        } 
        cout<<ans<<endl;
    }
}
