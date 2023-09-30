#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        set<string> st;
        string s;
        for(int i = 0;i<n;i++){
            cin>>s;
            st.insert(s);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}

