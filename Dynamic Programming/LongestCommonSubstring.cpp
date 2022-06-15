// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    vector<vector<int>>dp;
    int ans=0;
    int lcs(string &s1,string &s2,int n,int m){
        if(n==0 or m==0) return 0;
       int count1=0;
       if(dp[n][m]!=-1) return dp[n][m];
       if(s1[n-1]==s2[m-1]){
           count1=1+lcs(s1,s2,n-1,m-1);
       }
       int count2=lcs(s1,s2,n-1,m);
       int count3=lcs(s1,s2,n,m-1);
       ans=max({ans,count1,count2,count3});
       return dp[n][m]=count1;
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
         dp.resize(n+1,vector<int>(m+1,-1));
         lcs(s1,s2,n,m);
         return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends