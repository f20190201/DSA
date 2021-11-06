https://cses.fi/problemset/result/3091212/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define INF INT_MAX/2
#define M 1000000007
#define repn(i, a, b, c) for (int i = a; i < b; i+=c)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define read(type,x) type x; cin >> x
#define readStr(s) string s; getline(cin , s)
#define debug(x) cout << #x <<" "<<x<<endl;
#define print(x) cout << #x <<" ";_print(x);cout<<endl;

using namespace std;

void _print(int x) {
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

	cout << "}";

	return;
}



void solve() {

	unordered_map<char , int>mp;
	int oddCount = 0;

	readStr(s);
	int n = s.size();

	rep(i , 0 , n) {
		mp[s[i]]++;

		if (mp[s[i]] % 2 == 0)
			oddCount--;
		else
			oddCount++;
	}

	char oddChar;

	if (oddCount > 1)
		cout << "NO SOLUTION" << endl;

	else {
		string first = "" , last = "";

		for (auto it : mp) {

			int count = it.second;
			char ch = it.first;

			if (count % 2 != 0)
				oddChar = ch;

			string chars = "";

			rep (j , 0 , count / 2)
			chars += ch;

			first += chars;

			last = chars + last;
		}

		if (oddCount != 0)
			cout << (first + oddChar + last);

		else
			cout << (first + last);

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

	return 0;

}
