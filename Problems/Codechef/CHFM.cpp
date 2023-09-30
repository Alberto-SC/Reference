#include <bits/stdc++.h>
using namespace std;
    

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long sum = 0,ai;
        vector<pair<int,int>> nums(n);
        for(int i = 0;i<n;i++){
            cin>>ai;
            nums[i] = {ai,i+1};
            sum+=ai;
        }
        double mean = (sum*1.0)/n;
        double absolute = abs(mean);
        if(absolute != floor(absolute))cout<<"Impossible\n";
        else{
            sort(nums.begin(),nums.end());
            int l = 0,r = n-1,mid,search = sum-((n-1)*mean);
            while (r>l) {
                int mid = l + ((r-l)/2);
                if (nums[mid].first >= search)r = mid;   
                else 
                    l= mid+1; 
            }
            if(nums[r].first==search)cout<<nums[r].second<<"\n";
            else cout<<"Impossible\n";
        }
    } 
    return 0;
    
}