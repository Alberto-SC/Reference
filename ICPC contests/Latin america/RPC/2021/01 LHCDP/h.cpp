#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int main(){__
	int t; cin >> t;
	while(t--){
		int c,p,r; cin >> p >> r;
		string word;
		unordered_map<string,int> abr;
        abr.reserve(1024);
        abr.max_load_factor(0.25); 
		for(int i=1; i<=p; i++){
			cin >> c;
			while(c--){
				cin >> word;
                string s = "";
				for(int j=1; j<=word.size(); j++){
                    s+=word[j-1];
                    if(!abr.count(s))
                        abr[s]= i;
                    else{
                        if(abr[s]!=i)
					        abr[s]= -1;
                    }
				}
			}
		}
        vector<int> used(p+1,0);
		for(int i=1; i<=r; i++){
			cin >> c;
            int cont = 0;
			while(c--){
				cin >> word;
                if(abr.count(word)){
                    int who = abr[word];
                    if(who== -1)continue;
                    if(used[who]!= i)cont++;
                    used[who] = i;
                }
                
			}
            cout<<cont<<endl;
		}
	}

	return 0;
}