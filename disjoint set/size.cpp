#include<iostream>
#include<vector>    
using namespace std;
class DisjointSet {
    vector<int>par; vector<int>size;
    public:
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int findUpar(int node){
        if(node==par[node]) return node;
        return par[node]=findUpar(par[node]);
    }

    void unionBySize(int u, int v){
        int u_ult_par=findUpar(u);
        int v_ult_par=findUpar(v);
        if(u_ult_par==v_ult_par) return;
        if(size[u_ult_par] > size[v_ult_par]){
            size[u_ult_par] +=size[v_ult_par];
            par[v_ult_par]=u_ult_par;
        }
        else{
             size[v_ult_par] +=size[u_ult_par];
            par[u_ult_par]=v_ult_par;
        }
    
    }


};

    int main(){
    DisjointSet ds(6);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    
    if(ds.findUpar(6)==ds.findUpar(5)) cout<<"same";
    else cout<<"diff";

    if(ds.findUpar(1)==ds.findUpar(5)) cout<<"same";
    else cout<<"diff";   
}