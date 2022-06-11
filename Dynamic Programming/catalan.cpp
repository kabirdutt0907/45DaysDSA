#include<bits/stdc++.h>
using namespace std;


int helper(int index,  vector<int> &v, int n){
    if(index <= 0){
        return 1;
    }
    if(v[index] != -1){
        return v[index];
    }
    v[index] = 0;
    for(int i = 0 ; i < index ; ++i){
        v[index] += helper(i , v,  n)*helper(index - i-1 , v , n);
    }
    return v[index];
}
int main(){


    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>v(n+1 , -1);
        // cout<<helper(n , v , n)<<"\n";
        vector<int>v1(n+1 , 0);
        v1[0] = v1[1] = 1;
        for(int i = 0 ; i < n ; ++i){
            v1[0] = 1;
            for(int j = 0 ; j < i ; j++){
                v1[i] += v1[j]*v1[i - j-1];
            }
        }
        cout<<v1[n]<<"\n";
    }
	return 0;
}