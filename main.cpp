/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<int>pow10(18);
int numOfDigiht(int n,int i)
{
  
  if(n>pow10[i])
  {
      return pow10[i]*(i)+numOfDigiht(n-pow10[i],i+1);
  }else return (n+1)*(i);
}
void solution()
{
 int l,r;
cin>>l>>r;
pow10[0]=1;
for(int i=1;i<18;i++)
pow10[i]=pow10[i-1]*10ll;
cout<<numOfDigiht(max(l,r),1)-numOfDigiht(min(l,r)-1,1)<<endl;   
}
int32_t main()
{
solution();
    return 0;
}