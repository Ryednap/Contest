import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// Again A greedy problem

public class E {
    static FastScanner fs = new FastScanner();
    static final int Mod = (int)1e9 + 7;

    public static void main(String[] args) {
        int N = fs.nextInt(), K = fs.nextInt();
        int [] A = fs.readArray(N);

        sort(A);

        long answer = 1;
        if(A[N-1] == 0) answer = 0;
        else if(A[N - 1] < 0 || A[0] >= 0){

            for(int i = N - 1; i > N - 1 - K; --i) answer = Mul(answer,A[i]);

        } else {
            Vector<Integer> Positive = new Vector<>();
            Vector<Integer> Negative = new Vector<>();
            for(int i = 0; i < N; ++i){
                if(A[i] < 0) Negative.add(A[i]);
                else Positive.add(A[i]);
            }

            while(K > 0){
                if(Positive.size() == 1 && Negative.size() == 1){
                    answer = Mul( answer, Positive.lastElement());
                    Positive.remove(Positive.size() - 1);
                    --K;

                    if(K == 1){
                        answer = Mul(answer,Negative.lastElement());
                        Negative.remove(Negative.size() - 1);
                        --K;
                    }
                } else if(K == 1) {
                    if(Positive.size() != 0) answer = Mul(answer, Positive.lastElement());
                    else answer = Mul(answer, Negative.elementAt(0));

                } else {
                    long neg = 1, pos = 1;
                    if(Negative.size() >= 2){
                        neg = Negative.lastElement();
                        neg *= Negative.elementAt(Negative.size() - 2);
                    }

                    if(Positive.size() >= 1){
                        pos *= Positive.lastElement();
                    }
                    if(Positive.size() >= 2){
                        pos *= Positive.elementAt(Positive.size() - 2);
                    }

                    if(pos > neg){
                        answer = Mul(answer, pos);
                        for(int x = 0; x < 2; ++x ){
                            if(Positive.size() == 0) break;
                            Positive.remove(Positive.size() - 1);
                            --K;
                        }

                    } else {
                        answer = Mul(answer, neg);
                        for(int x = 0; x < 2; ++x){
                            Negative.remove(Negative.size() - 1);
                            --K;
                        }
                    }

                }
            }
        }

        System.out.println((answer + Mod)%Mod);
    }

    static long Mul(long a, long b){
        return ( ( a * b)%Mod +Mod)%Mod;
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