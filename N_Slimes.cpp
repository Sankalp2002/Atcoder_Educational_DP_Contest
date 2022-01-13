#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll dp[401][401];
ll sum[401][401];
ll slimes(vector<ll> &a,int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll mincost =1000000000000000;
    for(int k=i;k<j;k++){
        mincost=min({mincost,slimes(a,i,k)+slimes(a,k+1,j)+sum[i][j]});
    }
    return dp[i][j]=mincost;
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        ll n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        memset(sum,0,sizeof(sum));
        vector<ll> arr(n+1);
        for(int i=1;i<n+1;i++){
        	cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                sum[i][j]=arr[j]+((i==j)? 0:sum[i][j-1]);
            }
        }
        cout<<slimes(arr,1,n)<<"\n";
    //}

    return 0;
}
