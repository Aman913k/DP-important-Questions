#define ll long long
#include <iostream> 
using namespace std;
#include<bits/stdc++.h> 

ll dp[100001][101];

int solve(int n, vector<ll>& v, int money,  unordered_map<ll, ll>& mp, int indx){
    if(indx>=n){
        mp[money]=1;
        return 1;
    }
    
    if(dp[money][indx]!=-1) return dp[money][indx];
    
    ll pick=solve(n, v, money+v[indx], mp, indx+1);
    ll nonpick=solve(n, v, money, mp, indx+1);

    return dp[money][indx]=pick+nonpick;
}


int main(){
    int n;
    cin>>n;

    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    unordered_map<ll, ll> mp;
    memset(dp, -1, sizeof dp);
  
    solve(n, v, 0, mp, 0);       
    cout<<mp.size()-1<<endl;
    
    vector<ll> ans;
    for(auto i: mp) ans.push_back(i.first);
    
    sort(ans.begin(), ans.end());
    for(int i=1; i<ans.size(); i++) cout<<ans[i]<<" ";
    
}
