//#include <iostream>
//#include <string>
//using namespace std;
//
//string inp,tx,cons,cf,rez;
//char v[]={'a','e','i','o','u'};
//
//int isCons(char c) {
//  for(int i=0; i<5; ++i) if(tolower(c)==v[i]) return 0;
//  return 1;
//}
//
//string shift(int cnt,string s) {
//  string rez=s;
//  for(int i=0; i<s.size(); ++i) rez[i]=s[(i+cnt)%s.size()];
//  return rez;
//}
//
//int main() {
//  cin>>inp;
//  int number=0;
//  int i;
//  for(i=0; i<inp.size() && isdigit(inp[i]); ++i) number=number*10+inp[i]-'0';
//  for(; i<inp.size(); ++i) {
//    tx+=inp[i];
//    if(isCons(inp[i])) cons+=inp[i];
//  }
//  cf=shift(number,cons);
// // cout<<tx<<' '<<cons<<'\n';
//  rez=tx;
//  int ic=-1;
//  for(int i=0; i<tx.size(); ++i) {
//    if(isCons(tx[i])) rez[i]=cf[++ic];
//    else {
//      if(isupper(tx[i])) rez[i]=tolower(tx[i]);
//      else rez[i]=toupper(tx[i]);
//    }
//  }
//  cout<<rez;
//}