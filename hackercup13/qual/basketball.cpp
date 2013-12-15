#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include <vector>
#include<algorithm>
#define x first
#define y second
using namespace std;

int T,n,m,p;

void inc(map<pair<int,int>,string,greater<pair<int,int> > > &mp) {
  map<pair<int,int>,string,greater<pair<int,int> > > rez;
  for(map<pair<int,int>,string,greater<pair<int,int> > >::iterator im=mp.begin(); im!=mp.end(); ++im) {
    pair<pair<int,int>,string>aux= *im;
    ++aux.x.x;
    rez.insert(aux);
  }
  mp=rez;
}

int main() {
	ifstream f("input.txt");
	ofstream g("output.txt");
	f>>T;
	for(int t=1; t<=T; ++t) {
		f>>n>>m>>p;
		vector<pair<int,pair<int,string> > > v,a,b;
		v.resize(n);
		for(int i=0; i<n; ++i) f>>v[i].y.y>>v[i].x>>v[i].y.x;
		sort(v.rbegin(),v.rend());
		for(int i=0; i<n; ++i) {
			if(i&1) b.push_back(v[i]);
			else a.push_back(v[i]);
		}


		map<pair<int,int>,string,greater<pair<int,int> > > game[2];
		map<pair<int,int>,string> bench[2];
		//inserez in mapurile corespunzatoare si pe urma fac simularea
		for(int i=0; i<a.size(); ++i)
			if(i<p) game[0][make_pair(0,i)]=a[i].y.y;
			else bench[0][make_pair(0,i)]=a[i].y.y;
		for(int i=0; i<b.size(); ++i)
			if(i<p) game[1][make_pair(0,i)]=b[i].y.y;
			else bench[1][make_pair(0,i)]=b[i].y.y;

    for(int i=1; i<=m; ++i) {

//      for(map<pair<int,int>,string,greater<pair<int,int> > >::iterator im=game[0].begin(); im!=game[0].end(); ++im)
//        cout<<im->y<<' '<<im->x.x<<' '<<im->x.y<<'\n';
//      for(map<pair<int,int>,string,greater<pair<int,int> > >::iterator im=game[1].begin(); im!=game[1].end(); ++im)
//        cout<<im->y<<' '<<im->x.x<<' '<<im->x.y<<'\n';
//      cout<<'\n';
      inc(game[0]);
      inc(game[1]);
      pair<pair<int,int>,string> ga,gb,ba,bb;
      if(bench[0].size()) {
        ga=*(game[0].begin());
        ba=*(bench[0].begin());
        game[0].erase(game[0].begin());
        bench[0].erase(bench[0].begin());
        game[0].insert(ba);
        bench[0].insert(ga);
      }
      if(bench[1].size()) {
        gb=*(game[1].begin());
        bb=*(bench[1].begin());
        game[1].erase(game[1].begin());
        bench[1].erase(bench[1].begin());
        game[1].insert(bb);
        bench[1].insert(gb);
      }
    }
    g<<"Case #"<<t<<": ";
    vector<string> rez;
    for(map<pair<int,int>,string,greater<pair<int,int> > >::iterator im=game[0].begin(); im!=game[0].end(); ++im) rez.push_back(im->second);
    for(map<pair<int,int>,string,greater<pair<int,int> > >::iterator im=game[1].begin(); im!=game[1].end(); ++im) rez.push_back(im->second);
    sort(rez.begin(),rez.end());
    for(int i=0; i<rez.size(); ++i) g<<rez[i]<<' ';
    g<<'\n';
    //while(1);
	}
}
