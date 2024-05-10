import java.util.Scanner;
 
public class WeirdAlgorithm {
	public static void main(String[] args) {
		long n;
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextLong();
		while (n != 1) {
			System.out.print(n + " ");
			if (n % 2 == 0) {
				n = n / 2;
			} else {
				n = n * 3 + 1;
			}
		}
		System.out.println(1);
	}
}
