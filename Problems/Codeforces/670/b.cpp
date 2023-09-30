#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        vector<pair<lli,lli>> nabs(n);
        vector<lli> sign(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            if(nums[i]<0)
                nabs[i].second= 2;
            else nabs[i].second = 1;
            nabs[i].first = abs(nums[i]);
        }
        sort(nabs.rbegin(),nabs.rend());
        int cont = 0;
        lli ans = 1;
        lli mx =-1000000000000000000;
        for(int i = 0;i<=5;i++){
            ans = 1;
            cont = 0;
            if(!(i&1)){
                for(int j = 0;j<n&& cont<i;j++){
                    if(nabs[j].second== 2){
                        ans*= nabs[j].first;
                        ans*=-1;
                        cont++;
                    }
                }
                for(int j = 0;j<n && cont <5;j++){
                    if(nabs[j].second == 1){
                        ans*=nabs[j].first;
                        cont++;
                    }
                }
                if(cont == 5)
                    mx = max(mx,ans);
            }
            else {
                for(int j = n-1;j>=0&& cont<i;j--){
                    if(nabs[j].second== 2){
                        ans*= nabs[j].first;
                        ans*= -1;
                        cont++;
                    }
                }
                for(int j = n-1;j>=0 && cont<5;j--){
                    if(nabs[j].second == 1){
                        ans*=nabs[j].first;
                        cont++;
                    }
                }
                if(cont == 5)
                    mx = max(mx,ans);
            }
        }
        cout<<mx<<endl;

    }
    return 0;
}