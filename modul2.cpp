#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//modul2
pair<int, int> getMax(vector<string> arr)//������ ���� 2 ��������
{
    int Max = 0;//����� ����������� = 0
    int indexMax = 0;//������ ������������� �����
    for (int i = 0; i < arr.size(); i++)//��� ������ �����������
    {
        if (arr[i].size() > Max) {//�� ������ ������� ���������� �� ����� ������������� 
            Max = arr[i].size();//���� ���, �� �������� � �����������
            indexMax = i;//�� ���� ������
        }
    }
    return pair<int, int>(Max, indexMax);
}
pair<int, int> getMin(vector<string> arr)//��� ������ ���� ��� ���������� ���
{
    int Min = 1000000;//����� �� �����
    int indexMin = 0;//� �� ���� ������
    for (int i = 0; i < arr.size(); i++)//��� ������ �����������
    {
        if (arr[i].size() < Min) {//�� ������ ������� ���������� �� ����� ���������� 
            Min = arr[i].size();//���� ���, �� �������� � ��������
            indexMin = i;//�� ���� ������
        }
    }
    return pair<int, int>(Min, indexMin);
}
bool write(string outputPath, vector<string> arr, pair<int, int> Max, pair<int, int> Min)//������� ������ � ����
{
    ofstream file(outputPath);//����� ���� ����
    string line;
    if (file.is_open())//���� ���� �������
    {
        file << "Result:";//������ � ���� ������� ����� ����������

        for (int i = 0; i < arr.size(); i++)//������ �����������
        {
            file << arr[i] << " ";//�������� ��
        }

        file << endl
            << "Max element: " << getMax(arr).first << " | Index of max: " << getMax(arr).second; //�� ���� ����+������
        file << endl
            << "Min element: " << getMin(arr).first << " | Index of min: " << getMin(arr).second;//����� ��+������
        file.close();//��������� ����
    }
    else
    {
        return false;//���� �� ������ �������� � ����, �� ��������� ����
    }
    cout << endl << endl << "results were written in file" << endl;//���� ������, �� ������, �� ��� ����������
    return true;//�� ��������� ���
}