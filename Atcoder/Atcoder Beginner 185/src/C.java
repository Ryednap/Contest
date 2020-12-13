import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


// Easy combinatorics problem.

/*
    Stars and bars approach . If partition of size >= 0 then ( N + K - 1) C (K - 1) . But here we must have
    partition of size != 0 so it's ( N - 1 ) C ( K - 1).
    An easier way to code could be run the loop 11 times and the multiply (N - i).
 */


public class C {
    static FastScanner fs = new FastScanner();
    static  final int nax = 300;
    static long [][] dp = new long[nax][nax];
    public static void main (String [] args){
        int L = fs.nextInt();
        for(int i = 0; i < nax; ++i){
            for(int j = 0; j < nax; ++j){
                dp[i][j] = -1;
            }
        }
        long answer = nCk(L - 1, 11);
        System.out.print(answer);
    }

    static long  nCk(int n, int k){
        if(k == 0) return 1;
        if(n < k) return 0;

        if(dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = nCk(n - 1, k) + nCk(n - 1, k - 1);
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