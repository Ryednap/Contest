import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// Medium level problem:-


/* As the cost for kind of moves except teleport is 1 means it can be done using BFS else we would have to
   dijkstra. The complexity O(V + E). To achieve such complexity I have used a simple data-structure trick
   for teleportation part as everything else is Trivial BFS on grid;

   For each character we will store all the remaining position of the same character on the grid in vector
   and when we reach any one of them we know that it was shortest possible time to reach that character and so
   using that we can go to all other such characters on the grid. Now one note to avoid TLE is to clear the
   data structure for that character else we would iterate O( (#size) ^ 2) times.

   Else everything is trivial BFS.
*/
public class E {
    static FastScanner fs = new FastScanner();
    static int n, m;
    static final int OO = (int)1e9;
    static Vector<Pair>[] map = new Vector[26];
    static int [] dx = {-1, 1,0,0};
    static int [] dy = {0,0,-1,1};
    static boolean [][] visited = new boolean[2500][2500];
    static char [][] grid = new char[2500][2500];

    public static void main(String[] args) {
        n = fs.nextInt();
        m = fs.nextInt();

        for(int i = 0; i < 26; ++i) map[i] = new Vector<>();

        Pair start = new Pair();
        Pair end = new Pair();
        for(int i = 0; i < n ; ++i){
            grid[i] = fs.next().toCharArray();
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 'G'){
                    end = new Pair(i,j);
                } else if(grid[i][j] == 'S'){
                    start = new Pair(i,j);
                } else if(grid[i][j] == '#'){
                   visited[i][j] = true;

                } else if(grid[i][j] != '.'){
                    int x = grid[i][j] - 'a';
                    map[x].add(new Pair(i,j));
                }

            }
        }

        int answer = BFS(start, end);
        System.out.println(answer == OO ? -1 : answer);
    }

    static int BFS(final Pair src, final Pair dest){
        int [][] dist = new int[n + 1][m + 1];

        for(int i = 0; i <= n ; ++i) for(int j = 0; j <= m; ++j){
            dist[i][j] = OO;
        }

        Queue<Pair> q = new ArrayDeque<>();
        q.add(src);
        visited[src.first][src.second] = true;
        dist[src.first][src.second] = 0;

        while (!q.isEmpty()){
            Pair node = q.poll();
            int x = node.first, y = node.second;

            assert (!visited[x][y]);

            if(x == dest.first && y == dest.second){
                return dist[x][y];
            }
            for(int i = 0; i < 4; ++i){
                int RR = x + dx[i];
                int CC = y + dy[i];
                if(isValid(RR,CC)){

                    q.add(new Pair(RR,CC));
                    dist[RR][CC] = dist[x][y] + 1;
                    visited[RR][CC] = true;
                }
            }

            int c = grid[x][y] - 'a';
            if(c < 0 || c >= 26) continue;

            for(Pair child : map[c]){
                int RR = child.first;
                int CC = child.second;
                if(isValid(RR,CC)){
                    q.add(new Pair(RR,CC));
                    dist[RR][CC] = dist[x][y] + 1;
                    visited[RR][CC] = true;
                }
            }
            // This to avoid possible TLE
            map[c].removeAllElements();

        }

        return dist[dest.first][dest.second];
    }


    static boolean isValid(int x,int y){
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return !visited[x][y];
    }

    static class Pair{
        int first, second;
        Pair() {}
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