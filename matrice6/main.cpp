#include <iostream>
#include <fstream>
#include <cstdlib>
#define MOD 666013
using namespace std;

int n,m,s1[6],s2[6],pot[1005][1005];

void l2(int p) {
  if(p==n+1) {
    int c1=0,c2=0;
    for(int i=1; i<=n; ++i) cout<<s1[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=n; ++i) cout<<s2[i]<<' ';
    cout<<"gata\n";
    return;
  }
  for(int i=-5; i<6; ++i) if(abs(s1[p]-s2[p])<2 && (p==1 ||  abs(s2[p]-s2[p-1])<2)){
    s2[p]=i;
    l2(p+1);
  }
}

void l1(int p) {
  if(p==n+1) {
    l2(1);
    return;
  }
  for(int i=0; i<3; ++i) {
    s1[p]=i;
    l1(p+1);
  }
}

int main()
{
    ifstream f("matrice6.in");
    ofstream g("matrice6.out");
    f>>n>>m;
    l1(2);
    return 0;
}
