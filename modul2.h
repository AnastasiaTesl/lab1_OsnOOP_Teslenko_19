#pragma once
using namespace std;
#include <vector>
#include <string>

pair<int, int> getMin(vector<string> arr);
pair<int, int> getMax(vector<string> arr);
bool write(string outputPath, vector<string> arr, pair<int, int> Max, pair<int, int> Min);
