import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Medium level Problem : Nested style DP

/*
    Although this is a foundational level nested style dp but what makes
    it a bit hard is that it's not asking directly for the sum . rather it's asking
    for the sum rather it's asking for sum of sums. So what to do for the memoized people
    the best way is to return a Pair one for the sum and the other for the sum of sums.
    the one part is always going to be the toal sum of all items. and the other is our answer.
 */
public class N {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 3e3 + 10;
    static final long OO = (long)1e15;

    static int n;
    static Pair [][] dp = new Pair[NAX][NAX];
    static int [] arr = new int[NAX];
    public static void main(String[] args) {
        n = fs.nextInt();
        arr = fs.readArray(n);
        for(int i = 0; i < n + 1 ; ++i) for(int j = 0; j < n + 1; ++j){
            dp[i][j] = new Pair(-1,OO);
        }

        Pair answer = Brute(0, n - 1);
        System.out.println(answer.second);
    }

    static Pair Brute(int i, int j){
        if(i == j) return new Pair(arr[i], 0);
        if(i + 1 == j) return new Pair((long)arr[i] + arr[j], (long)arr[i] + arr[j]);

        if(dp[i][j].first != -1) return dp[i][j];

        Pair ans = new Pair(OO,OO);
        for(int k = i; k < j; ++k){
            Pair a = Brute(i , k);
            Pair b = Brute(k + 1 , j);

            long Pass = a.first + b.first;
            long Add = a.second + b.second;
            if(ans.second > Add + Pass){
                ans.second = Add + Pass;
                ans.first = Pass;
            }
        }
        return dp[i][j] = ans;
    }



    static class Pair{
        long first, second;
        Pair(long a, long b){
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