#include<iostream>
#include<string.h>

using namespace std;


int LCS(string s1 , string s2 , int n1 , int n2) {

	if (!n1 || !n2)
	{
		return 0;
	}

	if (s1[n1 - 1] == s2[n2 - 1])
	{
		/* code */
		return 1 + LCS(s1 , s2 , n1 - 1 , n2 - 1);
	}

	else {
		return max(LCS(s1 , s2 , n1 , n2 - 1) , LCS(s1 , s2 , n1 - 1 , n2));
	}
}

int main()
{
	/* code */
	cout << LCS("Subham" , "Supqbha" , 6 , 7);
	return 0;
}
