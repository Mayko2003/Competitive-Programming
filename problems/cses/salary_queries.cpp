/* https://cses.fi/problemset/task/1144 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define F first
#define S second
#define pb push_back
#define pbk pop_back
#define ALL(v) v.begin(), v.end()
#define forn(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, long long> pil;
 
 
const int MAXN = 4e5;
vi all;
 
struct seg_tree{
    int n;
    vector<int> s;
    void init(const vi& v, const int& z){
        n = 2 * pow(2 , ceil(log2(z))) - 1;
        s.resize(n);
        for(int i = n / 2,e = 0; i < n; i++,e++){
            if(e < z) s[i] = v[e];
            else s[i] = 0;
        }
        for(int i = n / 2 - 1; i >= 0; i--) s[i] = s[i * 2 + 1] + s[i * 2 + 2];
    }
    void update(int index, int val){
        index = n / 2 + index;
        s[index] = val;
        while(index){
            index = (index - 1) / 2;
            s[index] = s[index * 2 + 1] + s[index * 2 + 2];
        }
    }
    int query(int L, int R, int l, int r, int i){
        if(l >= L && r <= R) return s[i];
        if(l >= R || r <= L) return 0;
        int mid = (l + r) / 2;
        return query(L,R, l , mid, i * 2 + 1) + query(L, R, mid, r, i * 2 + 2);
    }
    int query(int L, int R){
        return query(L,R,0, n / 2 + 1,0);
    }
};
 
 
int comprimir(int x){
    return lower_bound(ALL(all), x) - all.begin();
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    seg_tree st;
    int n,q;
    cin>>n>>q;
    vector<int> salarios(n);
    forn(i,n) cin>>salarios[i];
    
    all = vi(ALL(salarios));
 
    vector<char> tipos;
    vector<pii> queries;
    forn(i,q){
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c == '!') all.pb(b);
        tipos.pb(c);
        queries.pb({a,b});
 
    }
    
    sort(ALL(all));
    all.resize(unique(ALL(all)) - all.begin());
    int t = all.size();
    vi cant(t,0);
    
    forn(i,n){
        int c = comprimir(salarios[i]);
        cant[c]++;
    }
 
    //system("pause");
    st.init(cant,t);
    forn(i,q){
        int a = queries[i].F, b = queries[i].S;
        if(tipos[i] == '!'){
            a--;
            int c1 = comprimir(salarios[a]), c2 = comprimir(b);
            cant[c2]++;
            if(cant[c1] > 0) cant[c1]--;
            st.update(c1,cant[c1]);
            st.update(c2,cant[c2]);
            salarios[a] = b;
        }
        else{
            int l = comprimir(a), r = comprimir(b);
            if(all[r] == b) r++;
            cout<<st.query(l,r)<<'\n';
        }
    }
 
    return 0;
}