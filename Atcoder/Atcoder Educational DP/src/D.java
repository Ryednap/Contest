import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// upper easy level.

/*
    This is a trivial O(n^2) knapsack in which we either pick or leave
    the current item . dp[i][j] means the maximum value obtained when we are
    at the ith item and already have collected j weights.
 */

public class D {
    static FastScanner fs = new FastScanner();
    static long [][] dp = new long[101][(int)1e5 + 1];

    public static void main(String[] args) {
            int n = fs.nextInt(), w = fs.nextInt();
            int [][] arr = new int[n][2];
            for(int i = 0; i < n; ++i) for(int j = 0 ;j < 2; ++j){
                arr[i][j] = fs.nextInt();
            }
            for(int i = 0; i< 100; ++i) for(int j = 0; j < (int)1e5; ++j){
                dp[i][j] = -1;
            }
            long ans = Brute(0,0,w,arr,n);
            System.out.println(ans);
    }

    static long Brute(int i, int j , final int W, final int [][] arr, final int n){
        if(j > W) return -(long)1e14;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        long a = Brute(i + 1, j , W , arr, n);
        long b = Brute(i + 1, j + arr[i][0], W, arr, n) + arr[i][1];

        return dp[i][j] = Math.max(a,b);
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