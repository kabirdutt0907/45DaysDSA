// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int helper(int i , int j , string s , string t , vector<vector<int>> &dp){
	        if(i < 0 or j < 0){
	            return 0;
	        }
	        if(dp[i][j] != -1){
	            return dp[i][j];
	        }
	        if(s[i] == t[j] && i!= j){
	            return dp[i][j] = 1+  helper(i-1 , j-1 , s , t , dp);
	        }
	        return dp[i][j] = max(helper(i-1 , j , s , t , dp) , helper(i , j-1 , s , t , dp));
	    }
		int LongestRepeatingSubsequence(string s){
		    // Code here
		    int n = s.size();
		    vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
		  //  return helper(n-1 , n-1 , str , str , dp);
		    for(int i =1 ; i<= n ; ++i){
		        for(int j = 1 ; j <= n ; ++j){
		            if(s[i-1] == s[j-1] && i!=j){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends