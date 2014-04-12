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
#include <limits.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REV(i,a,b) for(int i= (int )a ; i >= (int)b ; --i)
#define REP(i,a) FOR(i,0,a)
#define INF INT_MAX
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

bool compare(pair <int,int> a, pair<int,int> b) {
	return a.S < b.S ;
}

int main(int argc,char *argv[])
{
	int n;
//	cout << INF << endl ;
	scanf("%d",&n) ;
	vector <pair <int,int> > xs(n) ;
	vector <pair <int,int> > ys(n) ;
	for (int i = 0 ; i < n ; i++) { 
		scanf("%d%d",&xs[i].F,&xs[i].S) ;
		ys[i].F = xs[i].F ;
		ys[i].S = xs[i].S ;
	}
	sort(xs.begin(),xs.end()) ;
	sort(ys.begin(),ys.end(), compare) ;
	set < pair <int,int> > s ;
	int cnt = 0 ;
	int i =1 ,j =1 ;
	long long int ans = 0 ;
	while (cnt < n-1) {
		long long int mx = INF ;
		long long int my = INF ;
		if ( i < n && (s.find(xs[i]) == s.end() || s.find(xs[i-1]) == s.end() ))  
			mx = min(abs(xs[i].F  - xs[i-1].F),abs(xs[i].S - xs[i-1].S)) ;
		if ( j < n && (s.find(ys[j]) == s.end() || s.find(ys[j-1]) == s.end() ))
			my = min(abs(ys[j].S - ys[j-1].S),abs(ys[j].F - ys[j-1].F)) ;
		if ( mx < my && mx != INF) {
			ans += mx ;
			s.insert( ii (xs[i]) ) ;
			s.insert( ii (xs[i-1]) ) ;
			cnt++ ;
			i++ ;
		}
		else if ( mx >= my && my != INF) {
			ans += my ;
			s.insert( ii (ys[j]) ) ;
			s.insert( ii (ys[j-1]) ) ;
			cnt++ ;
			j++ ;
		}
		else if ( mx == INF && my == INF) {
			i++ ;
			j++ ;
		}
		if ( i == n && j == n) break ;
	}
	cout << ans << endl ;
	return 0;
}
