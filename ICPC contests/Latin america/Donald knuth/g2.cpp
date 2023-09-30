#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    vector<string> nums(n);
    for(auto &c:nums)cin>>c;
    bool flag = false;
    vector<string> e[10];
    vector<string> e2[10];
    for(int i = 0;i<10;i++)e2[i] = vector<string> (0);
    for(int i = 0;i<n;i++){
        sort(nums[i].rbegin(),nums[i].rend());
        if(nums[i][0]== nums[i].back())
            e[nums[i][0]-'0'].push_back(nums[i]);
        else {
            e2[nums[i][0]-'0'].push_back(nums[i]);
        }
    }
    for(auto c:nums)cout<<c<<endl;
    cout<<endl;
    // cout<<"HI"<<endl;
    for(int i = 1;i<10;i++)
        sort(e2[i].rbegin(),e2[i].rend());
    for(int i = 9;i>0;i--){
        for(int j = 0;j<(int)e[i].size();j++){
            cout<<e[i][j];
        }
        for(int j = 0;j<(int)e2[i].size();j++){
            if(j+1<(int)e2[i].size()){
                if(e2[i][j+1].size()<e2[i][j+1])
            }
            cout<<e2[i][j];
        }
    }    
    cout<<endl;

    return 0;
}