//#include <iostream>
//#include <vector>
//#include <cstdio>
//using namespace std;
//
//int n;
//vector<vector<int> > m;
//
//void lft(vector<vector<int> > m) {
//  for(;m.size();) {
//    for(int j=0; j<m.size(); ++j) cout<<m[j].size()<<' ';
//    cout<<'\n';
//    //for(int i=0; i<m.size(); ++i) {
//    //  for(int j=0; j<m[i].size(); ++j) cout<<m[i][j]<<' ';
//    //  cout<<'\n';
//    //}
//    for(int i=0; i<m.size(); ++i) {
//      for(int j=0; j<m[i].size(); ++j) --m[i][j];
//      while(m[i].size() && m[i].back()==0) m[i].pop_back();
//    }
//    for(;m.size() && m.back().empty();m.pop_back());
//
//  }
//  cout<<'\n';
//}
//
//void rgt(vector<vector<int> > m) {
//  for(int i=0; i<m[0].size(); ++i) {
//    vector<int> aux;
//    for(int j=0; j<m.size(); ++j) if(m[j].size()>i) aux.push_back(m[j][i]);
//    for(;aux.size();) {
//      cout<<aux.size()<<' ';
//      for(int i=0; i<aux.size(); ++i) --aux[i];
//      for(;aux.size() && aux.back()==0;aux.pop_back());
//    }
//    cout<<'\n';
//  }
//  cout<<'\n';
//}
//
//int main() {
//  //freopen("input.txt","r",stdin);
//  for(cin>>n;n;cin>>n) {
//    m.clear();
//    vector<int> rc;
//    for(int i=0; i<n; ++i) {
//      for(;;) {
//        int x; cin>>x;
//        if(x==0) break;
//        rc.push_back(x);
//      }
//      m.push_back(rc); rc.clear();
//    }
//    lft(m);
//    rgt(m);
//  }
//
//}