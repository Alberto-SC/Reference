#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,d,lane;   
    cin>>t;
    while(t--){
        cin>>n>>k>>d;
        vector<int> nums(n);
        vector<int> lane1;
        vector<int> lane2;
        for(int i = 0;i<n;i++)
            cin>>nums[i];
        for(int i = 0;i<n;i++){
            cin>>lane;
            if(lane == 1)lane1.push_back(nums[i]);
            else if(lane == 2) lane2.push_back(nums[i]);
        }
        bool clane = 1,cont = true;
        int i =0,j = 0,pos  = 0;
        if(lane1[i]>lane2[j])clane = 1;
        else clane  =0;
        if(lane1[i]+1 == lane2[j]|| lane2[j]+1 == lane1[i])cout<<max(lane1[0],lane2[0])<<endl;
        else {
            // cout<<"fjid"<<endl;
            while(pos<k && j<lane2.size() && i< lane1.size()){
                if(clane){
                    while(lane2[j]<lane1[i]){j++;}
                    if(j== lane2.size())pos = k;
                    else if(lane2[j]-(d+2)>lane2[j-1] &&lane2[j-1]+1!= lane1[i]){pos= lane2[j]-1;clane = !clane;}
                    else {pos = lane2[j];break;}
                }
                else {
                    while(lane1[i]<lane2[j]){i++;}
                    if(i == lane1.size())pos =k;
                    else if(lane1[i]-(d+2)>lane1[i-1] &&lane1[i-1]+1!= lane2[j]){pos= lane1[i]-1;clane = !clane;}
                    else {pos = lane1[j];break;}
                }
            }   
            if(pos>k)cout<<k<<endl;
            else cout<<pos<<endl;
        }
    }
    return 0;
}