// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mx = 0;
    int helper(int i , int j , vector<vector<int>> &v , vector<vector<int>> &dp){
    
        if(i < 0 or i > v.size()-1 or j < 0 or j > v[0].size()-1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        mx = v[i][j] + max(helper(i+1 , j+1 , v , dp) , max(helper(i-1 , j+1 , v ,dp) , helper(i , j+1, v , dp)));
        return dp[i][j] = mx;
    }
    int maxGold(int n, int m, vector<vector<int>> v)
    {
        // code here
         vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
         int mx = -1;
         for(int i = 0 ; i < n ; ++i){
                mx = max(mx , helper(i , 0 , v , dp));
         }
         return (mx);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends