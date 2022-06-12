// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int helper(int ind1, int ind2 , string s , string t , vector<vector<int>> &dp){
        
        if(ind1 < 0 or ind2 < 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = 1 + helper(ind1-1 , ind2-1 , s , t , dp);
        }
        return dp[ind1][ind2] = max(helper(ind1-1 , ind2 , s, t ,dp) , helper(ind1, ind2-1 , s ,t ,dp));
    
    }

    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x+1 , vector<int>(y+1 , -1));
        return helper(x-1, y-1 , s1 , s2 , dp);
        
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends