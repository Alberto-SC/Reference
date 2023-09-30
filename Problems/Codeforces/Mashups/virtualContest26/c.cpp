#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int n,ones =0;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> o,oa,ob;
    for(int i = 0;i<2*n;i++){
        if(s[i] == t[i] && s[i]=='1')o.push_back(i);
        else if(s[i]== '1')oa.push_back(i);
        else if(t[i]== '1')ob.push_back(i);
    }
    int turns = 2*n,a =0,b = 0;
    int turn = 0;
    while(turns--){
        if(!turn){
            if(o.size()){
                a++;
                o.pop_back();
            }
            else if(oa.size()>0){
                a++;
                oa.pop_back();
            }
            else if(ob.size())
                ob.pop_back();

        }
        else{
            if(o.size()){
                b++;
                o.pop_back();
            }
            else if(ob.size()){
                b++;
                ob.pop_back();
            }
            else if(oa.size())
                oa.pop_back();
        }
        // cout<<a<<" "<<b<<endl;
        turn^=1;
    }
    
    if(a==b)cout<<"Draw"<<endl;
    else if(a>b)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    
    return 0;
}  
