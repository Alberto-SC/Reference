    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n'
    #define int long long 
    #define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

    signed main(){__
        int t= 1,n;
        cin>>t;
        while(t--){
            cin>>n;
            string s;
            cin>>s;
            int z = 0,o = 0;
            string a(n,'?'),b(n,'?');
            for(int i = 0;i<n;i++){
                if(s[i]=='0')z++;
                else o++;
            }
            if(s[0]=='0' ||s[n-1]=='0' ||o&1 || z&1){
                cout<<"NO"<<endl;
                continue;
            }
            
            int cont =0;
            for(int i = 0;i<n;i++){
                if(s[i]== '1' && cont<o/2){
                    a[i] ='(';
                    b[i] ='(';
                    cont++;
                }
                else if(s[i]=='1'&&cont>=o/2){
                    a[i] = ')';
                    b[i] =')';
                    cont++;
                }
            }
            
            for(int i = 0;i<n;i++){
                if(s[i]=='1')continue;
                if(z%2){
                    a[i] ='(';
                    b[i] =')';
                }
                else{
                    a[i] =')';
                    b[i] ='(';
                }    
                z--;

            }
            cout<<"YES"<<endl;
            cout<<a<<endl;
            cout<<b<<endl;
        }
        return 0;
    }  
