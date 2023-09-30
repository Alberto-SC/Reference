#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> b(26);
        for(int i = 0;i<n;i++)
            b[s[i]-'a']= 1;
        int sum = 0;
        for(int i = 0;i<26;i++){
            if(b[i])k--,sum+=i+1,i++;
            if(k==0)break;
        }        
        if(k)cout<<-1<<endl;
        else cout<<sum<<endl;
    }
    return 0;
}  

