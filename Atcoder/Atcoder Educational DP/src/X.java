import javax.annotation.processing.SupportedSourceVersion;
import javax.swing.plaf.synth.SynthTextAreaUI;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Hard level : Dp on knapsack

// Check why this sorting works.

public class X {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int) 1e3 + 10;
    static final int MAX = (int) 3e4 + 10;


    static int N;
    static int [] w = new int[NAX];
    static int [] s = new int[NAX];
    static int [] v = new int[NAX];
    static long [][] dp = new long[NAX][MAX];

    public static void main(String[] args) {
       N = fs.nextInt();
       ArrayList<Tuple> l = new ArrayList<>();
       for(int i = 0; i < N; ++i){
           int a = fs.nextInt();
           int b = fs.nextInt();
           int c = fs.nextInt();
           l.add(new Tuple(a, b, c));
       }

       Collections.sort(l,Tuple.Comp);
       for(int i = 0; i < N ; ++i){
           Tuple t = l.get(i);
           w[i] = t.a;
           s[i] = t.b;
           v[i] = t.c;
       }


       for(int i = 0; i < NAX; ++i) for(int j = 0; j < MAX; ++j){
           dp[i][j] = -1;
       }

       long answer = Brute(0,0);
       System.out.println(answer);
    }



    static long Brute(int i, int j){
        if(i == N) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        long a = Brute(i + 1, j);
        long b = 0;
        if(j <= s[i]) b = Brute(i+ 1, j + w[i]) + v[i];
        return dp[i][j] = Math.max(a,b);
    }

    static class Tuple{
        int a, b, c;
        Tuple(int a, int b,int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public static Comparator<Tuple> Comp= Comparator.comparingInt(o -> (o.a + o.b));
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