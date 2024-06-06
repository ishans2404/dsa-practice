class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for(int i:hand) count[i]++;

        int start, curr;
        while(!count.empty()) {
            start = count.begin()->first;
            for(int i=0; i<groupSize; i++) {
                curr = start + i;
                if(count[curr] == 0) return false;
                count[curr]--;
                if(count[curr] == 0) {
                    count.erase(curr);
                }
            }
        }
        return true;
    }
};