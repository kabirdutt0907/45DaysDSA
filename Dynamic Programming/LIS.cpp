// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int helper(int index , int prev_index , int a[], int n , vector<vector<int>> &dp){
        
        if(index == n){
            return 0;
        }
        if(dp[index][prev_index+1] != -1 ){
            return dp[index][prev_index+1];
        }
        int len = 0 + helper(index+1 , prev_index , a , n , dp);
        if(prev_index == -1 || a[index] > a[prev_index]){
            len = max(len , 1 + helper(index+1 , index , a , n , dp));
        }
        return dp[index][prev_index+1] = len;
        // return len;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>>dp(n , vector<int>(n+1 , -1));
       return helper(0 , -1 , a , n , dp);
       
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends