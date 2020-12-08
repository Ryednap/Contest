import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


// Easy level problem Counting DP on grids :-

/*
    dp[i][j] = number of ways to reach the cell (i,j) transition is easy
    and is a pull up dp dp[i + 1][j] += dp[i][j] and dp[i][j + 1] += dp[i][j]

 */


public class H {
    static FastScanner fs = new FastScanner();
    static final int mod = (int)1e9 + 7;
    public static void main(String[] args) {
        int n = fs.nextInt(), m = fs.nextInt();
        char [][] grid = new char[n][m];
        for(int i = 0; i < n; ++i){
            grid[i] = fs.next().toCharArray();
        }

        int [][] dp = new int[n + 1][m + 1];
        dp[0][0] = 1;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                if(grid[i][j] == '#') continue;
                dp[i + 1][j] = Add(dp[i][j], dp[i + 1][j]);
                dp[i][j + 1] = Add(dp[i][j] , dp[i][j + 1]);
            }
        }
        System.out.println(dp[n - 1][m - 1]);
    }

    static int Add(int a, int b){
        return (( a + b)%mod + mod )%mod;
    }

    static class Pair{
        int first, second;
        Pair(int a, int b){
            this.first = a;
            this.second = b;
        }
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