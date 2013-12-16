#include <iostream>
#include <fstream>
#include <string>
#define LL unsigned long long
using namespace std;

int T;
LL nr;
string s;

int main()
{
    ifstream f("input.txt");
    ofstream g("output.txt");
    f>>T;
    for(int t=1; t<=T; ++t) {
      f>>s>>nr;
      string rez;
      int l=1;
      LL pc;
      for(pc=s.size(); pc<nr; nr-=pc,pc*=1ULL*s.size(),++l);
      pc/=s.size();
      for(int i=1; i<=l; ++i) {
        cout<<nr<<' '<<pc<<' '<<nr-pc<<'\n';
        int j=0;
        for(; j<s.size() && pc<nr; nr-=pc,++j);
        rez+=s[j];
        pc/=s.size();
      }
      cerr<<rez<<'\n';
      //cout<<'\n';
      g<<"Case #"<<t<<": "<<rez<<'\n';
    }
    return 0;
}