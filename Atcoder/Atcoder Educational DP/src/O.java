import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


// Medium level Problem . Dp on BitMask ( Elementary level)



public class O {
    static FastScanner fs = new FastScanner();
    static final int NAX = 30;
    static final long OO = (long)1e15;
    static final int mod = (int)1e9 + 7;

    static int n ;
    static int [] [] arr = new int[NAX][NAX];
    static int [] [] dp = new int[NAX][2097155 + 1];
    public static void main(String[] args) {
        n = fs.nextInt();
        for(int i = 0; i < n; ++i){
            arr[i] = fs.readArray(n);
            for(int j = 0; j < 2097155 + 1 ; ++j){
                dp[i][j] = -1;
            }
        }

        int answer = Brute(0, 0);
        System.out.println(answer);

    }

    static int Brute(int i , int Mask){
        if(i == n) return 1;

        if(dp[i][Mask] != -1) return dp[i][Mask];

        int res = 0;
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 1 && (Mask & (1 << j)) == 0) {
                res = Add(res, Brute(i + 1, Mask | (1 << j)));
            }
        }
        return dp[i][Mask] = res;
    }


    static int Add(int a, int b){
        return ( ( a + b)%mod + mod)%mod;
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