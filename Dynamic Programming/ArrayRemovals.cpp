// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int helper(int i , int j , int k , vector<int> &a , vector<vector<int>> &dp){
        if(i >= j){
            return 0;
        }
        else if(a[j] - a[i] <= k){
            return 0;
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        else if(a[j] - a[i] > k){
            dp[i][j] = 1 + min(helper(i+1 , j , k , a , dp) , helper(i , j-1 , k ,  a , dp));
        }
        return dp[i][j];
    }
    int removals(vector<int>& a, int k){
        //Code here
        int n = a.size();
        sort(a.begin() , a.end());
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        return helper(0 , n-1 ,k , a , dp);
        
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends