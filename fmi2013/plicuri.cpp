#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define DN 100005
using namespace std;

typedef pair<int,int> per;

int n,a[DN],b[DN],ind[DN],lgm[DN],r,aib[DN];
vector<per> v;

bool cmp(int x,int y) {
  if(a[x]==a[y]) return b[x]<b[y];
  return a[x]<a[y];
}

int lsb(int x){
  return (x&(x-1))^x;
}

void update(int p,int v) {
  for(int i=p; i<DN; i+=lsb(i)) aib[i]=max(aib[i],v);
}

int query(int p) {
  int r=0;
  for(int i=p; i;i-=lsb(i)) r=max(r,aib[i]);
  return r;
}

int main() {
  ifstream f("plicuri.in");
  ofstream g("plicuri.out");
  f>>n;
  for(int i=1; i<=n; ++i) {
    int l,w;
    f>>l>>w;
    if(l>w) swap(l,w);
    a[i]=l;
    b[i]=w;
    ind[i]=i;
  }
  sort(ind+1,ind+n+1,cmp);
  int j=1;
  lgm[1]=1;
  for(int i=2; i<=n; ++i) {
    if(a[ind[i]]>a[ind[i-1]]) {
      for(;j<i;++j) {
        update(b[ind[j]],lgm[j]);
      }
    }
    lgm[i]=1+query(b[ind[i]]-1);
    //cout<<i<<' '<<a[ind[i]]<<' '<<b[ind[i]]<<' '<<lgm[i]<<'\n';
    r=max(r,lgm[i]);
  }
  g<<r;
}