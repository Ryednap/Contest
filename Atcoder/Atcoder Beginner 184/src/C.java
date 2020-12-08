import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// Easy level problem :-

// the answer is either going to be 0 , 1 or 2 or 3. For each one of them just check what is the medium possible
// we have 4 kind of let's say move. 3-move to diagonal, diagonal to diagonal, 3 - move to 3 - move and diagonal
// to 3 - move. just make cases for each on of em'.


public class C {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
       int a = fs.nextInt(), b = fs.nextInt();
       int c = fs.nextInt(), d = fs.nextInt();

       int level = 10;

       if(a == c && b == d) level = 0;
       else if(a + b == c + d || a - b == c - d){
           level = 1;
       } else if(f(a,b,c,d) || f(c,d,a,b)) {
           level = 2;
       }

       level = Math.min( Math.min(level, g(a,b,c,d)), g(c,d,a,b));


       System.out.println(level == 10 ? 3 : level);
    }

    static boolean f(int x1, int y1 , int x2, int y2){ // diagonal to diagonal
        int a = x1 + y1;
        int b = x2 - y2;

        return (a + b) % 2 == 0 && Math.abs(a - b) % 2 == 0;
    }

    static int g(int x1, int y1, int x2, int y2){
        int res = 10;

        for(int i = x1 - 3; i <= x1 + 3; ++i){
            for(int j = y1 - 3; j <= y1 + 3; ++j){
                if(i == x2 && j == y2){
                    res = 1;
                } else if( i + j == x2 + y2 || i - j == x2 - y2){
                    res = Math.min(res, 2);
                }
            }
        }

        return res;
    }

    static class Pair{
        int first, second;
        Pair(int a, int b){
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