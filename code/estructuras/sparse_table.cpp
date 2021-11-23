#include<vector>
#include<math.h>
#include<iostream>
#define forn(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 1e4 + 3, K = 17, INF = 1e9 + 5;


//se puede reemplazar por suma, producto, resta, max, etc
int op(const int &a, const int &b){
	return min(a,b);
}

//sparse table para RMQ
struct sp_table{

	int sparse[MAXN][K];

	sp_table(){}
	sp_table(const vi &v){
		int t = v.size();
		forn(i,t) sparse[i][0] = v[i];
	}

	void construct(){

		for(int log = 1; log < K; log++){
			for(int i = 0; i + (1<<log) < MAXN; i++){
				//por ejemplo si quiero un rango de 4, agarro un rango de 2 desde i
				//y lo opero con otro rango de 2 pero desde i + 2, lo que seria 1 << (log - 1)
				const int b = sparse[i + (1 << (log - 1) )][log - 1];
				sparse[i][log] = op(sparse[i][log - 1], b);
			}
		}
	}
	//L y R tienen que estar indexados desde 0
	ll query(int L, int R){

		ll ans = INF;
		if(R < L) swap(L,R); 

		for(int log = K - 1; log >= 0; log--){
			if((1<<log) <= R - L + 1){
				ans = op(ans , sparse[L][log]);
				L = L + (1<<log);
			} 
		}

		return ans;
	}
};

int main(){

	int n;
	cin>>n;
	vi v(n);
	forn(i,n) cin>>v[i];

	sp_table st(v);
	st.construct();


	int q;
	cin>>q;
	while(q--){

		int L, R;
		cin>>L>>R;

		cout<<st.query(L,R)<<'\n';
	}

	return 0;
}