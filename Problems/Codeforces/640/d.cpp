#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int l = 1,r = n-1,lastl = nums[0],lastr = 0,a = lastl,b = 0,cont = 0;
        bool turn = 1;
        while(l<=r){
            cont++;
            // cout<<l<<" "<<r<<" "<<lastl<<" "<<lastr<<endl;
            if(turn){
                lastr =0;
                while(lastr<=lastl && r>=l){
                    lastr+=nums[r]; 
                    r--;
                }
                if(l > r){b+=lastr;break;}
                b+=lastr;
            } 
            else{
                lastl = 0;
                while(lastl<=lastr && l<=r){
                    lastl+=nums[l];
                    l++;
                }
                if(l > r){a+= lastl;break;}
                a+=lastl;
            }
            turn = !turn;
        }
        cout<<cont+1<<" "<<a<<" "<<b<<endl;
    }
    return 0;
}