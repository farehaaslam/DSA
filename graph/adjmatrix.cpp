#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;  //n-number of vertices, m-number of edges
    cin >> n >> m;
    vector<vector<int>>mat(n+1,vector<int>(n+1,0)); //adjacency list for 1 based indexing
    for(int i=0;i<m;i++){
        cout<<"enter u and v"<<endl;
        int u,v;
        cin >> u >> v;
        mat[u][v]=1;
        mat[v][u]=1;    
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}