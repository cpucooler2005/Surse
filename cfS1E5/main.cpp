//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//struct tr{
//  tr *f[10];
//  int end;
//  tr() {
//    memset(f,NULL,sizeof(f));
//    end=0;
//  }
//};
//
//int n;
//string s;
//
//int ins(tr *t,int p) {
//  if(p>=s.size()) {
//    t->end=1;
//    return 0;
//  }
//  int u=s[p]-'0';
//  if(t->f[u]==NULL) {
//    //cout<<u<<' ';
//    t->f[u]=new tr;
//    if(t->end) return 0&ins(t->f[u],p+1);
//    return 1|ins(t->f[u],p+1);
//  }
//  int r=ins(t->f[u],p+1);
// // cout<<u<<' '<<t->f[u]->end<<'\n';
//  if(t->end==1) {
//   // cout<<"aici";
//    return 0;
//  }
//  else return r;
//}
//
//int main()
//{
//    int T;
//    for(cin>>T;T--;) {
//      cin>>n;
//      tr *t=new tr;
//      int ok=1;
//      for(int i=0; i<n; ++i) {
//        cin>>s;
//        ok&=ins(t,0);
//        //cout<<'\n';
//      }
//      if(!ok) cout<<"NO\n";
//      else cout<<"YES\n";
//    }
//    return 0;
//}
