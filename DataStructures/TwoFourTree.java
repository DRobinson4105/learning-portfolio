import java.util.*;
import java.io.*;

class Node {
	private static final int ORDER = 4;
	private int numItems;
	private Node parent;
	private Node children[] = new Node[ORDER];
	private Integer items[] = new Integer[ORDER - 1];

	// connect child to this node
	public void connectChild(int index, Node child) {
		children[index] = child;
		if (child != null) child.parent = this;
	}

	// disconnect child from this node and return
	public Node disconnectChild(int index) {
		Node tempNode = children[index];
		children[index] = null;
		return tempNode;
	}

	public Node getChild(int index) {
		return children[index];
	}

	public Node getParent() {
		return parent;
	}

	public boolean isLeaf() {
		return (children[0] == null) ? true : false;
	}

	public int getNumItems() {
		return numItems;
	}

	public void setNumItems(int val) {
		numItems = val;
		return;
	}

	public Integer getItem(int index) {
		return items[index];
	}

	public Integer setItem(int index, Integer val) {
		items[index] = val;
		return items[index];
	}

	public boolean isFull() {
		return numItems == ORDER - 1;
	}

	public int insertItem(Integer item) {
		numItems++;

		for (int i = ORDER - 2; i >= 0; i--) {
			if (items[i] == null) continue;
			else {
				if (item < items[i])
					items[i + 1] = items[i];
				else {
					items[i + 1] = item;
					return i + 1;
				}
			}
		}

		items[0] = item;
		return 0;
	}

	public void insertAtFront(Integer item) {
		numItems++;
		for (int i = numItems - 1; i > 0; i--) {
			items[i] = items[i - 1];
			connectChild(i + 1, disconnectChild(i));
		}

		connectChild(1, disconnectChild(0));
		items[0] = item;
		connectChild(0, null);

		return;
	}

	public Integer removeItem() {
		Integer temp = items[numItems - 1];
		items[numItems - 1] = null;
		numItems--;
		return temp;
	}

	public void displayNode() {
		for (int i = 0; i < numItems; i++)
			System.out.print(items[i] + ", ");
	}

	public void displayValue(int index) {
        System.out.println(items[index]);
	}

	public void deleteValue(int val) {
		int flag = -1;
		for (int i = 0; i < numItems; i++) {
			if (val == items[i]) flag = i;

			if (flag != -1 && i + 1 < numItems) {
				items[i] = items[i + 1];
			}
		}
		items[--numItems] = null;
	}

	public Node getSibling(int val) {
		Node x = null;
		Node p = getParent();
		if (numItems != 0) {
			for (int i = 0; i <= p.numItems; i++) {
				if (p.children[i].items[0] < val)
					x = p.children[i];
			}
		} else if (numItems == 0) {
			for (int i = 0; i <= p.numItems; i++) {
				if (p.children[i].items[0] == null && i != 0)
					x = p.children[i - 1];
			}
		}
		return x;
	}

}

public class TwoFourTree {
	
	private Node root = new Node();

	public void insert(int val) {
		Node curNode = root;

		while (true) {
			if (curNode.isFull()) {
				split(curNode);
				curNode = curNode.getParent();
				curNode = getNextChild(curNode, val);
			} else if (curNode.isLeaf()) {
				break;
            } else {
				curNode = getNextChild(curNode, val);
            }
        }

		curNode.insertItem(val);
	}

	public void split(Node thisNode) {
		Integer itemB, itemC;
		Node parent, child2, child3;
		int itemIndex;

		itemC = thisNode.removeItem();
		itemB = thisNode.removeItem(); 
		child2 = thisNode.disconnectChild(2);
		child3 = thisNode.disconnectChild(3);

		Node newRight = new Node();

		if (thisNode == root) {
			root = new Node();
			parent = root;
			root.connectChild(0, thisNode);
		} else {
			parent = thisNode.getParent();
        }

		itemIndex = parent.insertItem(itemB);
		int n = parent.getNumItems();

		for (int i = n - 1; i > itemIndex; i--) {
			Node temp = parent.disconnectChild(i);
			parent.connectChild(i + 1, temp);
		}

		parent.connectChild(itemIndex + 1, newRight);

		newRight.insertItem(itemC);
		newRight.connectChild(0, child2);
		newRight.connectChild(1, child3);
	}

