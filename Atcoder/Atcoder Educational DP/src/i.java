import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


// Easy level Dp on Probability

/*
    The solution is easy due to easy transition . If we choose the current coin to be head or tail.
 */


public class i {
    static FastScanner fs = new FastScanner();
    static final int NAX = 3000;
    static int n;
    static double [] arr = new double[NAX];
    static double [][] dp = new double[NAX][NAX];


    public static void main(String[] args) {
        for(int i = 0; i < NAX; ++i) for(int j = 0; j < NAX; ++j) dp[i][j] = -1;
        n = fs.nextInt();
        for(int i = 0; i < n ; ++i){
            arr[i] = fs.nextDouble();
        }

        double answer = Brute(0,0);
        System.out.println(answer);
    }

    static double Brute(int i, int j){
        if(i == n) return (j <= n - j ? 0 : 1);

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = Brute(i + 1, j + 1) * arr[i] + Brute(i + 1, j ) * (1 - arr[i]);
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