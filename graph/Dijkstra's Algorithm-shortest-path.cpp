#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
typedef long long ll;
   vector<ll> djs(vector<vector<pair<ll,ll>>> v,ll src){
   vector<ll> dis(v.size(),MAX);
   dis[src]=0;
   set<pair<ll,ll>> s;
   s.insert(make_pair(0,src));
   while(!s.empty()){
     ll x=s.begin()->second;
     s.erase(s.begin());
     for(auto i:v[x]){
      if(dis[i.first]==MAX){
        dis[i.first]=i.second+dis[x];
        s.insert({dis[i.first],i.first});
      }
      else if(dis[i.first]>dis[x]+i.second){
            s.erase({dis[i.first],i.first});
            dis[i.first]=i.second+dis[x];
            s.insert({dis[i.first],i.first});   
      }
     }
   } 
   return dis;   
  }
 int main(){
 ios::sync_with_stdio(0);cin.tie(NULL);
 ll n,m,i,a,b,w;
 cin>>n>>m;
 vector<vector<pair<ll,ll>>> v(n+2);
 for( i=0;i<m;i++){
     cin>>a>>b>>w;
     v[a-1].push_back({b-1,w});
 }
 vector<ll> ans=djs(v,0);
 for(auto j=1;j<n;j++){
    cout<<ans[j]<<" ";
  }
 }   
