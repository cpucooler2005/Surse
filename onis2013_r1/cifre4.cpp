//#include <iostream>
//#include <fstream>
//#include <queue>
//#include <vector>
//#include <string>
//#include <algorithm>
//#define DN 5000005
//using namespace std;
//
//int t,n,p,pre[DN],lc[DN];
//int main (){
//  ifstream f("cifre4.in");
//  ofstream g("cifre4.out");
//  for(f>>t;t--;) {
//    f>>n>>p;
//    vector<int> cif;
//    cif.push_back(2%p);
//    cif.push_back(3%p);
//    cif.push_back(5%p);
//    cif.push_back(7%p);
//    for(int i=0; i<p; ++i) pre[i]=-1;
//    queue<int> c;
//    for(int i=0; i<cif.size(); ++i) {
//      c.push(cif[i]);
//      lc[cif[i]]=cif[i];
//      pre[cif[i]]=0;
//    }
//    for(;c.size(); c.pop()) {
//      int fr=c.front();
//      for(int i=0; i<cif.size(); ++i) {
//        int nxt=(fr*10+cif[i])%p;
//        if(pre[nxt]==-1) {
//          pre[nxt]=fr;
//          lc[nxt]=cif[i];
//          c.push(nxt);
//        }
//      }
//    }
//    if(pre[n]==-1) g<<"-1\n";
//    else {
//      string r;
//      for(;n;n=pre[n]) {
//        r+=lc[n]+'0';
//      }
//      reverse(r.begin(),r.end());
//      g<<r<<'\n';
//    }
//  }
//}
