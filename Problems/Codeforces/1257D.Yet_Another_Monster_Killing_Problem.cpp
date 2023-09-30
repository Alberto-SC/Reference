#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int N,n;

vector<int> st[2];

void update(int pos,int val,int l,int r,int who,int v= 1){
    if(l == r)st[who][v] = val;
    else {
        int mid = (l+r)>>1;
        if(pos<=mid)
            update(pos,val,l,mid,who,v<<1);
        else 
            update(pos,val,mid+1,r,who,v<<1|1);
        st[who][v] = max(st[who][v<<1],st[who][v<<1|1]);
    }
}

int query(int l,int r,int sl,int sr,int who ,int v = 1){
    if(sl>r || sr<l ||sl>sr)return -1;
    if(sl>=l && sr<=r)return st[who][v];
    int mid = (sl+sr)>>1;
    return max(query(l,r,sl,mid,who,v<<1),query(l,r,mid+1,sr,who,v<<1|1));
}

bool check(int l,int r){
    int mx = query(l,r,0,n-1,0);
    int mxJ = query(mx,N-1,0,N-1,1);
    if(mxJ>=(r-l)+1)return true;
    return false;
}
void  print(int who){
    for(int i =0;who?i<N:i<n;i++)
        cout<<query(i,i,0,who?N:n,who)<<" ";
    cout<<endl;
}
int main(){__
    int t,m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        cin>>m;
        st[0].assign(4*(n+1),0);
        vector<int> p(m);
        vector<int> s(m);
        vector<int> copy(m);
        for(int i = 0;i<m;i++){
            cin>>p[i]>>s[i];
            copy[i] = p[i];
        }
        for(int i = 0;i<n;i++)
            copy.push_back(nums[i]);
        sort(copy.begin(),copy.end());
        vector<int> uniques;
        int last = copy[0];
        uniques.push_back(last);
        for(int i = 0;i<m+n;i++){
            if(last!=copy[i]){
                last = copy[i];
                uniques.push_back(last);
            }
        }
        for(int i = 0;i<m;i++)
            p[i] = lower_bound(uniques.begin(),uniques.end(),p[i])-uniques.begin();

        N = uniques.size();
        st[1].assign(4*N,0);
        vector<int> best(N);
        for(int i = 0;i<m;i++)
            best[p[i]] = max(best[p[i]],s[i]);
    
        for(int i = 0;i<N;i++)
            update(i,best[i],0,N-1,1);
        for(int i = 0;i<n;i++){
            int mp = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
            update(i,mp,0,n-1,0);
        }
        int ans = 0;
        bool flag = true;
        int l = 0;
        while(l<n){
            int a = l,b = n;
            while(a<b){
                int m = (a+b)>>1;
                if(!check(l,m))
                    b = m;
                else
                    a = m+1;
            }
            if(a == l){
                flag = false;
                break;
            }
            ans++;
            l = a;
        }
        if(flag)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}