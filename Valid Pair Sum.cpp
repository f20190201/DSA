class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	
    	long long result = 0;
    	
    	sort(a , a + n);
    	
    	for(int i = 0 ; i < n; i++){
    	    
        int index = upper_bound(a + i + 1 , a + n , -a[i]) - a;
    	   
    	        result += (n - index);    
    	   
    	}
    	
    	return result;
    }   
};

