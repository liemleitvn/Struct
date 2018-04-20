#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

struct inforbook
{
	//Khai bao bien: ma sach, ten sach, tac gia, ngay nhap,gia
	string code, name, author, date;
	int price;

};

void input(inforbook b)
{
	fflush(stdin);
	cout << "\n\nCode of book: ";
	getline(cin, b.code);
	cout << "\nName of book: ";
	getline(cin, b.name);
	cout << "\nAuthor of book: ";
	getline(cin, b.author);
	cout << "\nDay input book (YYYY/MM/DD): ";
	getline(cin, b.date);
	cout << "\nPrice of book: ";
	cin>> b.price;
}

void output(inforbook b)
{
	fflush(stdin);
	cout << "\nCode of book: "<<b.code;
	cout << "\nName of book: "<<b.name;
	cout << "\nAuthor of book: "<<b.author;
	cout << "\nDay input book (YYYY/MM/DD): "<<b.date;
	cout << "\nPrice of book: "<<b.price;
}

//Tim cuon sach co gia dat nhat
inforbook maxPrice(inforbook* data, int n)
{
	inforbook maxbook = data[0];
	int maxprice = data[0].price;
	for (int i = 1; i < n; i++)
	{
		int bookprice = data[i].price;
		if (bookprice>maxprice)
		{
			maxprice = bookprice;
			maxbook = data[i];
		}
	}
	return maxbook;
}

//Ham sap xep theo gia
inforbook* sortPrice(inforbook* data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (data[i].price>data[j].price)
			{
				inforbook temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	return data;
}

//Viet hoa chu cai dau moi tu
void convert(string &sv)
{
	int len = sv.length();
	if (sv[0] >= 'a' && sv[0] <= 'z')
		sv[0] = sv[0] - 32;
	for (int i = 1; i <= len; i++)
	{
		if (sv[i - 1] == ' ')
		{
			if (sv[i] >= 'a' && sv[i] <= 'z')
				sv[i] = sv[i] - 32;
		}
	}
}

//Viet hoa chu cai dau tu cua cuon sach
inforbook* processName(inforbook* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		convert(data[i].name);
		convert(data[i].author);
	}
	return data;
}

void book()
{
	int n;
	int type = 0;
	inforbook data[1000];

	do
	{
		cout << "\n\nInput total book entry: ";//Nhap tong so sach muon nhap vao
		cin >> n;
		if (n < 0)
			cout << "\n\nError! Please input again";
	} while (n < 0);
	do
	{
		cout << "\n===================================";
		cout << "\n1. Input data book entry";
		cout << "\n2. Output data book entry";
		cout << "\n3. Find book has maximum price";
		cout << "\n4. Sort book price to raise ";//Sap xep sach theo gia tang dan
		cout << "\n5. Convert name and author from small letter to capital";//Chuyen ten va tac gia tu chu thuong sang chu hoa
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
							  cout << "\nInput information book " << i + 1;
							  input(data[i]);
						  }
						  break;
				}
			case 2:
				{
						  for (int i = 0; i < n; i++)
						  {
							  cout << "\nInformation book entry " << i + 1;
							  cout << "\n-----------------------------------";
							  output(data[i]);
						  }
						  break;
				}
			case 3:
			{
					  inforbook temp = maxPrice(data,n);
					  output(temp);
					  break;

			}
			case 4:
			{
					  inforbook* temp = sortPrice(data, n);
					  for (int i = 0; i < n; i++)
						  output(temp[i]);
					  break;
			}
			case 5:
			{
					  inforbook* temp = processName(data, n);
					  for (int i = 0; 1 < n; i++)
						  output(temp[i]);
					  break;
			}
			default:
				break;
		}

	} 
	while (type > 0);
}