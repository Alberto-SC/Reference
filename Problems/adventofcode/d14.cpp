#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;

map<lli,lli> mem;

void solve(string &mask,lli idx,lli v,lli Odir,lli dir = 0){
    if(idx<0){
        mem[dir] = v;
        return ;    
    }
    else if(mask[idx] == '0'){
        if(Odir>>(35-idx)&1)
            dir |= 1ll<<(35-idx);   
        solve(mask,idx-1,v,Odir,dir);
    }
    else if(mask[idx] == '1'){
        dir |= 1ll<<(35-idx);
        solve(mask,idx-1,v,Odir,dir);
    }
    else if(mask[idx]== 'X'){
        solve(mask,idx-1,v,Odir,dir|1ll<<(35-idx));
        solve(mask,idx-1,v,Odir,dir);
    }   
    
}
int main(){
    string mask,num,pos;
    char equal;
    while(cin>>pos>>equal>>num){
        int idx1 = 0;
        int idx2 = 0;
        if(pos== "mask"){
            mask = num;
        }
        else{
            for(int i = 0;i<pos.size();i++){
                if(pos[i]== '[')idx1 =i;
                if(pos[i] == ']')idx2 = i;
            }
            lli p = stoll(pos.substr(idx1+1,((idx2-1)-idx1)+1));
            lli n2 = stoll(num);
            lli value = n2;
            n2 = p;
            solve(mask,35,value,n2);
            // vector<int> posx;
            // for(int i = 0;i<mask.size();i++){
            //     if(mask[i]== 'X')posx.push_back((mask.size()-1)-i);
            //     else if(!((n2>>(35-i))&1) && mask[i] == '1')n2^= (1ll<<(35-i)); x
            // }
            // for(int i= 0;i<1<<posx.size();i++){
            //     lli aux = n2;
            //     for(int j = 0;j<posx.size();j++){
            //         if((i>>j)&1){
            //             aux |= 1ll<<posx[j];
            //         }   
            //         else{
            //             aux &= ~(1ll<<posx[j]);
            //             bitset<36> bs(~(1ll<<posx[j]));
            //         }
            //     }
            //     bitset<36> bs(aux);
            //     mem[aux] = value;
            // }
        }
    }
    lli sum = 0;
    for(auto c:mem){
        sum+=c.second;
    }
    cout<<sum<<endl;
    return 0;
}