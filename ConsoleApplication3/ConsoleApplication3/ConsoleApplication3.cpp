// ConsoleApplication3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	size_t pi[5];
	prefix_find("qwecvfbgnwqevcqwertqwesdgvfsgyjqwr", "qwert", pi);
	return 0;
}
// ������ ������� ���������, ������� ������� ������ ������ ���������� �������
int f(size_t i)
{
	cout << i;
	printf("%d\n", i);
	return 1;
}
// str ������ ������.
// obr �������, ������� ����.
// pi ������ ���� ��������� ��� ������� (�������  ������� �������� � �������).
// int f(size_t i) ����� ������� ������, ���������� ��� �������, 
// �� ���������� ������ ������ ���������� � str �������.
// ������� ���������� 0, ���� ���� ���������� ����� � 1, ���� ���� ����������.
void prefix_find(char *str, char *obr, size_t *pi)//, int(*f)(size_t))
{
	pi[0] = 0;     // � i-� �������� (��� ������ i-1) ���������� ��������� 
				   // �������� � ������ ������� � � ����� ��������� ����� i. 
				   // p[0]=0 ������, p[1]=1, ���� ���������� � ���� ���������� 
	size_t l;    // ����� ����� �������
				 // ��������� ������ ���� ��������� ��� �������
	for (l = 1; obr[l]; ++l)
	{
		size_t j = pi[l - 1];
		while ((j > 0) && (obr[l] != obr[j])) // �� �����
			j = pi[j - 1];	         // ����� ����� ������������ �������� (������� � ����������� ���������)
		if (obr[l] == obr[j])      // ����� 
			++j;
		pi[l] = j;
	}
	size_t j = 0; // ���������� ��������� ��������, ��� �� ������ ������������� 
				  // ������� � �������. � ������ ������������ ������ ����� ����� ������ i
	for (size_t i = 0; str[i]; ++i)
	{
		while ((j > 0) && (str[i] != obr[j]))
			// ��������� ������ ������ �� ������ � �������� � �������. �������� �������, 
			// ������ ����� �����, ��� ������ j �������� ������� ������� � ��������� ������ 
			// � ���� �������� j+1� ������ ������� (��� ������ j) � i+1� �������� ������.
			j = pi[j - 1];    // ���� j=0, �� �������� ������ ������� � ���� ������� ��������

		if (str[i] == obr[j]) // ���� ���������� ���������� ������� 
			++j;              // ����������� ����� ���������� ��������� �� 1
		if (j == l)
			if (!f(i - l + 1)) // ������� ������, ������� ������� ���������
				return;  // � ������ �� ���������, ���� ��� ������ 0. 
	}
}

