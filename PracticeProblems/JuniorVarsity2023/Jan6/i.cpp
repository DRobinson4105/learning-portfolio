#include <bits/stdc++.h>

using namespace std;

bool isAllPresent(set<string> toppings, vector<string> conditions) {
    return all_of(conditions.begin(), conditions.end(), [&toppings](const string& cond) {
        return toppings.find(cond) != toppings.end();
    });
}

bool isAnyPresent(set<string> toppings, vector<string> conditions) {
    return any_of(conditions.begin(), conditions.end(), [&toppings](const string& cond) {
        return toppings.find(cond) != toppings.end();
    });
}

int processPreferencesHelper(
    vector<pair<vector<string>, string>> andImplications,
    vector<pair<vector<string>, string>> orImplications,
    set<string> toppings
) {
    for (auto impl : andImplications) {
        if (isAllPresent(toppings, impl.first) && !toppings.count(impl.second)) {
            toppings.insert(impl.second);
            return processPreferencesHelper(andImplications, orImplications, toppings);
        }
    }

    for (auto impl : orImplications) {
        if (isAnyPresent(toppings, impl.first) && !toppings.count(impl.second)) {
            toppings.insert(impl.second);
            return processPreferencesHelper(andImplications, orImplications, toppings);
        }
    }

    return toppings.size();
}

int processPreferences(int numPreferences) {
    set<string> toppings;
    vector<pair<vector<string>, string>> andImplications, orImplications;

    cin.ignore();
    for (int i = 0; i < numPreferences; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());

        if (words.size() == 1)
            toppings.insert(words[0]);
        else {
            vector<string> conditions;
            string result;
            bool isResult = false;
            bool isOrCondition = find(words.begin(), words.end(), "or") != words.end();

            for (const auto& word : words) {
                if (word == "then") {
                    isResult = true;
                } else if (!isResult && word != "if" && word != "and" && word != "or") {
                    conditions.push_back(word);
                } else if (isResult) {
                    result = word;
                }
            }

            if (isOrCondition) {
                orImplications.push_back(make_pair(conditions, result));
            } else {
                andImplications.push_back(make_pair(conditions, result));
            }
        }
    }

    return processPreferencesHelper(andImplications, orImplications, toppings);
}

int main() {
    int numPreferences;
    cin >> numPreferences;

    cout << processPreferences(numPreferences) << endl;
    return 0;
}
