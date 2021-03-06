import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Unsolved the complexity is O(n^2)

// The reason for the O(N^2) complexity is that it's like memoized version of LCS just the space complexity is O(N)

public class Q {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 3e5 + 10;
    static final long OO = (long)1e15;

    static int N;
    static int [] H = new int[NAX];
    static int [] A = new int[NAX];
    static long [] dp =  new long[NAX];
    public static void main(String[] args) {

        N = fs.nextInt();
        for(int i = 0; i < N; ++i){
            H[i] = fs.nextInt();
        }
        A = fs.readArray(N);

        H[N] = -1;
        for(int i = 0; i < NAX ; ++i) dp[i] = -1;

        long answer = Brute(0,N);
        System.out.println(answer);
    }

    static long Brute(int flower, int i){ // current flower and the last chosen flower.
        if(flower == N) return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        long a, b = 0;
        a = Brute(flower + 1, i);
        if(H[flower] > H[i]) b = Brute(flower + 1, flower) + A[flower];
        return dp[i] = Math.max(a,b);
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