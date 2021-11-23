#include<vector>
#include<math.h>
#define forn(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;
const int MAXN = 1e5 + 7,LOGN = 18, RAIZ = 0;

vi mat[MAXN], dist(MAXN);
vector<bool> vis(MAXN,false);
struct lcatable{
    int sparse[MAXN][LOGN], level[MAXN];

    //constructor
    lcatable(){
        forn(i,MAXN) forn(j,LOGN) sparse[i][j] = RAIZ;
        level[RAIZ] = -1;
    }

    void initNode(int n, int p){
        level[n] = level[p] + 1;
        sparse[n][0] = p;
        for(int i = 1; i < LOGN; i++) p = sparse[n][i - 1],sparse[n][i] = sparse[p][i - 1];
    }

    int lca(int u, int v){
        if(level[u] < level[v]) swap(u, v);
        int i;
        for(i = 0; level[u] - (1<<i) > level[v]; i++);
        for(; level[u] > level[v]; i--){
            if(level[u] - (1<<i) < level[v]) continue;
            u = sparse[u][i];
        }
        if(u == v) return u;
        for(i = 0; sparse[u][i] != sparse[v][i]; i++);
        for(; i >= 0; i--){
            if(sparse[u][i] == sparse[v][i]) continue;
            u = sparse[u][i];
            v = sparse[v][i];
        }
        return sparse[u][0];
    }
}lca;

void dfsInit(int n, int p){
    vis[n] = true;
    lca.initNode(n,p);
    for(auto hijo : mat[n]){
        if(hijo == p) continue;
        dfsInit(hijo, n);
        dist[hijo] = dist[n] + 1;
    }
}
int main(){
    return 0;
}