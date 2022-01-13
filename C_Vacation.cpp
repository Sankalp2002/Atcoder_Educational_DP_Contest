#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;

int main(){
    int t=1;
    while(t--){
        int n;
	    cin>>n;
	   // vector<int> dp(n,0);
	    vector<vector<int> > h(n,vector<int>(3,0)),dp(n,vector<int>(3,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<3;j++){
	            cin>>h[i][j];
	        }
	    }
	    //int arr[3]={0,1,2};
	    dp[0][0]=h[0][0];
	    dp[0][1]=h[0][1];
	    dp[0][2]=h[0][2];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<3;j++){
	            dp[i][j]=max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+h[i][j];
	        }
	    }
	    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<"\n";
    }
    return 0;
}
