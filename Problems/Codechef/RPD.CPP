#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int nums[n];
        for(int i = 0;i<n;i++)
            cin>>nums[i];
        int mx = -1000;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int sum = 0; 
                if(i!=j){
                    int mul = nums[i]*nums[j];
                    while(mul){
                        sum+=mul%10;
                        mul/=10;
                    }
                    mx = max(sum,mx);
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}