#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;
    int totaltime;
    vector<int> testers(k);;
    vector<bool>free(k,true);
    vector<int> testN(k,0);
    for(int i = 0;i<k;i++)testers[i] = i;
    int d =0;
    int next = k,completed = 0,ans = 0, j = 0;
    totaltime = accumulate(nums.begin(), nums.end(), 0); 
    while(completed<= n){
        if(completed == n)break;
        for(int i = 0;i<k;i++){
            if(nums[testers[i]] <= 0 && free[i]== true){
                cout<<"ENTRO"<<endl;
                if(completed == n)continue;
                completed++;
                d = trunc((100*(completed/(n*1.0)))+0.5);
                if(next == n)next = 0,free[i]=false;
                testers[i] = next;
                next++;
                testN[i] = 0;
            }
            else{

                nums[testers[i]]--;
                testN[i]++;
                for(auto c : testN)cout<<c<<" ";
                cout<<endl;
                for(auto c: free)cout<<c<<" ";
                cout<<endl;
                for(auto c: nums)cout<<c<<" ";
                cout<<endl;
                if(testN[i] == d && free[i] == true){cout<<"HERE   "<<i<<"  "<<testers[i]<<"  "<<testN[i]<<endl;ans++;}
            }  
        }
        cout<<"D = "<<d<<endl;
        // cout<<completed<<endl;
    }
    cout<<ans<<endl;
    return 0;
}