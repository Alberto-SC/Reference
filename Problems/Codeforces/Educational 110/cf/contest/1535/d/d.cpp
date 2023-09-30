#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k,q;
    while(t--){
        cin>>k;
        string s;
        cin>>s;
        n = (1<<k)-1;
        int N = (1<<(k+1));
        vector<int> tree(N);
        for(int i = n+1;i<N;i++)
            tree[i] = 1;
        int idx = 0;
        map<int,int> node_to_idx;
        map<int,int> idx_to_node;
        for(int i = k-1;i>=0;i--){
            int start = 1<<i;
            for(int j =start;j<1<<(i+1);j++){
                node_to_idx[j] = idx;
                idx_to_node[idx] = j;
                if(s[idx]=='0')
                    tree[j] = tree[j<<1];
                else if(s[idx]=='1')
                    tree[j] = tree[j<<1|1];
                else{
                    tree[j] = tree[j<<1|1]+tree[j<<1];
                }
                idx++;
            }
        }
        cin>>q;
        for(int i= 0;i<q;i++){
            int x;
            char c;
            cin>>x>>c;
            int who =idx_to_node[x-1];
            s[x-1] = c;
            while(who){
                idx = node_to_idx[who];
                if(s[idx]=='1')
                    tree[who] = tree[who<<1|1];
                else if(s[idx]=='0')
                    tree[who] = tree[who<<1];
                else 
                    tree[who] = tree[who<<1]+tree[who<<1|1];
                who/=2;
            }
            cout<<tree[1]<<endl;
        }
    }
    return 0;
}  
