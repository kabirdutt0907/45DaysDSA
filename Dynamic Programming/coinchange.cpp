
#include<bits/stdc++.h>
using namespace std;

// using recursion 
int helper(int index , int target , vector<int> &nums){

	if(index == 0){
		if(target % nums[index] == 0){
			return target/nums[index];
		}
		return 1e9;
	}
	int not_take = helper(index-1 , target , nums);
	int take = INT32_MAX;
	if(nums[index] <= target){
		take = 1 + helper(index , target - nums[index] , nums);
	}
	return min(take , not_take);
}
//using memoization on recursion
int helper1(int index , int target , vector<int> &nums , vector<vector<int>> &dp){

	if(index == 0){
		if(target % nums[index] == 0){
			return target/nums[index];
		}
		return 1e9;
	}
	if(dp[index][target] != -1){
		return dp[index][target];
	}
	int not_take = helper1(index-1 , target , nums , dp);
	int take = INT32_MAX;
	if(nums[index] <= target){
		take = 1 + helper1(index , target - nums[index] , nums , dp);
	}
	return dp[index][target] = min(take , not_take);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef KABIROP
          freopen("error.txt" , "w" , stderr);
    #endif
	int T;
	cin>>T;
	while(T--){
		int n , target;
		cin>>n>>target;
		vector<int>v(n);
		for(int i =0  ; i < n ; ++i){
			cin>>v[i];
		}
		int ans = 0;
		//normal recursion call
		ans = helper(n-1 , target , v);
		cout<<ans<<"\n";
		//memoization recursion call
		vector<vector<int>>dp1(n+1 , vector<int>(target , -1));
		ans = helper1(n-1 , target , v , dp1);
		cout<<ans<<"\n";
		// eliminating extra stack space for recursion
		vector<vector<int>>dp(n+1 , vector<int>(target , 0));

		for(int T = 0 ; T <= target ; T++){

			if(T % v[0] == 0){
				dp[0][T] = T/v[0];
			}
			else{
				dp[0][T] = 1e9;
			}
		}

		for(int i= 1 ; i < n ; ++i){
			for(int T = 0 ; T <= target ; T++){
				int not_take = dp[i-1][T];
				int take = INT32_MAX;
				if(v[i] <= T){
					take = 1 + dp[i][T- v[i]];
				}
				dp[i][T] = min(take , not_take);
			}
		}
		cout<<(dp[n-1][target])<<"\n";

		// eliminating 2-D matrix by normal 2 vector 
		vector<int>prev(target+1 , 0);
		vector<int>curr(target+1 , 0);
		for(int T = 0; T <= target ; ++T){
			if(T % v[0] == 0){
				prev[T] = T/v[0];
			}
			else{
				prev[T] = 1e9;
			}
		}
		for(int i = 1 ; i < n ; ++i){
			for(int T = 0 ; T <= target ; T++){
				int not_take = prev[T];
				int take = INT32_MAX;
				if(v[i] <= T){
					take = 1 + curr[T- v[i]];
				}
				curr[T] = min(take , not_take);
			}
			prev = curr;
		}
		cout<<(prev[target])<<"\n";



		
	}
	return 0;
}