#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<int>* adj;
    public:

    graph(int V){
        this->V=V;
        this->adj=new list<int>[V];
    }

    void add_edge(int v, int w){
        adj[v].push_back(w);
    }
    
    void dfs(int v){
        bool* visited=new bool[this->V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        dfs_helper(v,visited);
    }

    void dfs_helper(int v, bool visited[]){
        visited[v]=true;
        cout<<v<<" ";
        for(auto i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i]) dfs_helper(*i,visited);
        }
    }
};
int main(){
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,0);
    g.add_edge(3,3);
    g.dfs(2);

    return 0;
}