import java.util.Scanner;
public class hw {
    
    static long sumdigits(int[] v) {
        int sum = 0;
        for(int i = 1; i<= v[0];i++) {
            sum += v[i];
        }
		while(sum >= 10) {
			int r = 0;
			while(sum > 0) {
				r += sum%10;
				sum /= 10;
			}
			sum = r;
		}
            
        return sum;
    }
    
    static int[] fact(int n) {
		int[] r = new int[1000];
		r[0] = 1;
		r[1] = 1;
		for(int i = 1; i <= n; i++) {
			long c = 0;
			for(int j = 1; j <= r[0]; j++) {
				r[j]*=i;
				c += r[j];
				r[j] = (int)(c%10);
				c /= 10;
			}
			while(c > 0) {
				r[++r[0]] = (int)(c%10);
				c /= 10;
			}
		}
		return r;
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int bn = sc.nextInt();
        int[] as = fact(bn);
		for(int i=as[0]; i>= 1; i--) System.out.print(as[i]);
		System.out.println("");
        
        int res = (int) sumdigits(as);
        System.out.println(res);
    
    }
}
