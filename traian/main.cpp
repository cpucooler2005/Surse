#include <iostream>
#include <fstream>
#define D 2000005
using namespace std;
ifstream f("crescator.in");
ofstream g("crescator.out");
int n,a[D],y,ma;
int secmax(int b[],int m)
{ int i;
  ma=1;
  int k=1;
      for(i=1;i<=m;i++)
          {
           if(a[i]<a[i+1])
              k++;
           else k=1;
           if(k>ma)
              ma=k;
          }
      return ma;

}
int secnr(int b[],int m)
{ int k=1,nr=0,i;
  a[m+1]=-1;
  for(i=1;i<=m;i++)
    {
      if(a[i]<a[i+1])
          k++;
      else {
            nr=nr +(k*(k+1))/2;
            k=1;
            }
    }
    return nr;

}
int main()
{int i;
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
 g<<secnr(a,n);
 g<<" ";
 g<<secmax(a,n);
    return 0;
}
