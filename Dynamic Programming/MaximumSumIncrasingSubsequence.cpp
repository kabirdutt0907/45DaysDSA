// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int helper(int arr[] , int n , int index ,int prev_val ,int prev_index , vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }
        if(dp[index][prev_index+1] != -1){
            return dp[index][prev_index+1];
        }
        int len = helper(arr , n , index+1 , prev_val , prev_index , dp);
        if(prev_val == -1 || prev_index == -1 || (arr[index] + prev_val > prev_val and arr[index] > arr[prev_index])){
            len = max(len , arr[index] + helper(arr , n, index+1 , prev_val + arr[index] , index , dp));
        }
        return dp[index][prev_index+1] = len;
}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1 ,vector<int>(n+1 , -1));
        return (helper(arr , n , 0 , -1 , -1 , dp));
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends