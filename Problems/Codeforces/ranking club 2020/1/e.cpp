#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
typedef long long int lli;
vector<int> bit;
int n2;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < n2; idx += idx & -idx) bit[idx] += delta;
}

int main(){
    int t,n,ai;
    cin>>n;    
    vector<int> nums(n);
    map<int,int> m;
    int key = 0;
    for(int i = 0;i<n;i++){
        cin>>ai;
        if(m.find(ai)== m.end())
            m[ai] = key++;
        nums[i] = m[ai];
    }
    vector<int> b(n);
    vector<int> vi(n);
    vector<int> vj(n);
    for(int i = 0;i<n;i++){ 
        b[nums[i]]++;
        vi[i] = b[nums[i]];
    }
    b.assign(n,0);
    for(int i = n-1;i>=0;i--){
        b[nums[i]]++;
        vj[i] = b[nums[i]];
    }
    bit.resize(*max_element(vj.begin(),vj.end())+1);
    for(int i = 0;i<bit.size();i++){add(i,0);}
    n2 =bit.size();
    // print(vi)
    // print(vj)
    // print(bit);
    lli ans = 0;
    for(int i = n-1;i>=0;i--){
        // ans+= (lli)sum(1,vi[i]);  
        if(vi[i]>1)      
            ans+=(lli)sum(vi[i]-2);
        add(vj[i]-1,1);
        // print(bit);
    }

    cout<<ans<<endl;
    return 0;
}