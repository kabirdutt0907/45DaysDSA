// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int helper(int i , int j , string s , string t , vector<vector<int>> &dp){
        
        if(i < 0 or j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = 1 + helper(i-1 , j-1 , s, t , dp);
        }
        return dp[i][j] = max(helper(i-1 , j , s , t ,dp) , helper(i , j-1 , s , t, dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        string t = A;
        reverse(t.begin() , t.end());
        vector<vector<int>>dp(t.size()+1 , vector<int>(t.size()+1 , -1));
        return helper(t.size()-1 , t.size()-1 , A , t , dp);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends