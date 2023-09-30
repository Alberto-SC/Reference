#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> bit[2];
int sum(int idx,int who) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[who][idx];
    return ret;
}

int sum(int l, int r,int who) {
    return sum(r,who) - sum(l - 1,who);
}

void add(int idx, int delta,int who) {
    for (++idx; idx <maxn; idx += idx & -idx) bit[who][idx] += delta;
}
// x ->01
// y ->10
int main(){__
	lli t= 1,n,x,y;
    string s;
    bit[0].resize(maxn);
    bit[1].resize(maxn);
    cin>>s;
    cin>>x>>y;
    n = s.size();
    lli ans1 = 0,ans2 = 0;
    {
        for(int i = 0;i<n;i++){
            if(s[i] == '1')
                add(i,1,1);
            else if(s[i]== '0')
                add(i,1,0);
        }
        for(int i = 0;i<n;i++){
            if(s[i]== '1'){
                // cout<<"HI 1 "<<i<<" "<<sum(i-1,0)<<endl;
                ans1+=(sum(i-1,0)*x);   
            }
            else if(s[i]== '0'){
                // cout<<"HI 0 "<<i<<" "<<sum(i-1,1)<<endl;
                ans1+=sum(i-1,1)*y;
            }
        }
        // cout<<"ans1: "<<ans1<<endl;
        for(int i = 0;i<n;i++){
            if(s[i]== '?'){
                lli x0,x1;
                // cout<<s<<endl;
                x0 =(sum(i-1,1)*y)+(sum(i+1,n,1)*x);
                x1 =(sum(i-1,0)*x)+(sum(i+1,n,0)*y);
                if(x1<x0){
                    s[i] = '1';
                    ans1+=x1;
                    add(i,1,1);
                } 
                else{
                    s[i] ='0';
                    ans1+=x0;
                    add(i,1,0);
                }
            }
        }
    }
    reverse(s.begin(),s.end());
    bit[0].assign(maxn,0);
    bit[1].assign(maxn,0);
    {
        for(int i = 0;i<n;i++){
            if(s[i] == '1')
                add(i,1,1);
            else if(s[i]== '0')
                add(i,1,0);
        }
        for(int i = 0;i<n;i++){
            if(s[i]== '1')
                ans2+=sum(i-1,0)*x;
            else if(s[i]== '0')
                ans2+=sum(i-1,1)*y;
        }
        for(int i = 0;i<n;i++){
            if(s[i]== '?'){
                lli x0,x1;
                x0 =(sum(i-1,1)*y)+(sum(i+1,n,1)*x);
                x1 =(sum(i-1,0)*x)+(sum(i+1,n,0)*y);
                if(x1<x0){
                    s[i] = '1';
                    ans2+=x1;
                    add(i,1,1);
                }
                else{
                    s[i] ='0';
                    ans2+=x0;
                    add(i,1,0);
                }
            }
        }
    }
    cout<<min(ans1,ans2)<<endl;
    return 0;
}  

