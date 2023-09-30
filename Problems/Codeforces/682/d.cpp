#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        lli sum = 0;
        lli total = 0;
        for(auto &c:nums)cin>>c,sum +=c,total^=c;
        if(sum/n == nums[0] && sum%n ==0 )return cout<<"YES"<<endl<<0<<endl,0;
        if(n&1){
            cout<<"YES"<<endl;
            cout<<((n-1)/2)+((n-3)/2) <<endl;
            for(int i = 1;i<=n-2;i+=2)
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
            
            for(int i = n-3;i>0;i-=2)
                cout<<i-1<<" "<<i<<" "<<i+1<<endl;
            
        }
        else{
            map<int,vector<int>> mp;
            for(int i = 0;i<n;i++)
                mp[nums[i]].push_back(i+1);
            
            vector<int> indices;
            vector<pair<int,int>> dobles;
            for(auto c:mp){
                for(int i = 0;i<c.second.size();i+=2){
                    if(i+1<c.second.size())
                        dobles.push_back({c.second[i],c.second[i+1]});
                }
                if(c.second.size()&1)
                    indices.push_back(c.second.back());
            }

            if(indices.size()&& total!= 0)
                return cout<<"NO"<<endl,0;
            else if(indices.size() && total==0){
                n--;
                cout<<"YES"<<endl;
                cout<<((n-1)/2)+((n-3)/2) <<endl;
                for(int i = 1;i<=n-2;i+=2)
                    cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                
                for(int i = n-3;i>0;i-=2)
                    cout<<i-1<<" "<<i<<" "<<i+1<<endl;
                return 0;
            }
            cout<<"YES"<<endl;
            cout<<dobles.size()-1<<endl;
            for(int i= 1;i<dobles.size();i++){
                cout<<dobles[i].first<<" "<<dobles[i].second<<" "<<dobles[0].first<<endl;
            }            
        }

    }
    return 0;
}  

