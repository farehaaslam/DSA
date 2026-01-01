#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m; //n-.vertices , m->edge;
    cin>>n>>m;
    //vector <int> adj[n+1]; //adjacency list for 1 based indexing //=>doesnt work with this compiler 
    vector<vector<int>>adj(n+1); // n+1 rows empty rows;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //print
    for(auto x:adj){

        for(int y:x){
            cout<<y;
        }
        cout<<endl;
    }
}