class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        target = countSort(target);
        arr = countSort(arr);
        int n = target.size();
        for(int i=0; i<n; i++) {
            if(target[i] != arr[i]) return false;
        }
        return true;
    }
private:
    vector<int> countSort(vector<int>& inputArray) {
        int N = inputArray.size();
        int M = 0;    
        for (int i = 0; i < N; i++) M = max(M, inputArray[i]);
    
        vector<int> countArray(M + 1, 0);

        for (int i = 0; i < N; i++)
            countArray[inputArray[i]]++;

        for (int i = 1; i <= M; i++)
            countArray[i] += countArray[i - 1];
    
        // Creating outputArray[] from countArray[] array
        vector<int> outputArray(N);
    
        for (int i = N - 1; i >= 0; i--) {
            outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
            countArray[inputArray[i]]--;
        }
    
        return outputArray;
    }
};