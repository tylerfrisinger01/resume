package assignment;

import java.util.Arrays;
import java.util.LinkedList;

public class LLhw3<T> {

	ListNodeHw3<T> head;
	int size;
	
	
	public LLhw3() {
		
		this.head = null;
		
	}
	
	public LLhw3(ListNodeHw3<T> h ) {
		this.head = h;
		size++;
	}
	
	
	public LLhw3(T x) {
		head = new ListNodeHw3<T>(x);
		size++;
	}
	
	
	public boolean isEmpty() {
		return head == null;

	}
	
	public void makeEmpty() {
		head = null;
		size = 0;
		

	}
	/**
	 * returns the first index in list
	 * @return
	 */
	public ListNodeHw3<T> getFirst(){
		return head;
	}
	
	public void add(T x) {
		insert(x,size);
	}
	
	public void insert(T x,int i) {
		if(i < 0 || i > this.size()) {
			System.out.println("index out of bounds");
			return;
		}
		
		int j;
		j= i > 0 ? 1 : 0;
		
		switch(j) {
		case 0:
			
			ListNodeHw3<T> newnode = new ListNodeHw3<T>(x);
			newnode.setNext(head);
			head = newnode;
			size++;
			
			
		case 1:
			
			ListNodeHw3<T> p = getNode(i-1);
			
			ListNodeHw3<T> n = new ListNodeHw3<T>(x);
			n.setNext(p.getNext());
			p.setNext(n);
			size++;
		}
		
	}
	
	
	public int size() {
		return size;	
		
	}
	
	
	public T get(int i) {
		return getNode(i).getData();
	}
	
	
	
	private ListNodeHw3<T> getNode(int i){
		
		if(isEmpty())
			return null;
		if(i>size()-1 || i < 0) {
			System.out.println("error: Tried to get node outside the list.");
			
		}
		ListNodeHw3<T> pointer = head;
		for(int j = 0; j < i; j++) {
			pointer = pointer.getNext();
		}
		return pointer;
	}
	
	

	
	public int find(T x) {
		ListNodeHw3<T> p = head;
		int i = 0;
		while (p!=null) {
			if(p.getData().equals(x)) {
				return i;
			}
			p = p.getNext();
			i++;
		}
		System.out.println("item not found");
		return -1;
	}
	
	
	
	public void delete(int i) {
		if(i < 0 || i > size()) {
			System.out.println("Index is out of bounds");
			return;
		}
		if(i == 0) {
			head = head.getNext();
			size--;
			return;
		}
		if( i > 0) {
			ListNodeHw3<T> p = getNode(i-1);
			p.setNext(p.getNext().getNext());
			size--;
			return;
		}
	}

	public void delete(T x) {
		int i = find(x);
		if(i == -1) return;
		delete(i);
	}
	
	public String toString() {
		return "List has "+size()+ " nodes.";
		
	}
	
	public String printList() {
		String str = "";
		ListNodeHw3<T> pointer = head;
		while(pointer != null) {
			str += pointer.getData().toString();
			str += " ";
			pointer = pointer.getNext();
		}
		return str;
	}

	
	public LLhw3<T> Intersection(LLhw3<T>list1,LLhw3<T>list2){
		LLhw3<T> intersection = new LLhw3<T>();
		for(int i = 0; i < this.size();i++) {
			ListNodeHw3<T> node = (ListNodeHw3<T>) list1.get(i);
			while(node != null && node.getNext() != null) {
				//if(list2.find()) {
					
				}
			}
		}
		
		
		return list2;
		
	}

	
	
	
	
}
