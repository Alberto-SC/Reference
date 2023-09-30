#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    string s;
    cin>>s;
    n = s.size();
    stack<char>st;
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(!st.empty() && st.top()== s[i])st.pop(),cont++;
        else
            st.push(s[i]);
    }
    if(cont&1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}  

