// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int solve(vector<int>& price, int index,bool canBuy, int transAllowed, int n, vector<vector<vector<int>>>& dp){
    if(transAllowed == 0 || index >= n){
        return 0;
    }
    
    if(dp[index][canBuy][transAllowed] != -1){
        return dp[index][canBuy][transAllowed];
    }
    if(canBuy == true){
        int idle = solve(price, index + 1, canBuy, transAllowed, n, dp);
        int buy = -price[index] + solve(price, index + 1, !canBuy, transAllowed, n, dp);
        return dp[index][canBuy][transAllowed] = max(idle, buy);
    }else{
        int idle = solve(price, index + 1, canBuy, transAllowed, n, dp);
        int sell = price[index] + solve(price, index + 1, !canBuy, transAllowed - 1, n, dp);
        return dp[index][canBuy][transAllowed] = max(idle, sell);
    }
}
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, -1)));
    return solve(price, 0, true, 2, n, dp);
    
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends