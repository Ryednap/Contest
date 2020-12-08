import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
    Hard problem

    Currently it's showing WA maybe because some modular arithmetic error but the idea is correct.
    Will try once i have built my own Library
 */

public class F {
    static FastScanner fs = new FastScanner();
    static final int mod = (int)1e9 + 7;
    static final int nax = (int)1e6 + 10;
    static int[] fact = new int[nax];

    public static void main( String [] args){

        fact[0] = fact[1] = 1;
        for(int i = 2; i < nax; ++i){
            fact[i] = Mul(i , fact[i -1]);
        }

        int K = fs.nextInt();
        String str = fs.next();

        int N = str.length() + K;
        int Total = PowMod(26, N);
        int Minus = 0;

        for(int i = 0; i < str.length() - 1; ++i){
            int Expression = Mul(nCk(N,i) , PowMod( 25, N - i));
            Minus = Add(Minus,Expression);
        }
        System.out.println(Sub(Total , Minus));
    }

    static int PowMod(int a, int b){
        int res = 1;

        for(; b > 0 ; b >>= 1){
            int bit = b & 1;
            if(bit == 1) res = Mul(res,a);
            a = Mul(a, a);
        }
        return res;
    }


    static int ModInverse(int n){
        BigInteger b1 = new BigInteger(String.valueOf(n));
        BigInteger b2 = new BigInteger(String.valueOf(mod));
        BigInteger res = b1.modInverse(b2);
        return Integer.parseInt(res.toString());
    }

    static int Add(int a,int b){
        return ( ( a + b)%mod + mod)%mod;
    }

    static int Sub(int a, int b){
        return ( ( a - b)%mod + mod )%mod;
    }

    static int Mul(int a,int b){
        return (int)(( (long)a * b)%mod + mod)%mod;
    }

    static int nCk(int n, int k){
         int Numo = fact[n];
         int Deno = Mul(fact[n - k], fact[k]);

         return Mul(Numo, ModInverse(Deno));
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