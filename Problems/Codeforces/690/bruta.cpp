#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M = 1e6;
const lli mod = 1e9+7;
vector<lli> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
lli ncr(lli n, lli r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (lli)fact[i-1] * i % mod;
		inv[i] = mod - (lli)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (lli)invfact[i-1] * inv[i] % mod;
	}
}

int main(){__
	int t= 1,n;
    cin>>t;
    calc();
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int cont = 0;
        for(auto &c:nums)cin>>c;
        set<pair<int,pair<int,int>>> st;
        for(int i = 1;i<13;i++){
            for(int j = i+1;j<13;j++){
                for(int k = j+1;k<13;k++){
                    vector<int> tr;
                    tr.push_back(nums[i]);
                    tr.push_back(nums[j]);
                    tr.push_back(nums[k]);
                    sort(tr.begin(),tr.end());
                    if(tr[2]-tr[0]<=2){
                        if(k>=9){
                            cont++;
                            cout<<i<<" "<<j<<" "<<k<<endl;
                            st.insert({i,{j,k}});
                        }
                    } 
                }
            }
        }
        cout<<cont<<endl;
        cout<<st.size()<<endl;
    }
    return 0;
}  

