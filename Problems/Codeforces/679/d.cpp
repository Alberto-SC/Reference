#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t = 1,n,x,idx = 0;
    cin>>n;
    char c;
    int m = 0;
    vector<int> nums(2*n,-1);
    bool flag = true;
    for(int i = 0;i<2*n;i++){
        cin>>c;
        if(c =='-'){
            cin>>nums[i];
        }
    }
    stack<int> ans,s;
    for(int i = 2*n-1;i>=0;i--){
        if(nums[i]== -1){
            if(s.empty())return cout<<"NO"<<endl,0;
            else    
                ans.push(s.top());
                s.pop();
        }
        else{
            if(!s.empty() && nums[i]>s.top())
                return cout<<"NO"<<endl,0;
            s.push(nums[i]);
        }
    }
    cout<<"YES"<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
    return 0;
}

