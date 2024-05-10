import java.util.Scanner;
import java.util.Arrays;

public class MissingNumber {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n - 1];
		boolean[] present = new boolean[n];
		Arrays.fill(present, Boolean.FALSE);

		for (int i = 0; i < n - 1; ++i) {
			present[sc.nextInt() - 1] = true;
		}
		for (int i = 0; i < n; ++i) {
			if (!present[i]) {
				System.out.println(i + 1);
			}
		}
	}
}
