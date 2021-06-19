// Maintain a vector v that stores the digits of the product in reverse order.

vector<int> v;

void multiply(int x){
    int carry = 0;
    int size = v.size();
    for(int i = 0 ; i < size ; i++){
        int prod = x*v[i] + carry;
        v[i] = (prod%10);
        carry = prod/10;
    }
    while(carry){
        v.push_back(carry%10);
        carry = carry/10;
    }

}

string Solution::solve(int A) {
    v.clear();
    product = 1;
    v.push_back(1);
    for(int i = 2 ; i <= A ; i++){
        multiply(i);
    }

    string result = "";
    for(auto x:v)
        result += to_string(x);
        reverse(result.begin() , result.end());
    return result;


}
