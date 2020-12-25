import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		int count=0;
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();

		boolean[] arr = new boolean[num + 1];
		arr[0] = arr[1] = false;
		for (int i = 2; i <= num; i += 1) {
			arr[i] = true;
		}

		for (int i = 2; i * i <= num; i += 1) {
			for (int j = i * i; j <= num; j += i) {
				arr[j] = false;
			}
		}
		for (int i = 0; i <= num; i += 1) {
			if (true == arr[i]) {
				count++;
			}
		}
		System.out.println(count);
	}
}
