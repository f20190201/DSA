// minPrice2 is the minimum price we need to pay from our pockets, that is equalt to price of stock on that day - profits till now

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size() , minPrice1 = INT_MAX , minPrice2 = INT_MAX , one_t = 0 , two_t = 0;

    for(int i = 0 ; i < n ; i++){
        minPrice1 = min(minPrice1 , A[i]);
        one_t = max(one_t , A[i] - minPrice1);

        minPrice2 = min(minPrice2 , A[i] - one_t);
        two_t = max(two_t , A[i] - minPrice2);
    }

    return two_t;
}
