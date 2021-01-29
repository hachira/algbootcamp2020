import java.util.*;
class Edge {
	int a, b, w;
	Edge(int a, int b, int w) { this.a=a; this.b = b; this.w = w; }
}
public class lab {
	static int INF = 1000000000;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(); int k = scan.nextInt();
		Vector<Edge> edges = new Vector();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			int w = scan.nextInt();
			edges.add(new Edge(a, b, w));
		}
		int start = scan.nextInt();
		int[] values = new int[n+1];
		for(int i = 1; i <= n; i++) values[i] = INF;
		values[start] = 0;
		boolean dirty = false;
		for(int i = 0; i < n; i++) {
			dirty = false;
			for(Edge e : edges) {
				if(values[e.a] == INF) continue;
				int t = values[e.a] + e.w;
				if(values[e.b] > t) {
					values[e.b] = t;
					dirty = true;
				}
			}
			if(!dirty) break;
		}
		if(dirty) { System.out.println("Invalid Graph"); return; }
		for(int i = 1; i <= n; i++) System.out.println(values[i]);
	}
}
