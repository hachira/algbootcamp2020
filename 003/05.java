import java.util.Scanner;

public class Main {
   
   static long fibo(int n) {
      long f1, f2, fn = n;
      if(n < 0) return -1;
      else if(n <= 1) return n;
      else {
         f2 = 0;
         f1 = 1;
      }
      for(int i=2; i<=n; i++) {
         fn = f1 + f2;
         f2 = f1;
         f1 = fn;
      }
      
      return fn;
   }
   
   public static void main(String[] args) {
      
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();

      System.out.println(fibo(n)%1000000009);
  
   }

}
