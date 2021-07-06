int firstOccurence(int arr[] , int i , int n , int k){
    
    if(i == n)
        return -1;
    
    if(arr[i] == k)
        return i;
    
    return first(arr , i + 1 , n , k);
    
}

int lastOccurence(int arr[] , int i , int n , int k){
    
    if(i == n)
        return -1;
    
    int value = last(arr , i + 1 , n , k);
    
    if(value != -1)
        return value;
    
    if(arr[i] == k)
        return i;
    
    return -1;
}

string ulta = "";

void reverse(string s , int start , int n){
    
    if(start == n)
        return;
    
    reverse(s , start + 1 , n);
    
    ulta += (s[start]);
    
    return;
}

void replace(string &s , int i){
    if(i >= s.size())
        return;
    
    if(s.substr(i,2) == "pi"){
        s = s.substr(0 , i) + "3.14" + s.substr(i + 2);
        replace(s , i + 4);
    }
    else
        replace(s , i + 1);
    
    return;
    
}


void ToH(int n , char start , char end , char helper){
    if(!n)
        return;
    
    ToH(n - 1 , start , helper , end);
    printf("Move block %d from %c to %c\n" , n , start , end);
    ToH(n - 1 , helper , end , start);
    
    return;
}
	

string removeDuplicates(string s){
    
    if(s.size() == 1)
        return s;
    
    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));
    
    if(ch == ans[0])
        return ans;
    
    return (ch + ans);
    
}


string moveXtoEnd(string s){
    
    if(s.size() == 0)
        return "";
    
    char ch = s[0];
    string ans = moveXtoEnd(s.substr(1));
    
    if(ch == 'x')
        return (ans + ch);
    
    return (ch + ans);
    
}

void allSubsequences(string s , string ans){
    
    if(s.size() == 0){
        cout<<ans<<endl;
        return;
    }
        
    
    char ch = s[0];
    string ros = s.substr(1);
    
    allSubsequences(ros , ans + ch);
    allSubsequences(ros , ans);
    
}

void permutations(string s , string ans){
    
    if(s.size() == 0){
        cout<<ans<<endl;
        return;
    }
        
    
    for(int i = 0 ; i < s.size() ; i++){
        char ch = s[i];
        
        string ros = s.substr(0 , i) + s.substr(i + 1);
        
        permutations(ros , ans + ch);
        
        
    }
    return;
    
}


void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}


int countPath(int start , int end){
    
    if(start == end){
        return 1;
    }
    
    if(start > end)
        return 0;
        
    int count = 0;
    
    for(int i = 1 ; i <= 6 ; i++){	// dice from 1 to 6
        count += countPath(start , end - i);
    }
    return count;
    
}

 
int countPathMaze(int n , int i , int j){
    
    if(i == (n-1) and j == (n - 1)){
        return 1;
    }
    
    if(i >= n or j >= n)
        return 0;
        
    return countPathMaze(n , i + 1 , j) + countPathMaze(n , i , j + 1);		//Can only move to right or bottom
    
}



int main() {
	// your code goes here
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i = 0 ; i < n ; i++)
	    cin >> arr[i];
	    
	int k;
	cin >> k;
	
	//First and last occurences
	cout<<lastOccurence(arr , 0 , n , k)<<endl<<firstOccurence(arr , 0 , n , k);
	
	// Reverse a string
	ulta = "";
	string s = "Subham";
	reverse(s , 0 , 6);
	cout<< ulta <<endl;
	
	//Replace particular characters with a different string
	string s = "xpixpiAA9x";
	replace(s , 0);
	cout<<s<<endl;
	
	//Tower Of Hanoi
	ToH(3 , 'A' , 'C' , 'B');
	
	//Remove Duplicates from a string
	string s;
	getline(cin , s);
	cout<<removeDuplicates(s)<<endl;
	
	//Move a particular character to the end
	string s;
	getline(cin , s);
	cout<<moveXtoEnd(s)<<endl;
	
	//Generate all subsequences of a string
	string s;
	getline(cin , s);
	allSubsequences(s , "");
	
	//All Permutations of a string
	string s;
	getline(cin , s);
	permutations(s , "");
	
	//All permutations of a string
	string str = "ABC";
    	int n = str.size();
    	permute(str, 0, n-1);
	
	//No of ways in a path of spacing 1 unit
	cout<<countPath(0 , 3);
	
	//No of paths in a maze from (0 , 0) to (n - 1 , n - 1)
	cout<<countPathMaze(3 , 0 , 0);

	
	
	return 0;
}
