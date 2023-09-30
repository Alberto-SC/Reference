#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int j = 0;
        bool flag= false;
        for(j = 0;j<n;j++)
            if(s[j]=='0')flag = true;
        
        if(!flag){
            cout<<0<<endl;
            continue;
        }
        for(j = 0;j<n;j++)
            if(s[j]=='1')break;

        if(j == n){
            cout<<1<<endl;
            continue;
        }
        s = s.substr(j+1);
        n = s.size();
        if(n ==0){
            cout<<"10"<<endl;
            continue;
        }
        vector<int> ac0(n);
        vector<int> ac1(n);
        for(int i = 0;i<n;i++){
            if(s[i]=='1')ac1[i]=1;
            else ac0[i]= 1;
        }
        for(int i = 0;i<n;i++){
            ac0[i] = ac0[i]+(i?ac0[i-1]:0);
            ac1[i] = ac1[i]+(i?ac1[i-1]:0);
        }
        int cont = 0;
        vector<int> ids;
        vector<int> zeros;
        ids.push_back(0);
        zeros.push_back(0);
        int z = 0;
        int last0 = 0,last1 = 0,last =0;
        // cout<<s<<endl;
        for(int i = 0;i<n;i++){ 
            if(s[i]== '0')z++;
            if(ac0[i]>last0 &&ac1[i]>last1){
                last0 = ac0[i]; 
                last1 = ac1[i]; 
                ids.push_back(i);
                cont++;
                if(z==cont-last)zeros.push_back(1);
                else {
                    last = cont;
                    zeros.push_back(0);
                    z = 0;
                }
            }
        }

        int x = 0;
        bool f = false;
        vector<int> ans;
        ans.push_back(1);
        if(!cont){
            ans.push_back((s[n-1]-'0')^1);
            for(auto c:ans)cout<<c;
            cout<<endl;
            continue;
        }
        
        vector<int> zz;
        for(int i= 1;i<zeros.size();i++)
            if(zeros[i]==0)zz.push_back(i);
        
        zz.push_back(ids.size());
        last =1;
        if(zz.size()==1 && (ids.back()==n-1 || s[n-1]=='1')){
            for(int i= 0;i<=cont;i++)
                ans.push_back(0);
            for(auto c:ans)cout<<c;
            cout<<endl;
            continue;
        }
        for(int i= 0;i<zz.size();i++){
            int y =last-1;

            for(int j = last;j<zz[i];j++){
                if(s[ids[j]]=='0')y = j;
            }
            for(int j = last;j<=y;j++){
                ans.push_back(0);
            }
             for(int j = y+1;j<=zz[i]-(zz[i]==ids.size()?1:0);j++){
                ans.push_back(s[ids[j]]-'0');
            }
            last = zz[i]+1;
        }
        if(ids.back()==n-1)ans.push_back(0);
        else ans.push_back((s[n-1]-'0')^1);
        int l = 1;
        int fz = -1;
        for(int i = 0;i<n;i++){
            if(s[i]-'0'== ans[l]){
                if(ac0[n-1]-ac0[i]<ans.size()-(l+1)){
                    fz = l+1;
                    break;
                }
                l++;
            }
            if(l ==ans.size())break;
        }
        if(ac0[n-1]<ans.size()-1)fz = 1;

        if(fz!=-1){
            for(int i= fz;i<ans.size();i++)
                ans[i] = 0;
        }
        for(auto c:ans)cout<<c;
        cout<<endl;
    }
    return 0;
}  
