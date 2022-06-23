// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int n= nums.size();
		    vector<int>dp(n+1 , 0);
		    string flag = "";
		    if(n == 1){
		        return 1;
		    }
		    dp[0] = 1;
		    if(nums[1] >= nums[0]){
		        flag = "down";
		    }
		    else{
		        flag = "up";
		    }
		    for(int i = 1 ; i < n; ++i){
		        if(nums[i] > nums[i-1] and flag == "down"){
		            dp[i] = dp[i-1] + 1;
		            flag = "up";
		        }
		        else if(nums[i] < nums[i-1] and flag == "up"){
		            dp[i] = dp[i-1] + 1;
		            flag = "down";
		        }
		        else{
		            dp[i] = dp[i-1];
		        }
		    }
		    return dp[n-1];
		    

		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends