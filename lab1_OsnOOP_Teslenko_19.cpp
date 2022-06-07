//I.Вхідні дані - Параметри командного рядка : 1.Послідовність слів тексту.Якщо  користувач  не  задав  параметри  командного  рядка,
//програма  входить  в діалогз користувачем і питає про ім’я файлу, з якого треба прочитати вхідні дані.
//II.Перша функція другого модуля упорядковує на дану їй через список параметрів послідовність за критерієм :
//0.За неспаданням суми цифр дробної частини числа(або суми рядка матриці, або реверсованогослова тексту).
//Критерій –це функція, передана такожякпараметрдляфункціїупорядкування.
//III.Друга функція другого модуля має для заданої послідовності(або матриці) обчислити і повернути :
//2.Чотири результати : максимум, мінімум, та їх номери(індекси) у заданій послідовності(матриці).
//IV.Програма  мусить  видати  результати у текстовий  файл, ім’я  якого вона отримує :
//0.З командного рядка.

#include <iostream>
#include <Windows.h>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include "modul1.h"
#include "modul2.h"

using namespace std;
bool getFileContent(string fileName, vector < string >& vecOfStrs) {
    // відкриття нашого файлу
    ifstream in(fileName.c_str());
    // перевіряємо чи дійсний цей файл
    if (!in) {
        cerr << "Cannot open the File : " << fileName << endl; //якщо не можна відкрити його
        return false;
    }
    string str;
    // читаємо рядки з файлу, поки не дійдемо до кінця
    while (getline(in, str)) {
        // лінія містить рядок з довжиною >0, зберігаємо у вектор
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //закриваємо файл
    in.close();
    return true;
}


int main(int argc, char** argv)
{
    // перший модуль
    string outFile = "";
    cout << "You have entered " << argc  << " arguments:" << "\n"; // виводимо наші значення

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    if (argc < 2) {
        cout << " \nno output parameter\n "; //якщо менше 2 слів, то виводимо що нічого не дано
        return 0;
    }
    else {
        outFile = argv[1]; //позначаємо що назва файлу - це 1 елемент
        cout << "outFile: " << outFile << endl; //виводимо назву 
    }

    vector < string > arr;
    for (int i = 2; i < argc; i++) {
        arr.push_back(argv[i]);
    }

    if (argc < 3) {
        string file1;
        cout << "Enter filename: " << endl;
        cin >> file1;
        // вміст файлу у вектор
        bool result = getFileContent(file1, arr);
        if (result) {
            // векторний зміст друкуємо
            for (string& line : arr)
                cout << line << endl;
        }
    }

//    в нас у прикладі така послідовність: {az by cxcx d eq}; 
// буде така реверсована послідовність: [za yb xcxc d qe] | а вже відсортована:  [d, eq, cxcx, by, az]
    HANDLE color1 = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color1, FOREGROUND_INTENSITY | FOREGROUND_BLUE); //робимо колір синім 
    arr = sortReversed(arr); //виводимо відсортоване вже
    cout << "Sorting: " << ""; 
    for (int i = 0; i < arr.size(); i++)  //робимо цикл для того щоб вивести відсортовану послідовність
    {
        if (i != arr.size() - 1) cout <<   arr[i] << ", ";//якщо не останій елемент, то пишемо  його і кому
        else cout << arr[i] << ".";//після останнього крапку ставимо
    }
    SetConsoleTextAttribute(color1, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);//прибираємо колір

    // другий модуль
    HANDLE color2 = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color2, FOREGROUND_RED | FOREGROUND_GREEN);//робимо жовтий колір
    cout << endl;
    cout << "Max element: " << getMax(arr).first << " | Index of max: " << getMax(arr).second << endl; // максимальний елемент та його індекс
    cout << "Min element: " << getMin(arr).first << " | Index of min: " << getMin(arr).second;//мінімальний елемент та його індекс
    SetConsoleTextAttribute(color2, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);//прибираємо колір

    if (!write(outFile, arr, getMax(arr), getMin(arr)))//якщо всі ці відповіді не вдалось занести до файлу
    {
        cout << endl << endl << "results were not written in file";//то пишемо що результати не записано
        return 0;
    }

    return 0;
}