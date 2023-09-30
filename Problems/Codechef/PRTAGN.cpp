#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,q;
    cin>>t;
    while(t--){
        cin>>q;
        int x,E = 0,O = 0,ones;
        set<int> s;
        for(int i = 0;i<q;i++){
            cin>>x;
            ones = 0;
            if(s.find(x)!= s.end()){ones = __builtin_popcount(x);s.insert(x);kkmm mnn }
            if(ones&1)E++;
            else O++;
            int size = s.size(),j = 0;
            for(auto a:s){
                j++; 
                int val = a^x;
                cout<<"    "<<a<<endl;
                if(s.find(val)!= s.end()){
                    if(__builtin_popcount(val)&1)E++;
                    else O++;
                    s.insert(val);
                }
                if(j ==size)break;
            }
            cout<<E<<" "<<s.size()-E<<endl;
            
        }
    }
    return 0;
}