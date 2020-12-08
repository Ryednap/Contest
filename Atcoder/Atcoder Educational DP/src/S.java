import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Upper easy level problem
// Dp on digits i.e dp on prefix with some uniqueness.

/*
    The complexity is O(D*|K| * 2)
    Here dp[i][j][k] means what is current number whose length is i and the sum of digits
    so far is j and k is an indicator we can remove it from the dp anyway as it just indicates whether
    the past chosen digit was larger than or smaller than the given digit.
 */

public class S {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 1e4 + 10;
    static final int mod = (int)1e9 + 7;

    static int D;
    static String K;
    static int[][][] dp = new int [NAX][100][2];
    public static void main(String[] args) {
        K = fs.next();
        D = fs.nextInt();
        for(int i = 0; i < NAX; ++i) for(int j = 0; j < 100; ++j){
            for(int k = 0; k < 2; ++k)
                dp[i][j][k] = -1;
        }

        int answer = Brute(0,0,0);
        System.out.println(Sub(answer,1));
    }

    static int Brute(int i, int j, int k){
        if(i == K.length()) return j == 0? 1 : 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int digit = K.charAt(i) - '0';
        int res = 0;

        for(int a = 0; a < 10; ++a){
            if(a > digit && k != 1) break;
            res = Add(res, Brute(i + 1, (j + a)%D, (a < digit ? 1 : k)));
        }
        return dp[i][j][k] = res;
    }


    static int Add(int a, int b){
        return ( ( a + b)%mod + mod)%mod;
    }
    static int Sub(int a, int b){
        return ( ( a  -  b)%mod + mod)%mod;
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