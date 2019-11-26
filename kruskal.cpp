#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define FIO                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define REP(i, a, b) for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define PER(i, a, b) for (int i = int(a); i > int(b); i--)
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define all(x) (x).begin(), (x).end()
#define PB push_back
#define S second
#define F first
#define MP make_pair
#define debug(x) cout << #x << ": " << (x) << "\n"
#define CASES \
  int T;      \
  cin >> T;   \
  while (T--)

const int MOD = (int)1e9 + 7;
const int maxx = 1e5;


//start

class UnionFind{
    private:
        int V;
        vector<int> p,rnk;
        //rnk helps to reduce the tree size.and also returns size of the components (here)
    public:
        UnionFind(int V){
            //initialize
            this->V = V;
            rnk.assign(V,1);
            REP(i,0,V){
                p.PB(i);
            }

        }
        int find(int u){
            return p[u] == u ? u: p[u] = find(p[u]); //path compression
        }
        bool isSameSet(int u,int v){
            return find(u) == find(v);
        }
        void unionSet(int u,int v){
            int p1 = find(u);
            int p2 = find(v);
            if(p1 == p2) return ;
            if(rnk[p1] > rnk[p2]) p[p2] = p1, rnk[p1] += rnk[p2];
            else{
                p[p1] = p2;
                if(rnk[p1] == rnk[p2]){
                    rnk[p2] <<= 1;
                }else{
                    rnk[p2] += rnk[p1];
                }
            }
        }
};

 int main(){
     //inside main
     vector<pair<int,ii>> EdgeList;
     int E,V; //edges, vertices
     cin>>E>>V;
     int u,v,w;
     REP(i,0,E){ // Store the Edges in EdgeList DS
         cin>>u>>v>>w;
         EdgeList.PB(MP(w,MP(u,v)));
     }
     sort(all(EdgeList)); //sort in non - decreasing order
     int mst_cost = 0; //in case we wanna store the minimum cost;
     UnionFind UF(V); //for checking cycle
     REP(i,0,E){
         pair<int,ii> front = EdgeList[i];
         if(!UF.isSameSet(front.S.F,front.S.S)){ //avoiding the cycles
            mst_cost += front.F;
            UF.unionSet(front.S.F,front.S.S); //join them
         }
     }
     printf("MST cost = %d",mst_cost);

     return 0;
 }
