#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> p_function(const string& v){
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i]){
            j = p[j - 1];
        }
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}

vector<int> match(const string& s, const string& pat) {
	int n = pat.size();
	int m = s.size();
	vector<int> res;
        if(m<n){
	    cout<<endl;
	    return res;
        }
	string match = pat+"#"+s;
	vector<int> kmp =p_function(match);
	for(int i = 0; i < m - n + 1; i++){   
		if(kmp[2 * n + i] == n){   
                  res.push_back(i);
                }
        }
        return res;
}


signed main(){__
  int n,k;
  string s,t;
  cin>>s;
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>t>>k;
    s+="#"+t;
//    vector<int> occ = match(s,t);
//    if(occ.size()<k)cout<<-1<<endl;
//    else cout<<occ[k-1]+1<<endl;
  }
  cout<<s<<endl;

  return 0;
}
