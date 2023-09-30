#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int get(string s,int l,int r){
    set<char> st;
    for(int i = l;i<=r;i++){
        st.insert(s[i]);
    }
    return st.size();
}

signed main(){__
    int T = 1,n,d;
    cin>>n;
    string ans(n+1,'*');
    int last = 1;
    char x;
    cout<<"? 1 1"<<endl;
    cin>>x;
    ans[1] = x;
    for(int i = 2;i<=n;i++){
        cout<<"? 2 1 "<<i<<endl;
        cin>>d;
        if(d!=last){
            cout<<"? 1 "<<i<<endl;
            cin>>x;
            ans[i] = x;
            last++;
        }
        else if(last==1){
            ans[i] = ans[1];
        }
    }
    vector<int> valid;
    set<char> st;
    vector<int> lastP(26,-1);
    for(int i = 1;i<=n;i++){
        if(ans[i]=='*'){
            valid.clear();
            for(int j = 0;j<26;j++){
                if(lastP[j]!=-1)valid.push_back(lastP[j]);
            }
            sort(valid.begin(),valid.end());
            int l = -1,r = valid.size();
            while(l+1<r){
                int m = (l+r)>>1;
                int d1,d2;
                cout<<"? 2 "<<valid[m]<<" "<<i<<endl;
                cin>>d1;
                d2 = get(ans,valid[m],i-1);
                if(d1 == d2)l = m;
                else r = m;
            }
            ans[i] = ans[valid[l]];
            lastP[ans[i]-'a'] = i;
        }
        else {
            lastP[ans[i]-'a'] = i;
        }
    }

    cout<<"! ";
    for(int i= 1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
