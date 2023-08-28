#define ll long long
#include <iostream> 
using namespace std;
#include<bits/stdc++.h> 

ll dp[1000001];

ll solve(vector<vector<ll>>& v, vector<ll>& temp, int indx){
    if(indx>=v.size()){
        return 0; 
    }
    
    if(dp[indx]!=-1) return dp[indx];
    
    ll pick=0, nonpick=0;
    auto it=upper_bound(temp.begin(), temp.end(), v[indx][1])-temp.begin();
    
    pick=v[indx][2]+solve(v, temp, it);
    nonpick=solve(v, temp, indx+1);
    
    return dp[indx]=max(pick,nonpick);
    
}


int main(){
    int n;
    cin>>n;
    
    memset(dp, -1, sizeof(dp));    

    vector<vector<ll>> v(n);
    for(int i=0; i<n; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v[i]={a,b,c};     
    }
    
    sort(v.begin(), v.end());
    vector<ll> temp;
    
    for(auto i: v) temp.push_back(i[0]);    
    cout<<solve(v, temp, 0)<<endl;

    
}