#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DisjointSet {
    vector<int> parent, rank;
    public:
    DisjointSet(int n){
       rank.resize(n+1,0);
       parent.resize(n+1,0);
       for(int i=0;i<=n;i++){
        parent[i]=i;
       }
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbyRank(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

};
class Solution {
  public:
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,pair<int,int>>> list;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            list.push_back({w,{u,v}});
        }
        sort(list.begin(),list.end());
        int ans=0;
        DisjointSet ds(V);
        for(auto e: list){
            int w=e.first;
            int u=e.second.first;
            int v=e.second.second;
            if(ds.findUpar(u) != ds.findUpar(v) ){
                ans+=w;
                ds.unionbyRank(u,v);
                
            }
        }
        return ans;
        
    }
};