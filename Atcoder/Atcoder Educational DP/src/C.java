import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Easy problem Vacation

// here dp[i][j] means what is the maximum happiness for ith day
// when we are picking the jth  event

public class C {
    static FastScanner fs = new FastScanner();


    public static void main(String[] args) {
        int n = fs.nextInt();
        int [][] arr = new int[n][3];
        for(int i = 0; i < n ; ++i) for(int j = 0; j < 3; ++j){
            arr[i][j] = fs.nextInt();
        }

        long [][] dp = new long[n + 1][3];
        for(int i = 0; i < 3; ++i) dp[0][i] = arr[0][i];

        for(int i = 1; i < n ; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    if(k != j) dp[i][j] = Math.max(dp[i][j], dp[i - 1][k] + arr[i][j]);
                }
            }
        }

        long ans = 0;
        for(int i = 0; i < 3; ++i) ans = Math.max(ans, dp[n - 1][i]);
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