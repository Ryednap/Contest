import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Foundational level problem Frog 2.

/*
    This is an extended version of the Problem a. In this we still
    have same meaning of dp[i] just the pull up has increased from
    1 or 2 to whole length 1...n
 */


public class B {
    static FastScanner fs = new FastScanner();


    public static void main(String[] args) {
        int n = fs.nextInt(), k = fs.nextInt();
        int [] arr = fs.readArray(n);
        long [] dp = new long[n + 1];
        for(int i = 0; i <= n ;++i) dp[i] = (long)1e14;
        dp[0] = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= k ; ++j){
                if(i + j < n ) dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(arr[i] - arr[i +j]));
            }
        }
        System.out.println(dp[n -1]);
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
