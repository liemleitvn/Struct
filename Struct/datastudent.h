#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

struct sinhvien
{
	string name, code, add, born;//ten, mssv, dia chi
	char sexual;//gioi tinh
	float pmath, pphysics, pchemistry;//toan, ly, hoa

};

void input(sinhvien &sv)
{
	fflush(stdin);
	cout << "\nName student: ";
	getline(cin,sv.name);
	cout << "\nDay of birth (YYYY/MM/DD): ";
	getline(cin, sv.born);
	cout << "\nCode: ";
	getline(cin, sv.code);
	cout << "\nSexual ('M' is man, 'W' is woman):  ";
	cin >> sv.sexual;
	fflush(stdin);
	cout << "\nAddress of student: ";
	getline(cin, sv.add);
	cout << "\nPoint math: ";
	cin >> sv.pmath;
	cout << "\nPoint physics: ";
	cin >> sv.pphysics;
	cout << "\nPoint chemistry: ";
	cin >> sv.pchemistry;
}

void output(sinhvien sv)
{
	cout << "\n\nName student: " << sv.name;
	cout << "\nDay of birth: " << sv.born;
	cout << "\nCode: " << sv.code;
	if (sv.sexual == 'M')
		cout << "\nSexual: Man";
	else
		cout << "\nSexual: Woman";
	cout << "\nAddress of student: "<<sv.add;
	cout << "\nPoint math - physics - chemistry: "<<sv.pmath <<"   "<< sv.pphysics<<"   "<< sv.pchemistry;
	cout << "\n-----------------------------------";
	
}

//Find student has maximun average point (sinh vien co diem trung binh cao nhat)
sinhvien maxPoint(sinhvien* datasinhvien, int n)
{
	sinhvien maxpointstudent = datasinhvien[0];
	float pointmax = (datasinhvien[0].pmath + datasinhvien[0].pphysics + datasinhvien[0].pchemistry) / 3;
	for (int i = 1; i < n; i++)
	{
		float pointstudent = (datasinhvien[i].pmath + datasinhvien[i].pphysics + datasinhvien[i].pchemistry) / 3;
		if (pointmax < pointstudent)
		{
			pointmax = pointstudent;
			maxpointstudent = datasinhvien[i];
		}
	}
	return maxpointstudent;
}
//Viet hoa chu cai dau dong
void toupper(string &sv)
{
	int len = sv.length();
	if (sv[0] >= 'a' && sv[0] <= 'z')
		sv[0] = sv[0] - 32;
	for (int i = 1; i <= len; i++)
	{
		if (sv[i-1] == ' ')
		{
			if (sv[i] >= 'a' && sv[i] <= 'z')
				sv[i] = sv[i] - 32;
		}
	}
}

sinhvien *processName(sinhvien* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		toupper(data[i].name);
		toupper(data[i].add);
	}	
	return data;
}

//Sap xep sinh vien theo thu tu tang dan diem trung binh 
sinhvien* sortPoint(sinhvien *data, int n)
{
	float dtb[100];
	for (int i = 0; i < n; i++)
		dtb[i] = (data[i].pmath + data[i].pphysics + data[i].pchemistry) / 3;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (dtb[i] < dtb[j])
			{
				sinhvien temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	return data;
}

void dataStudent()
{
	int n;
	int type = 0;
	sinhvien data[100];

	do
	{
		cout << "\n\nInput total students: ";
		cin >> n;
		if (n < 0)
			cout << "\n\nError! Please input again";
	} 
	while (n < 0);
	do
	{
		cout << "\n===================================";
		cout << "\n1. Input data student";
		cout << "\n2. Output data student";
		cout << "\n3. Find student has maximun average point";
		cout << "\n4. Sort student follow average point";//Sap xep sinh vien theo diem trung binh giam dan
		cout << "\n5. Viet hoa tu dau tien cua ten";
		cout << "\n===================================";
		cout << "\n\nPlease choose an acction: ";
		cin >> type;
		switch (type)
		{
		case 1:
		{
				  for (int i = 0; i < n; i++)
				  {
					  cout << "\n-----------------------------------";
					  cout << "\nInput information student " << i + 1;
					  input(data[i]);
				  }
				break;
		}
		case 2:
			{
				  for (int i = 0; i < n; i++)
				  {
					  cout << "\nInformation student " << i + 1;
					  cout << "\n-----------------------------------";
					  output(data[i]);
				  }
				  break;
			}
		case 3:
		{
				  sinhvien sv = maxPoint(data, n);
				  output(sv);
				  break;
		}
		case 4:
		{
				  sinhvien *temp = sortPoint(data, n);
				  for (int i = 0; i < n; i++)
					  output(temp[i]);
				  break;
		}
		case 5:
		{
				  processName(data, n);
				  for (int i = 0; i < n; i++)
					  output(data[i]);
				  break;
		}
		default:
			break;
		}
		
	} 
	while (type > 0);
}