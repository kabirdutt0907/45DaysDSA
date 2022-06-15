// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int mx = 0;
    int helper(int i , int j , vector<vector<int>> &v , vector<vector<int>> &dp){
        
        if(i < 0 or i > v.size()-1 or j < 0 or j > v[0].size()-1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mx = 0;
        mx += v[i][j] + max(helper(i+1 , j , v , dp) , max(helper(i+1 , j-1 , v ,dp) , helper(i+1 , j+1, v , dp)));
        dp[i][j] = mx;
    }
    int maximumPath(int N, vector<vector<int>> v)
    {
        // code here
        vector<vector<int>>dp(N+1 , vector<int>(N+1 , -1));
        int mx = -1;
        for(int i = 0 ; i < N ; ++i){
            mx = max(mx , helper(0 , i , v , dp));
        }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends