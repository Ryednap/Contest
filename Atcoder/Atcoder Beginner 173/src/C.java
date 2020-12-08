import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

// Medium Brute Force

/*
    One thing i learned is that although the array and all is passed by value in java but it's by
    reference to object . So java maintains only copy of that object no matter if it's directly copied by
    = operator or is passed to a function.

 */

public class C {
    static FastScanner fs = new FastScanner();

    static int N, M, K;
    public static void main(String[] args) {
        N = fs.nextInt();
        M = fs.nextInt();
        K = fs.nextInt();

        char [][] grid = new char[N][M];
        char [][] copy = new char [N][M];
        for(int i = 0; i < N; ++i){
            grid[i] = fs.next().toCharArray();
            if (M >= 0) System.arraycopy(grid[i], 0, copy[i], 0, M);
        }
        int answer = 0;

        for(int i = 0; i< (1 << N); ++i){
            for(int j = 0; j < (1 <<M); ++j){
                if(Check(i,j,grid)) ++answer;
                for(int row = 0; row < N; ++row){
                    if (M >= 0) System.arraycopy(copy[row], 0, grid[row], 0, M);
                }
            }
        }

        System.out.println(answer);

    }

    static  boolean Check(int x, int y, char [][] grid){
            for(int i = 0; i < N; ++i){
                int bit = x & (1 << i);
                if(bit > 0) for(int j = 0; j < M; ++j){
                    if(grid[i][j] == '#') grid[i][j] = 'R';
                }
            }

            for(int i = 0; i < M; ++i){
                int bit = y & (1 << i);
                if(bit > 0) for(int j = 0; j < N; ++j){
                    if(grid[j][i] == '#') grid[j][i] = 'R';
                }
            }

            int count = 0;
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < M; ++j){
                    if(grid[i][j] == '#') ++count;
                }
            }
            return count == K;
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