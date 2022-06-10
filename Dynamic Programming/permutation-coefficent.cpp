
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main(){


    int T;
    cin>>T;
    while(T--){
        int n, r;
        cin>>n>>r;
        vector<int>prev(r+1 , 0);
        vector<int>curr(r+1 ,0);
        prev[0] = 1;
        for(int i = 0 ; i <= r ; ++i){
            curr[i] = 1;
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= r ; ++j){
                curr[j] = ((prev[j] %MOD) + ((j % MOD)*(prev[j-1] % MOD)) % MOD)%MOD;
            }
            prev = curr;
        }
        cout<<"1-D Optimized DP"<<" "<<prev[r]<<"\n";
    }
	return 0;
}