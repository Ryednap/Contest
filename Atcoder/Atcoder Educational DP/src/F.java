import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Easy level. DP on Strings

/*
    Just the difference is we have to build output else it's a trivial
    LCS problem of O(N^2) complexity.
 */


public class F {
    static FastScanner fs = new FastScanner();
    static String a, b;
    static String ans = "";
    static int [][]dp= new int[3001][3001];
    public static void main(String[] args) {
        a = fs.next();
        b = fs.next();
        for(int i = 0; i < 3001; ++i) for(int j = 0; j < 3001; ++j){
            dp[i][j] = -1;
        }
        Brute(0,0);
        Build(0,0);
        System.out.println(ans);
    }

    static int Brute(int i, int j){
        if(i == a.length()) return 0;
        if(j == b.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(a.charAt(i) == b.charAt(j)) return dp[i][j] = Brute(i + 1, j + 1) + 1;

        int a = Brute(i + 1, j);
        int b = Brute(i , j + 1);
        return dp[i][j] = Math.max(a,b);
    }

    static void Build(int i, int j){
        if(i == a.length() || j == b.length()) return ;

        if(a.charAt(i) == b.charAt(j)){
            ans += a.charAt(i);
            Build(i + 1, j + 1);
            return ;
        }

        int maxi = Brute(i, j);
        int a = Brute(i + 1, j);

        if(maxi == a) Build(i + 1, j);
        else Build(i , j + 1);
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