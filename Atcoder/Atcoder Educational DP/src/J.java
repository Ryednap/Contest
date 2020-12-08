import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


// Hard problem :- Unsolved


public class J {
    static FastScanner fs = new FastScanner();
    static int a = 0, b = 0, c = 0;
    static final int  NAX = (int)3e2;

    public static void main(String[] args) {
        int n = fs.nextInt();

        for(int i = 0; i < n; ++i){
            int x = fs.nextInt();
            if(x == 1) ++a;
            else if(x == 2) ++b;
            else ++c;
        }

        double [][][] dp = new double[NAX][NAX][NAX];
        dp[a][b][c] = 1.0;


        for(int k = n; k >= 0 ; --k){
            for(int j = n; j >= 0; --j){
                for(int i = n; i >= 0; --i){
                    double sum = i + j + k;
                    if(i != 0) dp[i - 1][j][k] += dp[i][j][k] * i/sum;
                    if(j != 0) dp[i + 1][j - 1][k] += dp[i][j][k] * j / sum;
                    if(k != 0) dp[i][j + 1][k - 1] += dp[i][j][k] * k / sum;

                }
            }
        }


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