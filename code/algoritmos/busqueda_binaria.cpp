#include<vector>
using namespace std;
typedef vector<int> vi;
//lower bound
int bs(const vi& v, const int& x){
    
    int l = -1, r = int(v.size());
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(v[mid] < x) l = mid;
        else r = mid;
    }

    //l -> contiene los '<' a 'x'
    //r -> contiene los '>=' a 'x'
    return r;
}