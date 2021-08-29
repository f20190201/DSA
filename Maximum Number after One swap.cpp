// Very efficient string based solution(Python) -> https://binarysearch.com/problems/Maximum-Number-After-One-Swap/solutions/3119765

//Idea is to convert the number into array first
// Find the maximum number on the right array for each element
// Replace the last occurence of the maximum element for the leftmost element

int solve(int n) {
    if(n == 0)
        return 0;

    int digits = (int)(log10(n)) + 1 , num = n;
    vector<int> v(digits , 0);

    for(int i = digits - 1 ; i >= 0 ; i--){
        v[i] = num % 10;
        num = num / 10;
    }

    vector<int>rightMax(digits);
    int curr_max = INT_MIN;

    for(int i = digits - 1 ; i >= 0 ; i--){
        if(v[i] > curr_max){
            curr_max = v[i];
        }

        rightMax[i] = curr_max;
    }

    int toSwap = -1 , toBeSwapped = -1;

    for(int i = 0 ; i < digits ; i++){
        
        if(rightMax[i] > v[i]){
            toSwap = v[i];
            v[i] = rightMax[i];
            toBeSwapped = rightMax[i];
            break;
        }
    }

    if(toSwap == -1)
        return n;

    for(int i = digits - 1 ; i >= 0 ; i--){
        if(v[i] == toBeSwapped){
            v[i] = toSwap;
            break;
        }
    }

    string s = "";

    for(int i = 0 ; i < digits ; i++)
        s += (to_string(v[i]));
    
    return stoi(s);
