
#include<bits/stdc++.h>
using namespace std;
// by recursion 
const int MOD = 1000000007;
int helper(int n , int r){

    if(n < 0 or r < 0){
        return 0;
    }
    if(n == 0 or n == r){
        return 1;
    }
    return ((helper(n-1 , r-1) % MOD)  + (helper(n-1 ,r) % MOD)) %MOD;
}
// by memoization recursion
int helper1(int n , int r , vector<vector<int>> &dp){
    if(n < 0 or r < 0){
        return 0;
    }
    if(n == 0 or n == r){
        return 1;
    }
    if(dp[n][r] != -1){
        return dp[n][r];
    }
    return dp[n][r] = ((helper(n-1 , r-1) % MOD)  + (helper(n-1 ,r) % MOD)) %MOD;
    
}


int main(){


    int T;
    cin>>T;
    while(T--){
        int n, r;
        cin>>n>>r;
        vector<vector<int>>dp1(n+1 , vector<int>(r+1 , -1));        
        vector<vector<int>>dp2(n+1 , vector<int>(r+1 , 0));
        cout<<"Recursion"<<" "<<helper(n , r);
        cout<<"DP Recursion"<<" "<<helper1(n,r , dp1);
        for(int i =0  ; i <= n ; ++i){
            dp2[0][i] = 1;
        }
        for(int i =0  ; i <= r ; ++i){
            dp2[i][0] = 1;
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <=r ; ++j){
                if(i == j){
                    dp2[i][j] = 1;
                }
                else{
                    dp2[i][j] = ((dp2[i-1][j-1] % MOD) + (dp2[i-1][j] % MOD))%MOD;
                }
            }
        }
        cout<<"Tabulation DP"<<" "<<dp2[n][r]<<"\n";
        vector<int>prev(r+1 , 0);
        vector<int>curr(r+1 ,0);
        prev[0] = 1;
        for(int i = 0 ; i <= r ; ++i){
            curr[i] = 1;
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= r ; ++j){
                if(i == j){
                    curr[j] = 1;
                }
                else{
                    curr[j] = ((prev[j-1] %MOD) + (prev[j] % MOD))%MOD;
                }
            }
            prev = curr;
        }
        cout<<"1-D Optimized DP"<<" "<<prev[r]<<"\n";



    }
	return 0;
}