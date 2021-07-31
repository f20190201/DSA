// https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5

int nextGap(int gap) 
{ 
    //It returns the ceil value of gap/2 or 0 if gap is 1.
	if (gap <= 1) 
		return 0; 
	return (gap / 2) + (gap % 2); 
} 

void comp(long long &a , long long &b){
            if(a > b){
                long long temp = a;
                a = b;
                b = temp;
            }
            
            return;
        }


void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here
            long long gap = (n + m);
            
            for(gap = nextGap(gap) ; gap > 0 ; gap = nextGap(gap)){
                // cout<<gap<<endl;
                long long l = 0;
                long long r = l + gap;
                
                while(r < (n + m)){
                    
                    if(r < n){
                        comp(arr1[l] , arr1[r]);    
                    }
                    
                    else if (r >= n && l < n){
                        comp(arr1[l] , arr2[r - n]);
                    }
                    
                    else if(r >= n && l >= n)
                        comp(arr2[l - n] , arr2[r - n]);
                    
                    l++;
                    r++;
                    
                }
                
            }
            
            return;
        } 
