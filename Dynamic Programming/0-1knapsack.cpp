
#include<bits/stdc++.h>
using namespace std;
// by recursion 
int helper(int index , int target , vector<int> &values , vector<int> &weight){

    if(index == 0){
        if(weight[index] <= target){
            return values[index];
        }
        else{
            return 0;
        }
    }
    int not_take = helper(index -1 , target , values , weight);
    int take = INT32_MIN;
    if(weight[index] <= target){
        take = values[index] + helper(index-1 , target - weight[index] , values , weight);
    }
    return max(take , not_take);
}
// by memoization recursion
int helper1(int index , int target , vector<int> &values , vector<int> &weight , vector<vector<int>> &dp){

    if(index == 0){
        if(weight[index] <= target){
            return values[index];
        }
        else{
            return 0;
        }
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int not_take = helper1(index -1 , target , values , weight , dp);
    int take = INT32_MIN;
    if(weight[index] <= target){
        take = values[index] + helper1(index-1 , target - weight[index] , values , weight , dp);
    }
    return dp[index][target] = max(take , not_take);
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
		int n, target;
		cin>>n>>target;
		vector<vector<int>>dp1(n+1 , vector<int>(target+1 , -1));
		vector<vector<int>>dp(n+1, vector<int>(target+1 , 0));
		vector<int>weight(n);
		for(int i = 0 ; i < n ; ++i){
			cin>>weight[i];
		}
		vector<int>values(n);
		for(int i =0 ; i < n ; ++i){
			cin>>values[i];
		}
		cout<<"Recursion"<<" "<<helper(n-1 , target , weight , values);
		cout<<"DP Recursion"<<" "<<helper1(n-1,  target , weight , values , dp1);
		// tabulation DP
		for(int i = weight[0] ; i <= target ; ++i){
        	dp[0][i] = values[0];
    	}
    	for(int i = 1 ; i < n ; ++i){
        	for(int j = 0 ; j <= target ; ++j){
            		int not_take = dp[i-1][j];
            		int take = INT32_MIN;
            		if(j >= weight[i]){
                		take = values[i] + dp[i-1][j - weight[i]];
            		}
            		dp[i][j] = max(take , not_take);
        		}
    	}
    	cout<<"Tabulation DP"<<" "<<dp[n-1][target]<<"\n";
    	// Space Optimized DP
    	vector<int>prev(target+1 , 0);
    	vector<int>curr(target+1 , 0);
    	for(int i = weight[0] ; i <= target ; ++i){
        	prev[i] = values[0];
    	}
    	for(int i = 1 ; i < n ; ++i){
        	for(int j = 0 ; j <= target ; ++j){
            		int not_take = prev[j];
            		int take = INT32_MIN;
            		if(j >= weight[i]){
                		take = values[i] + prev[j - weight[i]];
            		}
            		curr[j] = max(take , not_take);
        	}
        	prev = curr;
    	}
    	cout<<"1-D Optimized DP"<<" "<<prev[target]<<"\n";



    		
	}
		return 0;
}