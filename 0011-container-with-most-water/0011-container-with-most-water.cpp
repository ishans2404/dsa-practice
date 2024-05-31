class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int area = 0, i = 0, j = height.size()-1;
        label: 
            area = max(area, (j-i)*min(height[i], height[j]));
            if(height[i] < height[j]) i++;
            else j--;
        if(i < j) goto label;
        return area;
    }
};