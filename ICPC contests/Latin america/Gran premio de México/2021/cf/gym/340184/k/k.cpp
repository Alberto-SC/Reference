#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    for(int test = 0;test <t;test++){ 
        string s;
        cin>>s;
        n = s.size();
        int x = 0;
        for(int i = 0;i<n;i++){
            x+=s[i]-'0';
        }
        set<int> ans;
        if((s.back()-'0')%2 ==0)ans.insert(2);
        if(x%3 ==0)ans.insert(3);
        if((s.size()>=2 && (((s[n-2]-'0')*10)+(s.back()-'0'))%4==0) ||(s=="4" || s=="8"))ans.insert(4); 
        if(s.back()=='0' || s.back()=='5')ans.insert(5);
        if(ans.count(2) && ans.count(3))ans.insert(6);
        if(ans.size()==0){
            cout<<-1<<endl;
        }
        else{
            int N = 0;
            for(auto c:ans){
                cout<<c;
                if(N !=ans.size()-1){
                    cout<<" ";
                }
                N++;
            }
            cout<<endl;
        }
    }
    return 0;
}  
