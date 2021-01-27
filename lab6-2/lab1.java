import java.util.Scanner;
import java.util.Vector;
import java.util.ArrayList;
public class lab1 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		ArrayList<Vector<Integer>> adjList = new ArrayList(n);
		for(int i = 0; i < n; i++) {
			adjList.add(i, new Vector<Integer>());
		}

		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			adjList.get(a-1).add(b);
			adjList.get(b-1).add(a);
		}

		for(int i = 0; i < n; i++) {
			System.out.print((i+1)+" : ");
			for(int j = 0; j < adjList.get(i).size(); j++) {
				System.out.print(adjList.get(i).elementAt(j)+" ");
			}
			System.out.println("");
		}
	}
}
