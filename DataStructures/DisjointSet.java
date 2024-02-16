public class DisjointSet {
    int arr[];

    public DisjointSet(int n) {
        arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = -1;
    }

    // Returns the parent of the set containing x
    public int find(int x) {
        return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
    }

    // Merges the sets containing a and b
    public void merge(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        
        if (p1 == p2) return;

        arr[p1] += arr[p2];
        arr[p2] = p1;
    }
};