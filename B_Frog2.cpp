#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;

int main(){
    int t=1;
    while(t--){
        int n,k;
	    cin>>n>>k;
	    vector<int> h(n),dp(n,INT_MAX);
	    for(int &i:h)
	        cin>>i;
	    if(n<2) return 0;
	    dp[0]=0;
	    for(int i=1;i<n;i++){
	        for(int j=1;j<=k;j++){
	            if(i-j<0) break;
	            dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
	        }
	    }
	    cout<<dp[n-1]<<"\n";
    }
    return 0;
}
