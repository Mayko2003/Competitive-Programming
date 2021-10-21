//aun en revision el calculo del lca
#include<vector>
#include<math.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
const int MAXN = 1e5 + 7,LOGN = 18, RAIZ = 0;

vi travel, mat[MAXN], dist(MAXN);
vector<bool> vis(MAXN,false);
struct lca_table{
    int sparse[MAXN][LOGN], level[MAXN];

    void construct(int nodo, int lev){
        level[nodo] = lev;
        int t = travel.size();
        for(int log = 0, p = 1; p <= t; log++, p *= 2) sparse[nodo][log] = travel[t - p];
    }

    int lca(int u, int v){
        if(level[u] < level[v]) swap(u,v);

        int log = log2(level[u]);

        //nivelar
        for(int i = log; i >= 0; i--)
            if(level[u] - (1<<i) >= level[v]) u = sparse[u][i];
        
        if(u == v) return u;

        //subir
        for(int i = log; i >= 0; i--)
            if(sparse[u][i] != sparse[v][i]) u = sparse[u][i], v = sparse[v][i];
        //retornar lca
        return sparse[u][0];

    }
}lca;

void dfsInit(int act, int padre, int lev){
    vis[act] = true;
    lca.construct(act,lev);
    travel.pb(act);
    for(auto hijo : mat[act]){
        if(hijo == padre) continue;
        dfsInit(hijo, act, lev + 1);
        dist[hijo] = dist[act] + 1;
    }
    travel.pop_back();
}