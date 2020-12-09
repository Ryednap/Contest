import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedOutputStream;
import java.util.*;


// Again A greedy problem

public class E {
    static FastScanner fs = new FastScanner();
    static final int Mod = (int)1e9 + 7;

    public static void main(String[] args) {
      int N = fs.nextInt(), K = fs.nextInt();
      Vector<Integer> Positive = new Vector<>();
      Vector<Integer> Negative = new Vector<>();

      for(int i = 0; i < N; ++i){
          int x = fs.nextInt();
          if(x < 0) Negative.add(x);
          else Positive.add(x);
      }

      long answer = 1;

      if(Negative.size() == 0){ // Case 1
          Positive.sort(Collections.reverseOrder());
          for(int i = 0; i < K; ++i){
              answer = Mul(answer,Positive.elementAt(i));
          }

      } else if(Positive.size() == 0){ // Case 2
          if(K%2 == 0) Collections.sort(Negative);
          else Negative.sort(Collections.reverseOrder());

          for(int i = 0; i < K; ++i){
              answer = Mul(answer, Negative.elementAt(i));
          }

      } else if(Positive.lastElement() == 0){ // Case 3
          if(K % 2 == 0){
              Collections.sort(Negative);
              for(int i = 0; i < K; ++i){
                  answer = Mul(answer,Negative.elementAt(i));
              }

          } else answer = 0;

      } else if(K == N) { // Case 4
          for(Integer x : Positive) answer = Mul(answer, x);
          for(Integer x : Negative) answer = Mul(answer, x);

      } else if(K == N - 1){ // Case 5
          Collections.sort(Positive);
          Collections.sort(Negative);
          if(Positive.elementAt(0) == 0){
              for(int i = 1; i < Positive.size(); ++i) answer = Mul(answer,Positive.elementAt(i));
              for(Integer x : Negative) answer = Mul(answer,x);

              answer = Math.max(0, answer);
          } else {
              if(Negative.size() % 2 != 0){
                  Negative.remove(Negative.size() - 1);
              } else {
                  Positive.remove(0);
              }

              for(Integer x : Positive) answer = Mul(answer, x);
              for (Integer x : Negative) answer = Mul(answer,x);

          }
      } else { // Case 7

          Negative.sort(Collections.reverseOrder());
          Positive.sort(Collections.reverseOrder());
          int p,n;
          if(K % 2 == 0){
              p = Positive.size() - 1;

          } else {
              answer = Mul(answer, Positive.lastElement());
              p = Positive.size() - 2;
          }

          n = Negative.size() - 1;

          while(K > 0){
              int i = p, j = n;
              long pos = 1, neg = 1;
              int count = 0;
              while(i >= 0 && count != 2){
                  pos *= Positive.elementAt(i);
                  --i; count++;
              }
              count = 0;
              while(j >= 0 && count != 2){
                  neg *= Negative.elementAt(j);
                  --j; count++;
              }

              if(pos > neg){
                  answer = Mul(answer,pos);
                  K -= (p - Math.max(i,0));
                  p = i;

              } else {
                  answer = Mul(answer,neg);
                  K -= ( n - Math.max(j,0));
                  n = i;
              }
          }

      }
      System.out.print(answer);

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