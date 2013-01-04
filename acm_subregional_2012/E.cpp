#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char c[100005];
int d=-1,sz;
vector<int> v;

int solve() {
  int r=0,sum=0;
  sort(v.begin(),v.end());
  for(int i=0; i<v.size(); ++i) {
    sum+=v[i];
    if(sum<d) r+=(d-sum);
  }
  return r;
}

int main()
{
  int nr=0;
  for(int i=5;;++i) {
    if(i>=sz) {
      fread(c,100005,100005,stdin);
      sz=strlen(c);
      i=0;
    }
    if(nr==0 && c[i]=='\n') {
      printf("Ben can earn %d points!\n",solve());
      d=-1;
      nr=0;
      v.clear();
    }else if(c[i]=='\n') {
      if(d==-1) d=nr;
      else v.push_back(nr);
      nr=0;
    }else if(isdigit(c[i])) {
      nr=nr*10+c[i]-'0';
    }
  }
}
