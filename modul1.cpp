#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//перший модуль
string myReverse(string str)//робимо функц≥ю реверсу 
{
    for (int i = 0; i < str.size() / 2; i++)//довжину нашого слова д≥лемо на 2
    {
        char temp = str[i];//записуЇмо до чар≥вського temp
        str[i] = str[str.size() - 1 - i];//та зм≥нюЇмо м≥сц€ми перший та останн≥й елемент 
        str[str.size() - 1 - i] = temp;
    }
    return str;
}
vector <string> sortReversed(vector<string> arr)//функц≥€ сортуванн€ вже в≥древерсованих елемент≥в
{
    for (int i = 0; i < arr.size(); i++) //беремо нашу посл≥довн≥сть
    {
        arr[i] = myReverse(arr[i]); //робимо реверс цих елемент≥в
    }

    for (int i = 0; i < arr.size(); i++)//i це л≥чильник дл€ того щоб перебирати слова
    {
        for (int j = 0; j < arr.size() - i - 1; j++) // j це л≥чильник дл€ перебору символ≥в у кожному ≥-тому слов≥
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = myReverse(arr[i]);
    }

    return arr;
}