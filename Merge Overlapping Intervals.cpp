
// A function to compare the Interval struct
bool comp(Interval a , Interval b){
    return (a.start < b.start);}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin() , A.end() , comp);
  
// Array has been sorted in accordance to the starting time
    vector<Interval> result;
    int curr_s = A[0].start;
    int n = A.size();
    int curr_e = A[0].end;

    for(int i = 1 ; i < n  ; i++){
        // We check if there's any overlap between current end point and start time of next interval, if yes, then we update the end time
        if(curr_e >= A[i].start){
            curr_e = max(curr_e , A[i].end);
            curr_s = min(curr_s , A[i].start);
            continue;
        }
      // If there's no overlap, we push the current interval into the result array and update the curr_s and curr_e
        else{
            result.push_back(Interval(curr_s , curr_e));
            curr_s = A[i].start;
            curr_e = A[i].end;
        }
    }
  // For the last interval, since its checking isn't done by the loop
    result.push_back(Interval(curr_s , curr_e));

    return result;


}


----------------------------------------------------------------------------------------------------------------------------
  
  
  
  
  // A C++ program for merging overlapping intervals
#include<bits/stdc++.h>
using namespace std;
 
// An interval has start time and end time
struct Interval
{
    int start, end;
};
 
// Compares two intervals according to their staring time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 
// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
    // Test if the given set has at least one interval
    if (n <= 0)
        return;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sort the intervals in increasing order of start time
    sort(arr, arr+n, compareInterval);
 
    // push the first interval to stack
    s.push(arr[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);
 
        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}
 
// Driver program
int main()
{
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
