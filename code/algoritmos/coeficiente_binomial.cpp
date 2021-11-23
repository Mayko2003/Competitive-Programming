#include<iostream>
using namespace std;
typedef long long ll;

//can use memoization
ll binomial(int n, int k){
	if(n == k || !k) return 1;
	return binomial(n - 1, k - 1) + binomial(n - 1, k);
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<binomial(n,k);
	return 0;
}