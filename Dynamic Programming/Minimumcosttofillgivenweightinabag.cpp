// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
const int MOD = 1e9 + 7;
class Solution{
		

	public:
	long long int dp[201][201];
   long long int helper(int cost[],int n,int w){
       if(w == 0) return 0;
       if(n == 0 || w < 0) return INT_MAX;
       if(dp[n][w] != -1) return dp[n][w];
       if(cost[n-1] != -1)
           return dp[n][w] = min(cost[n-1] + helper(cost,n,w-n), helper(cost,n-1,w));
       else return dp[n][w] = helper(cost,n-1,w);
   }
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
         memset(dp,-1,sizeof(dp));
        return helper(cost,N,W);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends