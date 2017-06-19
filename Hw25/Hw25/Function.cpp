#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct Contact
{
	char *name = new char[255];
	char *surname = new char[255];
	char *mob = new char[255];
	char *email = new char[255];
};

Contact *Add(Contact *c, int &length);
Contact *Remove(Contact *c, int &length, int num);
int cmp(char *str1, char *str2);
void Sort(Contact *c, int &length);
Contact *Search(Contact *c, int length, int &counter2);
Contact *Change(Contact *c, int length, int count, int index);
Contact *increaseStr(Contact *c, int &length);


void Function(int &length)
{
	Contact *c = new Contact[length];
	int count1 = 0, count2 = 0, key, save_key = 0, counter = 0, menu = 0, count_menu = 0, save_count1 = 0, save_count2 = 0;
	Contact *search, *menu1;
	short s_x = 1, x1 = 8;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		short x = 1;
		system("cls");
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 108; j++)
			{
				if (i % 2 == 0 && j > 0 && j < 25 || i == 0 && j > 62 && j < 107 || i == 4 && j > 62 && j < 107 || menu == 13 && j > 25 && j < 60 && (i == 0 || i == 20))
					cout << char(205);
				else if (j == 0 && i > 0 && i < 20 || j == 25 && i > 0 && i < 20 || j == 62 && i > 0 && i < 4 || j == 107 && i > 0 && i < 4 || menu == 13 && j == 60 && i > 0 && i < 20)
					cout << char(186);
				else if (i == 0 && j == 0 || i == 0 && j == 62)
					cout << char(201);
				else if (i == 0 && j == 25 || i == 0 && j == 107 || menu == 13 && j == 60 && i == 0)
					cout << char(187);
				else if (i == 20 && j == 0 || i == 4 && j == 62)
					cout << char(200);
				else if (i == 20 && j == 25 || i == 4 && j == 107 || menu == 13 && j == 60 && i == 20)
					cout << char(188);
				else
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleCursorPosition(h, { 63, 1 });
		cout << " a - add, r - remove, f - find, c - change\n";
		SetConsoleCursorPosition(h, { 56, 2 });
		cout << " \t\tEsc - exit";
		if (menu == 13)
		{
			if (save_key == 'f')
				menu1 = search;
			else
				menu1 = c;
			SetConsoleCursorPosition(h, { 34, 7 });
			cout << "Name:\n";
			SetConsoleCursorPosition(h, { 27, 8 });
			cout << menu1[count2].name;
			SetConsoleCursorPosition(h, { 34, 9 });
			cout << "Surname:\n";
			SetConsoleCursorPosition(h, { 27, 10 });
			cout << menu1[count2].surname << endl;
			SetConsoleCursorPosition(h, { 34, 11 });
			cout << "Mobile:\n";
			SetConsoleCursorPosition(h, { 27, 12 });
			cout << menu1[count2].mob << endl;
			SetConsoleCursorPosition(h, { 34, 13 });
			cout << "Email:\n";
			SetConsoleCursorPosition(h, { 27, 14 });
			cout << menu1[count2].email << endl;
		}
		for (int i = 0 + count1; i < length; i++)
		{
			SetConsoleCursorPosition(h, { 1, x });
			if (i < 10 + count1 && save_key != 102)
			{
				cout << c[i].name << " " << c[i].surname << endl;
				x += 2;
			}
			if (i < 10 + count1 && (save_key == 'f' || save_key == 'F') && i < counter)
			{
				cout << search[i].name << " " << search[i].surname << endl;;
				x += 2;
			}
		}
		if (menu == 13)
			SetConsoleCursorPosition(h, { 27, x1 });
		else
			SetConsoleCursorPosition(h, { 1, s_x });
		if (kbhit)
			key = getch();
		Sleep(77);
		if ((key == 'a' || key == 'A') && menu != 13)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			c = Add(c, length);
		}
		if (key == 'r' && count2 < length && menu != 13)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			c = Remove(c, length, count2);
		}

		if (key == 'f' && length > 0)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			search = Search(c, length, counter);
			save_key = key;
			save_count1 = count1;
			save_count2 = count2;
			count2 = 0;
			count1 = 0;
		}
		if (key == 13 && count2 < length && length > 0)
			menu = 13;
		
		if (key == 'c'  && menu == 13)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			if (save_key == 'f')
				menu1 = Change(menu1, counter, count2, count_menu);
			else
				menu1 = Change(menu1, length, count2, count_menu);
			menu = 0;
		}
		if (key == 27)
		{
			SetConsoleCursorPosition(h, { 0, 21 });
			if (menu == 13)
				menu = 0;
			else if (save_key == 'f')
			{
				delete[]search;
				save_key = 0;
				count1 = save_count1;
				count2 = save_count2;
			}
			else
				return;
		}
		if (key == 's' &&  length > count2 + 1 && s_x < 19 && menu != 13) // scroll down
		{
			s_x += 2;
			count2++;
		}
		else if (count2 >= 9 && key == 's' && count2 + 1 < length && menu != 13)
		{
			count1++;
			count2++;
		}
		if (key == 's' && menu == 13 && x1 < 14)
		{
			x1 += 2;
			count_menu++;
		}
		if (key == 'w' && s_x > 2 && menu != 13) // scroll up
		{
			s_x -= 2;
			count2--;
		}
		else if (count2 > 0 && key == 'w' && menu != 13)
		{
			count2--;
			count1--;
		}
		if (key == 'w' && menu == 13 && x1 > 8)
		{
			x1 -= 2;
			count_menu--;
		}
	}
}

