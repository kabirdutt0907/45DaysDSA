// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int index , int prev_index , int A[] , int n ,  vector<vector<int>> &dp){
        
        if(index == n){
            return 0;
        }
        if(dp[index][prev_index+1] != -1){
            return dp[index][prev_index+1];
        }
        int len = helper(index+1 , prev_index , A , n , dp);
        if(prev_index == -1 || (abs(A[prev_index] - A[index]) == 1)){
            len = max(len , 1 + helper(index+1 , index , A , n ,  dp));
        }
        return dp[index][prev_index+1] = len;
        
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>>dp(N+1 , vector<int>(N+1 , -1));
        return helper(0 , -1 , A , N , dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends