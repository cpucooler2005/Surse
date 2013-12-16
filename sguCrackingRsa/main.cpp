#include <iostream>
#include <vector>
#include <bitset>
#define DN 1000005
using namespace std;

bitset<105> ss[105];
int t,m,b[105],isp[DN];
int v[5555]={1,1};
vector<int> pr;

void dbl() {
  int trans[5555];
  for(int i=1; i<=v[0]+1; ++i) trans[i]=0;
  for(int i=1; i<=v[0]; ++i) {
    trans[i+1]=(v[i]*2)/10;
    v[i]=(v[i]*2)%10;
  }
  int i=1;
  for(;i<555;++i) {
    v[i]+=trans[i];
    trans[i+1]+=(v[i]/10);
    v[i]%=10;
    if(v[i]) v[0]=i;
  }
}

void mm() {
  int i;
  for(i=1;v[i]==0; ++i) {
    v[i]=9;
  }
  --v[i];
  for(int i=1; i<555; ++i) if(v[i]) v[0]=i;
}

void c() {
  for(int i=2; pr.size()<t; ++i) if(!isp[i]) {
    pr.push_back(i);
    for(int j=i*i; j<DN; j+=i) isp[j]=1;
  }
}

void gss() {
  int i,j,k;
  for(i=j=0; i<t && j<m;) {
    for(k=i; k<t && !ss[k][j]; ++k);
    if(k==t) {
      ++j;
      dbl();
      continue;
    }
    swap(ss[i],ss[k]);
    for(k=i+1; k<t; ++k) if(ss[k][j]) ss[k]^=ss[i];
    ++i; ++j;
  }
  for(;j<m;++j,dbl());
}

int main()
{
    cin>>t>>m;
    for(int j=0; j<m; ++j) cin>>b[j];
    c();
    for(int i=0; i<t; ++i) for(int j=0; j<m; ++j) {
      int cc=b[j];
      for(;cc%pr[i]==0;ss[i][j]=!ss[i][j],cc/=pr[i]);
    }
    gss();
    mm();
    for(int i=v[0];i;--i) cout<<v[i];
    return 0;
}