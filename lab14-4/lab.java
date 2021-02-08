import java.util.*;
class PriorityQueue {
	int[] data; int n;
	public PriorityQueue(int nsize) { data = new int[nsize+1]; }
	public int get() {
		int save = data[1], r = 1;
		int v = data[n--];
		while(2*r <= n) {
			int min = 2*r;
			if(min < n && data[min] > data[min+1]) min++;
			if(data[min] >= v) break;
			data[r] = data[min];
			r = min;
		}
		data[r] = v;
		return save;
	}
	public void put(int v) {
		int c = ++n;
		while(c != 1) {
			int p = c/2;
			if(data[p] <= v) break;
			data[c] = data[p];
			c = p;
		}
		data[c] = v;
	}
}
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		PriorityQueue pq = new PriorityQueue(n);
		for(int i = 0; i < n; i++) {
			String cmd = scan.next();
			if(cmd.equals("G")) System.out.println(pq.get());
			else pq.put(scan.nextInt());
		}
	}
}
