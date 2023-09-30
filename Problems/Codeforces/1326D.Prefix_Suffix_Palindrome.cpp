    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int n,t;
        string s;
        cin>>t;
        while(t--){
            cin>>s;
            int n = s.size();
            vector<vector<int>> p(2,vector<int>(n,0));
            for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
                for(int i=0;i<n;i++){
                    if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
                    int L=i-p[z][i], R=i+p[z][i]-!z;
                    while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
                    if(R>r) l=L,r=R;
                }
            int i;
            for(i = 0;i<n/2;i++)
                if(s[i] != s[n-i-1])break;

            int ans = i*2,idx = 0,aux = ans;
            bool flag = false;
            if(i == n/2){cout<<s<<endl;continue;}
            for(int j = i;j<=(n-i)-1;j++){
                if(p[1][j]>= j-i  && j +(j-i)<= (n-1)-i){
                    // cout<<j-i<<endl;
                    ans = max(ans,aux+((j-i)*2)+1);
                    idx = j;
                    flag = false;
                }
                else if(j>i && p[0][j]>= j-i && (j+(j-i))-1  <=(n-1)-i){
                    ans = max(ans,aux+((j-i)*2));
                    idx = j;
                    flag = true;
                }
            }
            string t = s;
            reverse(t.begin(),t.end());
            p[0].assign(n,0);
            p[1].assign(n,0);
            for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
                for(int i=0;i<n;i++){
                    if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
                    int L=i-p[z][i], R=i+p[z][i]-!z;
                    while(L-1>=0 && R+1<n && t[L-1]==t[R+1]) p[z][i]++,L--,R++;
                    if(R>r) l=L,r=R;
                }
            int ans2 = i*2,idx2 = n-1,aux2 = ans2;
            bool flag2 = false;
            for(int j = i;j<=(n-i)-1;j++){
                if(p[1][j]>= j-i  && j +(j-i)<= (n-1)-i){
                    ans2 = max(ans2,aux2+((j-i)*2)+1);
                    idx2 = j;
                    flag2 = false;
                }
                else if(j>i && p[0][j]>= j-i && (j+(j-i))-1  <=(n-1)-i){
                    ans2 = max(ans2,aux2+((j-i)*2));
                    idx2 = j;
                    flag2= true;
                }
            }
            // cout<<ans<<" "<<ans2<<endl;
            for(int j = 0;j<i;j++)
                cout<<s[j];
            if(ans>=ans2){
                if(!flag){
                    for(int j = idx-(idx-i);j<=idx+(idx-i);j++)
                        cout<<s[j];
                    }
                else {
                    for(int j = idx-(idx-i);j<idx+(idx-i);j++)
                        cout<<s[j];
                }
            }
            else{
                if(!flag2){
                    for(int j = idx2-(idx2-i);j<=idx2+(idx2-i);j++)
                        cout<<t[j];
                }
                else {
                    for(int j = idx2-(idx2-i);j<idx2+(idx2-i);j++)
                        cout<<t[j];
                }
                
            }
            for(int j = n-i;j<n;j++)
                cout<<s[j];
            cout<<endl;
        }
        return 0;
    }