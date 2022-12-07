#include "Leaderboard.h"
/*******************************************
References:
Merge sort code - Sorting lecture slides
*******************************************/

// import data into map
Leaderboard::Leaderboard()
{
    string line;
    cout << "Importing data... (0/4)" << endl;

    // read in plays for all players
    ifstream file1("../data/plays.csv");
    getline(file1, line);
    while (getline(file1, line, '\t'))
    {
        getline(file1, line, '\t');
        getline(file1, line);
        unsortedPlayers[line]["plays"]++;
    }
    cout << "Importing data... (1/4)" << endl;

    // read in clears for all players
    ifstream file2("../data/clears.csv");
    getline(file2, line);
    while (getline(file2, line, '\t'))
    {
        getline(file2, line, '\t');
        getline(file2, line);
        unsortedPlayers[line]["clears"]++;
    }
    cout << "Importing data... (2/4)" << endl;

    // read in likes for all players
    ifstream file3("../data/likes.csv");
    getline(file3, line);
    while (getline(file3, line, '\t'))
    {
        getline(file3, line, '\t');
        getline(file3, line);
        unsortedPlayers[line]["likes"]++;
    }
    cout << "Importing data... (3/4)" << endl;

    // read in records for all players
    ifstream file4("../data/records.csv");
    getline(file4, line);
    while (getline(file4, line, '\t'))
    {
        getline(file4, line, '\t');
        getline(file4, line, '\t');
        unsortedPlayers[line]["records"]++;
        getline(file4, line);
    }
    cout << "Importing data... (4/4)" << endl;
    cout << "Data imported successfully!" << endl
         << endl;
}

// given choice of attribute, return sorted vector of name/attribute pairs
vector<pair<string, int>> Leaderboard::mergeSort(string option)
{
    vector<pair<string, int>> players;
    auto start = chrono::high_resolution_clock::now();

    for (auto &it : unsortedPlayers)
    {
        players.push_back(make_pair(it.first, it.second[option]));
    }

    int left = 0;
    int right = players.size() - 1;
    mergeSortHelper(players, left, right);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Merge Sort: completed in " << duration.count() << " ms" << endl;

    return players;
}

// The idea for this function was based on the Lecture Slides for Sorting
void Leaderboard::mergeSortHelper(vector<pair<string, int>> &temp, int left, int right)
{
    if (left < right)
    {
        // Determine where the list of elements will begin to be divided into subarrays
        int mid = left + (right - left) / 2;
        mergeSortHelper(temp, left, mid);
        mergeSortHelper(temp, mid + 1, right);

        mergeHelper(temp, left, mid, right);
    }
}

// The idea for this function was based on the Lecture Slides for Sorting
void Leaderboard::mergeHelper(vector<pair<string, int>> &temp, int left, int mid, int right)
{
    // Create subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<string, int>> leftArray;
    vector<pair<string, int>> rightArray;

    for (int i = 0; i < n1; i++)
    {
        leftArray.push_back(temp.at(left + i));
    }

    for (int j = 0; j < n2; j++)
    {
        rightArray.push_back(temp.at(mid + 1 + j));
    }

    // Merge arrays
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray.at(i).second >= rightArray.at(j).second)
        {
            temp.at(k) = leftArray.at(i);
            i++;
        }
        else
        {
            temp.at(k) = rightArray.at(j);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        temp.at(k) = leftArray.at(i);
        i++;
        k++;
    }

    while (j < n2)
    {
        temp.at(k) = rightArray.at(j);
        j++;
        k++;
    }
}

// given choice of attribute, return sorted vector of name/attribute pairs
// The idea for this function was based on a conceptual discussion with Benny Cortese (TA)
vector<pair<string, int>> Leaderboard::radixSort(string option)
{
    vector<pair<string, int>> players;
    auto start = chrono::high_resolution_clock::now();

    for (auto &it : unsortedPlayers)
    {
        players.push_back(make_pair(it.first, it.second[option]));
    }

    // Find maximum element to determine how many iterations over the place values of each element is needed
    int max = findMax(players, players.size());

    for (int placeValue = 1; max / placeValue > 0; placeValue *= 10)
        countSort(players, players.size(), placeValue);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Radix Sort: completed in " << duration.count() << " ms" << endl;

    reverse(players.begin(), players.end());
    return players;
}

int Leaderboard::findMax(vector<pair<string, int>> &temp, int vectorSize)
{
    int maxTemp = temp.at(0).second;

    for (auto& i : temp)
    {
        if (i.second > maxTemp)
        {
            maxTemp = i.second;
        }
    }
    return maxTemp;
}

// The idea for this function was based on a conceptual discussion with Benny Cortese (TA)
void Leaderboard::countSort(vector<pair<string, int>> &temp, int vectorSize, int placeValue)
{
    vector<pair<string, int>> output (vectorSize);

    // 10 bit counter because we will be working decimal system. Each place value will either have a digit between 0-9
    int valueCount[10] = { 0 };

    // Divide value by place value to iterate through all the place values that make up the number
    for (auto& it : temp)
    {
        int index = it.second / placeValue;
        valueCount[index % 10]++;
    }

    // Predetermine index position in output
    for (int i = 1; i < 10; i++)
    {
        valueCount[i] += valueCount[i - 1];
    }

    for (int i = vectorSize - 1; i >= 0; i--)
    {
        int index = temp.at(i).second / placeValue;
        output.at(valueCount[index % 10] - 1) = temp.at(i);
        valueCount[(temp.at(i).second / placeValue) % 10]--;
    }

    for (int i = 0; i < vectorSize; i++)
    {
        temp.at(i) = output.at(i);
    }
}

// search using unordered map, return map representing player
unordered_map<string, int> Leaderboard::search(string name)
{
    if (unsortedPlayers.count(name) != 0)
    {
        return unsortedPlayers[name];
    }
    unordered_map<string, int> emptyMap;
    return emptyMap;
}
