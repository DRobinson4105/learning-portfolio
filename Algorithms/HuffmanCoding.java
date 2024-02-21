import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Map.Entry;

public class HuffmanCoding {
    static class Node implements Comparable<Node> {
        char character;
        int value, height;
        Node left, right;

        Node(char character, int value) {
            this.character = character;
            this.value = value;
            left = right = null;
            height = 1;
        }

        Node(Node left, Node right) {
            this.value = left.value + right.value;
            this.left = left;
            this.right = right;
            height = Math.max(left.height, right.height) + 1;
        }

        @Override
        public int compareTo(Node other) {
            return (value == other.value) ? (height - other.height) : (value - other.value);
        }
    }

    public static Node createTree(Map<Character, Integer> freq) {
        PriorityQueue<Node> pq = new PriorityQueue<>();

        for (Entry<Character, Integer> pair : freq.entrySet())
            pq.add(new Node(pair.getKey(), pair.getValue()));

        while (pq.size() > 1) {
            Node first = pq.poll(), second = pq.poll();
            // System.out.println(first.character + " " + second.character);
            // System.out.println(first.value + " " + second.value);
            pq.add(new Node(first, second));
        }

        return pq.peek();
    }

    public static Map<Character, Integer> getFrequencies(String message) {
        Map<Character, Integer> freq = new HashMap<>();
        message.chars().forEach(c -> freq.put((char)c, freq.getOrDefault((char)c, 0) + 1));
        // System.out.println(freq.get('a'));
        return freq;
    }

    public static void printHuffmanCodes(String message) {
        printHuffmanCodes(createTree(getFrequencies(message)));
    }

    public static void printHuffmanCodes(Node root) {
        printHuffmanCodesHelper(root, "");
    }

    private static void printHuffmanCodesHelper(Node root, String curr) {
        if (root.left == null && root.right == null) {
            System.out.println(root.character + ": " + curr);
            return;
        }

        printHuffmanCodesHelper(root.left, curr + "0");
        printHuffmanCodesHelper(root.right, curr + "1");
    }

    public static void main(String[] args) {
        printHuffmanCodes("""
            aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeee
            eeeeefffffffffffffffffffffffffffffffffffffffffffff
        """.replaceAll("\\s+", ""));
        
    }
}
