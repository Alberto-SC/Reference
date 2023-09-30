#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ai;
    cin>>n>>m;
    int mx = -1000;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>ai;
        mx = max(mx,ai);
        nums[i] = ai;
    }
    int igualar = 0;
    for(int i = 0;i<n;i++)
        igualar+=mx-nums[i];
    
    if(igualar>m)cout<<mx<<" "<<mx+m<<endl;
    else {
        int more = ceil((m-igualar)/(n*1.0));
        cout<<mx+more<<" "<<mx+m<<endl;
    }
    
    return 0;
}