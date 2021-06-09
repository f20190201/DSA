// Creating a comparator function

static bool compare(struct Item a ,struct Item b){
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
    }
// Sort the array according to the value/weight

// If Weight of the knapsack is greater than the total weight of a particular item, put the whole of the item into the knapsack and add the whole value of the item

// If wight of knapsack is lesser than the total weight of an item then calculate its value/weight and add the required weight to the knapsack 
// and proportional value to our result.

// It is important to note that there would be only 1 item which would have to be cut into fractions.

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double result = 0;
        
        sort(arr , arr + n , compare);
        
        for(int i = 0 ; i < n ; i++){
            if(W >= arr[i].weight){
                result += arr[i].value;
                W -= arr[i].weight;
                continue;
            }
            double pw = (double)arr[i].value/(double)arr[i].weight;
            double cost_added = W*pw;
            result += cost_added;
            break;
        }
        return result;
        
        
    }
