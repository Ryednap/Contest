import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


/* Another Nice Mathematical Problem
    In this note that the most optimal k would be the minimum gap length. because we cannot take k greater than
    that. Now if we do that we can always build the solution just total answer for each gap is ceil( gap_length / k).
 */


public class D {
    static FastScanner fs = new FastScanner();
    static  final  int OO = (int)2e9;
    public static void main (String [] args){
        int N = fs.nextInt(), M = fs.nextInt();
        int [] arr = fs.readArray(M);
        sort(arr);

        int ans = OO;
        int curr = 0;
        for(int i = 0; i < M; ++i){
            if(arr[i] - curr - 1 != 0){
                ans = Math.min(ans, arr[i] - curr - 1);
            }
            curr = arr[i];
        }

        if(N - curr  > 0) ans = Math.min(N - curr, ans);

        long  res = 0;
        curr = 0;
        for(int i = 0; i < M; ++i){
            int x = arr[i] - curr - 1;
            res += (x + ans - 1)/ans;
            curr = arr[i];
        }
        res += (N - curr + ans - 1)/ans;
        System.out.print(res);
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