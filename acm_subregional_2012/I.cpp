#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

per p;
int t,n,m;
vector<per> v;
multiset<int> miy;
multiset<int,greater<int> > may;

int faar(int minx,int maxx, int miny, int maxy) {
  --minx; --miny; ++maxx; ++maxy;
  //cout<<minx<<' '<<miny<<' '<<maxx<<' '<<maxy<<'\n';
  return (maxx-minx)*(maxy-miny);
}

int solve(int a,int b) {
  int r=(1<<30);
  //cout<<a<<' '<<b<<":\n";
  for(int i=a; i-a+1<=m; ++i) {
    miy.insert(v[i].y);
    may.insert(v[i].y);
  }
  for(int i=a+m-1;i<=b;++i) {
    r=min(r,faar(v[a].x,v[b].x,*miy.begin(),*may.begin()));
    miy.erase(miy.find(v[i-m+1].y));
    may.erase(may.find(v[i-m+1].y));
    miy.insert(v[i+1].y);
    may.insert(v[i+1].y);
  }
  miy.clear(); may.clear();
  return r;
}

int main() {
freopen("inp.in","r",stdin);
  for(cin>>t;t;--t) {
  int r=(1<<30);
    v.clear();

    cin>>n>>m;
    for(int i=1; i<=n; ++i) {
      cin>>p.x>>p.y;
      v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); ++i) for(int j=i+m-1; j<v.size(); ++j) r=min(r,solve(i,j));

    cout<<r<<'\n';
  }
}
