#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

class Leaderboard
{
private:
    // each player is represented by a string (name) and map of values (plays, clears, likes, records)
    unordered_map<string, unordered_map<string, int>> unsortedPlayers;

    void mergeSortHelper(vector<pair<string, int>> &temp, int left, int right);
    void mergeHelper(vector<pair<string, int>> &temp, int left, int mid, int right);

public:
    Leaderboard();
    vector<pair<string, int>> mergeSort(string option);
    vector<pair<string, int>> radixSort(string option);
    unordered_map<string, int> search(string name);
};
