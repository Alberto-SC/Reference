#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 

signed main(){
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        set<int> bads;
        int b1,g1;
        vector<int> ans(n);
        for(int i = 1;i<=n-2;i++){
            cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<endl;
            cin>>ans[i];
        }
        int res;
        for(int i = 1;i<=n-2;i++){
            if(i>=2 && ans[i]== 0 && ans[i-1]== 1){
                g1 = i-1,
                cout<<"? "<<i<<" "<<i+1<<" "<<i-1<<endl;
                cin>>res;
                if(res==0){
                    b1 = i;
                    bads.insert(i);
                    bads.insert(i+1);
                    break;
                }
                cout<<"? "<<i<<" "<<i+2<<" "<<i-1<<endl;
                cin>>res;
                if(res==0){
                    b1 = i;
                    bads.insert(i);
                    bads.insert(i+2);
                    break;
                }
                cout<<"? "<<i+1<<" "<<i+2<<" "<<i-1<<endl;
                cin>>res;
                if(res==0){
                    b1 = i+1;
                    bads.insert(i+1);
                    bads.insert(i+2);
                    break;
                }
            }
            else if((i<n-2) && ans[i]==0 && ans[i+1]==1){
                g1 = i+3,
                cout<<"? "<<i<<" "<<i+1<<" "<<i+3<<endl;
                cin>>res;
                if(res==0){
                    b1 = i;
                    bads.insert(i);
                    bads.insert(i+1);
                    break;
                }
                cout<<"? "<<i<<" "<<i+2<<" "<<i+3<<endl;
                cin>>res;
                if(res==0){
                    b1 = i;
                    bads.insert(i);
                    bads.insert(i+2);
                    break;
                }
                cout<<"? "<<i+1<<" "<<i+2<<" "<<i+3<<endl;
                cin>>res;
                if(res==0){
                    b1 = i+1;
                    bads.insert(i+1);
                    bads.insert(i+2);
                    break;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            if(!bads.count(i)&& i !=g1){
                cout<<"? "<<b1<<" "<<g1<<" "<<i<<endl;
                cin>>res;
                if(!res)
                    bads.insert(i);
            }
        }
        cout<<"! ";
        cout<<bads.size()<<" ";
        for(auto c:bads)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

// 1 1 1 0 0 0 
// 0 1 1 1 0 1 0 1 0


// 0 1 1 0 1 1 0 0 0
// 1 2 3 4 5 6 7 8 9
// 1 1 1   ->1
// 1 1   1 ->0
// 1   1 1 ->0
//   1 1 1 ->1

// 0 0 0 0 0 0 0 0 0 1 
// 1 1 1 1 1 1 1 0 0 0 

// 1 1 0 1 1 0 1 1 0 0 1 0
// 1 0 0 1 0 0 1 0 0 1 0 1 

// ^                 ^ ^   -> 1 
// ^                 ^   ^ -> 1
// ^                   ^ ^ -> 1

// ^                 ^ ^   -> 0 
// ^                 ^   ^ -> 1
// ^                   ^ ^ -> 0
