//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#define DN 205
//using namespace std;
//
//int t,h,c,l[DN];
//double err[DN][DN];//eroarea intre i si j
//double bst[DN][DN];//eroarea minima in intervalul 1...i in care j case sunt nestocate
//
//int main() {
//  for(cin>>t;t--;) {
//    cin>>h>>c;
//    c=h-c;
//    for(int i=0; i<h; ++i) cin>>l[i];
//    for(int i=0; i<h; ++i) for(int j=i+1; j<h; ++j) {
//      err[i][j]=0;
//      for(int k=i+1; k<j; ++k) err[i][j]+=fabs(l[i]+(l[j]-l[i])*1.0*(k-i)/(j-i)-l[k]);
//    }
//    for(int i=1; i<h; ++i) for(int j=0; j<=c; ++j) {
//      if(j==0) {
//        bst[i][j]=0;
//        continue;
//      }
//      bst[i][j]=999999999;
//      if(j>=i) break;
//      for(int k=i-1; k>=0; --k) {
//        int goale=i-k-1;
//        if(goale>j) break;
//        bst[i][j]=min(bst[i][j],bst[k][j-goale]+err[k][i]);
//      }
//    }
//    cout<<fixed<<setprecision(4)<<1.0*bst[h-1][c]/h<<'\n';
//  }
//}
