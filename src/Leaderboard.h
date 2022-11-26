#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Leaderboard
{
private:
    unordered_map<string, vector<string>> unsortedPlayers;

public:
    Leaderboard();
    void mergeSort();
    void radixSort();
    void search(string name);
};
