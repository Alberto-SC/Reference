#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int c,n,m;
    cin>>c>>n>>m;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<lli> days(51);
    for(int i = 0;i<n;i++){
        int j = 0;
        lli cows = nums[i];
        while(cows<=c && j<=50){
            days[j] +=1;
            cows*=2;
            j++;
        }
        // cout<<"j: "<<j<<" "<<days[j-1]<<endl;
        lli aux = 2;
        for(j;j<=50;j++)
            days[j] += aux,aux*=2;
        
    }
    int day;
    for(int i = 0;i<m;i++){
        cin>>day;
        cout<<days[day]<<endl;
    }
    return 0;
}