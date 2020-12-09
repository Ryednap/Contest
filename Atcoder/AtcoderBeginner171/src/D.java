import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


// Easy problem

// Just Maintain a look-up table and then do as per the problem.


public class D {
    static FastScanner fs = new FastScanner();
    static final int nax = (int)1e5 + 10;

    public static void main( String [] args){
        int N = fs.nextInt();
        long sum = 0;
        int [] arr = new int[nax];


        for(int i=  0; i < N; ++i){
            int x = fs.nextInt();
            sum += x;
            arr[x]++;
        }
        int Q = fs.nextInt();
        for(int i = 0;i < Q; ++i){
            int a = fs.nextInt(), b = fs.nextInt();
            sum -= ((long)a * arr[a]);
            sum += ((long)b * arr[a]);

            arr[b] += arr[a];
            arr[a] = 0;
            System.out.println(sum);
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