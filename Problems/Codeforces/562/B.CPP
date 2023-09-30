#include <bits/stdc++.h>
using namespace std;
bool comp (pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<pair<int,int>> nums(m);
    for(int i = 0;i<m;i++){
        cin>>a>>b;
        nums[i] = {a,b};
    }
    vector<int> values= {nums[0].first,nums[0].second};
    for(auto x:values){
        vector <int> val(n+1,0);
        int count = 0;
        for(auto c:nums){
            if(c.first != x&& c.second!= x){
                val[c.first]++;
                val[c.second]++;
                count++;  
            }

        }
        if(*max_element(val.begin(),val.end()) == count)
        return cout<<"YES",0;
    }
    cout<<"NO"<<endl;
    return 0;
}