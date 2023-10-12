#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> pair1, pair<int, string> pair2) {
    if (pair1.first == pair2.first) {
        return pair1.second.compare(pair2.second) < 0;
    }
    return pair1.first > pair2.first;
}

void merge(vector<pair<int, string> >& result, int low, int high, int mid) {
    int length1 = mid - low + 1;
    int length2 = high - mid;

    vector<pair<int, string> > arrL(length1);
    vector<pair<int, string> > arrR(length2);

    for(int i = 0; i < length1; i++)
        arrL[i] = result[i + low];

    for(int i = 0; i < length2; i++)
        arrR[i] = result[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = low;
    
    while (i < length1 && j < length2) {
        if (compare(arrL[i], arrR[j]))
            result[k++] = arrL[i++];
        else
            result[k++] = arrR[j++];
    }
    
    while (i < length1)
        result[k++] = arrL[i++];
 
    while (j < length2)
        result[k++] = arrR[j++];

}

void mergeSort(vector<pair<int, string> >& result, int low, int high) {
    if (low >= high) return;

    int mid  = (low + high) / 2;

    mergeSort(result, low, mid);
    mergeSort(result, mid + 1, high);

    merge(result, low, high, mid);
}

void lowercase(string& s) {
    int size = s.size();

    for (int i = 0; i < size; i++) {
        s[i] = tolower(s[i]);
    }
}

string getHashtag(string word, int size) {
    lowercase(word);

    for (int i = 0; i < size; i++) {
        if (!isalpha(word[i]))
            return word.substr(0, i);
    }

    return word;
}

int main() {
    int numTweets;
    vector<string> hashtags;
    map<string, int> frequencies;
    cin >> numTweets;
    string garbage;

    for (int t = 0; t < numTweets; t++) {
        string tweet;
        getline(cin, garbage);
        getline(cin, tweet);

        istringstream iss(tweet);

        do {
            string word;
            iss >> word;

            if (word[0] == '#') {
                int size = word.size();
                string hashtag = getHashtag(word.substr(1, size - 1), size);

                if (frequencies.find(hashtag) != frequencies.end()) {
                    frequencies[hashtag]++;
                } else {
                    frequencies[hashtag] = 1;
                    hashtags.push_back(hashtag);
                }
            }
        } while(iss);
    }

    vector<pair<int, string> > result;
    for (string hashtag : hashtags) {
        result.push_back(make_pair(frequencies[hashtag], hashtag));
    }

    mergeSort(result, 0, result.size());

    for (auto res : result) {
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}