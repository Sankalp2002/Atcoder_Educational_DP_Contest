#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
double fun(vector<double> &prob,int i,int x,vector<vector<double> > &dp){
    if(x==0) return 1;
    if(i==0) return 0;
    if(dp[i][x]>-0.1) return dp[i][x];
    return dp[i][x]=prob[i]*fun(prob,i-1,x-1,dp)+(1-prob[i])*fun(prob,i-1,x,dp);
}
int main(){
    int t=1;
    while(t--){
        int n;
	    cin>>n;
	    vector<double> prob(n+1);
	    for(int i=1;i<n+1;i++){
	        cin>>prob[i];
	    }
	    vector<vector<double> > dp(n+2,vector<double>(n+2,-1));
        cout<<fixed<<setprecision(10)<<fun(prob,n,(n+1)/2,dp)<<endl;
    }
    return 0;
}
