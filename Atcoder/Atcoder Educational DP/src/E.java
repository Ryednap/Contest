import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Medium level Had to see the solution.

// This is a nice tough problem. In this the weight is so large
// that we can't do the direct O(n^2) approach on weight. I was'nt
// able to the memoized version of this.

/*
     Here instead of maximizing the value we will minimize the weight we can
     get for each value from 1 to 1e3. and then check for each one of them the maximum
     just less than the given weight.
     dp[i][j] = minimum weight that we have picked for ith item and jth value.
 */

public class E {
    static FastScanner fs = new FastScanner();
    static int n , w, max_value;

    public static void main(String[] args) {
        n = fs.nextInt();
        w = fs.nextInt();
        int [] weight = new int[n];
        int [] value = new int[n];
        for(int i = 0; i < n; ++i){
            weight[i] = fs.nextInt();
            value[i] = fs.nextInt();
            max_value += value[i];
        }

        long [][] dp = new long[n + 1][max_value + 1];
        for(int i = 0; i <= n ; ++i) for(int j = 0; j <= max_value; ++j){
            dp[i][j] = (long)1e12;
        }
        dp[0][0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0;j <= max_value; ++j){
                dp[i+1][j] = Math.min(dp[i + 1][j] , dp[i][j]);
                if(j + value[i] <= max_value) dp[i+1][j + value[i]] = Math.min(dp[i+1][j + value[i]],
                        dp[i][j] + weight[i]);
            }
        }
        long ans = 0;
        for(int i = 0; i <= max_value; ++i){
            if(dp[n][i] <= w) ans = i;
        }
        System.out.println(ans);

    }



    static void sort(int[] a) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : a) list.add(i);
        Collections.sort(list);
        for (int i = 0; i < a.length; ++i) a[i] = list.get(i);
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer("");

        String next() {
            while (!token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(br.readLine());
                } catch (IOException ie) {
                    ie.printStackTrace();
                }
            }
            return token.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = nextInt();
            return a;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) a[i] = nextLong();
            return a;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public double[] readDoubleArray(int n) {
            double[] a = new double[n];
            for (int i = 0; i < n; ++i) a[i] = nextDouble();
            return a;
        }
    }
}