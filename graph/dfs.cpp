#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll x,bool vis[],ll level[],vector<vector<ll>> v){ //either v or &v
  vis[x]=true;     
  for(auto i:v[x]){
     if(vis[i])continue;
     level[i]=1+level[x];
     dfs(i,vis,level,v);
 }    
}
int main() {
	 ll n,t,m,i,j,k,ans;
	 vector<vector<ll>> v(10);
	 // 1->2    1->3  1->4  3->5 3->6 4->7 5->8 8->9
	 v[1].push_back(2);      v[1].push_back(3);      v[1].push_back(4 );      
	 v[3].push_back(5);      v[3].push_back(6);      v[4].push_back(7 );      
	 v[5].push_back(8);      v[8].push_back(9);      
	 
     bool vis[10];
     ll   level[10];
     level[1]=1;
     memset(vis,false,sizeof(vis));
	 dfs(1,vis,level,v);
	 for(i=1;i<10;i++)
	  cout<<level[i]<<" ";
     return 0;
}
