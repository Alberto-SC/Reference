#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(m);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        for(auto &x:c)cin>>x;
        vector<int> dummy(n+1,-1);
        for(int i = 0;i<n;i++){
            if(a[i]== b[i])dummy[a[i]] = i;
        }
        vector<queue<int>> changes(n+1);
        for(int i = 0;i<n;i++){
            if(a[i]!= b[i]){
                changes[b[i]].push(i);
            }
        }
        int last =n+1;
        for(int i = 1;i<=n;i++){
            if(!changes[i].empty()){
                last = i;
                break;
            }
        }
        bool flag = true;
        vector<int> ans;
        vector<int> o(n+1);
        for(int i = 0;i<m;i++){
            o[c[i]]++;
        }
        for(int i = 0;i<n;i++){
            if(a[i]!= b[i]){
                o[b[i]]--;
                if(o[b[i]]<0)flag = false;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        // cout<<flag<<endl;
        int idxNe = n+1;
        vector<int> idx(n+1,-1);
        for(int i = 0;i<n;i++)
            idx[b[i]]= i;
        for(int i = 1;i<=n;i++){
            if(o[i]>0 && idx[i]!= -1){
                idxNe = i;
                break;
            }
        }
        for(int i =0;i<m;i++){
            if(changes[c[i]].empty()){
                if(dummy[c[i]]!= -1){
                    ans.push_back(dummy[c[i]]);
                }
                else if(last<=n){
                    ans.push_back(changes[last].front());
                }
                else if(idxNe<=n){
                    ans.push_back(idx[idxNe]);
                    changes[b[idx[idxNe]]].push(idx[idxNe]);

                }
                else {
                    flag = false;
                    break;
                }
                o[c[i]]--;
                while(idxNe <=n && (o[idxNe]== 0 || idx[idxNe]== -1)){
                    idxNe++;
                }
            }
            else{
                // cout<<"Changes"<<endl;
                ans.push_back(changes[c[i]].front());
                changes[c[i]].pop();
                while(last<=n && changes[last].empty()){
                    last++;
                }
            }
        }
        for(int i = 1;i<=n;i++)
            if(!changes[i].empty())flag = false;
        if(flag){
            cout<<"YES"<<endl;
            for(auto c:ans)cout<<c+1<<" ";
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}  

