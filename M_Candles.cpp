#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll dp[101][100001];
ll candies(vector<ll> &arr, ll n, ll k){
    for(int i=0;i<=k;i++){
        dp[1][i]=(i>arr[1])? 0:1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=(mod+dp[i][j-1]%mod+dp[i-1][j]%mod-((j-arr[i]-1>=0)?dp[i-1][j-arr[i]-1]%mod:0))%mod;
            }
        }
    }
    return dp[n][k];
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        ll n,k;
        cin>>n>>k;
        memset(dp,0,sizeof(dp));
        vector<ll> arr(n+1);
        for(int i=1;i<n+1;i++){
        	cin>>arr[i];
        }
        
        
        cout<<candies(arr,n,k)<<"\n";
    //}

    return 0;
}
