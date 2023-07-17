package assignment;

import java.util.Iterator;
import java.util.LinkedList;


public class MethodLinky<T> {

	public static void merge(LinkedList<Integer>linky,LinkedList<Integer>list){
		
		

		//Iterator it = linky.iterator();
		//Iterator it2 = list.iterator();
		System.out.println("Intersection of Integers: ");
		if(list.size()>linky.size()) linky.addLast(list.getLast());
			for(int i = 0; i < list.size();i++) {
			if(list.get(i) == linky.get(i)) {
			
			 System.out.println(list.get(i));
			 
			}

	}
			System.out.println(list.getLast());

	
}
	
	public static void union(LinkedList<Integer>linky,LinkedList<Integer>list) {
		
		//LinkedList<Integer> union = new LinkedList<Integer>();

			System.out.println("Union of two Integers: \n");
			
			Iterator i = list.iterator();
			//Iterator i2 = linky.iterator();

			while(i.hasNext()) {
				
				linky.add((int)i.next());
			}
		System.out.println(linky+ " \n");
	}
	
	
	
}
