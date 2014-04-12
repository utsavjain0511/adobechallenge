
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
void search(int r, vector <vector <int> > & a ) {
	int i = 0;
	int j = a[0].size() - 1 ;
	int n = a.size() ;
	int m = a[0].size() ;
	while (true) {
		if ( i >= n || j < 0) {
			cout << "-1 -1" << endl ;
			break ;
		}
		else if ( a[i][j] == r) {
			cout << i << " " << j << endl ;
			break ;
		}
		else if ( a[i][j] < r) {
			i++ ;
		}
		else if ( a[i][j] > r) {
			j--; 
		}
	}
	return ;
}

int main(int argc,char *argv[])
{
	int n,m ;
	scanf("%d%d",&n,&m) ;
	vector < vector <int> > a(n, vector<int> (m,0)) ;
	for (int i = 0; i < n ;i++) {
		for (int j = 0 ; j < m ; j++) {
			scanf("%d",&a[i][j]) ;
		}
	}
	int q;
	scanf("%d",&q) ;
	for (int i = 0 ; i < q ; i++) {
		int r ;
		scanf("%d",&r) ;
		search(r,a) ;
	}
	return 0;
}
