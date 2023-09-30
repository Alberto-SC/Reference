
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    vector<int> acusan(n+1);
    vector<int> defienden(n+1);
    int a = 0,d=0;
 
    for(int i = 0;i<n;i++){
        cin>>nums[i];     
        if(nums[i]>0)a++,acusan[nums[i]]++;
        else d++,defienden[-nums[i]]++;
    }
    if(m ==0){
        for(int i = 0;i<n;i++)
            cout<<"Lie"<<endl;
        return 0;
    }
    vector<string> s(n);
    bool two = false;
    vector<int> culpables;
    vector<bool> c(n+1,false);
    for(int i = 0;i<n;i++){        
        if((d-defienden[i+1])+acusan[i+1]==m){
            culpables.push_back(i+1);            
            c[i+1] = true;
        }
    }
    for(int i = 0;i<n;i++){
        if(nums[i]>0){
            if(!c[nums[i]])s[i] = "Lie";
            else if(c[nums[i]] && culpables.size()>1)s[i] = "Not defined";
            else if(c[nums[i]] && culpables.size()==1)s[i] = "Truth";
        }
        else{
            if(c[-nums[i]] && culpables.size()==1)s[i] = "Lie";
            else if(c[-nums[i]] && culpables.size()>1)s[i] = "Not defined";
            else if(!c[-nums[i]])s[i] = "Truth";
        }
    }
    for(auto c:s)cout<<c<<endl;
    return 0;
}  

