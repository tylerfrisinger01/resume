package assignment;

import java.util.Iterator;
import java.util.LinkedList;

public class Linky {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LinkedList<Integer> linky = new LinkedList<Integer>();
		linky.add(8);
		linky.add(9);
		linky.add(12);
		linky.add(34);
		linky.add(66);
		linky.add(89);
		
		System.out.println("First List of Integers:\n");
		System.out.println(linky+"\n");

		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(8);
		list.add(10);
		list.add(15);
		list.add(34);
		list.add(65);
		list.add(66);
		list.add(67);
		
		System.out.println("Second List of Integers:\n");
		System.out.println(list+"\n");
		

		MethodLinky.union(linky,list);

		
		MethodLinky.merge(linky,list);
		
		
		}
		
	
	
	
	
}
	
	
	
	

	
	
	
	
	
	

		
