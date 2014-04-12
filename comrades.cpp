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

long long int check(vector <long long int> & dp , vector <int> & s,int i) {
	if ( dp[i] == -1) {
		dp[i] = 1 + check(dp,s,s[i] -1) ;
	}
	return dp[i] ;
}

int main(int argc,char *argv[])
{
	int t ;
	scanf("%d",&t) ;
	while (t--) {
		int n ;
		scanf("%d",&n) ;
		vector <int> s(n) ;
		vector <long long int> dp(n,-1) ; 
		for (int i = 0 ; i < n ; i++) {
			scanf("%d",&s[i]) ;
			if (s[i] == 0) 
				dp[i] = 0 ;
		}
		long long int hs = 0 ;
		for (int i = 0 ; i < n ; i++) {
			hs += check(dp,s,i) ;
		}
		long long int fs = (n*1LL*(n-1))/2 - hs ;
		cout << hs << " " << fs << endl ;

	}
	return 0;
}
