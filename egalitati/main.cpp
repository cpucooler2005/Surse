#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string s;
int nrd;

int main()
{
    ifstream f("egalitati.in");
    ofstream g("egalitati.out");
    getline(f,s);
    s+=';';
    int rez=1;
    for(int i=0; i<s.size(); ++i) {
      if(s[i]=='(') ++nrd;
      else if(s[i]==')') {
        if(nrd<1) rez=0;
        else --nrd;
      }else if(s[i]=='=') {
        if(nrd>0) rez=0;
        nrd=0;
      }else if(s[i]==';') {
        g<<rez<<'\n';
        nrd=0;
      }
    }
    return 0;
}
