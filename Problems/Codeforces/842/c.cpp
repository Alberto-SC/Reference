#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums){
            cin>>c;
        }
        if(n == 1){
            cout<<"YES"<<endl;
            cout<<1<<endl<<1<<endl;
            continue;
        }
        vector<pair<int,int>> pos(n+1,{-1,-1});

        for(int i = 0;i<n;i++){
            if(pos[nums[i]].first == -1){
                pos[nums[i]].first = i;
            }
            else pos[nums[i]].second = i;
        }

        vector<int> a(n);
        vector<int> b(n);

        vector<int> valid;
        bool flag = true;
        for(int i= n;i>=1;i--){
            if(pos[i].first ==-1){
                if(valid.size()==0){
                    flag = false;
                    break;
                }
                int idx = valid.back();
                if(a[idx]==0)a[idx] = i;
                else b[idx] = i;
                valid.pop_back();

                if(valid.size()==0){
                    flag = false;
                    break;
                }
                idx = valid.back();
                if(a[idx]==0)a[idx] = i;
                else b[idx] = i;
                valid.pop_back();

                continue;
            }
            valid.push_back(pos[i].first);
            a[pos[i].first] = i;
            if(pos[i].second!=-1){
                b[pos[i].second] = i;
                valid.push_back(pos[i].second);
            }
            else{
                if(valid.size()==0){
                    flag = false;
                    break;
                }
                int idx = valid.back();
                if(a[idx]==0)a[idx] = i;
                else b[idx] = i;
                valid.pop_back();
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(auto c:a)cout<<c<<" ";
            cout<<endl;
            for(auto c:b)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}