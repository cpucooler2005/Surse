#include <iostream>
#include <cmath>
using namespace std;

//struct punct{
//  int x,y;
//  int f(punct b) {
//    return sqrt((b.x-x)*(b.x-x)+(b.y-y)*(b.y-y));
//  }
//};
//
//struct dreptunghi {
//  punct a,b;
//
//  int arie() {
//    return (a.x-b.x)*(a.y-b.y);
//  }
//
//  int perimetru() {
//    return 2*(a.x-b.x)+2*(a.y-b.y);
//  }
//};

struct boxer {
  char nume[555];
  int putere;
  int isDead;
  void lupta(boxer inamic) {
    if(inamic.putere>putere) isDead=1;
    else putere-=inamic.putere;
  }
  void afiseaza() {
    cout<<nume<<' '<<putere<<' ';
    if(isDead) cout<<"Mort\n";
    else cout<<"Viu\n";
  }
};


int main()
{
  boxer a,b,c;
  c.afiseaza();
  cin>>a.nume>>a.putere>>b.nume>>b.putere>>c.nume>>c.putere;
  //a.isDead=0;

  a.afiseaza();
  a.lupta(b);
  a.afiseaza();
  a.lupta(c);
  a.afiseaza();
  return 0;
}