import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Optimization problem

/*
    Think in the problem domain of binary search, greedy or Dp or some combination of them.

    Here Dp is not possible A short note that we have similar problem based on Dp on two pointers in Educational Dp but
    the constraint there supported O(N^2) complexity. So let's think about binary search.

    Let's say that any time we have read a books from A and b from B . then total = a + b. so for a trivial implementation
    will be iterate over all possible a and b but the compleixty will be O(NM) . so let's improve it we can do binary search
    for the second variable if sort the list. :)
 */

public class C {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args){
        int N = fs.nextInt(), M = fs.nextInt(), K = fs.nextInt();
        int [] A = fs.readArray(N);
        int [] B = fs.readArray(M);

        long [] a = PartialSum(A);
        long [] b = PartialSum(B);

        int answer = 0;

        for(int i = 0; i <= N; ++i){

            int res = 0;
            int lo = 0, hi = M;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(a[i] + b[mid] <= K){
                    res = mid;
                    lo = mid + 1;

                } else hi = mid - 1;
            }

            if(a[i] + b[res] > K) continue;

            answer = Math.max(answer , i + res);
        }
        System.out.print(answer);
    }

    static long [] PartialSum(int [] arr){
        long [] res = new long[arr.length + 1];

        for(int i = 1 ; i < res.length; ++i){
            res[i] = res[i - 1] + arr[i - 1];
        }

        return res;
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