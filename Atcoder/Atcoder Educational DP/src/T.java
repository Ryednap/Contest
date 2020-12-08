import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// DP on Permutation (I guess we can change the problem to subset finding problem)

public class T {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 1e3 + 10;
    static final int mod = (int)1e9 + 7;

    static int n;
    static String str;
    static int [] [] dp = new int[NAX][NAX];
    public static void main(String[] args) {
        n = fs.nextInt();
        str = fs.next();
        for(int i = 0; i < NAX; ++i) for(int j = 0; j < NAX; ++j){
            dp[i][j] = -1;

        }

        int answer = 0;
        for(int i = 1; i <= n; ++i){
            answer = Add(answer, Brute(0,i));
        }
        System.out.println(answer);
    }

    static int Brute(int i, int j){
        if(i == n - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;

        char ch = str.charAt(i);
        if(ch == '<'){
            for(int k = j + 1; k <= n; ++k){
                res = Add(res, Brute(i + 1, k));
            }
        } else {
            for(int k = j - 1; k > 0; --k){
                res = Add(res, Brute(i+ 1, k));
            }
        }

        return dp[i][j] = res;
    }

    static int Add(int a, int b){
        return ( ( a + b)%mod + mod)%mod;
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