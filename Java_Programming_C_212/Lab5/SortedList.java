
public class SortedList 
{
	// Instance variables
	private Node<Integer> head;
	private String name;

	// Constructor
	public SortedList (String name)
	{
		this.name = name;
		this.head = null;
	}

	// Getters
	public String getName()
	{
		return name;
	}

	public Node<Integer> getHead()
	{
		return head;
	}

	// Public Methods
	public void insert(int intData)
	{
		//create node
		Node<Integer> node = new Node<Integer>(new Integer(intData) , null);

		// two temporary Nodes to loop over list
		Node<Integer> currentNode;
		Node<Integer> previousNode;

		// insert node in list, in proper place
		// if list is empty than, node is to be inserted as head node
		if (head == null)
		{
			head = node;
		}
		// check if node is to be inserted at the begining
		else if (node.getData().intValue() <= head.getData().intValue())
		{
			node.setNext(head);
			head = node;
		}
		// find insertion point
		else
		{
			// starting at head Node find insertion point
			previousNode = head;
			currentNode = head.getNext();

			while(currentNode != null)
			{
				if (node.getData().intValue() <= currentNode.getData().intValue() && node.getData().intValue() > previousNode.getData().intValue())
				{
					// insert node before current node
					node.setNext(currentNode);

					// fix the link from previous node to point to the inserted node
					previousNode.setNext(node);

					// insertion is done return, to calling method
					return;
				}

				// move temporary nodes to next location
				previousNode = currentNode;
				currentNode = currentNode.getNext();

			}

			// currentNode is a link to the last element in the list
			// if while loop is over without insertion, node is inserted at the end
			previousNode.setNext(node);
			node.setNext(null);
		}
	}

	public void insert(Node<Integer> node)
	{
		// two temporary Nodes to loop over list
		Node<Integer> currentNode;
		Node<Integer> previousNode;

		// insert node in list, in proper place
		// if list is empty than, node is to be inserted as head node
		if (head == null)
		{
			head = node;
		}
		// check if node is to be inserted at the begining
		else if (node.getData().intValue() <= head.getData().intValue())
		{
			node.setNext(head);
			head = node;
		}
		// find insertion point
		else
		{
			// starting at head Node find insertion point
			previousNode = head;
			currentNode = head.getNext();

			while(currentNode != null)
			{
				if (node.getData().intValue() <= currentNode.getData().intValue() && node.getData().intValue() > previousNode.getData().intValue())
				{
					// insert node before current node
					node.setNext(currentNode);

					// fix the link from previous node to point to the inserted node
					previousNode.setNext(node);

					// insertion is done return, to calling method
					return;
				}

				// move temporary nodes to next location
				previousNode = currentNode;
				currentNode = currentNode.getNext();

			}

			// currentNode is a link to the last element in the list
			// if while loop is over without insertion, node is inserted at the end
			previousNode.setNext(node);
			node.setNext(null);
		}
	}


	public void merge(SortedList anotherSortedList)
	{
		// A temporary Node to loop over list
		Node<Integer> currentNode = anotherSortedList.head;
		Node<Integer> nextNode = currentNode.getNext();
		
		// insert in calling list
		while (currentNode != null)
		{
			this.insert(currentNode);
			currentNode = nextNode;
			if (currentNode != null)
				nextNode = nextNode.getNext();
		}
		
		// clear the otherList
		anotherSortedList.head = null;
	}

	public void printList()
	{
		// print list name
		System.out.print(name + ": ");

		// check if list is empty
		if (head == null)
		{
			System.out.println("Empty List!");
			return;
		}

		// A temporary Node to loop over list
		Node<Integer> currentNode = head;

		// print list data
		while (currentNode != null)
		{
			System.out.format("%2d  ", currentNode.getData());
			currentNode = currentNode.getNext();			
		}

		System.out.println();
	}
}
