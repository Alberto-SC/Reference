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
        priority_queue<lli> p;
        for(int i = 0;i<n;i++){
            p.push(nums[i]);
        }
        bool turn = false;
        lli sa = 0 ,sb = 0;
        while(!p.empty()){
            if(!turn){
                if(p.top()%2== 0)
                    sa+=p.top();

            }
            else{
                if(p.top()&1)
                    sb+=p.top();
            }
            p.pop();
            turn = !turn;
        }
        if(sa>sb)cout<<"Alice"<<endl;
        else if(sa<sb)cout<<"Bob"<<endl;
        else cout<<"Tie"<<endl;
    }
    return 0;
}  

