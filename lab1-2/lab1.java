import java.util.Scanner;
public class lab1 {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      int n = scan.nextInt();
      int k = scan.nextInt();
      int j = n/k;
      long sum = 0;
      sum = (long)k*j*(j+1)/2;
      System.out.println(sum);
   }
}