	public Node getNextChild(Node node, int val) {
		int i, numItems = node.getNumItems();

		for (i = 0; i < numItems; i++) {
			if (val < node.getItem(i))
				return node.getChild(i);
		}

		return node.getChild(i);
	}

	public void displayTree(int i) {
		if (i == 0)
			recDisplayTree(root, 0, 0);
		else
            inOrderDisplay(root, 0, 0);

		System.out.println();
	}

	private void recDisplayTree(Node node, int level, int childNumber) {
		System.out.print("level=" + level + " child=" + childNumber + " ");
		node.displayNode();
		System.out.println();

		int numItems = node.getNumItems();
		for (int i = 0; i < numItems + 1; i++) {
			Node nextNode = node.getChild(i);
			if (nextNode != null)
				recDisplayTree(nextNode, level + 1, i);
			else
				return;
		}
	}

	public void inOrderDisplay(Node node, int level, int childNumber) {
		int numItems = node.getNumItems();

		for (int i = 0; i < numItems + 1; i++) {
			Node nextNode = node.getChild(i);
			if (nextNode != null) {
				inOrderDisplay(nextNode, level + 1, i);
            } else {
				node.displayNode();
				return;
			}

			if (i < node.getNumItems())
                node.displayValue(i);
		}
	}

	public Node find(int val) {
		return findValue(root, val);
	}

	public Node findValue(Node theNode, int val) {
		Node l = null;
		int numItems = theNode.getNumItems();

		for (int i = 0; i < numItems; i++) {
			if (val == theNode.getItem(i)) {
				l = theNode;
				break;
			} else if (val < theNode.getItem(i) && !theNode.isLeaf()) {
				l = findValue(theNode.getChild(i), val);
				break;
			} else if (val > theNode.getItem(i) && !theNode.isLeaf()) {
				l = findValue(theNode.getChild(i + 1), val);
			}
		}

		return l;
	}
    
	public Node delete(Node currnode, int val) {
		Node y = null;
		
		if (currnode.isLeaf()) {
			if (currnode.getNumItems() > 1) {
				currnode.deleteValue(val);
				return currnode;
			} else {
				y = deleteLeafCases(currnode, val);
				return y;
			}
		} else {
			Node n = getNextChild(currnode, val);
			Node c = getInOrderNode(n);
			Integer d = c.getItem(0);
			int k = d;
			delete(c, d);
					
			Node found = find(val);
			for (int i = 0; i < found.getNumItems();i++) {
				if(found.getItem(i) == val)
                    found.setItem(i, k);
			}

			return found;
		}
	}

	public Node deleteLeafCases(Node thisNode, int theValue) {
		String sibling_side = "l";
		Node p = thisNode.getParent();
		Node sibling = thisNode.getSibling(theValue);

		if (sibling == null) {
			sibling_side = "r";
			sibling = p.getChild(1);
		}

		if (sibling.getNumItems() == 1) {
			for (int i = 0; i <= p.getNumItems(); i++) {
				if (p.getChild(i) == sibling && sibling_side == "l") {
					thisNode.setItem(thisNode.getNumItems() - 1, null);
					thisNode.setNumItems(thisNode.getNumItems() - 1);

					Integer d = p.getItem(i);
					sibling.insertItem(d);
					p.disconnectChild(i + 1);

					for (int j = i; j < p.getNumItems(); j++) {
						if (j + 1 < p.getNumItems()) {
							p.setItem(j, p.getItem(j + 1));
							if (j + 2 <= p.getNumItems()) {
								p.connectChild(j + 1, p.disconnectChild(j + 2));
							}
						}
					}

					p.setItem(p.getNumItems() - 1, null);
					p.setNumItems(p.getNumItems() - 1);

					if (p.getNumItems() == 0) {
						if (p != root) p = balanceTree(p);
						else root = sibling;
					}

					return p;

				} else if (p.getChild(i) == sibling && sibling_side == "r") {
					thisNode.setItem(thisNode.getNumItems() - 1, null);
					thisNode.setNumItems(thisNode.getNumItems() - 1);
					Integer d = p.getItem(i - 1);
					sibling.insertItem(d);
					p.disconnectChild(0);
					p.connectChild(0, p.disconnectChild(1));

					for (int j = i; j < p.getNumItems(); j++) {
						p.setItem(j - 1, p.getItem(j));
						if (j + 1 <= p.getNumItems()) {
							p.connectChild(j, p.disconnectChild(j + 1));
						}
					}

					p.setItem(p.getNumItems() - 1, null);
					p.setNumItems(p.getNumItems() - 1);

					if (p.getNumItems() == 0) {
						if (p != root) p = balanceTree(p);
						else root = sibling;
					}
					return p;

				}
			}
		} else if (sibling.getNumItems() > 1) {
			int f = 0;
			if (sibling_side == "r") {
				f = 0;
			} else {
				f = sibling.getNumItems() - 1;
			}

			for (int i = 0; i <= p.getNumItems(); i++) {
				if (p.getChild(i) == sibling && sibling_side == "l") {
                    thisNode.setItem(0, p.getItem(i));
                    p.setItem(i, sibling.getItem(f));
					sibling.deleteValue(sibling.getItem(f));
					return p;
				}

				if (p.getChild(i) == sibling && sibling_side == "r") {
                    thisNode.setItem(0, p.getItem(i - 1));
                    p.setItem(i - 1, sibling.getItem(f));
					sibling.deleteValue(sibling.getItem(f));
					return p;
				}
			}
		}

		return null;
	}

