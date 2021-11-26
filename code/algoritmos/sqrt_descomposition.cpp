//sqrt descomposition for range sum queries

#include <iostream>
#include <math.h>
#include <vector>
#define forn(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	vi v(n);
	forn(i,n) cin>>v[i];

	int s_block = ceil(sqrt(n));

	vector<ll> blocks;
	int cont = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cont++;
		sum += v[i];
		if(cont == s_block){
			blocks.push_back(sum);
			cont = sum = 0;
		}
	}
	if(cont) blocks.push_back(sum);



	int q;
	cin>>q;
	while(q--){
		int t, l, r;
		cin>>t>>l>>r;
		if(t == 1){
			int i_block = ceil(l / s_block);
			blocks[i_block] -=  v[l];
			blocks[i_block] += r;
			v[l] = r;
		}
		else{
			int l_block = ceil(l / s_block), r_block = ceil(r / s_block);
			
			sum = 0;
			//suma de los bloques entre el bloque de L y el bloque de R
			for(int i = l_block + 1;i < r_block; i++) sum += blocks[i];

			//si estan en el mismo bloque voy de L a R
			if(l_block == r_block) for(int i = l; i <= r; i++) sum += v[i];
			else{
				//sino voy de L al limite de su bloque y sumo
				for(int i = l; i < (l_block + 1) * s_block; i++) sum += v[i];

				//tambien desde el comienzo del bloque de R hasta R
				for(int i = r_block * s_block; i <= r; i++) sum += v[i];
			}
			cout<<sum<<'\n';
		}
	}

	return 0;
}