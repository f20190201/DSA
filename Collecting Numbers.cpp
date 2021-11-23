// https://www.youtube.com/watch?v=lhhHCZYoJvs

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

template<class T> void _print(vector<T> v) {
	cout << "{ ";

	for (T i : v)
		_print(i);

	cout << "}" << endl;

	return;
}



void solve() {

	read(ll , n);
	vector<pii> v;

	rep(i , 0 , n) {
		read(ll , x);
		v.push_back({x , i});
	}


	sort(v.begin() , v.end());

	ull currMin = INT_MAX , count = 0;

	rep(i , 0 , n) {
		ull index = v[i].second;

		if (index < currMin) {
			count++;
		}

		currMin = index;
	}

	println(count);

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
