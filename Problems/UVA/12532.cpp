#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100007;
vector<int> st(4*MAXN);


void build(vector<int> &A,int v,int SL,int SR){
    if(SL == SR)
        st[v] = A[SL];
    else{
        int SM = (SL+SR)/2;
        build(A,v*2,SL,SM);
        build(A,v*2+1,SM+1,SR);
        st[v]= st[v*2]*st[v*2+1];
    }
} 
int query(int v, int SL,int SR,int l,int r){
    if(l>r)
        return 1;
    if(SL == l && SR == r)
        return st[v];
    int SM = (SL + SR) / 2;
    return query(v*2,SL,SM,l,min(SM,r)) * query(v*2+1,SM+1,SR,max(l,SM+1),r);
}
void update(int v,int SL,int SR,int pos,char new_v){
    if(SL == SR)
        st[v]=new_v;
     else{
        int SM = (SL+SR)/2;
        if(pos<=SM)
            update(v*2,SL,SM,pos,new_v);
        else
            update(v*2+1,SM+1,SR,pos,new_v);
        st[v] = st[v*2]*st[v*2+1]; 
    }
        
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n,q,pos,val,ai,l,r;
    char c;
    vector<int> nums;
    while(cin>>n>>q){
        nums.resize(n);
	    for(int i = 0;i<n;i++){
            cin >> ai;
            if(ai<0)ai=-1;
            else if(ai == 0)ai=0;
            else if(ai>0)ai=1;
            nums[i]=ai;
        } 
        build(nums,1,0,n-1);
        for(int i = 0;i<q;i++){
            cin>>c;
            if(c == 'C'){
                cin>>pos>>val;
                if(val<0)val=-1;
                else if(val == 0)val=0;
                else if(val>0)val=1;
                update(1,0,n-1,--pos,val);
            }
            if(c == 'P'){
                cin>>l>>r;
                int ans =query(1,0,n-1,--l,--r);
                if(ans<0)cout<<'-';
                else if(ans == 0)cout<<'0';
                else if(ans>0)cout<<'+';
            }
        }
        cout<<"\n";
    }
    return 0;
}