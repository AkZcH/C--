class Solution {

    static final int MAX = 50;
    long[][] C = new long[MAX + 1][MAX + 1];

    public long nthSmallest(long n, int k) {
        buildComb();

        long result = 0L;

        for (int bit = MAX - 1; bit >= 0 && k > 0; bit--) {
            long countWithZero = 0;

            if (bit >= k) {
                countWithZero = C[bit][k];
            }

            if (n > countWithZero) {
                n -= countWithZero;
                result |= (1L << bit);
                k--;
            }
        }

        return result;
    }

    private void buildComb() {
        for (int i = 0; i <= MAX; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
}
