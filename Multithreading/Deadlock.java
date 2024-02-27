import java.util.List;
import java.util.ArrayList;

class TreeNode {
    TreeNode parent = null;
    private static int counter = 0;
    List<TreeNode> children = new ArrayList<>();
  
    public synchronized void addChild(TreeNode child) {
        // wait for other thread
        counter++;
        while (counter != 2) {}

        System.out.println("started adding child");
        if (!this.children.contains(child)) {
            this.children.add(child);
            child.setParentOnly(this);
        }
        System.out.println("finished adding child");
    }
    
    public synchronized void addChildOnly(TreeNode child) {
        if (!this.children.contains(child))
            this.children.add(child);
    }
    
    public synchronized void setParent(TreeNode parent) {
        // wait for other thread
        counter++;
        while (counter != 2) {}

        this.parent = parent;
        System.out.println("started setting parent");
        parent.addChildOnly(this);
        System.out.println("finished setting parent");
    }
  
    public synchronized void setParentOnly(TreeNode parent) {
        this.parent = parent;
    }
}

public class Deadlock {
    public static void main(String[] args) {
        // Both threads will lock one of the resources and wait for the other to be opened,
        // creating a deadlock
        TreeNode child = new TreeNode(), parent = new TreeNode();
        Thread thread1 = new Thread(() -> child.setParent(parent));
        Thread thread2 = new Thread(() -> parent.addChild(child));
        thread1.setDaemon(true); thread2.setDaemon(true);
        
        thread1.start(); thread2.start();

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}