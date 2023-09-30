#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';
int n;
int A[32][100007];

int query(int l,int r,int bit){
    if(l-1<0)
        return A[bit][r];
    return A[bit][r]-A[bit][l-1];
}

int find_first_one(int i,int bit){
    int l = i,r = n;
    int val = query(0,i,bit);
    while(l+1<r){
        int m =(l+r)>>1;
        if(query(0,m,bit)==val)
            l = m;
        else 
            r = m;
    }
    // cout<<i<<" "<<bit<<" "<<r<<endl;
    return r;
}

void print(){
    for(int j = 0;j<n;j++)
        for(int i = 6;i>=0;i--)
            cout<<query(j,j,i)<<" \n"[i ==0];
    cout<<endl;
}

int main(){__
    int t,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<32;i++){
            for(int j = 0;j<n;j++){
                if(j==0  && (nums[j]>>i) &1)A[i][j] = 1;
                else if(j && (nums[j]>>i)&1)A[i][j] =1+A[i][j-1];
                else if(j) A[i][j] = A[i] [j-1];
            }
        }
        // print();
        for(int j = 0;j<n-1;j++){
            if(x==0)break;
            for(int i = 31;i>=0;i--){
                if(x==0)break;
                if((nums[j]>>i)&1){
                    int idx= find_first_one(j,i);
                    if(idx ==n)idx--;
                    nums[idx] ^= (1<<i);
                    nums[j] ^= (1<<i);
                    x--;
                }
            }
        }
        if(n == 2 && x&1){
            nums[n-1]^=1;
            nums[n-2]^=1;
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
        }
        else{
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}