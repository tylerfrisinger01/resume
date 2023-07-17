package assignment;

public interface Hw4Queue<T> {


		void enqueue(T x);
		
		
		T dequeue();
		
		
		T peekFront();
		
		
		T peekBack();

		
		boolean isEmpty();
		
		
		void makeEmpty();
		
		
		String toString();


}
