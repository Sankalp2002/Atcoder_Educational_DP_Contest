#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;
typedef long long int ll;
int main(){
    int t=1;
    while(t--){
        ll n,w;
	    cin>>n>>w;
	    vector<pair<ll,ll>> items(n+1);
	    vector<vector<ll> > dp(n+1,vector<ll>(w+1,0));
	    for(int i=1;i<=n;i++){
	        int a,b;
	        cin>>a>>b;
	        items[i]={a,b};
	    }
	    //sort(items.begin(),items.end());
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=w;j++){
	            if(j<items[i].first){
	                dp[i][j]=dp[i-1][j];
	            }else{
	                dp[i][j]=max(dp[i-1][j-items[i].first]+items[i].second,dp[i-1][j]);
	            }
	        }
	    }
	    cout<<dp[n][w]<<"\n";
    }
    return 0;
}
