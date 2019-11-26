#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define INF 1e9
#define F first
#define S second
#define FILEIO(name)  freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);

typedef vector<int> vi ;
typedef pair<int,int> ii;


class Dijkstra{
    vi parent; //for printing path
    vector<vector<ii>> adjacencyList;
    int V; //#verteces
    int source;//this is SSSP hence we know the source priorly
    vi dist;
    public:
    Dijkstra(int v,vector<vector<ii>> adjL,int source ) {
        this->source = source;
        dist = vi(v,INF);
        this->V = v;
        parent = vi(v);
        adjacencyList = adjL; //assiging the adjList
        for(int i= 0; i<v; ++i){
            parent[i] = i;
        }
    }
    void dijkstra(int source){

        dist[source] = 0; //dist to itself is 0
        priority_queue<ii, vector<ii>, greater<ii>> pq; //we use priority queue
        pq.push(ii(0,source));
        while(!pq.empty()){
            ii front = pq.top(); pq.pop();
            int d = front.F, u = front.S; //d = dist, u = vertex
            if(d > dist[u]) continue; //IMP check
            for(ii vertex: adjacencyList[u]){
                if(d + vertex.S < dist[vertex.F]){
                    dist[vertex.F] = dist[u] + vertex.S;//relax operation
                    //remeber the parent just to print the path
                    parent[vertex.F] = u;
                    pq.push({dist[vertex.F], vertex.F});
                }
            }
        }
    }

    void printPath(int dest){
        if(dest == source){
            cout<<source + 1<<' ';
        }
        else{
            printPath(parent[dest]);
            cout<<dest + 1<<' ';
        }
    }
    void displ_dist(){
      for(int x: dist){
        cout<<x<<' ';
      }
    }
};

int main(){
    FILEIO("data");
    int V,E; //# vertices
    cin>>V>>E;

    int u,v,w;
    vector<vector<ii>> adjacencyList(V); //first is vectex number and second is weight

    //taking input of graph
    for(int i = 0;i< E; i++){
        cin>>u>>v>>w;
        --u,--v;
        adjacencyList[u].PB({v,w}); //directed
    }
    Dijkstra d(V,adjacencyList,0);

    d.dijkstra(0); //source
    d.printPath(4);


}
