#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> lI(n),rI(n),lD(n),rD(n);
        for(int i = 0;i<n;i++){
            if(i){
                if(nums[i]<nums[i-1])rD[i] = rD[i-1]+1,rI[i] = 0;
                else rD[i] = 0,rI[i] = rI[i-1]+1;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(i<n-1){
                if(nums[i]<nums[i+1])lI[i] = lI[i+1]+1,lD[i] = 0;
                else lI[i] = 0,lD[i] = lD[i+1]+1;
            }
        }
        vector<int> mxRDS(n);
        vector<int> mxLIS(n);
        vector<int> mxRDP(n);
        vector<int> mxLIP(n);
        mxRDS[n-1] = rD[n-1]; 
        mxLIS[n-1] = lI[n-1]; 
        mxRDP[0] = rD[0]; 
        mxLIP[0] = lI[0]; 
        for(int i = n-2;i>=0;i--){
            mxRDS[i] = max(rD[i],mxRDS[i+1]);
            mxLIS[i] = max(lI[i],mxLIS[i+1]);
        }
        for(int i = 1;i<n;i++){
            mxRDP[i] = max(mxRDP[i-1],rD[i]);
            mxLIP[i] = max(mxLIP[i-1],lI[i]);
        }
        int cont = 0;
        for(int i = 0;i<n;i++){ 
            if(lD[i]%2 ==0 && rI[i]%2==0)continue;
            if(lD[i]&1 && rI[i]%2 == 0){
                cout<<"I: 1 0 " <<i<<endl;
                int l = (i-rI[i])-1,r = i+1,mxl,mxr;
                cout<<l<<" "<<r<<endl;
                if(l<0)mxl = 0;
                else mxl = max(mxLIP[l],mxRDP[l]);
                if(r>=n)mxr = 0;
                else mxr = max(mxRDS[i+1],mxLIS[i+1]);
                cout<<mxl<<" "<<mxr<<endl;
                if(mxl>=lD[i]|| mxr>=lD[i])continue;
            }
            if(lD[i]%2 ==0 && rI[i]&1){
                cout<<"I: 0 1 "<<i<<endl;
                int l = i-1,r = i+rI[i]+1,mxl,mxr;
                cout<<l<<" "<<r<<endl;
                if(l<0)mxl = 0;
                else mxl = max(mxLIP[l],mxRDP[l]);
                if(r>=n)mxr = 0;
                else mxr = max(mxRDS[r],mxLIS[r]);
                cout<<mxl<<" "<<mxr<<endl;
                if(mxl>=lD[i]|| mxr>=lD[i])continue;
            }
            if(lD[i]&1 && rI[i]&1){
                cout<<"I: 1 1 "<<i<<endl;
                int l = (i-rI[i])-1,r =i+rI[i]+1,mxl,mxr;
                if(l<0)mxl = 0;
                else mxl = max(mxLIP[l],mxRDP[l]);
                if(r>=n)mxr = 0;
                else mxr = max(mxRDS[r],mxLIS[r]);
                cout<<l<<" "<<r<<endl;
                cout<<mxl<<" "<<mxr<<endl;
                if(mxl>=lD[i]|| mxr>=lD[i])continue;
            }
            cout<<"I: "<<i<<endl;
            cont++;
        }
        cout<<cont<<endl;
        for(auto c:lI)cout<<c<<" ";
        cout<<endl;
        for(auto c:lD)cout<<c<<" ";
        cout<<endl;
        for(auto c:rI)cout<<c<<" ";
        cout<<endl;
        for(auto c:rD)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
