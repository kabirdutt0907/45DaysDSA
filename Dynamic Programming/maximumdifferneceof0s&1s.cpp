// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int f(int i,int j,int arr[],int N,int K,  vector<vector<int>>&dp)
    {
        int take=0,nottake=0;
        if(j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(arr[i]-arr[j]<K)
        take=arr[i]+arr[j]+f(j-1,j-2,arr,N,K,dp);
        nottake=f(i-1,j-1,arr,N,K,dp);
        return dp[i][j]=max(take,nottake);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        sort(arr , arr + N);
        vector<vector<int>>dp(N+1 , vector<int>(N+1 , -1));
        return f(N-1,N-2,arr,N,K,dp);
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends