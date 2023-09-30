#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
typedef long long int  lli;


vector<lli> sum;
vector<int> idl;
vector<int> idr;
vector<bool> lazy;

lli mx = (1e18)+(1e9)+1;
  void extend(int v,lli l,lli r){
    if(idl[v]== 0 && l!= r){
      lli m = (l+r)>>1; 
      idl[v] = sum.size();
      sum.push_back((m-l)+1);
      idr[v] = sum.size();
      sum.push_back((r-(m+1))+1);

      idr.push_back(0);
      idr.push_back(0);
      idl.push_back(0);
      idl.push_back(0);
      lazy.push_back(false);
      lazy.push_back(false);
    }   
    if(lazy[v]){
      sum[v] = 0;
      if(l!= r){
        lazy[idl[v]] = true;
        lazy[idr[v]] = true;
      }
      lazy[v] = false;  
    }
  }
  
  void update(lli l,lli r,int v = 0,lli sl= 0,lli sr = mx){
    if(sl> r || sr<l || sl>sr)return;
    if(sl>=l && sr<=r){
      lazy[v]= true;
      extend(v,sl,sr);
      return;
    }
    extend(v,sl,sr);
    lli m = (sl+sr)>>1;
    update(l,r,idl[v],sl,m);
    update(l,r,idr[v],m+1,sr);
      sum[v] = sum[idl[v]] + sum[idr[v]];
  }

  lli queryRange(lli l,lli r,int v = 0,lli sl = 0,lli sr = mx){
    extend(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>= l && sr<=r)return sum[v];
    
    lli m = (sl+sr)>>1;
    return queryRange(l,r,idl[v],sl,m)+ queryRange(l,r,idr[v],m+1,sr);
  }  

  lli query(lli k,int v = 0,lli sl = 0,lli sr = mx){
    if(sl ==sr)return sl;
    lli m = (sl+sr)>>1;
    extend(v,sl,sr);
    if(sum[idl[v]]>=k)
      return query(k,idl[v],sl,m);
    else 
      return query(k-sum[idl[v]],idr[v],m+1,sr);

  }


signed main(){__
  int n;
  lli c,s;
  cin>>n;
  sum.push_back((mx)+1);
  idl.push_back(0);
  idr.push_back(0);
  lazy.push_back(false);
  for(int i = 0;i<n;i++){
    cin>>s>>c;
    lli x = queryRange(0,s-1);
    lli idx = query(c+x);
    cout<<idx<<endl;
    update(s,idx);
  }
  return 0;
}
