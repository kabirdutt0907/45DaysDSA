// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int index , int wgt ,  int val[] , int weight[] , vector<vector<int>> &dp){
        if(wgt == 0){
            return 0;
        }
        if(index < 0){
            return 0;
        }
        if(dp[index][wgt] != -1){
            return dp[index][wgt];
        }
        int include =0 ;
        if(wgt >= weight[index]){
            include = val[index] + helper(index , wgt - weight[index] , val , weight , dp);
        }
        int not_include = helper(index-1 , wgt , val , weight , dp);
        return dp[index][wgt] = max(include , not_include);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n+1 , vector<int>(w+1 , -1));
        return helper(n-1 , w , val , wt , dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends