#include <bits/std++.h>
using namespace std; 
int maxProductSubarrayOfSizeK(vector<int>&A, int n, int k){ 
	sort(A.begin(), A.end()); 
	int product = 1; 
	if (A[n - 1] == 0 && (k & 1)) 
		return 0; 
	if (A[n - 1] <= 0 && (k & 1)) { 
		for (int i = n - 1; i >= n - k; i--) 
			product *= A[i]; 
		return product; 
	} 

	int i = 0; 
	int j = n - 1; 
	if (k & 1) { 
		product *= A[j]; 
		j--; 
		k--; 
	} 
	k >>= 1; 
	for (int itr = 0; itr < k; itr++) { 
		int left_product = A[i] * A[i + 1]; 
		int right_product = A[j] * A[j - 1]; 
		if (left_product > right_product) { 
			product *= left_product; 
			i += 2; 
		} 
		else { 
			product *= right_product; 
			j -= 2; 
		} 
	} 
	return product; 
} 

int main(){ 
    int n,k;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
	cout << maxProductSubarrayOfSizeK(A, n, 5 b    ); 
	return 0; 
} 
