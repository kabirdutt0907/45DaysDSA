#include<bits/stdc++.h>
using namespace std;


int helper(int i , int j , string s , string t){

    if(j < 0){
        return i+1;
    }
    if(i < 0 ){
        return j+1;
    }
    if(s[i] == t[j]){
        return helper(i-1 , j-1 , s, t);
    }
    // insert the character 
    int op1 = 1 + helper(i , j-1 , s, t);
    // delete the character 
    int op2 = 1 + helper(i-1 , j , s , t);
    // replace the character 
    int op3 = 1 + helper(i-1, j-1, s,  t);
    return min(op1 , min(op2, op3));
}
int helper1(int i , int j , string s , string t, vector<vector<int>>& dp){

    if(j < 0){
        return i+1;
    }
    if(i < 0 ){
        return j+1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = helper1(i-1 , j-1 , s, t , dp);
    }
    // insert the character 
    int op1 = 1 + helper1(i , j-1 , s, t ,dp);
    // delete the character 
    int op2 = 1 + helper1(i-1 , j , s , t , dp);
    // replace the character 
    int op3 = 1 + helper1(i-1, j-1, s,  t ,dp);
    return dp[i][j] = min(op1 , min(op2, op3));
}

int main(){


    int T;
    cin>>T;
    while(T--){
        string s , t;
        cin>>s>>t;
        int n = s.size();
        int m = t.size();
        cout<<"Recursion"<<" "<<helper(s.size()-1 , t.size()-1 , s, t)<<"\n";
        vector<vector<int>>dp1(n+1 , vector<int>(m+1 ,-1));
        cout<<"Memo Recursion"<<" "<<helper1(n-1 , m-1 , s , t , dp1)<<"\n";
        vector<vector<int>>dp(n+1 ,vector<int>(m+1 , 0));
        for(int i = 0 ; i <= n ; ++i){
            dp[i][0] = i;
        }
        for(int j = 0 ; j <= m ; ++j){
            dp[0][j] = j;
        }

        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= m ; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j]));
                }
            }
        }
        cout<<"tabulation DP"<<" "<<dp[n][m]<<"\n";
        m = t.size(), n = s.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            pre[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = pre[j - 1];
                } else {
                    cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        // debug(prev);
        cout<<"1-D DP"<<" "<<pre[n]<<"\n";



    }
    return 0;
}