Contact *Add(Contact *c, int &length)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Contact *tempContact = new Contact[length + 1];
	for (int i = 0; i < length; i++)
		tempContact[i] = c[i];
	tempContact[length].name = new char[255];
	tempContact[length].name = new char[255];
	SetConsoleCursorPosition(h, { 78, 5 });
	cout << "Name:\n";
	SetConsoleCursorPosition(h, { 71, 6 });
	cin.getline(tempContact[length].name, 255);
	SetConsoleCursorPosition(h, { 78, 7 });
	cout << "Surname:\n";
	SetConsoleCursorPosition(h, { 71, 8 });
	cin.getline(tempContact[length].surname, 255);
	SetConsoleCursorPosition(h, { 78, 9 });
	cout << "Mobile:\n";
	SetConsoleCursorPosition(h, { 71, 10 });
	cin.getline(tempContact[length].mob, 255);
	SetConsoleCursorPosition(h, { 78, 11 });
	cout << "Email:\n";
	SetConsoleCursorPosition(h, { 71, 12 });
	cin.getline(tempContact[length].email, 255);
	length++;
	delete[] c;
	Sort(tempContact, length);
	return tempContact;
}

Contact *Remove(Contact *c, int &length, int num)
{
	int count = 0;
	Contact *tempContact = new Contact[length - 1];
	for (int i = 0; i < length; i++)
	{
		if (i != num)
		{
			tempContact[count] = c[i];
			count++;
		}
	}
	length--;
	delete[]c;
	Sort(tempContact, length);
	return tempContact;
}

void Sort(Contact *c, int &length)
{
	int i, j, num1 = 0;
	Contact x;
	for (i = 0; i < length; i++)
	{
		for (j = length - 1; j > i; j--)
		{
			num1 = cmp(c[j - 1].name, c[j].name);
			if (num1 == 0)
				num1 = cmp(c[j - 1].surname, c[j].surname);
			if (num1 == 1)
			{
				x = c[j - 1];
				c[j - 1] = c[j];
				c[j] = x;
			}
		}
	}
}

int cmp(char *str1, char *str2)
{
	int count = 0, num1, num2;
	for (int i = 0; i < 255; i++)
	{
		num1 = int(str1[i]);
		num2 = int(str2[i]);
		if (num1 < 91)
			num1 += 32;
		if (num2 < 91)
			num2 += 32;
		if (num1 > num2)
		{
			count = 1;
			break;
		}
		else if (num2 > num1)
		{
			count = 2;
			break;
		}
	}
	return count;
}

Contact *Search(Contact *c, int length, int &counter2)
{
	int counter1 = 0, index = 0, answ = 5;
	counter2 = 0;
	char *tempstr;
	char *search = new char[255];
	Contact *searchStr = new Contact[counter2];
	cout << "Search by 1 - name, 2 - surname, 3 - mobile, 4 - email\n";
	while (answ < 1 || answ > 4)
	{
		cin >> answ;
	}
	cout << "Search: ";
	cin.ignore(13,'\n');
	cin.getline(search, 255);
	while (search[index] != '\0')
		index++;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			if (answ == 1)
				tempstr = c[i].name;
			if (answ == 2)
				tempstr = c[i].surname;
			if (answ == 3)
				tempstr = c[i].mob;
			if (answ == 4)
				tempstr = c[i].email;
			if (tempstr[j] == search[counter1])
				counter1++;
			else if (counter1 < index)
			{
				counter1 = 0;
				break;
			}
			if (counter1 == index)
			{
				searchStr = increaseStr(searchStr, counter2);
				searchStr[counter2 - 1] = c[i];
				break;
			}
		}
		counter1 = 0;
	}
	return searchStr;
}

Contact *Change(Contact *c, int length, int count, int index)
{
	char *tempStr;
	cout << "Enter:\n";
	if (index == 0)
		tempStr = c[count].name;
	if (index == 1)
		tempStr = c[count].surname;
	if (index == 2)
		tempStr = c[count].mob;
	if (index == 3)
		tempStr = c[count].email;
	cin.getline(tempStr, 255);
	Sort(c, length);
	return c;
}

Contact *increaseStr(Contact *c, int &length)
{
	Contact *tempStr = new Contact[length + 1];
	for (int i = 0; i < length; i++)
		tempStr[i] = c[i];
	length++;
	delete[] c;
	return tempStr;
}



//Other add
//cout << "Enter Name\n";
//cin.getline(tempContact[length].name, 255);
//cout << "Enter Surname\n";
//cin.getline(tempContact[length].surname, 255);
//cout << "Enter mobile\n";
//cin.getline(tempContact[length].mob, 255);
//cout << "Enter email\n";
//cin.getline(tempContact[length].email, 255);
