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

bool match(const string& s, const string& pat) {
	int n = pat.size();
	int m = s.size();
	if(m<n){
		cout<<endl;
		return false;
	}
	string match = pat+"#"+s;
	vector<int> kmp =p_function(match);
	for(int i = 0; i < m - n + 1; i++){   
		if(kmp[2 * n + i] == n){   
            return true;
        }
    }
    return false;
}


vector <string> substrings (string s){
  
  //vector<string> subs;
  
  vector<string> subs;
  
  for(int i = 1; i <= s.size(); i++){

    for(int j = 0; j <= s.size() - i; j++){
      
      int tam = i + j - 1;
      string sub = "";
      for(int k = j; k <= tam; k++){
          sub += s[k];
      }
      //cout << sub << endl;
      subs.push_back(sub);
      
    }
    
  }
  
  return subs;

  
}

int main() {__

  int n; cin>>n;
  vector<string> words(n);

  int minSize = 10000;
  string minS;
  
  for(auto & s: words) {
    cin>>s;
    if(s.size() < minSize){
      minS = s;
      minSize = s.size();
    }
  }
  vector <string> subs = substrings (minS);
  int ans = 0;
  vector<string> nw;
  nw.push_back(subs[0]);
  for(int i = 1;i<subs.size();i++)
    if(subs[i]!= subs[i-1])nw.push_back(subs[i]);
  
  reverse(nw.begin(),nw.end());
  for(string &sub : nw){
    bool isAns = true;
    for(string &word: words){
    	
      bool isMatch = match(word, sub);
      if(!isMatch){isAns = false;break;}
      //cout << word << " " << sub << " " << isMatch << endl;
      
    }
  
    if(isAns){
      ans = sub.size();
      break;
    }
  }
  
  cout << ans << endl;

  return 0;
  
}
