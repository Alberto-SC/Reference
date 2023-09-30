    #include <bits/stdc++.h>
    using namespace std;
    typedef long long int lli;
    const int inf = 1000000007;
    int  main(){
        int n,l,r;
        cin>>n;
        int index ,mn = 1000000007;
        vector<pair<int,int>> segments(n);
        for(int i = 0;i<n;i++){
            cin>>l>>r;
            segments[i] = {l,r};
            if((r-l)+1 <mn)mn = (r-l)+1,index = i;
        }   
        vector<pair<int,int>> acleft(n+7,{0,inf});
        vector<pair<int,int>> acright(n+7,{0,inf});
        for(int i = 0;i<n;i++){
            l = max(segments[i].first,acleft[i].first);
            r = min(segments[i].second,acleft[i].second);
            acleft[i+1] = {l,r};
        }
        l = -1, r = 1000000007;
        for(int i =n-1;i>=0;i--){
            l = max(segments[i].first,acright[i+1].first);
            r = min(segments[i].second,acright[i+1].second);
            acright[i] = {l,r};
        }
        int ans = 0;
        // for(auto c:acleft)cout<<c.first<<" "<<c.second<<endl;
        // cout<<endl;
        // for(auto c:acright)cout<<c.first<<" "<<c.second<<endl;
        for(int i = 0;i<n;i++){
            ans = max(ans,min(acleft[i].second,acright[i+1].second)-max(acleft[i].first,acright[i+1].first));
        }
        cout<<ans<<endl;
        return 0;
    }