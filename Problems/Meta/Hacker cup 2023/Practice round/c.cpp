#include <bits/stdc++.h>
using namespace std;

void print(int id,string s){
    cout<<"Case #"<<id<<": "<<s<<endl;
}

int main(){
    int T,n;
    cin>>T;
    int id = 1;
    while(T--){
        cin>>n;
        vector<int> a((2*n)-1);
        for(auto &c:a)cin>>c;
        if(n==1){
            cout<<"Case #"<<id<<": "<<1<<endl;
            id++;
            continue;
        }

        sort(a.begin(),a.end());
        int miss = 0;
        int ans1 = -1;
        int need = a[0]+a.back(); 
        for(int i = 1;i<n;i++){
            int r = ((2*n)-1)-i-1;
            if (ans1!=-1)r+=1;

            if(i == r){
                ans1 = need-a[i];
                if(ans1<=0)miss++;
            }
            else if(a[i]+a[r]!=need){
                miss++;
                if(ans1 ==-1){
                    ans1 = need-a[i]; 
                    miss--;
                }
            }
        }
        if(miss or ans1<=0)
            ans1 = 2e9+7;

        need = a[0]+a[a.size()-2];
        miss = 0;
        int ans2 = need-a.back();
        for(int i = 1;i<n-1;i++){
            int r = ((2*n)-3)-i;
            // cout<<i<<" "<<r<<endl;
            if(a[i]+a[n-i]!=need)miss++;
        }
        if(miss || ans2<=0)ans2 = 2e9+7;
        
        need = a[1]+a[a.size()-1];
        miss = 0;
        int ans3 = need-a[0];
        // cout<<endl;
        for(int i = 2;i<=n-1;i++){
            int r = ((2*n)-1)-i;
            // cout<<i<<" "<<r<<endl;
            if(a[i]+a[r]!=need)miss++;
        }
        if(miss || ans3<=0)ans3 = 2e9+7;

        if(ans1 == ans2 && ans2 == ans3  && ans1 == 2e9+7)
            cout<<"Case #"<<id<<": "<<"-1"<<endl;
        else
            cout<<"Case #"<<id<<": "<<min(ans1,min(ans2,ans3))<<endl;

        id++;
    }
    return 0;
}