#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//������ ������
string myReverse(string str)//������ ������� ������� 
{
    for (int i = 0; i < str.size() / 2; i++)//������� ������ ����� ����� �� 2
    {
        char temp = str[i];//�������� �� ���������� temp
        str[i] = str[str.size() - 1 - i];//�� ������� ������ ������ �� ������� ������� 
        str[str.size() - 1 - i] = temp;
    }
    return str;
}
vector <string> sortReversed(vector<string> arr)//������� ���������� ��� �������������� ��������
{
    for (int i = 0; i < arr.size(); i++) //������ ���� �����������
    {
        arr[i] = myReverse(arr[i]); //������ ������ ��� ��������
    }

    for (int i = 0; i < arr.size(); i++)//i �� �������� ��� ���� ��� ���������� �����
    {
        for (int j = 0; j < arr.size() - i - 1; j++) // j �� �������� ��� �������� ������� � ������� �-���� ����
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