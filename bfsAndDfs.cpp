#include<iostream>
#include<vector>
#include<queue>
#include<bitset>

using namespace std;

#define FILEIO(name)  freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);

void bfs(vector<vector<int>> const adjList, int node);
void dfs(vector<vector<int>> const adjList, int node);
void dfs(vector<vector<int>> const adjList, int node, bitset<20> &visited);

int main(){

    int N; //#vertices
    int E; //#edges

    FILEIO("data");

    cin>>N>>E;
    vector<vector<int>> adjList(N+1, vector<int>()); //adjacent list representation for graph
    int u,v;

    //reading edges
    for(int i=0;i<E; ++i){
        cin>>u>>v;
        //assume undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int node;
    cin>>node; //reading the node from where you wanna traverse
    bfs(adjList, node);
    dfs(adjList, node);
}

void bfs(vector<vector<int>> const adjList, int node)
{
    queue<int> q;
    bitset<20> visited(0);
    q.push(node);
    visited[node] = 1;
    cout<<"bfs: ";
    while (!q.empty())
    {
        int topEl = q.front(); q.pop();
        cout<<topEl<<' '; //process the node
        for(int child: adjList[topEl]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1;
            }
        }
    }
}

//we need to track verices, whether ther are visited or not
//If we aren't allowed to use global variables, then we can use this way
void dfs(vector<vector<int>> const adjList, int node){
    bitset<20> visited(0);
    cout<<"\ndfs: ";
    dfs(adjList,node,visited);
    
}
void dfs(vector<vector<int>> const adjList, int node, bitset<20> &visited){
    cout<<node<<' ';
   visited[node] = 1;
   for(int child: adjList[node])
   {
       if(!visited[child]){
           dfs(adjList,child,visited);
       }
   }
}