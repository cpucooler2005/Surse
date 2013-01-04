#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int fr[26];
long long cmb[25][25];
string s;

int fa() {
  long long r=1,tot=0;
  for(int i=0; i<26; ++i) if(fr[i]) {
    if(!tot) tot+=fr[i];
    else r*=cmb[tot][fr[i]];
  }
  return r;
}

int main() {
  for(int i=1; i<25; ++i) for(int j=0; j<25; ++j) {
    if(j==0) cmb[i][j]=1;
    else {
      cmb[i][j]=cmb[i-1][j]+cmb[i-1][j-1];
    }
  }
  int t;
  for(cin>>t;t;--t) {
    memset(fr,0,sizeof(fr));
    cin>>s;
    cout<<s<<'\n';
    for(int i=0; i<s.size(); ++i) ++fr[s[i]-'A'];
    long long rez=0;
    for(int i=0; i<s.size(); ++i) {
      for(char c='A'; c<s[i]; ++c) if(fr[c-'A']){
        --fr[c-'A'];
        cout<<i<<' '<<c<<'\n';
        rez+=fa();
        ++fr[c-'A'];
      }
      --fr[s[i]-'A'];
    }
    cout<<rez<<'\n';
  }
}