	public Node balanceTree(Node currnode) {
		String sibling_side = "l";
		Node p = currnode.getParent();
		Node sibling = currnode.getSibling(-1);
		if (sibling == null) {
			sibling_side = "r";
			sibling = p.getChild(1);
		}

		if (sibling.getNumItems() == 1) {
			for (int i = 0; i <= p.getNumItems(); i++) {
				if (p.getChild(i) == sibling && sibling_side == "l") {
					Integer d = p.getItem(i);
					sibling.insertItem(d);
					sibling.connectChild(sibling.getNumItems(),
							currnode.disconnectChild(0));

					p.disconnectChild(i + 1);

					for (int j = i; j < p.getNumItems(); j++) {
						if (j + 1 < p.getNumItems()) {
							p.setItem(j, p.getItem(j + 1));
							if (j + 2 <= p.getNumItems()) {
								p.connectChild(j + 1, p.disconnectChild(j + 2));
							}
						}
					}
					p.setItem(p.getNumItems() - 1, null);
					p.setNumItems(p.getNumItems() - 1);

					if (p.getNumItems() == 0) {
						if (p != root) p = balanceTree(p);
						else root = sibling;
					}
					return p;
				} else if (p.getChild(i) == sibling && sibling_side == "r") {
					Integer d = p.getItem(i - 1);
					sibling.insertAtFront(d);
					sibling.connectChild(0, currnode.disconnectChild(0));
					p.disconnectChild(0);
					p.connectChild(0, p.disconnectChild(1));

					for (int j = i; j < p.getNumItems(); j++) {
						p.setItem(j - 1, p.getItem(j));
						if (j + 1 <= p.getNumItems()) {
							p.connectChild(j, p.disconnectChild(j + 1));
						}
					}
					p.setItem(p.getNumItems() - 1, null);
					p.setNumItems(p.getNumItems() - 1);

					if (p.getNumItems() == 0) {
						if (p != root) {
							p = balanceTree(p);
						} else {
							root = sibling;
						}
					}
					return p;
				}

			}

		} else if (sibling.getNumItems() > 1) {
			int f = 0;
			if (sibling_side == "r") {
				f = 0;
			} else {
				f = sibling.getNumItems() - 1;
			}
			for (int i = 0; i <= p.getNumItems(); i++) {
				if (p.getChild(i) == sibling && sibling_side == "l") {
					currnode.setNumItems(currnode.getNumItems()+1);
					currnode.connectChild(1, currnode.disconnectChild(0));
					currnode.connectChild(0,
							sibling.disconnectChild(sibling.getNumItems()));
					currnode.setItem(0, p.getItem(i));
					p.setItem(i, sibling.getItem(f));
					sibling.setItem(sibling.getNumItems() - 1, null);
					sibling.setNumItems(sibling.getNumItems() - 1);
					return p;
				}

				if (p.getChild(i) == sibling && sibling_side == "r") {
					currnode.setNumItems(currnode.getNumItems()+1);
					currnode.setItem(0, p.getItem(i - 1));
					p.setItem(i - 1, sibling.getItem(f));

					currnode.connectChild(1, sibling.disconnectChild(f));

					for (int j = 0; j < sibling.getNumItems(); j++) {
						if (j + 1 < sibling.getNumItems()) {
							sibling.setItem(j, sibling.getItem(j + 1));
						}
						sibling.connectChild(j, sibling.disconnectChild(j + 1));
					}
					sibling.setItem(sibling.getNumItems() - 1, null);
					sibling.setNumItems(sibling.getNumItems() - 1);
					return p;
				}
			}
		}
		return null;
	}
	
	public Node getInOrderNode(Node thisNode){
		Node c = null;
        
		if (thisNode.isLeaf())
			c = thisNode;
		else
			c = getInOrderNode(thisNode.getChild(0));

		return c;
	}

    public static void main(String[] args) {
		TwoFourTree tree = new TwoFourTree();
		int n;
		Random random = new Random();
		while (true) {
			try {
				System.out.println("""
                    1. Insert n random Integers\n
                    2. Perform 2n operations with probability\n
                    3. Print In Order\n
                    4. View Tree level by level\n
                    5. Insert an element\n
                    6. Delete an element\n
                    7. find an element\n
                    8. Quit
                        """);
				char choice = getChar();
				switch (choice) {
                    case '1':
                        System.out.println("Enter the value of n");
                        n = getInt();
                        for (int a = 1; a < n+1; a++) {
                            Node present = tree.find(a);
                            if (present != null){
                            }else{
                                tree.insert(a);
                            }
                        }
                        break;
                    case '2':
                        System.out.println("Enter the value of n");
                        n = getInt();
                        long startTime, endTime;
                        int operation = 0;
                        int searchCount = 0;
                        int insertCount = 0;
                        int deleteCount = 0;
                        startTime = System.nanoTime();
                        while (operation < (2 * n)) {
                            double rand = random.nextDouble();
                            if (rand < 0.4) {
                                int x = random.nextInt(n);
                                Node present = tree.find(x);
                                if (present == null)
                                    tree.insert(x);
                            
                                operation++;
                                insertCount++;
                            }
                            rand = random.nextDouble();
                            if (rand < 0.25) {
                                operation++;
                                deleteCount++;
                            }
                            rand = random.nextDouble();
                            if (rand < 0.35) {
                                operation++;
                                searchCount++;
                            }
                        }
                        endTime = System.nanoTime() - startTime;
                        
                        System.out.println("Total No. of search operations performed :"
                                + searchCount);
                        System.out.println("Total No. of delete operations performed :"
                                + deleteCount);
                        System.out.println("Total No. of insert operations performed :"
                                + insertCount);
                        System.out.println("Total Time Taken:" + endTime + " nanoseconds");
                        break;

                    case '3':
                        System.out.println("In Order: ");
                        tree.displayTree(1);
                        break;

                    case '4':
                        System.out.println("Tree:");
                        tree.displayTree(0);
                        break;

                    case '5':
                        System.out.println("Enter value to insert: ");
                        int value = getInt();
                        Node present = tree.find(value);
                        if (present != null)
                            System.out.println("Data Already present");
                        else
                            tree.insert(value);
                        break;

                    case '6':
                        System.out.println("Enter value to delete: ");
                        value = getInt();
                        Node del = tree.find(value);
                        if (del != null) {
                                if(tree.delete(del,value) != null)
                                    System.out.println("Deleted" + value);
                                else
                                    System.err.println("Not Deleted");
                        } else {
                            System.out.println("Could not find " + value);
                        }
                        break;

                    case '7':
                        System.out.println("Enter value to find: ");
                        value = getInt();
                        Node found = tree.find(value);
                        if (found != null)
                            System.out.println("Found " + value);
                        else
                            System.out.println("Could not find " + value);
                        break;

                    case '8':
                        System.exit(0);
                        
                    default:
                        System.out.println("Invalid entry\n");
				}
			} catch (Exception e) {
				System.err.println("Please enter valid input");
			}
		}

	}
	
	private static String getString() throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return s;
	}

	private static char getChar() throws IOException {
		String s = getString();
		return s.charAt(0);
	}

	private static int getInt() throws IOException {
		String s = getString();
		return Integer.parseInt(s);
	}
}