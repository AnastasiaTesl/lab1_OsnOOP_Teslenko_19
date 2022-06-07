#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//modul2
pair<int, int> getMax(vector<string> arr)//беремо пару 2 елементів
{
    int Max = 0;//нехай максимальне = 0
    int indexMax = 0;//індекс максимального також
    for (int i = 0; i < arr.size(); i++)//далі беремо послідовність
    {
        if (arr[i].size() > Max) {//та кожний елемент перевіряємо чи більше максимального 
            Max = arr[i].size();//якщо так, то записуємо у максимальне
            indexMax = i;//та його індекс
        }
    }
    return pair<int, int>(Max, indexMax);
}
pair<int, int> getMin(vector<string> arr)//далі беремо пари для мінімального вже
{
    int Min = 1000000;//нехай це мінімум
    int indexMin = 0;//а це його індекс
    for (int i = 0; i < arr.size(); i++)//далі беремо послідовність
    {
        if (arr[i].size() < Min) {//та кожний елемент перевіряємо чи менше мінімального 
            Min = arr[i].size();//якщо так, то записуємо у мінімальне
            indexMin = i;//та його індекс
        }
    }
    return pair<int, int>(Min, indexMin);
}
bool write(string outputPath, vector<string> arr, pair<int, int> Max, pair<int, int> Min)//функція запису у файл
{
    ofstream file(outputPath);//нехай дано файл
    string line;
    if (file.is_open())//якщо його відкрито
    {
        file << "Result:";//пишемо у його початок наших результатів

        for (int i = 0; i < arr.size(); i++)//беремо послідовність
        {
            file << arr[i] << " ";//записуємо її
        }

        file << endl
            << "Max element: " << getMax(arr).first << " | Index of max: " << getMax(arr).second; //та апис макс+індекс
        file << endl
            << "Min element: " << getMin(arr).first << " | Index of min: " << getMin(arr).second;//запис мін+індекс
        file.close();//закриваємо файл
    }
    else
    {
        return false;//якщо не вийшло записати у файл, то повертаємо фолс
    }
    cout << endl << endl << "results were written in file" << endl;//якщо вийшло, то пишемо, що все записалось
    return true;//та повертаємо тру
}