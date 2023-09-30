#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<lli> st[3];
vector<lli> lazy[3];
void propagate(lli v,lli l ,lli r,lli who){
    if(!lazy[who][v])return ;
    st[who][v] += ((r-l)+1)*lazy[who][v];
    if(l!= r){
        lazy[who][v<<1] += lazy[who][v];
        lazy[who][v<<1|1]+= lazy[who][v];
    }
    lazy[who][v] = 0;
}
lli n;
void update(lli l,lli r,lli val,lli who,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[who][v] += val;
        propagate(v,sl,sr,who);
        return;
    }
    lli m = (sl+sr)>>1;
    update(l,r,val,who,v<<1,sl,m);
    update(l,r,val,who,v<<1|1,m+1,sr);
    st[who][v] = st[who][v<<1]+st[who][v<<1|1];
}


lli query(lli l,lli r,lli who,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[who][v];
    lli m = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,m)+query(l,r,who,v<<1|1,m+1,sr);
}

void print(){
    for(lli i = 0;i<n;i++){
        cout<<query(i,i,0)<<" ";
    }
    cout<<endl;
    for(lli i = 0;i<n;i++){
        cout<<query(i,i,1)<<" ";
    }
    cout<<endl;
}
vector<lli> b[100007];
lli check(lli k,lli i,lli sz,bool reverse){ 
    lli total=0;
    for(lli j = 0;j<=k;j++){    
        total+=query(b[i][j],b[i][j],0);
        if(b[i][j])
            update(0,b[i][j]-1,-1,1);
        if(b[i][j]+1<n)
            update(b[i][j]+1,n-1,-1,0);
    }
    for(lli j = k+1;j<sz;j++){
        total+=query(b[i][j],b[i][j],1);
        if(b[i][j])
            update(0,b[i][j]-1,-1,1);
        if(b[i][j]+1<n)
            update(b[i][j]+1,n-1,-1,0);
    }
    if(!reverse)return total;
    for(lli j = 0;j<=k;j++){    
        if(b[i][j])
            update(0,b[i][j]-1,1,1);
        if(b[i][j]+1<n)
            update(b[i][j]+1,n-1,1,0);
    }
    for(lli j = k+1;j<sz;j++){
        if(b[i][j])
            update(0,b[i][j]-1,1,1);
        if(b[i][j]+1<n)
            update(b[i][j]+1,n-1,1,0);
    }
    return total;
}
int main(){
    lli t = 1;
    cin>>n;
    st[0].resize(4*n);
    lazy[0].resize(4*n);
    st[1].resize(4*n);
    lazy[1].resize(4*n);
    st[2].resize(4*n);
    lazy[2].resize(4*n);
    vector<lli> nums(n);
    for(lli i = 0;i<n;i++){
        cin>>nums[i];
        update(i,i,i,0);
        update(i,i,(n-1)-i,1);
        update(i,i,i,2);
        b[nums[i]].push_back(i);
    }
    print();
    // cout<<"HI"<<endl;
    lli ans = 0,mn,inf = 1e15,ans2 = 0;
    
    for(lli i = 1;i<=n;i++){
        mn = inf;
        if(b[i].size()>1){
            lli sz = b[i].size();
            lli l =0,r=sz-1;
            while(l<r) {
                lli mid = (l+r)>>1;
                if(check(mid,i,sz,true)>check(mid,i,sz,true)) 
                    r = mid;
                else 
                    l = mid+1;
            }
            
            if(check(l,i,sz,true)<check(r,i,sz,true)){
                mn = check(l,i,sz,false);
            }
            else 
                mn = check(r,i,sz,false);
            ans+=mn;
        }
        else if(b[i].size()==1){
            if(query(b[i][0],b[i][0],0)<query(b[i][0],b[i][0],1)){
                ans+=query(b[i][0],b[i][0],0);
            }
            else {
                ans+=query(b[i][0],b[i][0],1);
            }
            if(b[i][0])
                update(0,b[i][0]-1,-1,1);
            if(b[i][0]+1<n)
                update(b[i][0]+1,n-1,-1,0);
        }    
        
   
    }
     for(lli i = 1;i<=n;i++){
        mn = inf;
        if(b[i].size()>0){
            for(lli k =0;k<b[i].size();k++){
                ans2+= query(b[i][k],b[i][k],2);
                update(b[i][k]+1,n-1,-1,2);
            }
        } 
    }
    cout<<ans2<<" "<<ans<<endl;
    return 0;
}      
