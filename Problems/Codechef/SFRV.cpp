#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<pair<int,int>> copy(n);
        int sump = 0,sumi = 0;
        for(int i = 1;i<=n;i++){
            cin>>nums[i-1];
            copy[i-1] ={nums[i-1],i};
            sump += nums[i-1]*i;
        }
        sort(copy.begin(),copy.end(),comp);
        for(int i = 0;i<n;i++)
            sumi += copy[i].first*(i+1);
        for(int i = 0;i<n;i++){
            if(copy[i].second == i+1||copy[i].second == i-1 && copy[i+1].second == copy[i].second-1)continue;
            if(i+1<copy[i].second-1){
                int sumar = copy[i].first*(copy[i].second)-(copy[i].first*(i+1));
                sumi+= sumar;
            }
            else if(i-1>copy[i].second){
                int restar = (copy[i].first*(i+1))-copy[i].first*(copy[i].second);
                sumi-=restar;
            }
        }
        cout<<sumi<<endl;
    }
    return 0;
}