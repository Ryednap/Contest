import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


// Foundational Problem for dp on Game Theory

// Here we check if for each step if there's any winning chance. Even a single winning chance wuld make
// this step winning else this step becomes or stays losing.


public class K {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 1e6;
    public static void main(String[] args) {
        int N = fs.nextInt(),  K = fs.nextInt();
        int [] arr = fs.readArray(N);

        int [] dp = new int[NAX]; // dp[i] = winning chance at ith stone.
        dp [0] = 0; // 0 is the losing state.

        for(int i = 0; i <= K; ++i){
            for(int j = 0; j < N; ++j){
                int x = arr[j];
                dp[i + x] |= dp[i] ^ 1;
            }
        }

        System.out.println(dp[K] == 1 ? "First" : "Second");

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