#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int m = n/2;
        m--;
        while(nums[m]==nums[n/2]){
            m--;
        }
        vector<int> diffs;
        for(int i = 0;i<=m;){
            int j = i;
            if(nums[i]== nums[j]){
                while(nums[j]== nums[i])
                    j++;
            }
            diffs.push_back(j-i);
            i = j;
        }   
        // for(auto c:diffs)cout<<c<<" ";
        // cout<<endl;
        int a =0,b = 0,c= 0 ;
        if(diffs.size()<3){

            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else{
            a = diffs[0];
            int total = accumulate(diffs.begin(),diffs.end(),-a);
            b = 0;
            bool flag = false;
            for(int i = 1;i<diffs.size();i++){
                // cout<<b<<" "<<total-b<<endl;
                if(b>a && total-b >a){
                    flag = true;
                    break;
                }
                b+=diffs[i];
            }
            if(!flag)cout<<"0 0 0"<<endl;
            else{
                c = total-b;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }
    return 0;
}  

