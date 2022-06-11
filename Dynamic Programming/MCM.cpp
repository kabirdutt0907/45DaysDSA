#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;



// memoization of Recursion 
int helper(int i , int j, vector<int> &v  , vector<vector<int>> &dp){

    // base case 
    if(i == j){
        return 0; // single matrix;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int op = 0;
    int mini = 1e9;
    for(int k = i ; k < j ; k++){
        op = v[i-1]*v[k]*v[j] + helper(i , k , v , dp) + helper(k+1 , j ,v , dp);
        mini = min(mini , op);
    }
    return dp[i][j] = mini;
}

int main(){


    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int &i : v){
            cin>>i;
        }
        vector<vector<int>>dp1(n+1 , vector<int>(n+1 , -1));
        cout<<"Memoization of Recursion"<<" "<<helper(1 , n-1 , v , dp1)<<"\n";
        vector<vector<int>>dp(n+1, vector<int>(n+1 , 0));
        for(int i = n-1 ; i >=1 ; i--){
            for(int j = i+1 ; j < n ; ++j){
            int op ;
            int mini = MOD;
            for(int k = i ; k < j ; k++){
                op = v[i-1]*v[k]*v[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini , op);
            }
            dp[i][j] = mini;
            }
        }
        cout<<"2-D Bottom Up"<<" "<<dp[1][n-1]<<"\n";
        
    }
	return 0;
}