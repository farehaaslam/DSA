#include <iostream>
#include <vector>
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
int main(){
    DisjointSet ds(6);
    ds.unionbyRank(1,2);
    ds.unionbyRank(2,3);
    ds.unionbyRank(4,5);
    ds.unionbyRank(6,7);
    ds.unionbyRank(5,6);
    
    if(ds.findUpar(6)==ds.findUpar(5)) cout<<"same";
    else cout<<"diff";

    if(ds.findUpar(1)==ds.findUpar(5)) cout<<"same";
    else cout<<"diff";   
}