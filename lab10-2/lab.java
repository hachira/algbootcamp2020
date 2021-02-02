import java.util.*;
public class lab {
	public static void main(String[] args) {
		//	Process Inputs
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int[] maze = new int[(n+2)*(m+2)];
		for(int i = 1; i <= n; i++) {
			String str = scan.next();
			for(int j = 0; j < m; j++) {
				maze[i*(m+2)+j+1] = str.charAt(j) - '0';
			}
		}
		int startpoint = m+3, endpoint = n*(m+2)+m;
		//	Queue
		int[] queue = new int[n*m]; int qp=0, dp=0;
		//	push (1, 1) into queue
		queue[qp++] = startpoint;
		//	node values
		int[] values = new int[(n+2)*(m+2)];
		values[startpoint] = 1;
		//	For while queue is not empty.
		while(dp < qp) {
			//	Dequeue from queue
			int r = queue[dp++];
			//	Check this is end point
			if(r == endpoint) { System.out.println(values[endpoint]); break; }
			int[] diff = { 1, m+2, -1, -m-2 };
			for(int i = 0; i < 4; i++) {
				int nr = r + diff[i];
				if(maze[nr] == 1 && values[nr] == 0) {
					values[nr] = values[r]+1;
					queue[qp++] = nr; 
				}
			}
		}
	}
}
