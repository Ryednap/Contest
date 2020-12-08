import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Upper Easy level Problem :- DP on two pointers.

/*
    O(N^2 * 2) complexity .
    dp[i][j][turn] = On the turn when the two pointers are at ith and jth
    location respectively what is the maximum or minimum respectively based on turn
 */


public class L {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 3e3 + 10;

    static long [][][] dp = new long[NAX][NAX][2];
    static int [] arr = new int[NAX];
    static int N;

    public static void main(String[] args) {
        N = fs.nextInt();
         arr = fs.readArray(N);

        for(int i = 0; i < NAX; ++i) for(int j = 0; j < NAX; ++j) for(int k = 0; k < 2; ++k){
            dp[i][j][k] = -1;
        }

        System.out.println(Brute(0, N - 1, 0));

    }

    static long Brute(int i, int j ,int k){
        if(i > j) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        long a = Brute(i + 1, j, k ^ 1); // take from left
        long b = Brute(i , j - 1, k ^ 1); // take from right

        if(k == 0) return dp[i][j][k] = Math.max(a + arr[i], b + arr[j]);
        else return dp[i][j][k] = Math.min(a - arr[i], b - arr[j]);
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