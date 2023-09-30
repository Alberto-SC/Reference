#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli DP[60][2][60];
lli n,k,a,b;
vector<int> Num;
vector<lli> nums;
lli bc[60][60];

void binomial_Coeff(int n = 51,int m = 51){ 
	int i,j;
	for (i=0; i<=n; i++) bc[i][0] = 1;
	for (j=0; j<=n; j++) bc[j][j] = 1;
	for (i=1; i<=n; i++)
	    for (j=1; j<i; j++)
	        bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
}
lli go(int pos,int f,int c){
    // cout<<"POS "<<pos<<" "<<c<<" "<<f<<endl;
    if(pos == Num.size()){
        if(c == k)
            return 1;
        return 0;
    }

    lli &x = DP[pos][f][c];
    if(x!= -1)return x;
    lli res = 0;
    if(!f){
        if(Num[pos]== 0)
            res +=go(pos+1,0,c);
        else {
            res +=go(pos+1,0,c+1);
            res +=go(pos+1,1,c);
        }
    }
    else
        res = go(pos+1,1,c+1)+go(pos+1,1,c);
    
        // res = bc[Num.size()-pos][k-c];
    
    return x = res;
}

lli solve(lli x){
    Num.clear();
    while(x){
        Num.push_back(x%2);
        x/=2;
    }
    memset(DP,-1,sizeof(DP));
    reverse(Num.begin(),Num.end());
    return go(0,0,0);
}

bool check(lli m,lli limit){
    lli sum = 0;
    lli mx = LLONG_MAX;
    for(int i = 0;i<n;i++){
        if((m>>i) & 1)
        if(nums[i]>(mx-sum))return false;
        else
            sum+=nums[i];
    }
    return sum<=limit;
}
lli get_mask(lli limit){
    lli l = 0,r = (1ll<<n);
    while(l+1<r){
        lli m = (l+r)>>1;
        if(check(m,limit))
            l = m;
        else r = m;
    }
    return r-1;
}
int main(){
    cin>>n>>k;
    nums.resize(n);
    binomial_Coeff();
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end());
    cin>>a>>b;
    cout<<solve(get_mask(b))-solve(get_mask(a-1))<<endl;
    return 0;
}