#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n,l,r;
    cin>>n>>l>>r;
    int id_i, j_l,j_r,ac = 0,c = n-1,id_j,j_end;
    for(int i = 1;i<=n;i++){
        if(ac+c>=l){
            id_i = i;
            j_l = i + (l-ac);
            j_r = min(n,j_l+(r-l));
            break;
        }
        ac+=c;
        c--;
    }
    id_j = id_i;
    for(int i = id_i;i<=n;i++){
        if(ac+c>=r){
            id_j = i;
            j_end = i+(r-ac);
            break;
        }
        ac+=c;
        c--;
    }

    vector<int> ans(n+1);
    iota(ans.begin(),ans.end(),0);

    for(int j = j_l;j<=j_r;j++){   
        swap(ans[id_i],ans[j]);
    }

    int d = id_j-id_i-1;
    if(d>=1){
        int start = id_i+1;
        int len = n-id_i;
        vector<int> temp(len);
        for(int i = 0;i<len;i++){
            temp[(i+d)%len] = ans[i+start];
        }
        reverse(temp.begin(),temp.begin()+d);
        for(int i = 0;i<len;i++){
            ans[i+start] = temp[i];
        }
    }
    if(id_j>id_i){
        for(int j = id_j+1;j<=j_end;j++)
            swap(ans[id_j],ans[j]);
    }

    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
  
    cout<<endl;

    return 0;
}