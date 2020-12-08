import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Hard Combinatorics Problem .

/*
    This problem is based on inclusion - exclusion principle.
    It's hard to number of configuration in which both the sequence for each posn are different. but the reverse is easy
    to calculate.

    Total number of possible configuration(unique) is (nPm)^2 i.e permutation. Now some are bad and the bad items are that
    which for each position some numbers are same. so let's say that exactly one such number is there then two,.....
    and then it becomes inclusion exclusion

    1)- Number of cases in which one position is same :- mC1 * nC1 * 1! * Remaining_comb
    2)- Number of cases in which two position is same :- mC2 * nC2 * 2! * Remaining_comb
    .
    .
    i) - Number of cases in which i positions are same :- mCi * nCi * i! * Remaining_comb

    Remaining_comb is ( ( m - i)P(n - i))^2.

    Now if we remove 1's case then note that cases in which 2 are same has been removed two times. so we need to add
    and so on using inclusion - exclusion principle.
 */

public class E {
    static FastScanner fs = new FastScanner();
    static final int Mod = (int)1e9 + 7;
    static int [] fact = new int [(int)5e5 + 10];
    public static void main( String [] args){

        fact[0] = 1;
        for(int i = 1; i <= (int)5e5 + 9; ++i) fact[i] = Mul(fact[i -1], i);

         int N  = fs.nextInt() , M = fs.nextInt();

         int Total = PowMod(Mul(nCk(M,N), fact[N]), 2);

         for(int i = 1; i <= N; ++i){
             int Exp = Mul(nCk(M,i) , Mul(nCk(N,i) , fact[i]));
             int Rem = PowMod(Mul(nCk(M - i, N - i) , fact[N - i]), 2);
             if(i % 2 == 0) Total = Add(Total, Mul(Exp, Rem));
             else Total = Sub(Total, Mul(Exp, Rem));
         }

         System.out.println(Total);
    }


    static int Add(int a,int b){
        return ( ( a + b)%Mod + Mod)%Mod;
    }

    static int Mul(int a, int b){
        return (int)(( (long)a * b)%Mod + Mod)%Mod;
    }

    static int Sub(int a, int b){
        return ( ( a - b)%Mod + Mod)%Mod;
    }

    static int PowMod(int a, int b){
        int res = 1;

        for(; b > 0 ; b >>= 1){
            int bit = b & 1;
            if(bit == 1) res = Mul(res, a);
            a = Mul(a, a);
        }

        return res;
    }

    static int ModInverse(int x){
        return PowMod(x, Mod - 2);
    }
    static int nCk(int n, int k){
        if(n < k) return 0;
        if(k == 0) return 1;
        int Nemo = fact[n];
        int Deno = Mul(fact[k], fact[n - k]);

        return Mul(Nemo, ModInverse(Deno));
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