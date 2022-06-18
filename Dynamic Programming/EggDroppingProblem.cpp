// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    const int MOD = 1e9 + 7;
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int helper(int egg , int floor , vector<vector<int>> &dp){

        if(egg == 1 || floor <= 1){
            return floor;
        }
        if(dp[egg][floor] != -1){
            return dp[egg][floor];
        }
        // if(floor <= 1)
        int ans = MOD , temp_ans = MOD;
        for(int i = 1 ; i <= floor ; ++i){
            temp_ans =1 + max(helper(egg-1 , i-1 , dp) , helper(egg , floor-i , dp));
            ans = min(ans , temp_ans);
        }
        return dp[egg][floor] = ans;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int>>dp(e+1 , vector<int>(f+1 , -1));
        return (helper(e , f, dp));
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends