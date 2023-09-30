#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,v,type;
    cin>>t;
    while(t--){
        cin>>n;
        stack<int> stck;
        multiset<int> st;
        for(int i = 0;i<n;i++){
            cin>>type;
            if(type == 1){
                cin>>v;
                stck.push(v);
                st.insert(v);
            }
            else if (type == 2){
                if(stck.empty())continue;
                int num = stck.top();  
                stck.pop();
                st.erase(st.find(num));
            }
            else {
                if(st.empty())cout<<"Empty!"<<endl;
                else{
                    int mn =*st.begin();
                    int mx = *(--st.end());
                    cout<<abs(mn-mx)<<endl;
                }
            }
        }
    }
    return 0;
}  

