#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;

int main(){
    int t=1;
    while(t--){
        int n;
	    cin>>n;
	    vector<int> h(n),dp(n);
	    for(int &i:h)
	        cin>>i;
	    if(n<2) return 0;
	    dp[1]=abs(h[1]-h[0]);
	    for(int i=2;i<n;i++){
	        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	    }
	    cout<<dp[n-1]<<"\n";
    }
    return 0;
}
