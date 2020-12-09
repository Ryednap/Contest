import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// Upper Easy level

// This was a new type of problem i.e Meet in the middle
// The idea is of brute force so no problem :) :-



public class F {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        int N = fs.nextInt(), T = fs.nextInt();

        int [] arr = fs.readArray(N);
        Vector<Integer> A = new Vector<>();
        Vector<Integer> B = new Vector<>();

        for(int i = 0; i < N; ++i) {
            if(i <= N/2) A.add(arr[i]);
            else B.add(arr[i]);
        }

        long[] ans1 = Solve(A);
        long[] ans2 = Solve(B);


        sort(ans2);
        long answer = 0;


        for(long x : ans1){
            int lo = 0,hi = ans2.length - 1;
            long res = -1;

            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(x + ans2[mid] <= T){
                    res = x + ans2[mid];
                    lo = mid + 1;

                } else hi = mid - 1;
            }

            answer = Math.max(answer,res);
        }

        System.out.println(answer);
    }

    static long [] Solve(Vector<Integer> arr){
        Vector<Long> v = new Vector<>();
        final int n = arr.size();
        for(int i = 0; i < (1 << n); ++i){
            long sum = 0;
            for(int j = 0;j < n; ++j){
                int bit = i & (1 << j);
                if(bit > 0) sum += arr.elementAt(j); // java way to check whether a bit is set or unset
            }
            v.add(sum);
        }
        long [] res = new long[v.size()];
        for(int i = 0; i < v.size(); ++i) res[i] = v.elementAt(i);
        return res;
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