#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(vector<int> &nums){
	
	for(int i = 0, j = nums.size()-1; i < nums.size()/2; i++, j--){
		
		if(nums[i] != nums[j]){
			return false;
		}
	}
	return true;
}


int main (){
	
	int t; cin>>t;
	
	
	while(t--){
		
		int n; cin>>n;
		vector<int> nums(n);
		
		
		for(int i = 0; i < n; i++){
			cin>>nums[i];
		}
		
		
		if(isPalindrome(nums)){
			
			cout << "YES\n";
		
		} else {
			
			int toErase = -1;
			int cont = 0;
			
			//Der
			for(int i = 0, j = nums.size()-1; i < j;){
				
				if(toErase == nums[i]){i++;continue;}
				if(toErase == nums[j]){j--;continue;}
			        
                                if(nums[i] != nums[j]){
					if(toErase == -1) toErase = nums[j];										
					j--;
					cont++;
				} else {
					i++, j--;
				}
	
			}
			
			if(cont <= 1){
				cout << "YES\n";
				continue;
			}
			
			toErase = -1;
			cont = 0;

			
			for(int i = 0, j = nums.size()-1; i < j;){
				
				if(toErase == nums[i]){i++;continue;}
				if(toErase == nums[j]){j--;continue;}
				
				if(nums[i] != nums[j]){
					if(toErase == -1) toErase = nums[i];										
					i++;
					cont++;
				} else {
					i++, j--;
				}
	
			}
			
			if(cont <= 1){
				cout << "YES\n";
				continue;
			}
			
			cout << "NO\n";
		}
		
		
	} 
	
	
	return 0;	
}
