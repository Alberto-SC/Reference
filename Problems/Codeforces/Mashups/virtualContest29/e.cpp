#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct problem{
    int a,c,id;
};

signed main(){__
	int t= 1,n,a,x;
    cin>>n>>t;
    vector<problem> problems(n);
    for(int i = 0;i<n;i++){
        cin>>a>>x;
        problems[i] = {a,x,i+1};
    }
    sort(problems.begin(),problems.end(),[&](problem a,problem b){
        if(a.c==b.c)return a.a<b.a;
        return a.c<b.c;
    });
    int maxP = -1,s = 0;
    for(int i = 0;i<n;i++){
        s+=problems[i].c;
        if(s>t)break;
        maxP= i;
    }
    maxP++;
    vector<int> used;
    s = 0;
    vector<int> notused;
    for(int i = 0;i<n;i++){
        if(problems[i].a<=maxP && used.size()<maxP)used.push_back(i),s+=problems[i].c;
        else notused.push_back(i);
    }
    int ans = maxP;
    if(s<t){
        ans = (int)used.size();
        cout<<ans<<endl;
        cout<<maxP<<endl;
        int l = 0;
        while(used.size()<maxP){
            used.push_back(notused[l++]);
        }
        for(int i = 0;i<used.size();i++)
            cout<<problems[used[i]].id<<" ";
        cout<<endl;
    }
    else{
        int r = maxP-1;
        int l = 0;
        while(s>t){
            s-=problems[used[r--]].c;
            s+=problems[notused[l++]].c;
            ans--;
        }
        cout<<ans<<endl;
        cout<<maxP<<endl;
        for(int i = 0;i<l;i++)
            cout<<problems[notused[i]].id<<" ";
        for(int j = 0;j<=r;j++)
            cout<<problems[used[j]].id<<" ";
        cout<<endl;
    }
    return 0;
}  
