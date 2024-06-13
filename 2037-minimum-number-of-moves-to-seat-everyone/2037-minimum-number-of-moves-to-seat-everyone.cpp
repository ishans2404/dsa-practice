class Solution {
public:
    vector<int> countSort(vector<int>& inputArray) {
        int N = inputArray.size();
        int M = *max_element(inputArray.begin(), inputArray.end());

        vector<int> countArray(M + 1, 0);
        for (int i = 0; i < N; i++) countArray[inputArray[i]]++;
        for (int i = 1; i <= M; i++) countArray[i] += countArray[i - 1];

        vector<int> outputArray(N);
        for (int i = N - 1; i >= 0; i--) {
            outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
            countArray[inputArray[i]]--;
        }
        return outputArray;
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        seats = countSort(seats);
        students = countSort(students);
        int c = 0, n = seats.size();
        for(int i=0; i<n; i++) c += abs(seats[i] - students[i]);
        return c;
    }
};