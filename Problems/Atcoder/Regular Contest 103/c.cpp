#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        if(s[0]!='1'|| s[n-1]!= '0')return cout<<-1<<endl,0;
        for(int i = 0;i<n/2;i++){
            if(s[i]!= s[n-2-i])return cout<<-1<<endl,0;
        }
        vector<int> ones;
        for(int i = 0;i<n-1;i++)
            if(s[i]== '1')
                ones.push_back(i+1);
        for(int i = 1;i<=ones.size();i++)
            cout<<i<<" "<<i+1<<endl;
        int k = ones.size()+2;
        for(int i = 1;i<ones.size();i++)
            for(int j =0;j< ones[i]-ones[i-1]-1;j++)
                cout<<1+i<<" "<<k++<<endl;
        
        
    }
    return 0;
}  

