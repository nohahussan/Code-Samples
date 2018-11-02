
public class Node<T> 
{
	// Instance variables
	private T data;
	private Node<T> next;
	
	// Constructor
	public Node(T data, Node<T> next)
	{
		this.data = data;
		this.next = next;
	}

	// Getters and Setters
	public T getData() 
	{
		return data;
	}

	public void setData(T data) 
	{
		this.data = data;
	}

	public Node<T> getNext() 
	{
		return next;
	}

	public void setNext(Node<T> next) 
	{
		this.next = next;
	}
}
