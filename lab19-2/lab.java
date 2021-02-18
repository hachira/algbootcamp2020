//	Using Priority Queue(Heap) method
import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();

		PriorityQueue<Integer> maxHeap = new PriorityQueue<>(10, 
			(Integer a, Integer b)-> v[b] - v[a]);
		PriorityQueue<Integer> minHeap = new PriorityQueue<>(10, 
			(Integer a, Integer b)-> v[a] - v[b]);
		int half = k/2;
		//	Store k elements to maxHeap
		for(int i = 0; i < k; i++) maxHeap.add(i);
		//	Move half of k elements from maxHeap to minHeap
		for(int i = 0; i < half; i++) minHeap.add(maxHeap.poll());
		int sum = v[maxHeap.peek()], minCnt = half;
		for(int i = k; i < n; i++) {
			int r = v[maxHeap.peek()];
			maxHeap.remove(i-k);
			if(minHeap.remove(i-k)) minCnt--;
			if(v[i] > r) { minHeap.add(i); minCnt++; }
			else maxHeap.add(i);
			if(minCnt < half) {
				minHeap.add(maxHeap.poll());
				minCnt++; 
			} else if(minCnt > half) {
				maxHeap.add(minHeap.poll());
				minCnt--;
			}
			sum += v[maxHeap.peek()];
		}
		System.out.println(sum);
	}
}
