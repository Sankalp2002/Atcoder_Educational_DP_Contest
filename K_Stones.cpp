#include <bits/stdc++.h>
using namespace std;
#define ll long long 

string stones(vector<int> &arr,int k){
    vector<bool> dp(k+1,false);
    for(int i=1;i<=k;i++){
        for(int val:arr){
        if(val>i) continue;
        if(!dp[i-val])
            dp[i]=true;
    }
    }
    return dp[k]? "First":"Second";
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int &i:arr){
        	cin>>i;
        }

        cout<<stones(arr,k)<<"\n";
    //}

    return 0;
}
