#include<vector>
#include<math.h>
using namespace std;
typedef vector<int> vi;
const int NEUTRO = 0;
int op(const int& a, const int& b){
    return a + b;
}

//para indexado desde 1
struct segtree{
    int n;
    vi s;
    void init(const vi& v, const int& z){
        n = 2 * pow(2 , ceil(log2(z))) - 1;
        s.resize(n);
        for(int i = n / 2,e = 0; i < n; i++,e++){
            if(e < z) s[i] = v[e];
            else s[i] = NEUTRO;
        }
        for(int i = n / 2 - 1; i >= 0; i--) s[i] = op(s[i * 2 + 1], s[i * 2 + 2]);
    }
    
    void update(int index, int val){
        index = n / 2 + index - 1;
        s[index] = val;
        while(index){
            index = (index - 1) / 2;
            s[index] = op(s[index * 2 + 1], s[index * 2 + 2]);
        }
    }

    int query(int L, int R, int l, int r, int i){
        if(l >= L && r <= R) return s[i];
        if(l >= R || r <= L) return NEUTRO;
        int mid = (l + r) / 2;
        return op(query(L, R, l, mid, i * 2 + 1), query(L, R, mid, r, i * 2 + 2));
    }
    
    int query(int L, int R){
        L--;
        return query(L, R, 0, n / 2 + 1, 0);
    }

};