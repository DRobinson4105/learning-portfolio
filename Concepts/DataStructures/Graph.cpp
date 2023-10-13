class Graph {
    int** edges;
    int n;

    public:
        Graph(int n) {
            this->n = n;
            this->edges = new int*[n];
            for (int i = 0; i < n; i++)
                this->edges[i] = new int[n];
        }

        // Adds an edge between a and b with given weight
        void addEdge(int a, int b, int weight) {
            this->edges[a][b] = weight;
            this->edges[b][a] = weight;
        }

        // Returns the weight of the edge between a and b
        int getWeight(int a, int b) {
            return this->edges[a][b];
        }

        // Returns the number of vertices in the graph
        int getNumVertices() {
            return this->n;
        }
};