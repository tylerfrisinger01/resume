package assignment;

import java.util.Scanner;

public class PrimeDriver {

		public static void main(String[] args) {
		// TODO Auto-generated method stub

			int [ ] numbers = new int [100];
			System.out.println("Please enter positive integers to test for primality: \n");
		Scanner scanner = new Scanner(System.in);
		String line = scanner.nextLine();
		String [] num = line.split(" ");
		int i = 0;
		for(String s: num) {
			numbers[i] = Integer.parseInt(s);
			i++;
		}
		for(int j = 0; j < i; j++) {
			if(Prime.is_Prime(numbers[j],numbers[j]-1)) {
				System.out.println(numbers[j]+ " is a prime.");
			}
			else
				System.out.println(numbers[j]+ " is not a prime.");
		}
		
		scanner.close();
	}
		
		
		
		
		
		
}
