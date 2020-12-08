import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// Medium level problem:-

/* If you have practiced problems on EV then's it's a trivial problem but if not then it's surely a tough
    Normally for EV problems it may be some sequence like AP , GP or sometimes AGP. Sometimes it may be a
    trivial formula one , but sometimes it's something like this DP. here dp[i][j][k] is the EV of
    reaching this state from the original a,b,c. once we fulfill the condition we need to return the total
    amount spend and that can be easily calculated as the sum of net increase in the parameter from the initial
    one.
 */


public class D {
    static FastScanner fs = new FastScanner();

    static double [][][] dp = new double[101][101][101];
    static int a , b , c;
    public static void main(String[] args) {

        a = fs.nextInt();
        b = fs.nextInt();
        c = fs.nextInt();
        for(int i = 0; i < 101; ++i) for(int j = 0; j < 101; ++j) for(int k = 0; k < 101; ++k){
            dp[i][j][k] = -1;
        }

        double answer = Brute(a, b, c);
        System.out.println(answer);
    }

    static double Brute(int i, int j , int k){
        if(i == 100 || j == 100 || k == 100){
            return i - a + j - b + k - c;
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        double res = 0;
        res += Brute(i + 1, j ,k) * (double)i / (i + j  + k);
        res += Brute(i, j + 1, k) * (double)j / (i + j + k);
        res += Brute(i , j , k + 1) *(double)k / (i + j + k);
        return dp[i][j][k] = res;
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