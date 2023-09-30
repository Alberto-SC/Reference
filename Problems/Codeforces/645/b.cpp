#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int cont = 1;
        int j = 0;
        for(int i = 0;i<n;i= j){
            j = i;
            if(cont>=nums[i]){
                while(j<n && cont>=nums[j]){
                    j++;
                    cont++;
                }
            }
            else {
                int aux = cont;
                while(j<n&& nums[j]>aux){
                    j++;
                    aux++;
                }
                // cout<<aux<<endl;
                if(j == n && aux-1>=nums[j-1])cont = aux;
                else if(j<n && nums[j]<=aux)cont= aux;
            }
            if(j == i)j++;
        }
        cout<<cont<<endl;
    }
    return 0;
}