int first(int arr[] , int i , int n , int k){
    
    if(i == n)
        return -1;
    
    if(arr[i] == k)
        return i;
    
    return first(arr , i + 1 , n , k);
    
}

int last(int arr[] , int i , int n , int k){
    
    if(i == n)
        return -1;
    
    int value = last(arr , i + 1 , n , k);
    
    if(value != -1)
        return value;
    
    if(arr[i] == k)
        return i;
    
    return -1;
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
	
	cout<<last(arr , 0 , n , k)<<endl;
	return 0;
}
