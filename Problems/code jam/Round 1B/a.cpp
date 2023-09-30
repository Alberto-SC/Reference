#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,id = 1,h,m,s,n,A,B,C,a,b,c;
    cin>>t;
    while(t--){
        cin>>A>>B>>C;
        int x = 1000000000,y =43200000000000;
        h = 0,m = 0,s = 0,n = 0;
        bool flag = false;
        for(int i = 0;i<12;i++){
            if(flag)break;
            for(int j = 0;j<60;j++){
                if(flag)break;
                for(int k = 0;k<60;k++){
                    if(flag)break;
                    int a = (y/12)*i;
                    int b = (y/60)*j;
                    int c = (y/60)*k;
                    a+=(y/(12*60))*j;
                    b+=(y/(60*60))*k;
                    a+=(y/(12*60*60))*k;
                    vector<int> mm = {A,B,C};
                    vector<int> mm2 = {a,b,c};
                    sort(mm.begin(),mm.end());
                    sort(mm2.begin(),mm2.end());
                    if(mm[0]-mm2[0] ==mn[1]-mn2[1] && mm[0]-mm2[0] ==mn[1]-mn2[1] && mm[0]-mm2[0] ==mn[1]-mn2[1] && mm[0]-mm2[0] ==mn[1]-mn2[1]){
                        h = i;
                        m = j;
                        s = k;
                        flag = true;
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<id++<<": "<<h<<" "<<m<<" "<<s<<" "<<n<<endl;
    }
    return 0;
}  
