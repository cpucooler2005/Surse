#include <iostream>
using namespace std;

int i, x, y, z, x1, y1, z1, rez = 0, a[7];

int main() {
        cin >> x >> y >> z >> x1 >> y1 >> z1;
        for(i = 1; i <= 6; ++i) cin >> a[i];
        if(y<0) rez += a[1];
        if(y>y1) rez += a[2];
        if(z<0) rez += a[3];
        if(z>z1) rez += a[4];
        if(x<0) rez += a[5];
        if(x>x1) rez += a[6];
        cout<< rez;
        return 0;
}
