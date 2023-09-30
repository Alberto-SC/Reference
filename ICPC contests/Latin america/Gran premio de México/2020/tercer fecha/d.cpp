#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        string s;
        cin>>s>>k;
        n = s.size();
        vector<char> ans;
        lli sz = 0;
        for(int i = 0;i<n;){
            int num = 0;
            int j = i;
            while(j<n && s[j]<='9' && s[j]>='0'){
                num*=10;
                num+=s[j]-'0';
                j++;
            }
            // cout<<num<<" "<<j<<" "<<s[j]<<endl;
            if(num == 0)num = 1;
            sz+=num;
            if(sz>k)break;
            for(int k = 0;k<num;k++)
                ans.push_back(s[j]);
            j++;
            i = j;
            if(ans.size()>k)break;
        }
        if(sz>k)cout<<"unfeasible"<<endl;
        else {
            for(auto c:ans)cout<<c;
            cout<<endl;
        }
    }
    return 0;  
}  

