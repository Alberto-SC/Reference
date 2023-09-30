#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

const int N = 20000043;

int nxt[N][2];
 
int szt = 1;
 
int new_vertex(){
	nxt[szt][0] = nxt[szt][1] = -1;
	return szt++;
}
 
int go(int x, int y){
	if (nxt[x][y] == -1)
		nxt[x][y] = new_vertex();
	return nxt[x][y];
}

int cur = 0;
void add_number(int x){
		int u = cur;
		for(int i = 10; i >= 0; i--){
				int z = ((x >> i) & 1);
				u = go(u, z);
		}
}
 
int descend(int x){
		int ans = 0;
		int u = cur;

		for(int i = 10; i >= 0; i--){
				int z = ((x >> i) & 1);
				if(nxt[u][z] != -1)
						u = nxt[u][z];
				else
						u = nxt[u][z^1],ans|=(1<<i);
			}
			return ans;
}

signed main(){__
    int T,n,q;
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;

        int len = (r-l)+1;
        if(len>=520)cout<<0<<endl;
        else{
						int ans = 1e9;
						nxt[cur][0] = nxt[cur][1] = -1;
						for(int i = l;i<=r;i++){
								if(i > l)
										ans = min(ans,descend(nums[i]));
								add_number(nums[i]);
						}
						cout<<ans<<endl;
        }
				cur = szt;
    }
    return 0;
}

