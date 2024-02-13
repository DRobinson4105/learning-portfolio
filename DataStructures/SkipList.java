import java.util.*;

class Node {
    public Node above, below, next, prev;
    public int data;

    public Node(int data) {
        this.data = data;
        this.above = this.below = this.next = this.prev = null;
    }
}

public class SkipList {
    private final int NEG_INF = Integer.MIN_VALUE;
    private final int POS_INF = Integer.MAX_VALUE;

    private Node head, tail;
    private int height = 0;
    
    private Random random = new Random();

    public SkipList() {
        head = new Node(NEG_INF);
        tail = new Node(POS_INF);

        head.next = tail;
        tail.prev = head;
    }

    public Node search(int data) {
        Node cur = head;

        while (cur.below != null) {
            cur = cur.below;

            while (data >= cur.next.data)
                cur = cur.next;
        }

        return cur;
    }

    public Node insert(int data) {
        Node position = search(data);
        Node q;

        int level = -1;

        if (position.data == data) return position;

        do {
            level++;

            increaseLevel(level);

            q = position;

            while (position.above == null)
                position = position.prev;

            position = position.above;

            q = insertAfterAbove(position, q, data);

            if (q.next.data == POS_INF && q.prev.data == NEG_INF) break;
        } while (random.nextBoolean());

        return q;
    }

    public Node remove(int data) {
        Node nodeToBeRemoved = search(data);

        if (nodeToBeRemoved.data != data) return null;

        removeReferencesToNode(nodeToBeRemoved);

        while (nodeToBeRemoved != null) {
            removeReferencesToNode(nodeToBeRemoved);
            
            nodeToBeRemoved = nodeToBeRemoved.above;
        }

        return nodeToBeRemoved;
    }

    private void removeReferencesToNode(Node nodeToBeRemoved) {
        Node nextNode = nodeToBeRemoved.next;
        Node prevNode = nodeToBeRemoved.prev;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    private void increaseLevel(int level) {
        if (level < height) return;
        height++;

        Node newHead = new Node(NEG_INF);
        Node newTail = new Node(POS_INF);

        newHead.next = newTail;
        newTail.prev = newHead;

        newHead.below = head;
        head.above = newHead;
        newTail.below = tail;
        tail.above = newTail;

        head = newHead;
        tail = newTail;
    }

    private Node insertAfterAbove(Node position, Node q, int data) {
        Node newNode = new Node(data);
        Node nodeBeforeNewNode = position.below.below;

        setBeforeAndAfterReferences(q, newNode);
        setAboveAndBelowReferences(position, data, newNode, nodeBeforeNewNode);

        return newNode;
    }

    private void setBeforeAndAfterReferences(Node q, Node newNode) {
        newNode.next = q.next;
        newNode.prev = q;
        q.next.prev = newNode;
        q.next = newNode;
    }

    private void setAboveAndBelowReferences(Node position, int data, Node newNode, Node nodeBeforeNewNode) {
        if (nodeBeforeNewNode != null) {
            while (nodeBeforeNewNode.next.data != data)
                nodeBeforeNewNode = nodeBeforeNewNode.next;

            newNode.below = nodeBeforeNewNode.next;
            nodeBeforeNewNode.next.above = newNode;
        }

        if (position != null && position.next.data == data)
                newNode.above = position.next;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        
        Node levelNode, curNode;
        levelNode = curNode = head.below;
        int level = height - 1;

        while (levelNode != null) {
            curNode = curNode.next;

            if (curNode.data != POS_INF) {
                sb.append("Level: " + level + "\n");
                
                while (curNode.data != POS_INF) {
                    sb.append(curNode.data);

                    if (curNode.next.data != POS_INF)
                        sb.append(" : ");
                    
                    curNode = curNode.next;
                }
            }

            curNode = levelNode = levelNode.below;
            level--;

            if (levelNode != null)
                sb.append("\n");
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        SkipList list = new SkipList();
        for (int i = 1; i <= 10; i++)
            list.insert(i);
        
        System.out.println(list);
        System.out.println("-----");

        for (int i = 1; i <= 10; i += 2)
            list.remove(i);

        System.out.println(list);
    }
}