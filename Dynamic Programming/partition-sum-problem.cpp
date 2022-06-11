// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int index, int target , int arr[], vector<vector<int>> &dp){
        
        if(target == 0){
            return 1;
        }
        if(index == 0){
            return arr[index] == target;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        int not_take = helper(index-1 , target , arr , dp);
        int take = false;
        if(arr[index] <= target){
            take = helper(index-1,  target - arr[index] , arr , dp);
        }
        return dp[index][target] = take or  not_take;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0 ; i < N ; ++i){
            sum += arr[i];
        }
        if(sum % 2 == 1){
            return false;
        }
        vector<vector<int>>dp(N+1,  vector<int>(sum/2 + 1  , -1));
        return helper(N-1 , sum/2 , arr , dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends