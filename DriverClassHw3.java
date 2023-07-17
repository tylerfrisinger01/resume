package assignment;


public class DriverClassHw3 {
	
	
	
	
	
	
	
	public static void main(String[] args) {

		
		System.out.println("Test case 1 - Integers\n");
		System.out.println("First list of Integers: ");
		ListNodeHw3<Integer> node = new ListNodeHw3<Integer>(8);
		Hw3List<Integer> list1 = new Hw3List<Integer>(node);
		
		list1.add(9);
		list1.add(12);
		list1.add(34);
		list1.add(66);
		list1.add(89);
		
		System.out.println(list1.printList());
		System.out.println("\n");
	
	
		System.out.println("Second list of Integers:");
		ListNodeHw3<Integer> node2 = new ListNodeHw3<Integer>(8);
		Hw3List<Integer> list2 = new Hw3List<Integer>(node2);
		list2.add(10);
		list2.add(15);
		list2.add(34);
		list2.add(65);
		list2.add(66);
		list2.add(67);
		
		System.out.println(list2.printList());
	
		/*
		ListNodeHw3<Integer> node3 = new ListNodeHw3<Integer>(8);
		Hw3List<Integer> list3 = new Hw3List<Integer>(node3);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);
		list3.add(null);

		
		System.out.println(list2.size);
		System.out.println(list1.size);
*/
		
		
		
	}

		
		
		
	}
	


	


