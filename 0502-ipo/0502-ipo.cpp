class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> pairs(n);
        for(int i=0; i<n; i++) {
            pairs[i] = {capital[i], profits[i]};
        }
        sort(pairs.begin(), pairs.end());
        for(int i=0; i<n; i++) cout<<pairs[i][0]<<" : "<<pairs[i][1]<<endl;
        cout<<endl;
        priority_queue<int> maxHeap;
        for(int i=0; i<n; i++) {
            if(w >= pairs[i][0]) {
                maxHeap.push(pairs[i][1]);
            }
            else if(maxHeap.size() > 0 && k > 0) {
                k--;
                i--;
                w += maxHeap.top();
                maxHeap.pop();
            }
        }
        while(maxHeap.size() > 0 && k > 0) {
            k--;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};