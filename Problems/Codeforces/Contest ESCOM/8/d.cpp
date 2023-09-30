#include <bits/stdc++.h>
using namespace std;
const int SIZE = 11; 
struct Trie { 
	struct Trie *children[SIZE]; 
	bool end; 
    int preffix;
}; 

Trie *CreateNode(void){ 
	Trie* Node = new Trie(); 
    return Node;
} 

void insert(struct Trie *root, string word) { 
	Trie *S = root; 
	for (int i = 0; i < word.size(); i++) { 
		int index = word[i] - '0'; 
		if (!S->children[index]) 
			S->children[index] = CreateNode(); 
		S = S->children[index]; 
        S->preffix++;
    }  
	S->end = true; 
} 
int  countpreffix(struct Trie *root, string pref) { 
	Trie * S = root; 
	for (int i = 0; i < pref.size(); i++) { 
		int index = pref[i] - '0'; 
		if (!S->children[index]) 
			return 0; 
		S = S->children[index]; 
    }
    return S->preffix;
} 

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    vector<string> keys;
    string s;
    for(int i = 0;i<n;i++){
        cin>>s;
        string k = s;
        for(int j = 0;j<s.size();j++){
            if(s[j] == 's')k[j] = '7';
            else if(s[j] == 'v')k[j] = '8';
            else if(s[j] == 'y')k[j] = '9';
            else if(s[j] == 'z')k[j] = '9';
            else k[j] = (((s[j]-'a')/3)+2)+'0';
        }
        keys.push_back(k);
    } 
    // for(auto c:keys)cout<<c<<" ";
    // cout<<endl;
	struct Trie *root = CreateNode(); 
    for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 
    for(int i = 0;i<q;i++){
        cin>>s;
        cout<<countpreffix(root,s)<<endl;
    }
	return 0; 
} 