package assignment;

public class Prime {


	 public static boolean isPrime(int n, int j) { // returns true if its a prime.

		 if (j == 1) // 2 is a prime number
			 return true;
		 else if(n%j == 0)
			 return false;
		 else
			 return isPrime(n,j-1);
	}
	 
	 public static boolean is_Prime(int num1,int num2) {
		 while(num1 < 2) {
			 return false;
		 }
		 if(num1%num2 == 0)
			 return false;
		 else
			 return isPrime(num1,num2-1);
		 
	 }
	
	
}
