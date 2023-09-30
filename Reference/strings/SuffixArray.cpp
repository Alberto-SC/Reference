/**
 * Author: Alberto Silva
 * License: CO0
 * Description: Builds suffix array for a string.
 * \texttt{sa[i]} is the starting index of the suffix which
 * is $i$'th in the sorted suffix array.
 * The returned vector is of size $n+1$, and \texttt{sa[0] = n}.
 * The \texttt{lcp} array contains longest common prefixes for
 * neighbouring strings in the suffix array:
 * \texttt{lcp[i] = lcp(sa[i], sa[i-1])}, \texttt{lcp[0] = 0}.
 * The input string must not contain any zero bytes.
 * Time: O(n \log n)
 * Status: stress-tested
 */
 
void radix_sort(vector<int> &P,vector<int> &c){
    int n = P.size();
    vector<int> cnt(n);
    for(auto d:c)
        cnt[d]++;
    vector<int> pos(n);
    vector<int> nP(n);
    pos[0]= 0;
    for(int i = 1;i<n;i++)
        pos[i] = pos[i-1]+cnt[i-1];
    for(auto d:P){
        int i = c[d];
        nP[pos[i]] = d;
        pos[i]++;
    }
    P = nP;
}
// SuffixArray and LCP (Longest common preffix)
void suffixArray(string s){
	s+=char(31);
	int N;
	cin>>N;
	vector<int> nums(N);
	for(auto &c:nums)cin>>c;
	int n = s.size();
	vector<int>c(n);
	vector<int>p(n);
	vector<pair<char,int>> a(n);
	for(int i = 0;i<n;i++)a[i] = {s[i],i};
	sort(a.begin(),a.end());
	for(int i = 0;i<n;i++)
		p[i] = a[i].second;
	c[p[0]] = 0;
	for(int i = 1;i<n;i++){
		if(a[i].first == a[i-1].first)
			c[p[i]] = c[p[i-1]];
		else c[p[i]] = c[p[i-1]]+1;
	}

	int k = 0;
	while((1<<k)<n){
		for(int i = 0 ;i<n;i++)
			p[i] = ((p[i]-(1<<k))+n)%n;
		radix_sort(p,c);
		vector<int> nC(n);
		nC[p[0]] = 0;
		for(int i = 1;i<n;i++){
			pair<int,int> prev = {c[p[i-1]],c[(p[i-1]+ (1<<k))%n]};
			pair<int,int> now = {c[p[i]],c[(p[i]+ (1<<k))%n]};
			if(prev == now)
				nC[p[i]] = nC[p[i-1]];
			else nC[p[i]] = nC[p[i-1]]+1;
		}
		c = nC;
		k++;
	}
	
	// LCP O(n)
	k = 0;
	vector<int> lcp(n);
	for(int i = 0;i<n-1;i++){
		int x = c[i];
		int j = p[x-1];
		while(s[i+k] == s[j+k])k++;
		lcp[x] = k;
		k = max(k-1,0ll);
	}
	
	for(int i = 0;i<N;i++)cout<<p[nums[i]+1]<<" ";
	cout<<endl;
	for(int i = 0;i<n;i++)cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
	cout<<endl;
}
