#include <bits/stdc++.h>
using namespace std;
int main(){
    int q,n,k;
    cin>>q;
    while(q--){
        cin>>n>>k;
        vector<int> nums(n);
        for(int i = 0;i<n;i++)
            cin>>nums[i];
        vector<int> sol(k);
        int j = 0,counti = 0;
        for(int i = 0;i<n;i++)
            if(nums[i]&1)counti++;
        if(counti <k){cout<<"NO"<<endl;continue;}
        else{
            if((counti -k)&1)cout<<"NO"<<endl;
            else{
                for(int i = 0;i<n&&j<k-1;i++){
                    if(nums[i]&1){
                        while(nums[i+1]%2 == 0){
                            i++;
                        }
                        sol[j]=i;j++;
                    }
                }
                
                cout<<"YES"<<endl;
                for(int i = 0;i<k-1;i++)
                    cout<<sol[i]<<" ";

                cout<<n<<"\n";
            }
        }
    }
    return 0;
}