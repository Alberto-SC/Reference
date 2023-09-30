#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int count_inversions(vector<int> a){
    int cont = 0,n =a.size();
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[j]<a[i])cont++;
        }
    }
    return cont;
}

int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(int i = 0;i<k;i++){
            nums[i] = i+1;
        }
        for(int i = k;i<n;i++){
            nums[i] = nums[i-1]-1;
        }
        vector<int> p(k);
        iota(p.begin(),p.end(),1);
        vector<int> ans(n,0);
        vector<int> pans(k);
        int inva = count_inversions(nums);
        // cout<<inva<<endl;
        do {
            vector<int> b(n);
            for(int i = 0;i<n;i++){
                b[i] = p[nums[i]-1];
            }
            // for(auto c:p)cout<<c<<" ";
            // cout<<endl;
            // for(auto c:b)cout<<c<<" ";
            // cout<<endl;
            int invb  = count_inversions(b);
            // cout<<invb<<endl;
            if(invb<=inva){
                ans = min(ans,b);
                pans = p;
            }
        }while(next_permutation(p.begin(),p.end()));
        for(auto c:pans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

