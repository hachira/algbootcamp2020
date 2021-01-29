import java.util.*;
class Edge {
	int w, a, b;
	Edge(int a, int b, int w) { this.a = a; this.b = b; this.w = w; }
}
public class lab {
	static int findRoot(int[] set, int v) {
		if(set[v] == v) return v;
		return (set[v] = findRoot(set, set[v]));
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		Vector<Edge> edges = new Vector<Edge>();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			int w = scan.nextInt();
			edges.add(new Edge(a, b, w));
		}
		Collections.sort(edges, new Comparator<Edge>() {
			public int compare(Edge x, Edge y) { return x.w - y.w; }
		});
		int comp = 0, sum = 0;			//	selected edges count
		int[] set = new int[n+1];		//	disjoint set
		for(int i = 1; i <= n; i++) set[i] = i;
		for(Edge e : edges) {
			int ra = findRoot(set, e.a);
			int rb = findRoot(set, e.b);
			if(ra == rb) continue;
			sum += e.w;
			set[rb] = ra;
			if(++comp == n-1) break;
		}
		System.out.println(sum);
	}
}
