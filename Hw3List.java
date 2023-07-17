package assignment;

public class Hw3List<T> {

	
	ListNodeHw3<T> head;
	int size;
	/**
	 * zero-parameter constructor
	 * initizalizes empty list
	 */
	
	public Hw3List() {
		this.head = null;
	}
	/**
	 * construct takes node parameter
	 * and sets it as the list
	 * @param h
	 */
	
	public Hw3List(ListNodeHw3<T> h) {
		this.head = h;
		size++;
	}
	/**
	 * Constructor takes data parameter,
	 * create node containing data,
	 * and sets as list
	 * @param x
	 */
	public Hw3List(T x) {
		head = new ListNodeHw3<T>(x);
		size++;
	}
	/**
	 * Tells if list is empty
	 * @return
	 */
	public boolean isEmpty() {
		return head == null;
	}
	/**
	 * Makes the list empty
	 * Erases access for all nodes after & including head.
	 * The old list is ready for garbage collection
	 */
	public void makeEmpty() {
		head = null;
		size = 0;
	}
	/**
	 * returns the first (zeroth-indexed) node in list
	 * @return
	 */
	public ListNodeHw3<T> getFirst(){
		return head;
	}
	
	/**
	 * adds new data to end of list.
	 * @param x
	 */
	public void add(T x) {
		
		insert(x,size);
	}
	/**
	 * Inserts value x at position i of the list
	 * If i is 0, we shift all values right and
	 * crate new head. 
	 * If i > 0, we find the position at i-1, and 
	 * we shift remaining nodes to the right. 
	 * @param x
	 * @param i
	 */
	public void insert(T x, int i) { // adds to front of list
		if ( i< 0 || i>this.size()) {
			System.out.println("index out of bounds");
			return;
		}
		int j;
		j = i>0 ? 1: 0;
		// 2 cases
		switch(j) {
		case 0: 
			// x -> head --> ...
			// make node containing 6
			ListNodeHw3<T>	newnode = new ListNodeHw3<T>(x); // these 3 steps for making new node and starting at beginning. order is important
			//point x to head
			newnode.setNext(head);
			// point head to x
			head = newnode;
			size++;
			
			case 1:
			// 0 < i < size()-1 
			// get node at i - 1
			ListNodeHw3<T> p = getNode(i-1);
			// set x to i-1.next
			ListNodeHw3<T> n = new ListNodeHw3<T>(x);
			n.setNext(p.getNext()); // when we call p.getNext it gives us i which is the first one we wanted 
			// set i - 1's next to x
			p.setNext(n);
			size++;
			
		}
	}
	
	/**
	 * Returns count of nodes in the list
	 * Size value is modified when the list is changed.
	 * @return
	 */
	public int size() {
		return size;
	}
	
	/**
	 * Return the value at given index i
	 * @param i
	 * @return
	 */
	public T get(int i) {
		return getNode(i).getData();
		
	}
	
	/**
	 * Returns the node at given index i
	 * Checks list up to i, if i is valid.
	 * @param i
	 * @return
	 */
	private ListNodeHw3<T> getNode(int i){
		// get the node at an index	
		// case: if list is empty
		if(isEmpty())
			return null;
		
		// case: check if i is valid (in range of list)
		if(i>size()-1 || i<0) {
			System.out.println("error: tried to get node outside the list");
			return null;
	}
		
		ListNodeHw3<T> pointer = head;
		// if j initialized to 0 & i is 0, will return head.
		for ( int j = 0; j<i;j++) {
			pointer = pointer.getNext();
		}
		
		return pointer;
	}
	
	/**
	 * Search list for first instance of x, 
	 * returns index location.
	 * returns -1 if not found.
	 * @param x
	 * @return
	 */
	public int find(T x) {
		ListNodeHw3<T> p = head;
		int i = 0;
		while(p != null) {
			if (p.getData().equals(x)) {
				return i;
			}
			p = p.getNext();
			i++;
		}
		System.out.println("Item not found");
		return -1;
	}
	
	
	/**
	 * Deletes node at given index i, 
	 * shifts remaining nodes left.
	 * @param i
	 */
	
	public void delete(int i ) {
		// check if i is valid
		if(i < 0 || i > size()) {
			System.out.println(" i is out of bounds");
			return;
		}
		// if deleting head node
		if ( i == 0) {
			head = head.getNext();
			size--;
			return;
		}
		// deleting later in the list
		// also handles i = size()-1
		if(i > 0) {
			ListNodeHw3<T> p = getNode(i-1);

			p.setNext(p.getNext().getNext());
			size--;
			return;
		}
	}
	
	/**
	 * delete value from list (first instance)
	 * @param x value to delete
	 */
	public void delete(T x) {
		int i = find(x);
		if (i == -1) return;
		delete(i);
		
	}
	
	/**
	 * String representation of list: prints num of nodes.
	 * Could be modified to iterate through list and print out each nodes data
	 */
	public String toString() {
		return "List has "+size() + " nodes.";
	}
	
	/**
	 * Iterates through the list, returns string containing all data.
	 * @return
	 */
	public String printList() {
		String str = "";
		ListNodeHw3<T> pointer = head;
		while (pointer != null) {
			str += pointer.getData().toString();
			str += "  ";
			pointer = pointer.getNext();
		}
		return str;
	}
	
	
	
	
}

