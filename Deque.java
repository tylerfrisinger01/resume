package assignment;




public class Deque<T> implements Hw4Queue<T>{

	Hw4QueueNode<T> front;
	Hw4QueueNode<T> back;
	int size;
	
	
	public Deque() {
		front = null;
		back = front;
		size = 0;
	}
	
	public Deque(T x) {
		front = new Hw4QueueNode<T>(x);
		back = front;
		size = 1;
	}
	
	
	public Deque(Hw4QueueNode<T> n) {
		this.front = n;
		this.back = n;
		size = 1;
	}
	
	
	
	
	@Override
	public void enqueue(T x) {
		// TODO Auto-generated method stub
		if (isEmpty()) {
			front = back = new Hw4QueueNode<T>(x);
			size++;
			return;
		}
		Hw4QueueNode<T> toinsert = new Hw4QueueNode<T>(x);
		back.setNext(toinsert);
		toinsert.setPrev(back);
		back = toinsert;
		size++;
	}

	@Override
	public T dequeue() {
		if(isEmpty()) {
			System.out.println("Tried to peek from Empty Queue");
		}
		if(size()==1) {
			T toreturn = front.getData();
			this.makeEmpty();
			return toreturn;
		}
		T toreturn = front.getData();
		// assignments work right to left
		front = front.getNext();
		front.setPrev(null);
		size--;
		return toreturn;
	}

	@Override
	public T peekFront() {
		if(isEmpty()) {
			System.out.println("Tried to peek from Empty Queue");
		}
		return front.getData();
		
	}

	@Override
	public T peekBack() {
		if(isEmpty()) {
			System.out.println("Tried to peek from Empty Queue");
		}
		return back.getData();		
	}

	@Override
	public boolean isEmpty() {
		return size == 0;		
	}

	@Override
	public void makeEmpty() {
		front = back = null;
		size = 0;
		
	}

	public int size() {
		return size;
	}
	
	public String toString() {
		//print everything in queue
		String s = "";
		Hw4QueueNode<T> p = front;
		s +="Queue, front to back: ";
		while (p!=null) {
			s+=p.getData().toString();
			if( p.getNext()!= null)
				s+=" , ";
			p=p.getNext();
		}
			return s;
	}
	
	
	
	
	
	
	
	
}
