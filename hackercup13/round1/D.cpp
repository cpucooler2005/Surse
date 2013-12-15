#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> pr,pmari;
int np;
long long T,n,k,a[22],cfin[22];//costul pana la final;
long long low[55][(1<<16)],bst[22][(1<<16)];

bool isprime(int n) {
  for(int i=2; i*i<=n; ++i) if(n%i==0) return 0;
  return 1;
}

void ge() {
  //pr.push_back(0);
  //pr.push_back(1);
  for(int i=2; i<50; ++i) if(isprime(i))
    pr.push_back(i);
  for(int i=51; pmari.size()<25; ++i) if(isprime(i))
    pmari.push_back(i);
  np=pr.size();
}

void back(int nr,int st,int nc,int ind) {
  if(nc>=nr) low[nr][st]=min(low[nr][st],1LL*nc);
  if(nc>=low[nr][st] || ind>=np) return;
  if(st&(1<<ind) && nc*pr[ind]>nc) back(nr,st,nc*pr[ind],ind);
  back(nr,st,nc,ind+1);
}

void gem() {
  for(int i=1; i<=50; ++i) for(int st=0; st<(1<<np); ++st) {
    low[i][st]=(1<<30);
    back(i,st,1,0);
  }
}

int main() {
  ge();
  gem();
  ifstream f("input.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>n>>k;
    long long rez=0,rmin=(1LL<<60);
    int am0=0,am1=0;
    for(int i=0; i<n; ++i) {
      f>>a[i];
      if(!a[i]) {
        if(!am0) am0=1;
        else {
          ++a[i];
          if(!am1) {
            am1=1;
            continue;
          }
        }
      }
      for(;a[i]%k;++a[i],++rez);
      a[i]/=k;
    }
    for(int i=n-1; i>=0; --i) cfin[i]=cfin[i+1]+(pmari[i]-a[i])*k;
    int mask=(1<<np)-1;
    for(int i=0; i<(1<<np); ++i) bst[0][mask-i]=(low[a[0]][i]-a[0])*k;
    for(int i=1; i<n; ++i) for(int state=0; state<(1<<np); ++state) bst[i][state]=(1LL<<60);
    cerr<<t<<' ';
    for(int i=1; i<n; ++i) for(int state=0; state<(1<<np); ++state) {
     // cerr<<i<<' '<<state<<'\n';
      if(state==0) {
        rmin=min(rmin,bst[i-1][state]+cfin[i]);
        continue;
      }
      for(int s=state;s>0;s=state&(s-1)) {
        //aduc numarul a[i] la low[a[i]][s]
        bst[i][state^s]=min(bst[i][state^s],bst[i-1][state]+(low[a[i]][s]-a[i])*k);

      }
    }
    g<<"Case #"<<t<<": "<<rez+rmin<<'\n';
  }
}
