#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	int t= 1,n,m,ans;
    cin>>m>>n;
    vector<int> nums(n);
    int inf = m;
    for(int i = 0;i<n;i++){
        cout<<inf<<endl;
        fflush(stdout);
        cin>>ans;
        if(ans == 0)return 0;
        if(ans==-1)
            nums[i] = 1;
        else 
            nums[i] = 0;
    }
    int cont = 60-n;
    int l = 1,r = m;
    int idx = 0;
    while(cont--){
        int m = (l+r)>>1;
        cout<<m<<endl;
        fflush(stdout);
        cin>>ans;
        if(ans == 0)break;
        if(ans==-1 && nums[idx%n]==0){
            l = m+1;
        }
        else if(ans==-1 && nums[idx%n]== 1){
            r = m-1;
        }
        else if(ans ==1 && nums[idx%n]== 0){
            r = m-1;
        }
        else if(ans ==1 && nums[idx%n]== 1){
            l = m+1;
        }
        idx++;
    }    

    
    return 0;
}  

