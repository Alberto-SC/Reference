#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n,m,d,x;
    cin>>n>>m>>d;
    vector<pair<int,int>> nums(n);
    vector<int>numsc(n);
    for(int i = 0;i<n;i++){
        cin>>x;
        nums[i] ={x,i};
        numsc[i] = x;
    }
    sort(nums.begin(),nums.end());
    sort(numsc.begin(),numsc.end());
    int day = 1,start;
    vector<bool>used(n,false);
    vector<int>ans(n);
    int nc = n;
    int lastselect = 0;
    while(n){
        for(int i = lastselect;i<nc;i++){if(used[i]==false){start=numsc[i];break;}lastselect = i+1;}
        int offset=0;
        while(true){
            vector<int>::iterator search = lower_bound(numsc.begin()+offset,numsc.end(),start);
            if(search == numsc.end())break;
            int index = search-numsc.begin();
            if(used[index]==false){
                used[index] = true;
                ans[nums[index].second] = day;
                start = numsc[index]+d+1;
                n--;
            }
            else offset=index+1;
        }
        day++;
    }
    cout<<day-1<<endl;
    for(int c:ans)cout<<c<<" ";
    return 0;
    cout<<endl;
}