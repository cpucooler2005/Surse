//#include <iostream>
//#include <fstream>
//#include <string>
//#include <set>
//#define MOD 9001
//using namespace std;
//
//int n,k,nr[100005],sp[100005],dsp[100005];
//string s;
//set<char> v;
//
//int cb(int i) {
//  int ls=0,ld=i-1,m,r;
//  for(;ls<=ld;) {
//    m=(ls+ld)/2;
//    if(sp[i]-sp[m]<=k) {
//      r=m;
//      ld=m-1;
//    }else ls=m+1;
//  }
//  for(;r>0 && sp[i]-sp[r]<=k; --r);
//  if(sp[i]-sp[r]>k) ++r;
//  return r;
//}
//
//int main() {
//  ifstream f("propozitie.in");
//  ofstream g("propozitie.out");
//  f>>n>>k>>s;
//  v.insert('a');
//  v.insert('e');
//  v.insert('i');
//  v.insert('o');
//  v.insert('u');
//  sp[0]=v.find(s[0])!=v.end(); nr[0]=1;
//  dsp[0]=1;
//  for(int i=1; i<s.size(); ++i) {
//    sp[i]=sp[i-1]+(v.find(s[i])!=v.end());
//    if(sp[i]<=k) nr[i]=1;
//    int r=cb(i);
//   // cerr<<i<<' '<<r<<'\n';
//    if(r) nr[i]+=(dsp[i-1]-dsp[r-1]+MOD)%MOD;
//    else nr[i]+=dsp[i-1];
//    nr[i]%=MOD;
//    dsp[i]=(nr[i]+dsp[i-1])%MOD;
//  }
//  g<<nr[s.size()-1];
//}