package assignment;

public class ListNodeHw3<T> {
	private T data;
	private ListNodeHw3<T> next;
	
	public ListNodeHw3(T d) {
		this.data = d;
		this.next = null;
	}
	
	public ListNodeHw3(T d, ListNodeHw3<T> n) {
		this.data = d;
		this.next = n;
	}
	public T getData() {
		return data;
	}
	public void setData(T data) {
		this.data = data;
	}
	public ListNodeHw3<T> getNext() {
		return next;
	}
	public void setNext(ListNodeHw3<T> next) {
		this.next = next;
	}
	
	public String toString() {
		return "First List of Integers: "+this.data;
	}
	
	
}
