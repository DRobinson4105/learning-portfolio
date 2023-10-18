#include <iostream>
#include <vector>
#include <iomanip>

//Implement a solution to corgi using DSU
//Disjoint Set Unions

//A DSU Utilizes 3 seperate functions
//One to create the Disjoing Set
//One to the find representative or parent
//and finally, one that merges to sets together

void makeSet(int index);
int find(int index);
void merge(int rep1, int rep2);

using namespace std;

vector<int> parents;
vector<int> sizes;

int main()
{
    //Determine the # of times the program will run
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) //One indexes the loop
    {
        //First determine the number of corkis and bonds
        int numCorgis, bonds;

        cin >> numCorgis >> bonds;

        //Make a disjoint set for each corgi
        for (int j = 0; j < numCorgis; j++)
            makeSet(j);
        
        //Start reading in the friendship bonds
        for (int j = 0; j < bonds; j++)
        {
            int corgi1, corgi2;
            cin >> corgi1 >> corgi2;

            corgi1--;
            corgi2--;

            //Merge the two corgi sets together
            merge(corgi1, corgi2);
        }

        //Now that all the friendships are merged in sets
        //print out the answer
        //the size of each set * number of corgis in that set
        //averged by numCorgis

        double count = 0.0;

        for (int j = 0; j < numCorgis; j++)
        {
            //find the size of each set 
            //find the representative of the corgi
            int rep = find(j);
            count += sizes[rep];
        }

        cout << "Pond #" << i << ": " << fixed << setprecision(3) << count/numCorgis << endl;

        //clears the vectors for next test case
        parents.clear();
        sizes.clear();
    }
}

//The DSU Functions

void makeSet(int index)
{
    parents.push_back(index);
    sizes.push_back(1); 
}

int find(int index)
{
    if (parents[index] == index) return index;
    int answer = find(parents[index]);
    parents[index] = answer;
    return answer;
}

void merge(int corgi1, int corgi2)
{
    int parent1 = find(corgi1);
    int parent2 = find(corgi2);

    //the sets are already merged
    if (parent1 == parent2) return;

    //link the smaller set to the larger one
    if (sizes[parent1] < sizes[parent2])
    {
        parents[parent1] = parent2;
        sizes[parent2] += sizes[parent1];
    }else{
        parents[parent2] = parent1;
        sizes[parent1] += sizes[parent2];
    }
}