// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    const int MOD = 1e9 + 7;
    /*You are required to complete below method */
    long long int helper(int st, int en , string &s , vector<vector<long long int>> &dp){
        if(st > en){
            return 0;
        }
        if(st == en){
            return 1;
        }
        if(dp[st][en] != -1){
            return dp[st][en];
        }
        if(s[st] == s[en]){
            return dp[st][en] = (1 + helper(st+1 , en , s ,dp) + helper(st , en-1 , s ,dp)) % MOD;

        }
        return dp[st][en] = ( MOD + helper(st+1 , en , s, dp) + helper(st , en-1 , s ,dp) - helper(st+1 , en-1 , s ,dp))%MOD;

        
    }
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size();
       vector<vector<long long int>>dp(n+1 , vector<long long int>(n+1 , -1));
       return helper(0 , n-1 , str , dp) % MOD;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends