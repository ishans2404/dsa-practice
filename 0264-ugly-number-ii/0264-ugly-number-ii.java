class Ugly{
    public int[] nums = new int[1690];
    Ugly(){
        nums[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < 1690; i++) {
            int nextUgly = Math.min(nums[i2] * 2, Math.min(nums[i3] * 3, nums[i5] * 5));
            nums[i] = nextUgly;

            if (nextUgly == nums[i2] * 2) i2++;
            if (nextUgly == nums[i3] * 3) i3++;
            if (nextUgly == nums[i5] * 5) i5++;
        }
    }
}

class Solution {
    public static Ugly ugly = new Ugly();
    public int nthUglyNumber(int n) {
        return ugly.nums[n - 1];
    }
}
