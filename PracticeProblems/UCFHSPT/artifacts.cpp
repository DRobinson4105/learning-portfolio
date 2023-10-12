#include <bits/stdc++.h>

using namespace std;

//artificat struct
typedef struct {
    double x;
    double y;
    double r;
    int valid;
} artifact;

//an array list to hold all the artifacts
typedef struct {
    int size;
    int capacity;
    artifact * array;
} arraylist;

//Function Prototypes
arraylist * initialize(int cap);
//inside function
int inside(arraylist * artifacts, int * indexes);
//merge function
void mergeArtifacts(arraylist * artifacts, int * indexes, int size);

int main()
{
    int numExpeditions;
    cin >> numExpeditions;
    arraylist * artifacts;
    int * indexes;

    for(int exp = 0; exp < numExpeditions; exp++)
    {
        int numArtifacts;
        cin >> numArtifacts;
        artifacts = initialize(numArtifacts);
        indexes = (int *) malloc(sizeof(int) * numArtifacts);
        int size;

        for(int art = 0; art < numArtifacts; art++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            size = 0;
            
            artifacts->array[artifacts->size].x = x;
            artifacts->array[artifacts->size].y = y;
            artifacts->array[artifacts->size].r = r;
            artifacts->array[artifacts->size].valid = 1;
            artifacts->size++;
            
            int size = inside(artifacts, indexes);
            
            while(size != 0)
            {
                mergeArtifacts(artifacts, indexes, size);
                size = inside(artifacts, indexes);
            }
        }
        int count = 0;
        for(int i = 0; i < numArtifacts; i++)
            if(artifacts->array[i].valid == 1) count++;

        cout << count << endl;
    }

    delete(artifacts->array);
    delete(artifacts);
    delete(indexes);
    
    return 0;   
}

arraylist * initialize(int cap)
{
    arraylist * artifacts = (arraylist *) malloc(sizeof(arraylist));
    artifacts->array = (artifact *) malloc(sizeof(artifact) * cap);
    artifacts->capacity = cap;
    artifacts->size = 0;

    return artifacts;
}

int inside(arraylist * artifacts, int * indexes)
{
    //loops through the arraylist of artifacts
    //for each artifact check if any other ones
    //are in its field space
    //merge if they are

    int count = 0;

    for(int i = 0; i < artifacts->size - 1; i++)
    {
        //Current Values
        if(artifacts->array[i].valid == 0) continue;
        
        artifact curr = artifacts->array[i];
        artifact last = artifacts->array[artifacts->size-1];
        // comp artifacts[i] to artifacts[size - 1]
        long double distance = pow(curr.x - last.x,2) + pow(curr.y - last.y,2);
        
        // if they interact:
        if(distance <= pow(10,-10) || distance <= pow(curr.r + last.r,2))
        {
            indexes[count] = i;
            count++;
        }
    }
    return count;
}

void mergeArtifacts(arraylist * artifacts, int * indexes, int size)
{
    double area = pow(artifacts->array[artifacts->size - 1].r, 2);
    double x = artifacts->array[artifacts->size - 1].x;
    double y = artifacts->array[artifacts->size - 1].y;
    
    for(int i = 0; i < size; i++)
    {
        area += pow(artifacts->array[indexes[i]].r, 2);
        x += artifacts->array[indexes[i]].x;
        y += artifacts->array[indexes[i]].y;
        artifacts->array[indexes[i]].valid = 0;
    }

    artifacts->array[artifacts->size - 1].r = sqrt(area);
    artifacts->array[artifacts->size - 1].x = x / (size + 1.0);
    artifacts->array[artifacts->size - 1].y = y / (size + 1.0);
}
