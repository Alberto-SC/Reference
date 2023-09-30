#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

struct simpleCron {      
	string hrs;
	string min;
	string sec;
	
};

vector<int> bucket(60*60*24);

void fillBucket(vector<int> &h, vector<int> &m, vector<int> &s){
        h.erase(unique(h.begin(),h.end()),h.end());	
        m.erase(unique(m.begin(),m.end()),m.end());	
        s.erase(unique(s.begin(),s.end()),s.end());	
	for(int i = 0; i < h.size(); i++){
		
		for(int j = 0; j < m.size(); j++){
			
			for(int k = 0; k < s.size(); k++){
			        //cout<<h[i]<<" "<<m[j]<<" "<<s[k]<<endl;	
				int pos = (h[i]*3600) + (m[j]*60) + s[k];
                                //cout<<pos<<" "<<bucket.size()<<endl;
                                bucket[pos]++;
				
			}
			
		}
		
	}
	
	
	
}


vector<int> calculateTotOf (string &s, bool isHrs){
	
	vector<int> values;
	
	if(s == "*"){
		if(isHrs) { for(int i = 0; i < 24; i++) values.push_back(i); }
		else { for(int i = 0; i < 60; i++) values.push_back(i); }
		
		return values;
	}
	
	string temp1 = "";
	string temp2 = "";
	
	bool isRange = false;
	
	for(int i = 0; i < s.size(); i++){
		
		if(isRange)
			temp2 += s[i];
		else
			temp1 += s[i];
		
		
		if(s[i] == ','){
			
			if(isRange){
				
				int l = stoi(temp1);
				int r = stoi(temp2);
				for(int i = l; i <= r; i++)values.push_back(i);
				
			} else {
				
				values.push_back(stoi(temp1));
				
			}
			
			temp1 = "";
			temp2 = "";
			isRange = false;	
			
		} else if(s[i] == '-'){
			isRange = true;
			
		}
	}
	
	if(isRange){
				
		int l = stoi(temp1);
		int r = stoi(temp2);
		for(int i = l; i <= r; i++)values.push_back(i);
				
	} else {
				
		values.push_back(stoi(temp1));
				
	}
	
	//for(auto &x: values) cout << x << " ";
	//cout << endl;
	return values;
	
}


signed main (){__
	
	int n; cin>>n; bucket.resize(86400, 0);
	
	vector<simpleCron> simples(n);
	
	for(int i = 0; i < n; i++){
		
		string h, m, s; cin>>h>>m>>s;
		simples[i].hrs = h;
		simples[i].min = m;
		simples[i].sec = s;
		
	}
	
	int ansTot = 0;
	for(int i = 0; i < n; i++){
		// cout << "Horas:\n";
		// cout << calculateTotOf(simples[i].hrs, true) << endl;
		// cout << "Min:\n";
		// cout << calculateTotOf(simples[i].min, false) << endl;
		// cout << "Sec:\n";
		// cout << calculateTotOf(simples[i].sec, false) << endl;
		
		auto totHrs = calculateTotOf(simples[i].hrs, true);
		auto totMin = calculateTotOf(simples[i].min, false);
		auto totSec = calculateTotOf(simples[i].sec, false);
		
	        fillBucket(totHrs,totMin,totSec);
		
		int tot = totHrs.size() * totMin.size() * totSec.size();
		//cout << tot << endl;
		
		ansTot += tot;
	
	}
	int ans2 = 0;
        for(int i = 0;i<bucket.size();i++){
          if(bucket[i]>0)ans2++;
        }
	cout << ans2 << " " << ansTot << endl;
	
	
	return 0;
}
