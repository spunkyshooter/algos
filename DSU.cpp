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
            //path compression: links all the nodes to the root while back tracking
            return p[u] == u? u: p[u] = find(p[u]); 
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
        int sizeOfComponent(int u){
            return rnk[find(u)];
        }
};

//In case if vertices are strings, map them to indexes. use map<string,int>