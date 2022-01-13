#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;
typedef long long int ll;
int main(){
    int t=1;
    while(t--){
        ll V=0;
        ll n,w;
	    cin>>n>>w;
	    vector<pair<ll,ll>> items(n+1);
	    for(int i=1;i<=n;i++){
	        int a,b;
	        cin>>a>>b;
	        items[i]={a,b};
	        V+=b;
	    }
	    vector<vector<ll> > dp(n+1,vector<ll>(V+1,1000000000000000));
	    //sort(items.begin(),items.end());
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=V;j++){
	            if(j==0) dp[i][j]=0;
	            else if(i==0) dp[i][j]=1000000000000000;
	            else if(j<items[i].second){
	                dp[i][j]=dp[i-1][j];
	            }else{
	                dp[i][j]=min(dp[i-1][j-items[i].second]+items[i].first,dp[i-1][j]);
	            }
	        }
	    }
        for(ll j=V;j>0;j--){
            if(dp[n][j]<=w){
                cout<<j<<"\n";
                break;
            }
        }
    }
    return 0;
}
