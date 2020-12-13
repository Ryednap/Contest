import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
    Standard Dp on two pointers. Here we either take or leave. Just take care of the base case so that it may
    not leave you wondering why my answering is wrong even after getting it right.
 */



public class E {
    static FastScanner fs = new FastScanner();
    static int nax = (int)1e3 + 10;
    static int OO = (int)1e7;

    static int[] A = new int[nax];
    static int[] B = new int[nax];
    static int [][] dp = new int[nax][nax];

    static int N, M;
    public static void main (String [] args){
        N = fs.nextInt();
        M = fs.nextInt();
        A = fs.readArray(N);
        B = fs.readArray(M);

        for(int i = 0; i < nax; ++i){
            for(int j = 0; j < nax; ++j){
                dp[i][j] = -1;
            }
        }

        int answer = Brute(0,0);
        System.out.println(answer);
    }

    static int Brute(int i, int j) {
        if(i == N || j == M) return (N - i + M - j);

        if (dp[i][j] != -1) return dp[i][j];

        int a = Brute(i + 1, j) + 1; // delete from A
        int b = Brute(i, j + 1) + 1; // delete from B

        int c = (A[i] != B[j] ? Brute(i + 1, j + 1) + 1 : Brute(i + 1, j + 1)); // i am considering

        int[] temp = {a,b,c};
        sort(temp);
        return dp[i][j] = temp[0];
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