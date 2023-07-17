package assignment;

public class Hw4QueueNode<T> {
	
	private T data;
	Hw4QueueNode<T> next;
	Hw4QueueNode<T> prev;
	public Hw4QueueNode(T data, Hw4QueueNode<T> next, Hw4QueueNode<T> prev) {
		super();
		this.data = data;
		this.next = next;
		this.prev = prev;
	}
	
	public Hw4QueueNode(T data) {
		this.data = data;
		
	}
	public Hw4QueueNode() {
		this.data = null;
		next = null;
		prev = null;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

	public Hw4QueueNode<T> getNext() {
		return next;
	}

	public void setNext(Hw4QueueNode<T> next) {
		this.next = next;
	}

	public Hw4QueueNode<T> getPrev() {
		return prev;
	}

	public void setPrev(Hw4QueueNode<T> prev) {
		this.prev = prev;
	}
	
	
	public String toString() {
		return data.toString();
	}
	
	
	
	
	
	

}
