//	A* Algorithm
import java.util.*;
class Pair {
	float key; int value;
	Pair(float k, int v) { key = k; value = v; }
}
public class lab {
	static float INF = 1000000000;
	static float distance(float[][] v, int s, int e) {
		return (float)Math.sqrt((v[s][0]-v[e][0])*(v[s][0]-v[e][0]) +
			(v[s][1]-v[e][1])*(v[s][1]-v[e][1]));
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		float[][] v = new float[n+1][2];
		for(int i = 1; i <= n; i++) {
			v[i][0] = scan.nextFloat();
			v[i][1] = scan.nextFloat();
		}
		Vector<Vector<Integer>> adjList = new Vector<Vector<Integer>>();
		for(int i = 0; i <= n; i++) adjList.add(new Vector<Integer>());
		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			adjList.get(a).add(b);
		}
		int start = scan.nextInt(); int end = scan.nextInt();
		Queue<Pair> que = new PriorityQueue(n, new Comparator<Pair>() {
			public int compare(Pair x, Pair y) {
				return (x.key > y.key)?1:(x.key < y.key)?-1:0;
			}
		});
		boolean[] visited = new boolean[n+1];
		float[] values = new float[n+1];
		for(int i = 1; i <= n; i++) values[i] = INF;
		values[start] = 0;
		int[] from = new int[n+1]; from[start] = 0;
		que.add(new Pair(distance(v, start, end), start));
		while(!que.isEmpty()) {
			Pair r = que.remove();
			if(visited[r.value]) continue;
			if(r.value == end) break;
			visited[r.value] = true;
			for(int c : adjList.get(r.value)) {
				if(visited[c]) continue;
				float t = values[r.value] + distance(v, r.value, c);
				if(values[c] > t) {
					values[c] = t;
					from[c] = r.value;
					que.add(new Pair(t+distance(v, c, end), c));
				}
			}
		}
		System.out.println(values[end]);
		//	Print path
		int[] path = new int[n]; int pq = 0;
		while(end != 0) {
			path[pq++] = end;
			end = from[end];
		}
		for(int i = pq-1; i >= 0; i--) System.out.print(path[i]+" ");
		System.out.println("");
	}
}
