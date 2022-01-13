#include <bits/stdc++.h>
using namespace std;
#define ll long long 
double dp[302][302][302];
double sushi(ll x,ll y,ll z,int n){
    if(x<0||y<0||z<0) return 0;
    if(x==0&&y==0&&z==0) return 0;
    if(dp[x][y][z]>-0.9) return dp[x][y][z];
	double expo=n+x*sushi(x-1,y,z,n)+y*sushi(x+1,y-1,z,n)+z*sushi(x,y+1,z-1,n);
	return dp[x][y][z]=expo/(x+y+z);
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        ll one=0,two=0,three=0; 
        vector<ll> v(n);
        for(ll &i:v){
        	cin>>i;
        	if(i==1) one++;
        	else if(i==2) two++;
        	else three++;
        }

        cout<<fixed<<setprecision(10)<<sushi(one,two,three,n)<<"\n";
    //}

    return 0;
}
