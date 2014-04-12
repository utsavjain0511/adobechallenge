//Utsav Jain
//
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REV(i,a,b) for(int i= (int )a ; i >= (int)b ; --i)
#define REP(i,a) FOR(i,0,a)
#define INF 1000000000
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define present(container, element) (container.find(element) != container.end()) 
#define cpresent(container, element) (find(all(container),element) != container.end())
#define tr(container,it) for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define minheap(t) priority_queue< t,vector<t>,greater<t> >
#define maxheap(t) priority_queue<t>
#define pb push_back
#define ii pair<int,int>
#define ss pair<string,string>
#define F first
#define S second
#define seive(n) vector<int> prime(n+1,1);for(int i=2;i*i<n;i++) if(prime[i])  for(int j=i+i;j<n;j+=i) prime[j]=0;
#define gcd __gcd

int main(int argc,char *argv[])
{
	vector <long long int> pp; 
	pp.pb(4) ;
	for (int i = 3; i < 31640 ; i++)
			pp.pb(i*i) ;
	int t ;
	scanf("%d",&t) ;
	while (t--) {
		int x,y; 
		scanf("%d%d",&x,&y) ;
		if ( x > y) {
			int temp = y ;
			y = x ;
			x = temp ;
		}
		vector <bool> a(10000000,false) ;
		long long int cnt = y-x+1;
		for(int j = 0 ; j < pp.size() ; j++) {
			if ( pp[j] > y) break ;
			int r = x%pp[j] ;
			int start = x - r + pp[j] ;
			if (r == 0)
				start = x ;
			//cout << start << " " << pp[j] << endl ;
			for (int i = start ; i <= y ; i += pp[j]) {
				if (a[i-x] == false) 
				{	
					a[i-x] =true ;
					cnt-- ;
				}
			}
		}
		cout << cnt << endl ;
	}
	return 0;
}
