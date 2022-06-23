// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int helper(string &s , int index , unordered_set<string> &st , vector<int> &dp){
        
        if(index == s.size()){
            return 1;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        string tmp = "";
        for(int j = index ; j < s.size() ; j++){
            tmp += s[j];
            if(st.find(tmp) != st.end()){
                if(helper(s , j+1 , st , dp) == 1){
                    return dp[index] = 1;
                }
            }
        }
        return dp[index] = 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string>st;
        vector<int>dp(A.size()+1 , -1);
        for(auto it : B){
            st.insert(it);
        }
        return helper(A , 0 , st , dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends