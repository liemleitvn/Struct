#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//khai bao student structure
struct student
{
	string mssv;
	string tensv;
	char sex;
	float diemkt1;
	float diemkt2;
	float diemcc;
	float diemgk;
	float diemck;
	float tongdiem;
	int soItem;
};
//cac nguyen mau ham (function prototype)
int search(struct student st[], string id, int biendem);
void clean(struct student st[], int deleteitem);

student addData()
{
	student st;
	cout << "\nInput ID of Student: ";
	cin >> st.mssv;
	getc(stdin);
	cout << "\nInput fulname student: ";
	getline(cin, st.tensv);
	cout << "\nSexual ('M' is man, 'F' is woman): ";
	cin >> st.sex;
	getc(stdin);
	cout << "\nPoint of test 1: ";
	cin >> st.diemkt1;
	cout << "\nPoint of test 2: ";
	cin >> st.diemkt2;
	cout << "\nPoint test midterm: ";//Diem thi giua ky
	cin >> st.diemgk;
	cout << "\nPoint test end term: ";//Diem thi cuoi ky
	cin >> st.diemck;
	cout << "\n Point of diligent: ";//Diem chuyen can
	cin >> st.diemcc;
	st.tongdiem = st.diemkt1 + st.diemkt2 + st.diemgk + st.diemck + st.diemcc;

	return st;
}

//Xuat thong tin sinh vien
void output(struct student st)
{
	
		cout << "\nInput fulname student: " << st.tensv << "     ID: " << st.mssv;
		if (st.sex == 'M')
			cout << "\nSexual: Male";
		else
			cout << "\nSexual: Female";
		cout << "\nPoint: Test 1: " << st.diemkt1 << "   -   Test 2: " << st.diemkt2 << "   -   Midterm: " << st.diemck << "   -   Endterm: " << st.diemck << "   -   Diligent: " << st.diemcc;
		cout << "\nPoint total: " << st.tongdiem;
	
}

//Ham tim kiem sinh vien bang id
int search(struct student st[], string id, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (st[i].mssv == id)
			return i;
	}
	return -1;
}

//ham de xoa sach ban ghi da bi xoa
//void clean(struct student st, int index)
//{
//	st.mssv = "";
//	st.tensv = "";
//	st.sex = NULL;
//	st.diemkt1 = 0;
//	st.diemkt2 = 0;
//	st.diemcc = 0;
//	st.diemgk = 0;
//	st.diemck = 0;
//	st.tongdiem = 0;
//}

void deletedata(student st[], int count)
{
	int index=-3;
	string id;
	if (count > 0)
	{
	label:
		cout << "\nInput ID of Student: ";
		cin >> id;
		index = search(st, id, count);
		if (index == -1)
		{
			cout << "\ID does not exist!";//ban ghi k ton tai
			goto label;
		}
		else
		{
			//Xoa ban ghi cuoi
			if (index == (count - 1))
			{
				st[index].mssv = "";
				st[index].tensv = "";
				st[index].sex = NULL;
				st[index].diemkt1 = 0;
				st[index].diemkt2 = 0;
				st[index].diemcc = 0;
				st[index].diemgk = 0;
				st[index].diemck = 0;
				st[index].tongdiem = 0;
				count--;
				cout << "\nData were deleted\n";
			}
			else
			{
				//xoa ban ghi o vi tri bat ky
				for (int i = index; i < count - 1; i++)
				{
					st[i] = st[i + 1];
				}
					st[count - 1].mssv = "";
					st[count - 1].tensv = "";
					st[count - 1].sex = NULL;
					st[count - 1].diemkt1 = 0;
					st[count - 1].diemkt2 = 0;
					st[count - 1].diemcc = 0;
					st[count - 1].diemgk = 0;
					st[count - 1].diemck = 0;
					st[count - 1].tongdiem = 0;
					cout << "\nData were deleted\n";
					count--;
			}
		}

	}
	else
		cout << "Ban chua nhap ban ghi nao";
}

//ham de quan sat tat ca ban ghi
void viewall(struct student st[], int count)
{
	int i = 0;
	cout << left << setw(5) << "ID" << setw(20) << "TEN" << setw(10) << "GIOI TINH"
		<< setw(5) << "DKT1"
		<< setw(5) << "DKT2" << setw(5) << "DCC" << setw(5) << "DGK" << setw(5) << "DCK"
		<< setw(5) << "TONG" << "\n";
	cout << "==============================================\n";
	while (i <= count)
	{
		if (st[i].mssv != "")
		{
			cout << left << setw(5) << st[i].mssv << setw(20) << st[i].tensv << setw(10)
				<< st[i].sex;
			cout << setw(5) << st[i].diemkt1 << setw(5) << st[i].diemkt2 << setw(5) << st[i].diemcc
				<< setw(5) << st[i].diemgk << setw(5) << st[i].diemck << setw(5)
				<< st[i].tongdiem;

			cout << "\n";
		}
		i = i + 1;

	}
}

//ham cap nhat thong tin cua sinh vien
student updateData(student st)
{
	int index;
	cout << "\n==============================================";
	cout << "\n1. Update Name";
	cout << "\n2. Update sexual";
	cout << "\n3. Update point test 1";
	cout << "\n4. Update point test 2";
	cout << "\n5. Update point test midterm";
	cout << "\n6. Update point test endterm";
	cout << "\n7. Update point diligent";
	cout << "\n==============================================\n";
	cout << "Choose of acction: ";
	cin >> index;
	switch (index)
	{
		case 1:
		{
				  getc(stdin);
				  cout << "\nUpdate fulname student: ";
				  getline(cin, st.tensv);
				  break;
		}
		case 2:
		{
				  cout << "\nSexual ('M' is man, 'F' is woman): ";
				  cin >> st.sex;
				  break;
		}
		case 3:
		{
				  cout << "\nPoint of test 1: ";
				  cin >> st.diemkt1;
				  break;
		}
		case 4:
		{
				  cout << "\nPoint of test 2: ";
				  cin >> st.diemkt2;
				  break;
		}
		case 5:
		{
				  cout << "\nPoint test midterm: ";
				  cin >> st.diemgk;
				  break;
		}
		case 6: 
		{
				  cout << "\nPoint test end term: ";
				  cin >> st.diemck;
				  break;
		}
		case 7:
		{
				  cout << "\n Point of diligent: ";//Diem chuyen can
				  cin >> st.diemcc;
		}

		default:
			break;
	}
	return st;
}

//ham de hien thi menu tuy chon
void displaymenu(){
	cout << "==========================================" << "\n";
	cout << "                  MENU " << "\n";
	cout << "==========================================" << "\n";
	cout << " 1. Them ban ghi sinh vien" << "\n";
	cout << " 2. Tim sinh vien boi ID" << "\n";
	cout << " 3. Xoa ban ghi sinh vien" << "\n";
	cout << " 4. Cap nhat ban ghi sinh vien" << "\n";
	cout << " 5. Quan sat tat ca ban ghi sinh vien" << "\n";
	cout << " 6. Tinh diem trung binh cua sinh vien da chon" << "\n";
	cout << " 7. Hien thi sinh vien co tong diem cao nhat" << "\n";
	cout << " 8. Hien thi sinh vien co tong diem thap nhat" << "\n";
	cout << " 9. Sap xep cac ban ghi boi tong diem" << "\n";
}

void displaydata()
{
	int type, count = 0;
	student st[100];
	do{
		displaymenu();
		cout << "\n==========================================";
		cout << "\nPlease choose an acction: ";
		cin >> type;
		switch (type)
		{
			case 1:
			{
				label:
				student stdtemp = addData();
				if (count == 0 || search(st, stdtemp.mssv, count) == -1){
					st[count] = stdtemp;
					count++;
				}
				else{
					cout << "\nID already";
					goto label;
				}
				break;
			}
			case 2:
			{
					  string id;
					  cout << "\nInput ID of Student: ";
					  cin >> id;
					  int index = search(st, id, count);
					  if (index == -1){
						  cout << "\ID not already";
					  }
					  else{
						  output(st[index]);
					  }
					  break;
			}
			case 3:
			{
				deletedata(st, count);
				break;
			}
			case 4:
			{
				string id;
				cout << "\nInput ID of Student: ";
				cin >> id;
				int index = search(st, id, count);
				if (index != -1){
					st[index] = updateData(st[index]);
				}
				else
					cout << "\nID not already";
				break;
			}
			case 5:
				viewall(st, count);
				break;
			
			default:
				break;
		}

	} while (type > 0);
}