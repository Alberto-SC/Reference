#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
int total,k;
vector<pair<int,int>>nums;
bool check(int m){
    int sum = 0;
    for(int i = 0;i<m;i++){
        sum+=nums[i].x;
    }
    return (int)((double(sum)/total)*100)>=k;
}

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}
int main(){
	int t= 1,n;
    cin>>n>>k;
    nums.resize(n);
    vector<int> copy(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i].x;
        copy[i] = nums[i].x;
        nums[i].y = i;
        total+=nums[i].x;
    }
    sort(nums.rbegin(),nums.rend());
    int l = 0,r = n+1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(check(m))
            r = m;
        else 
            l = m;
    }
    string mask(n,'0');
    for(int i = 0;i<r;i++)
        mask[i] = '1';
    sort(mask.begin(),mask.end());
    vector<vector<int>> ans;
    do{
        int sum = 0;
        vector<int> res;
        int val = 0;
        for(int i = 0;i<n;i++){
            if(mask[i]== '1')sum+=copy[i],res.push_back(i+1),val+=bin_pow(2,i);
        }
        if((int)((double(sum)/total)*100)>=k){
            res.push_back(1000000000+(int)((double(sum)/total)*100));
            res.push_back(val);
            ans.push_back(res);

        }
        
    }while(next_permutation(mask.begin(),mask.end()));
    sort(ans.begin(),ans.end(),[&](vector<int>A,vector<int>B){
        return A.back()<B.back();
    });
    cout<<r<<" "<<ans.size()<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i][r]-1000000000<<" ";
        for(int j = 0;j<r;j++){
            cout<<ans[i][j];
            if(j<r-1)cout<<" ";

        }
        cout<<endl;
    }
    return 0;  

}  

