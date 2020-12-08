import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


// Upper Easy level

// This was a new type of problem i.e Meet in the middle
// The idea is of brute force so no problem :) :-


public class D {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args){
        int N = fs.nextInt();
        long [] arr = fs.readLongArray(N);
        long xor = 0;
        for(int i = 0; i < N ; ++i){
            xor ^= arr[i];
        }
        for(int i = 0; i < N; ++i){
            arr[i] ^= xor;
            System.out.print(arr[i] + " ");
        }
    }


    static void sort(long[] a) {
        ArrayList<Long> list = new ArrayList<>();
        for (long i : a) list.add(i);
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