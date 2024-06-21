class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grum, int min) {
        int n = cust.size();
        int gain = 0;
        int loss = 0;
        for(int i=0; i<n; i++) {
            if(grum[i] == 0) gain += cust[i];
        }

        for(int i=0; i<min; i++) {
            if(grum[i] == 1) loss += cust[i];
        }

        int total = loss;

        for(int i=min; i<n; i++) {
            if(grum[i-min] == 1) loss -= cust[i-min]; // remove last element of window
            if(grum[i] == 1) loss += cust[i];  // add new element to window
            total = max(total, loss);  // maximise total
        }
        return gain + total;
    }
};