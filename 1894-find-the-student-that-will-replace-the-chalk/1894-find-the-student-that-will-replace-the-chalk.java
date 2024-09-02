class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long s = 0;
        for(int i=0; i<chalk.length; i++) s += chalk[i];
        k = (int)(k % s);
        if(k == 0) return 0;
        for(int i=0; i<chalk.length; i++) {
            if(k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
}