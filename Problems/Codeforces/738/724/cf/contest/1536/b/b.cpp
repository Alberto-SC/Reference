#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        string x;
        set<string> st;
        for(int i = 0;i<n;i++){
            string s1;
            for(int j = 0;j<5;j++){
                s1+=s[i+j];
                st.insert(s1);
            }
        }
        bool flag = false;
        for(int l = 1;l<=3;l++){
            string x = string(l,'a');
            while(1){
                if(!st.count(x)){
                    cout<<x<<endl;
                    flag = true;
                }
                if(flag)break;
                int idx = l-1;
                while(idx>=0 && x[idx]=='z'){
                    x[idx] ='a';
                    idx--;
                }
                if(idx<0)break;
                x[idx]++;
            }
            if(flag)break;
        }
    }
    return 0;
}  
