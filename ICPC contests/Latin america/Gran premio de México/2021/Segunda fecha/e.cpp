#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(int R,vector<int> &ac,int M,int n){
    for(int i = 0;i<(n-R)+1;i++){
        int left = i?ac[i-1]:0;
        if(ac[(i+R)-1]-left>M)return false;
    }
    return true;
}

signed main(){__
	int t= 1,n,M;
    while(t--){
        string s;
        cin>>n;
        cin>>s;
        int x = stoll(s.substr(0,s.size()-1));
        if(s[s.size()-1]=='T')
            M = x*1024*1024;
        else if(s[s.size()-1]=='G')
            M = x*1024;
        else 
            M = x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ac(n);
        ac[0] = nums[0];
        for(int i = 1;i<n;i++)
            ac[i] = ac[i-1]+nums[i];
        
        vector<int> ans(n);
        int mn = 1e15;
        int l = 1,r = n+1;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,ac,M,n))
                l = m;
            else 
                r = m;
        }
        if(l==n)cout<<l<<" "<<-1<<endl;
        else {
            int idx = 0;
            for(int i = 0;i<n;i++){
                int left = i?ac[i-1]:0;
                if(ac[i+l]-left>M){
                    idx =i+1;
                    break;
                }
            }
            cout<<l<<" "<<idx<<endl;
        }
    }
    return 0;
}  
