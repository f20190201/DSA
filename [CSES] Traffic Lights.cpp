// https://www.youtube.com/watch?v=4HKXdh_LHps

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define inf INT_MAX
#define M 1000000007
#define test(s) cout<<"SUCCESS "<< s<<endl
#define repn(i, a, b, c) for (int i = a; i < b; i+=c)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pq priority_queue
#define read(type,x) type x; cin >> x
#define readStr(s) string s; getline(cin , s)
#define vi vector<int>
#define debug(x) cout << #x <<" "<<x<<endl;
#define print(x) cout << #x <<" ";_print(x);cout<<endl;
#define println(x) cout<<x<<endl
#define space cout<<endl
#define runTime cout<<endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " secs\n";

using namespace std;
using namespace std::chrono;

void _print(int x) {
	cout << x << " ";
}

void _print(ull x) {
	cout << x << " ";
}

void _print(string x) {
	cout << x << " ";
}

void _print(char x) {
	cout << x << " ";
}

void _print(pii x) {
	cout << x.first << "," << x.second << " ";
}

template<class T> void _print(vector<T> v) {
	cout << "{ ";

	for (T i : v)
		_print(i);

	cout << "}" << endl;

	return;
}



void solve() {

	read(int  , x);
	read(int  , n);

	set<int>s1;	// for positions of lights

	multiset<int>s2; // for unlit passage length

	s1.insert(0);
	s1.insert(x);

	s2.insert(x);

	rep(i , 0 , n) {

		read(int  , k);

		s1.insert(k);

		auto it = s1.find(k);
		auto previous = *prev(it) , nxt = *next(it);


		s2.erase(s2.find(nxt - previous));

		s2.insert(nxt - k);
		s2.insert(k - previous);


		println(*s2.rbegin());


	}

	return;
}



int main() {

#ifndef ONLINE_JUDGE

	freopen("input.txt" , "r" , stdin);

	freopen("output.txt" , "w" , stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#endif

	solve();

	// runTime;

	return 0;

}
