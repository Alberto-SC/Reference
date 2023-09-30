#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<pair<int,int>> st;
int N;
void update(int x,int val,int idx,int v = 1,int sl = 0,int sr = N-1){
    if(sl == sr){st[v] = {val,idx};return;}
    int m = (sl+sr)>>1;
    if(x<=m)
        update(x,val,idx,v<<1,sl,m);
    else 
        update(x,val,idx,v<<1|1,m+1,sr);
    st[v] = min(st[v<<1],st[v<<1|1]);
}

const int inf = 1e9;
pair<int,int> query(int l,int r,int v = 1,int sl = 0,int sr = N-1){
    if(sl>r ||sl>r ||sr<l)return {inf,-1};
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return min(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

#define x first
#define y second

void print(){
    for(int i = 0;i<N;i++)
        cout<<query(i,i).x<<" ";
    cout<<endl;
}
signed main(){
	int t= 1,n,d;
    while(t--){
        cin>>n>>d;
        vector<pair<int,int>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;
        vector<int> _all;
        for(int i = 0;i<n;i++){
            _all.push_back(nums[i].x);
            _all.push_back(nums[i].y);
        }

        vector<int> copy = _all;
        vector<int> u;
        copy.push_back(d);
        sort(copy.begin(),copy.end());
        int last = copy[0];
        u.push_back(last);
        for(int i = 0;i<copy.size();i++){
            if(copy[i]!=last){
                last = copy[i];
                u.push_back(last);
            }
        }
        N = u.size();
        st.resize(4*N);
        d = lower_bound(u.begin(),u.end(),d)-u.begin();

        for(int i =0;i<N;i++)
            update(i,inf,i);

        for(int i = 0;i<n;i++){
            nums[i].x = lower_bound(u.begin(),u.end(),nums[i].x)-u.begin();
            nums[i].y = lower_bound(u.begin(),u.end(),nums[i].y)-u.begin();
            update(nums[i].x,nums[i].y,nums[i].x);
        }
        int ans = 0;
        int aux = 10;
        print();
        while(aux--){
            cout<<d<<endl;
            auto mn = query(d,N-1);
            cout<<mn.x<<" "<<mn.y<<endl;
            if(mn.x==inf)break;
            d = max(d,mn.x);
            ans++;
            update(mn.y,inf,mn.y);
            print();
        }
        cout<<ans<<endl;

    }
    return 0;
}  
