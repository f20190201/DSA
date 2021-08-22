// Idea is to sort the array and then try to comvert the sorted array into the original
// This can be done by storing the original indexes of the elements in the form of a pair

int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int , int>> v;
	    
	    for(int i = 0 ; i < nums.size() ; i++){
	        v.push_back({nums[i] , i});    
	    }
	    
	    sort(v.begin() , v.end());
	    
	    int count = 0;
	    
	    for(int i = 0 ; i < nums.size() ; i++){
	        auto curr = v[i];
	        
	        if(curr.second == i)
	            continue;
	           
	        swap(v[i] , v[curr.second]);
	        count++;
	        i--;
	    }
	    
	    return count;
	}
