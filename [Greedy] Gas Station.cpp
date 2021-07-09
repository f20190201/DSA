// Make a variable total_surplus that keeps count of gas[i] - cost[i] for the total array. If this total value < 0, no path can be found, no matter where we start.
// surplus keeps a count of surplus fuel from our assumed start. If surplus < 0, then re-initialise it to 0 and make start as i + 1

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int start = 0 , surplus = 0 , total_surplus = 0;

    for(int i = 0 ; i < A.size() ; i++){
        total_surplus += A[i] - B[i];
        surplus += A[i] - B[i];

        if(surplus < 0){
            surplus = 0;
            start = i + 1;
        }

    }

    if(total_surplus >= 0)
        return start;
    return -1;
}

---------------------------------------------------------------------------------------------------------------------------------------

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int sumGas = 0;
            int sumCost = 0;
            int start = 0;
            int tank = 0;
            for (int i = 0; i < gas.length; i++) {
                sumGas += gas[i];
                sumCost += cost[i];
                tank += gas[i] - cost[i];
                if (tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
            if (sumGas < sumCost) {
                return -1;
            } else {
                return start;
            }
        }
};
