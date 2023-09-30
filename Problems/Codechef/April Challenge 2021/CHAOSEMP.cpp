#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n,q,m;
    string ans;
    cin>>t>>q>>m;
    while(t--){
        int l = -(1e18),r = 1e18;
        int u = r,d = l;
        bool setx = false,sety = false;
        int cont = 0;
        if(m== 0){
            while(1){
                int mid = (l+r)>>1;
                cout<<1<<" "<<mid<<" "<<0<<endl<<flush;
                cin>>ans;
                if(ans=="O")break;
                if(ans=="XP"|| ans == "XN"){
                    cout<<2<<" "<<mid<<" "<<d<<" "<<mid<<" "<<u<<flush<<endl;
                    cin>>ans;
                    break;
                }
                if(ans[0]=='P')
                    r = mid-1ll;
                else if(ans[0]=='N')
                    l = mid+1ll;
            }
        }
        else{
            while(1){
                int x = (l+r)>>1;
                int y = (u+d)>>1;
                if(r-l<=3 && u-d<=3){
                    if(r-l == 2){
                        if(u-d==2){
                            cout<<1<<" "<<x<<" "<<y<<endl<<flush;
                            cin>>ans;
                            if(ans == "O")break;
                            if(ans == "PN")cout<<2<<" "<<x-2<<" "<<y<<" "<<x<<" "<<y+2<<endl<<flush,cin>>ans;
                            if(ans == "NN")cout<<2<<" "<<x<<" "<<y<<" "<<x+2<<" "<<y+2<<endl<<flush,cin>>ans;
                            if(ans == "NP")cout<<2<<" "<<x<<" "<<y-2<<" "<<x+2<<" "<<y<<endl<<flush,cin>>ans;
                            if(ans == "PP")cout<<2<<" "<<x-2<<" "<<y-2<<" "<<x<<" "<<y<<endl<<flush,cin>>ans;
                            if(ans == "XN")cout<<2<<" "<<x-1<<" "<<y<<" "<<x+1<<" "<<y+2<<endl<<flush,cin>>ans;
                            if(ans == "XP")cout<<2<<" "<<x-1<<" "<<y-2<<" "<<x+1<<" "<<y<<endl<<flush,cin>>ans;
                            if(ans == "NY")cout<<2<<" "<<x<<" "<<y-1<<" "<<x+2<<" "<<y+1<<endl<<flush,cin>>ans;
                            if(ans == "PY")cout<<2<<" "<<x-2<<" "<<y-1<<" "<<x<<" "<<y+1<<endl<<flush,cin>>ans;
                        }
                        else {
                            cout<<1<<" "<<x<<" "<<y<<endl<<flush;
                            cin>>ans;
                            if(ans == "O")break;
                            else if(ans == "NP")cout<<2<<" "<<x<<" "<<y-2<<" "<<x+2<<" "<<y<<endl<<flush,cin>>ans;
                            else if(ans == "PP")cout<<2<<" "<<x-2<<" "<<y-2<<" "<<x<<" "<<y<<endl<<flush,cin>>ans;
                            else if(ans == "XP")cout<<2<<" "<<x-1<<" "<<y-2<<" "<<x+1<<" "<<y<<endl<<flush,cin>>ans;
                            else if(ans == "NY")cout<<2<<" "<<x<<" "<<y-1<<" "<<x+2<<" "<<y+1<<endl<<flush,cin>>ans;
                            else if(ans == "PY")cout<<2<<" "<<x-2<<" "<<y-1<<" "<<x<<" "<<y+1<<endl<<flush,cin>>ans;
                            else {
                                if(ans == "XN"){
                                    cout<<2<<" "<<x-1<<" "<<y+1<<" "<<x+1<<" "<<y+3<<endl<<flush,cin>>ans;
                                    if(ans=="O")break;
                                    else if(ans == "IN")cout<<2<<" "<<x-1<<" "<<y+1<<" "<<x+1<<" "<<y+3<<endl<<flush,cin>>ans;
                                    else cout<<2<<" "<<x-1<<" "<<y-1<<" "<<x+1<<" "<<y+1<<endl<<flush,cin>>ans;
                                }
                                else if(ans == "NN"){
                                    cout<<2<<" "<<x<<" "<<y+1<<" "<<x+2<<" "<<y+3<<endl<<flush,cin>>ans;
                                    if(ans=="O")break;
                                    else if(ans == "IN")cout<<2<<" "<<x<<" "<<y+1<<" "<<x+2<<" "<<y+3<<endl<<flush,cin>>ans;
                                    else cout<<2<<" "<<x<<" "<<y-1<<" "<<x+2<<" "<<y+1<<endl<<flush,cin>>ans;
                                }
                                else if(ans == "PN"){
                                    cout<<2<<" "<<x-2<<" "<<y+1<<" "<<x<<" "<<y+3<<endl<<flush,cin>>ans;
                                    if(ans=="O")break;
                                    else if(ans == "IN")cout<<2<<" "<<x-2<<" "<<y+1<<" "<<x<<" "<<y+3<<endl<<flush,cin>>ans;
                                    else cout<<2<<" "<<x-2<<" "<<y-1<<" "<<x<<" "<<y+1<<endl<<flush,cin>>ans;
                                }
                            }
                        }
                        break;
                    }
                    if(r-l ==3){
                        if(u-d ==2){
                            cout<<1<<" "<<x<<" "<<y<<endl<<flush;
                            cin>>ans;
                            if(ans == "O")break;
                            else if(ans == "PN")cout<<2<<" "<<x-2<<" "<<y<<" "<<x<<" "<<y+2<<endl<<flush,cin>>ans;
                            else if(ans == "PP")cout<<2<<" "<<x-2<<" "<<y-2<<" "<<x<<" "<<y<<endl<<flush,cin>>ans;
                            else if(ans == "XN")cout<<2<<" "<<x-1<<" "<<y<<" "<<x+1<<" "<<y+2<<endl<<flush,cin>>ans;
                            else if(ans == "XP")cout<<2<<" "<<x-1<<" "<<y-2<<" "<<x+1<<" "<<y<<endl<<flush,cin>>ans;
                            else if(ans == "PY")cout<<2<<" "<<x-2<<" "<<y-1<<" "<<x<<" "<<y+1<<endl<<flush,cin>>ans;
                            else {
                                if(ans == "NY"){
                                    cout<<2<<" "<<x+1<<" "<<y-1<<" "<<x+3<<" "<<y+1<<endl<<flush,cin>>ans;
                                    if(ans=="O")break;
                                    else if(ans == "IN")cout<<2<<" "<<x+1<<" "<<y-1<<" "<<x+3<<" "<<y+1<<endl<<flush,cin>>ans;
                                    else cout<<2<<" "<<x-1<<" "<<y-1<<" "<<x+1<<" "<<y+1<<endl<<flush,cin>>ans;
                                }
                                else if(ans == "NN"){
                                    cout<<2<<" "<<x+1<<" "<<y<<" "<<x+3<<" "<<y+2<<endl<<flush,cin>>ans;
                                    if(ans=="O")break;
                                    else if(ans == "IN")cout<<2<<" "<<x+1<<" "<<y<<" "<<x+3<<" "<<y+2<<endl<<flush,cin>>ans;
                                    else cout<<2<<" "<<x-1<<" "<<y<<" "<<x+1<<" "<<y+2<<endl<<flush,cin>>ans;
                                }
                                else if(ans == "NP"){
                                    cout<<2<<" "<<x+1<<" "<<y-2<<" "<<x+3<<" "<<y<<endl<<flush,cin>>ans;
                                    if(ans=="O")break;
                                    else if(ans == "IN")cout<<2<<" "<<x+1<<" "<<y-2<<" "<<x+3<<" "<<y<<endl<<flush,cin>>ans;
                                    else cout<<2<<" "<<x-1<<" "<<y-2<<" "<<x+1<<" "<<y<<endl<<flush,cin>>ans;
                                }
                            }
                        }
                        else{
                            cout<<2<<" "<<l<<" "<<d<<" "<<r-1<<" "<<u<<endl<<flush;
                            cin>>ans;
                            if(ans == "O")break;
                            if(ans == "IN"){
                                cout<<2<<" "<<l<<" "<<d<<" "<<r-1<<" "<<u-1<<endl<<flush;
                                cin>>ans;
                                if(ans== "O")break;
                                if(ans == "IN"){
                                    cout<<2<<" "<<l<<" "<<d<<" "<<r-1<<" "<<u-1<<endl<<flush;
                                    cin>>ans;
                                }
                                else{
                                    cout<<2<<" "<<l<<" "<<d+2<<" "<<r-1<<" "<<d+4<<endl<<flush;
                                    cin>>ans;
                                }
                            }
                            else {
                                cout<<2<<" "<<l+2<<" "<<d<<" "<<r+1<<" "<<u-1<<endl<<flush;
                                cin>>ans;
                                if(ans== "O")break;
                                if(ans == "IN"){
                                    cout<<2<<" "<<l+2<<" "<<d<<" "<<r+1<<" "<<u-1<<endl<<flush;
                                    cin>>ans;
                                }
                                else{
                                    cout<<2<<" "<<l+2<<" "<<d+2<<" "<<r+1<<" "<<u+1<<endl<<flush;
                                    cin>>ans;
                                }
                            }
                        }
                        break;
                    }
                }
                cout<<1<<" "<<x<<" "<<y<<endl<<flush;
                cin>>ans;
                cont++;
                if(ans == "O"){break;}
                if(ans == "NY"){
                    sety = true;
                    u = y+1;
                    d = y-1;
                    l = x;
                    r++;
                    continue;
                }   
                else if(ans == "PY"){
                    sety = true;
                    u = y+1;
                    d = y-1;
                    r = x;
                    l--;
                    continue;
                }   
                else if(ans == "XN"){
                    setx = true;
                    l = x-1;
                    r = x+1;
                    d = y;
                    u++;
                    continue;
                }  
                else if(ans == "XP"){
                    setx = true;
                    l = x-1;
                    r = x+1;
                    u = y;
                    d--;
                    continue;
                }
                if(ans[0] == 'N'){
                    if(setx)l++,r++;
                    else l = x,r++;
                }
                else if(ans[0]== 'P'){
                    if(setx)l--,r--;
                    else r = x,l--; 
                }
                if(ans[1]== 'N'){
                    if(sety)d++,u++;
                    else d = y,u++;
                }
                else if(ans[1] == 'P'){
                    if(sety)d--,u--;
                    else u = y,d--;
                }
            }
        }
    }   
    return 0;
}  
