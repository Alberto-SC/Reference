#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,id = 1,c;
	cin>>t;
    while(t--){
        cin>>n>>c;
        int x = (n*(n+1))/2;
        x--;
        if(c>x){
            cout<<"Case #"<<id<<": "<<"IMPOSSIBLE"<<endl;
            id++;
            continue;
        }
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        vector<int> ans;
        bool flag = false;
        do {
            // for(auto c:nums)cout<<c<<" ";
            // cout<<endl;
            int cont = 0;
            vector<int> copy = nums;
            for(int i = 0;i<n-1;i++){
                int mn =n+1,idx;
                for(int j = i;j<n;j++){
                    if(copy[j]<mn){
                        idx = j;
                        mn = copy[j];
                    }
                }
                reverse(copy.begin()+i,copy.begin()+idx+1);
                cont+= (idx-i)+1;
            }
            ans.push_back(cont);
            // cout<<cont<<endl;
            if(cont == c){
            
                flag = true;
                break;
            }
            // cout<<cont<<endl;
        }while(next_permutation(nums.begin(),nums.end()));
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
        if(flag){
            cout<<"Case #"<<id<<": ";
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
            id++;

        }
        else{
            cout<<"Case #"<<id<<": "<<"IMPOSSIBLE"<<endl;
            id++;
        }
    }
    return 0;
}  
