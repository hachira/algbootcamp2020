import java.util.Scanner;

public class Main {

   public static void main(String[] args) {
      
      Scanner sc = new Scanner(System.in);
      System.out.println("두 개의 문자열 입력");
      char[] s1 = sc.nextLine().toCharArray();
      char[] s2 = sc.nextLine().toCharArray();

      int[][] arr = new int[s1.length+1][s2.length+1];

      for (int i=1; i<=s1.length; i++) {
         for (int j=1; j<=s2.length; j++) {
            if (s1[i-1] == s2[j-1]) arr[i][j] = arr[i-1][j-1]+1;
            else arr[i][j] = Math.max(arr[i-1][j], arr[i][j-1]);
         }
      }

      System.out.println(arr[s1.length][s2.length]);

   }

}
