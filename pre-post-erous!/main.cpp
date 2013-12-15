#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define DN 30
#define LL long long
using namespace std;

LL v[DN],c[DN][DN];
string a,b;
int deg,poz[300],p;
vector<int> gr[DN];

void dfs(int pc) {
  for(;p<a.size() && poz[a[pc]]<poz[a[p]];) {
    ++v[pc];
    dfs(p++);
  }
}

int main()
{
  c[0][0]=1;
  for(int i=1; i<DN; ++i) {
    c[i][0]=1;
    for(int j=1; j<=i; ++j) c[i][j]=c[i-1][j-1]+c[i-1][j];
  }
  for(;;) {
    cin>>deg;
    if(!deg) break;
    cin>>a>>b;
    reverse(b.begin(),b.end());
    for(int i=0; i<b.size(); ++i) {
      v[i]=0;
      poz[b[i]]=i;
    }
    p=1;
    dfs(0);
    LL r=1;
    for(int i=0; i<a.size(); ++i) {
      r*=c[deg][v[i]];
     // cerr<<v[i]<<' ';
    }
    cout<<r<<'\n';
  }
  return 0;
}
