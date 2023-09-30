/**
 * Author: chilli / Alberto Silva (MatchWithWildcards)
 * License: CC0
 * Description: z[x] computes the length of the longest common prefix of s[i:] and s, except z[0] = 0. (abacaba -> 0010301)
 * Time: O(n)
 * Status: stress-tested
 */
vector<int> zf (string s) {
	int n = s.size();
	vector<int> z (n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
 
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
 
		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}

// Not sure if it's correct, works for leetcode problem 
// Suppose you can change from pattern, p[i] to some set of characters c, 
// you can use this code to deal with that case 
// ONLY CAN CHECK IF EXIST ONE OCURRENCE , IT WILL FAIL TO TRY TO GET ALL THE OCURRENCES
// LIKE IN THIS EXAMPLE
// Possible mappings:
// a -> {a,b}
// b -> {b,c}
// c -> {c,a}
// t = abc
// s = abcaaba

class MatchWithWildcards {
public:
    vector<int> z_function(const string& s,map<char,set<char>> &mp){
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && mp[s[z[i]]].count(s[i+z[i]])) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    bool match(const string& s, const string& pat, map<char,set<char>> &mp) {
        int n = pat.size();
        int m = s.size();
        if(m<n){
            cout<<endl;
            return false;
        }
        
        string match = pat+"#"+s;
        vector<int> z =z_function(match,mp);
        for(int i = n; i<match.size(); i++){   
            if(z[i] == n){   
                return true;
            }
        }
        return false;
    }

		// Mappings are of the form: [[a,b]] -> a can be replaced by b
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map<char,set<char>> mp;
        
        for(auto c:mappings){
            mp[c[0]].insert(c[1]);
            mp[c[0]].insert(c[0]);
        }
        for(auto c:sub){
            mp[c].insert(c);
        }
   
        
        return match(s,sub,mp);
    }
};