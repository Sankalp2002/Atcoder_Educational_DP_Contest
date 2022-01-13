#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[3002][3002][2];
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        vector<ll> arr(n);
        for(ll &i:arr){
        	cin>>i;
        }
        for(int i=0;i<n;i++){
            dp[i][i][0]=arr[i];
            dp[i][i][1]=-arr[i];
        }
        for(int d=1;d<n;d++){
            for(int i=0;i<n-d;i++){
                int j=i+d;
                int m=n-j+i-1;
                if(m%2==0)
                    dp[i][j][0]=max(arr[i]+dp[i+1][j][1],arr[j]+dp[i][j-1][1]);
                else
                    dp[i][j][1]=min(dp[i+1][j][0]-arr[i],dp[i][j-1][0]-arr[j]);
            }
        }
        cout<<dp[0][n-1][0]<<"\n";
    //}

    return 0;
}
