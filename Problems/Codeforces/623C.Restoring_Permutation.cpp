#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>t;
    while(t--){

        cin>>n;
        vector<int> nums(n);
        vector<int> a(2*n);
        vector<bool> b((2*n)+1);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            a[(i*2)] = nums[i];
            b[nums[i]] = true;
        }

        set<int> m;    
        for(int i = 1;i<=2*n;i++)
            if(!b[i])m.insert(i);
        bool is_possible = true;
        for(int i = 1;i<2*n;i+=2){
            auto next = m.lower_bound(a[i-1]);
            if(next== m.end()){is_possible = false;break;}
            a[i] = *next;
            m.erase(next);
        }
        if(is_possible)
            for(auto c:a)cout<<c<<" ";
        else
            cout<<-1;
        cout<<endl;
    }
    return 0;
}