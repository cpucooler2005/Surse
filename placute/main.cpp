#include <iostream>
#include <fstream>
#include <set>
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int > per;
typedef set<per,greater<per> >::iterator is;

int n,k,lst=-1,rez,fr[1005],g[100005],c[100005];
set<per,greater<per> > s;
multiset<int,greater<int> > w[1005];

int main()
{
    ifstream f("placute.in");
    ofstream go("placute.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
      f>>g[i]>>c[i];
      ++fr[c[i]];
      w[c[i]].insert(g[i]);
    }
    for(int i=1; i<=k; ++i) if(w[i].size()){
      s.insert(mp(*w[i].begin(),fr[i]));
      w[i].erase(w[i].begin());
    }
    go<<rez;
    return 0;
}
