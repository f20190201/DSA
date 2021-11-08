// https://www.youtube.com/watch?v=QAcH8qD9Pe0

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf INT_MAX
#define M 1000000007
#define test(s) cout<<"SUCCESS "<< #s<<endl
#define repn(i, a, b, c) for (int i = a; i < b; i+=c)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define read(type,x) type x; cin >> x
#define readStr(s) string s; getline(cin , s)
#define vi vector<int>
#define debug(x) cout << #x <<" "<<x<<endl;
#define print(x) cout << #x <<" ";_print(x);cout<<endl;
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


int BF(ull n) {
	string s;

	for (ull i = 1 ; i <= 1e5 ; i++) {
		s += to_string(i);
	}

	// cout << s << endl;
	int ans = s[n - 1] - 48;

	return ans;
}



void digit(ull n) {

	ull m = 1, k = 1 , div = 9 * k * m , N = n;
	//m - smallest k+1 digit number
	//k - digits in our required number

	while (N > div) {

		N -= div;

		k++;

		m = m * 10;

		div = 9 * k * m;

	}

	ull low = m , high = 10 * m - 1 , ans = 0 , ans_start = 0;

	while (low <= high) {
		ull mid = low + (high - low) / 2;

		ull mid_start = ((n - N) + 1) + (mid - m) * k;

		if (mid_start <= n) {

			if (mid > ans) {
				ans = mid;
				ans_start = mid_start;
			}

			low = mid + 1;
		}

		else
			high = mid - 1;

	}

	string number = to_string(ans);

	int res = number[n - ans_start] - 48;

	cout << res << endl;

}



void solve() {

	read(int , q);

	while (q--) {
		read(ull , n);

		// if (BF(n) != digit(n)) {
		// 	cout << n << endl;
		// 	debug(BF(n));
		// 	debug(digit(n));
		// 	space;
		// }

		digit(n);
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
