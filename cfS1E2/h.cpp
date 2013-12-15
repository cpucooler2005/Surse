//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//#define x first
//#define y second
//#define mp make_pair
//using namespace std;
//
//typedef pair<double,double> per;
//
//int x[5],y[5];
//vector<per> p,pi;
//
//double det(per a,per b,per c) {
//  return 0.5*(a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-c.x*b.y-b.x*a.y);
//}
//
//double area(vector<per> a) {
//  double r=0;
//  for(int i=2; i<a.size(); ++i) r+=det(a[0],a[i-1],a[i]);
//  return fabs(r);
//}
//
//void print(vector<per> a) {
//  for(int i=0; i<a.size(); ++i) cerr<<a[i].x<<' '<<a[i].y<<'\n';
//}
//
//int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
//  for(int c=1;cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3]>>x[4]>>y[4];++c){
//    double ma=-9999999999,mb=99999999999;
//    p.clear(); pi.clear();
//    int allz=1;
//    for(int i=1; i<5; ++i) {
//      p.push_back(mp(x[i],y[i]));
//      if(x[i] || y[i]) allz=0;
//    }
//    if(allz) break;
//
//    pi.push_back(p[0]);
//    for(int i=1; i<p.size(); ++i) {
//      pi.push_back(mp(0.5*(p[i].x+p[i-1].x),0.5*(p[i].y+p[i-1].y)));
//      pi.push_back(p[i]);
//    }
//    pi.push_back(mp(0.5*(p[3].x+p[0].x),0.5*(p[3].y+p[0].y)));
//    //for(int i=0; i<pi.size(); ++i) cerr<<pi[i].x<<' '<<pi[i].y<<'\n';
//    //while(1);
//    for(int i=0; i<pi.size(); ++i) for(int j=i+1; j<pi.size(); ++j) {
//      vector<per> a;
//      for(int k=i; k<=j; ++k) a.push_back(pi[k]);
//      if(area(a)<1e-6) continue;
//      if(fabs(area(p)-2*area(a))<mb-ma) {
//        ma=min(area(a),area(p)-area(a));
//        mb=max(area(a),area(p)-area(a));
//      }
//    }
//
//    cout<<"Cake "<<c<<": "<<fixed<<setprecision(3)<<ma<<' '<<mb<<'\n';
//  }
//  return 0;
//}
