#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        bool flag = true;
        vector<int> posI[28];
        vector<int> posP[28];
        t+="{";
        s+="{";

        n = s.size();
        for(int i = 0;i<n;i++){
            if(i&1)
                posI[s[i]-'a'].push_back(i);
            else
                posP[s[i]-'a'].push_back(i);
        }
        int m = t.size(),c1 = 0,c2= 0;

        for(int i = 0;i<m;i++){
            if(c1 ==c2 && c1 ==-1)
                break;
            int idx1,idx2;
            if(c2!=-1)
                idx1 =lower_bound(posI[t[i]-'a'].begin(),posI[t[i]-'a'].end(),c2)-posI[t[i]-'a'].begin();
            else 
                idx1 = -1;
            if(c1!=-1)
                idx2 =lower_bound(posP[t[i]-'a'].begin(),posP[t[i]-'a'].end(),c1)-posP[t[i]-'a'].begin();
            else   
                idx2 = -1;
            if(idx1==posI[t[i]-'a'].size())
                idx1 =-1;
            if(idx2==posP[t[i]-'a'].size())
                idx2 =-1;
    
            if(idx1 ==-1 && idx2==-1){
                flag = false;
                break;
            }
            int nc1,nc2;
            if(idx1!=-1){
                if(c2 ==-1) nc1 ==-1;
                else nc1 = posI[t[i]-'a'][idx1];
            }         
            else 
                nc1 =-1;  
                 
            if(idx2!=-1){
                if(c1==-1) nc2 = -1;
                else nc2 = posP[t[i]-'a'][idx2];
            }
            else 
                nc2 =-1;
            c1 = nc1,c2 = nc2;
        }
        if(c1==c2 && c1==-1)
            flag = false;
        cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}  
