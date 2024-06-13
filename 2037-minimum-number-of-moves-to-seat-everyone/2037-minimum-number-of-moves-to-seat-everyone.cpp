class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int c = 0, n = seats.size();
        for(int i=0; i<n; i++) c += abs(seats[i] - students[i]);
        return c;
    }
};