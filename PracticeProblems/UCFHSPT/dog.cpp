#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int numParks;
    cin >> numParks;
    
    for(int park = 0; park < numParks; park++)
    {
        int numFlowers, leashLength;
        cin >> numFlowers >> leashLength;

        int count = 0;
        double distance;

        int x, y;
        cin >> x >> y;

        int flowerX, flowerY;
        for(int i = 0; i < numFlowers; i++)
        {
            cin >> flowerX >> flowerY;
            distance = sqrt((flowerX - x) * (flowerX - x) + (flowerY - y) * (flowerY - y));
            if(distance <= leashLength) count++;
        }

        cout << count << "\n";
    }

    return 0;
}