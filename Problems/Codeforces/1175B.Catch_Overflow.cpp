#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int n;
    string t;
    cin>>n;
    stack<int> st;
    st.push(1);
    int x = 0,y;
    bool flag = true,f2 = true;
    int mx = (1ll<<32)-1;
    while(n--){
        cin>>t;
        if(t=="add"){
            if(!f2){
                flag = false;
                continue;
            }
            x+=(st.top())*flag;
            if(x>mx)
                flag = false;
        }
        else if(t == "for"){
            cin>>y;
            if(f2&& st.top()*y<=mx)
                st.push(st.top()*y);
            else 
                st.push(1e15),f2 =false;
        }
        else{
            st.pop();
            if(st.top()<=mx)f2 = true;
        }

    }
    if(flag)cout<<x<<endl;
    else cout<<"OVERFLOW!!!"<<endl;
    return 0;
}  
