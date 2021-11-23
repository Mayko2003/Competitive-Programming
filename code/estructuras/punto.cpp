#include <iostream>
#include<math.h>
using namespace std;

typedef long double ld;
struct punto{
    ld x, y;
    punto(ld a = 0, ld b = 0){
        x = a;
        y = b;
    }                      // Constructor
    punto operator+(punto a){ return punto(x + a.x, y + a.y); }     // Suma de vectores
    punto operator-(punto a){ return punto(x - a.x, y - a.y); }     // Diferencia de vectores
    punto operator*(ld a){ return punto(x*a, y*a); }                // Producto por un escalar
    ld operator*(punto a){ return x*a.x + y*a.y; }                  // Producto escalar
    ld operator^(punto a){ return x*a.y - y*a.x; }                  // Producto cruz
    long double modulo(){ return hypotl(x, y); }                    // Modulo del vector
};
ld dist_sq(punto P, punto Q){
    ld x = P.x - Q.x, y = P.y - Q.y;
    return sqrt(x*x + y*y);
}


int main(){
    punto a(1,1),b(3,3);

    int x,y;
    
    while(true){
        cin>>x>>y;
        punto c(x,y);
        c = c - a;
        a = a - b;
        if((a ^ c) > 0) cout<<"left\n";
        else if((a ^ c) == 0) cout<<"same\n";
        else cout<<"right\n";
    }
}