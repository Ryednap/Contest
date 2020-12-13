import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


// the damn decimal may get you a bad feel but forget it and it's an easy adhoc problem.

public class B {
    static FastScanner fs = new FastScanner();

    public static void main (String [] args) {
        int N = fs.nextInt(),M = fs.nextInt(), T = fs.nextInt();
        int temp = N;
        boolean ok = true;
        int curr = 0;
        for(int i = 0; i < M; ++i){
            int a = fs.nextInt(), b =fs.nextInt();
            int x = a - curr;
            if(x >= N) ok = false;
            N = Math.min(temp, N - x + b - a);
            curr = b;
        }
        int x = T - curr;
        if(x >= N) ok = false;
        System.out.print(ok ? "Yes" : "No");
    }



    static class Pair{
        int F, S;
        Pair() {}
        Pair(int a, int b){
            this.F = a;
            this.S = b;
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