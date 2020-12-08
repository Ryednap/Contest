import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Vector;

// upper medium DP on DAG graph

/* This is a foundational problem in dp on DAG . What we are doing is two things. First is that we are
    Moving across each node in the topological order via in_degree and also it ensures that we visit each node
    exactly once . So when a node say is visited means we are now final with the fact that dp which it represents
    is them maximum we can get.
 */




public class G {
    static FastScanner fs = new FastScanner();
    static final int NAX = (int)1e5 + 1;
    static int n , m;
    static Vector<Integer> [] adj = new Vector[NAX];
    static int [] in_degree = new int[NAX];
    static boolean [] visited = new boolean[NAX];
    static int [] dp = new int[NAX];

    public static void main(String[] args) {
        n = fs.nextInt();
        m = fs.nextInt();
        for(int i = 0; i < NAX; ++i) adj[i] = new Vector<Integer>();

        for(int i = 0; i < m; ++i){
            int a = fs.nextInt(), b = fs.nextInt();
            adj[a].add(b);
            in_degree[b]++;
        }

        for(int i = 1; i <= n ;++i){
            if(in_degree[i] == 0 && !visited[i]){
                dfs(i);
            }
        }

        int ans = 0;
        for(int i = 1; i <= n ;++i) ans = Math.max(dp[i], ans);
        System.out.println(ans);
    }

    static void dfs(int node){
        visited[node] = true;

        for(Integer child : adj[node]){
            dp[child] = Math.max(dp[child], dp[node] + 1);
            --in_degree[child];
            if(in_degree[child] == 0 && !visited[child]) dfs(child);
        }
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