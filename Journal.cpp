#include "Journal.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ����������� ������� (������� ������ �������).

int Journal::countJournal{ 0 };              //������������� ������������ ���� (����.��� ������)


void Journal::addStud(Journal stud)         //���������� ����. � ������.
{
	cout << " ��������� addStud Journal" << endl;
	countJournal++;  
	Student* stud_journal = new Student[countJournal];
	for (int i = 0; i < countJournal; i++)            
		stud_journal[i]=stud;

}

Student* Journal::creatAr(int size)
{
	Student* buf = new Student[size];
	return buf;
}

//����� ����� �������.
void Journal::getshowJournal()
{
	cout << endl<<"\t ������ : " << endl;
	if (countJournal)
	{
		for (int i = 0; i < countJournal; i++)
		{
			cout << i + 1 << " ������� :" << endl;
			stud_journal[i].getStudFIO();     //����� ���.
		    stud_journal[i].getStudMark();    //����� ������. 
	    }
		cout << endl << endl;
	}
	else cout << " ������ ����." << endl;

}

void Journal:: interface()
{
	cout << " ������� ���������� ���������\n"
		<< " (��� ���������� �������): ";
	

	do {
		cin >> countJournal;
		if (countJournal <= 0 or countJournal > 100)
     	cout << " ������� ����� ������: (�� 0 �� 100) : ";

	} while (countJournal <= 0 or countJournal > 100);

	//delete[] stud_journal;                           ///???????

	stud_journal = creatAr(countJournal);
	int i = 0;
	for (; i < countJournal;i++)
	{
		cout << i+1 << " ������� : " << endl << endl;
		stud_journal[i].setStudent();     //���� ���.
		stud_journal[i].setRatings();     //��������� ������.

	}

		 int x;
		do {
			cout << endl;
			cout << setw(44) << " ��������� (��������) ������:   1 " << endl;
			cout << setw(44) << " ��������� ������:   2 " << endl;
			cout << setw(44) << " ����� ���. � ��������:   3 " << endl;
			cout << setw(44) << " ����� ���. ����� �������:   4 " << endl;
			cout << setw(44) << " �������� ��������  �� �������:   5 " << endl;
			cout << setw(44) << " ������� ���� ����������� (aver < 3):   6 " << endl;
			cout << setw(44) << " �����:   7 " << endl;

			cin >> x;
			switch (x) {
			case 1:
				cout << " ������� ����� �������� : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					cout << " ��� �����: " << endl;
					stud_journal[x - 1].getStudFIO();
					stud_journal[x - 1].setRatings();
				}
				else
					cout<< " ������� � ����� ������� �� ����������." << endl;
				break;
			case 2:
				cout << " ������� ����� �������� : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					stud_journal[x - 1].getStudFIO();
					stud_journal[x - 1].getStudMark();
					stud_journal[x - 1].setCorrectGrades();
					stud_journal[x - 1].getStudMark();
				}
				else 
					cout << " ������� � ����� ������� �� ����������." << endl;
				break;
			case 3:
				cout << " ������� ����� �������� : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					stud_journal[x - 1].getStudFIO();
					stud_journal[x - 1].getStudMark();
				}
				else 
					cout << " ������� � ����� ������� �� ����������." << endl;
				break;
			case 4:
				getshowJournal();
				break;
			case 5:
				cout << " �� ������� �������!" << endl;
				cout << " ������� ����� �������� : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					cout << " ��� �����: " << endl;
					stud_journal[x - 1].getStudFIO();
					cout << " ����������� �������� ( y / n ) : ";
					char y;
					cin >> y;
					if (y == 'y')
					{
						deletStud(stud_journal,x);
						getshowJournal();
					}
					else break;

				}
				else
					cout << " ������� � ����� ������� �� ����������." << endl;
				break;
			case 6:
				cout << " ������ �����������: " << endl << endl;
				getshowDebtors();        //����� �����������.

				break;
			case 7:
				cout << " ����������." << endl;//
				break;
			}

		} while (x != 7);
}


//�������� ����.�� �������.                   
void Journal::deletStud(Student*& stud_journal,int ipos)
{
	countJournal--;
	Student* buf = new Student[countJournal];
	for (int i = 0; i < ipos-1; i++)
		buf[i] = stud_journal[i];
	for (int i = ipos-1; i < countJournal; i++)
		buf[i] = stud_journal[i + 1];
	//delete &stud_journal[ipos];                
	delete[]stud_journal;
	stud_journal = buf;
}


//����� �����������          ///??????????


void Journal:: getshowDebtors()
{
	for (int i = 0; i < countJournal; i++)
	stud_journal[i].getaver( stud_journal[i]);

}

//**************************************************   
 

//������� ���.                  //??????????????
void Student:: getaver(Student& stud)
{
    double sum = 0;
	int count = 0;
	for (int i = 0; i < countMat; i++) {
		sum += mark_mat[i];
	}
	averMat = sum / countMat;
        if (averMat < 3) {
			count++;
			stud.getStudFIO();
			cout << " ����������� �� ����������: " << averMat << " (��. ������)" << endl;
			cout << "������: ";
			for (int i = 0; i < countMat; i++) {

				cout << mark_mat[i]<<" ";
			}
			cout << endl;
        }
	sum = 0;
	for (int i = 0; i < countPhysic; i++) {
		sum += mark_physic[i];
	}
	averPhysic = sum / countPhysic;
		if (averPhysic < 3) {
			if (!count) {
				stud.getStudFIO();
			}
			cout << " ����������� �� ������: " << averPhysic << " (��. ������)" << endl;
			cout << " �����: ";
			for (int i = 0; i < countPhysic; i++) {
				cout << mark_physic[i]<<" ";
			}
			cout << endl;
		}
	sum = 0;
	for (int i = 0; i < countRusian; i++) {
		sum += mark_rusian[i];
	}
	averRusian = sum / countRusian;
		if (averRusian < 3) {
			if (!count) {
				stud.getStudFIO();
			}
			cout << " ����������� �� ��������: " << averRusian << " (��. ������)" << endl;
			cout << " ������: ";
			for (int i = 0; i < countRusian; i++) {
				cout << mark_rusian[i]<<" ";
			}
			cout << endl;
		}

}


//�������� �����������.
void Student::operator = (Student& stud)
{
	this->surname = stud.surname;
	this->name = stud.name;
	this->patronymic = stud.patronymic;
	this->countMat = stud.countMat;
	this->countPhysic = stud.countPhysic;
	this->countRusian = stud.countRusian;

	//delete[]mark_mat;
	mark_mat = new int[countMat];
	for (int i = 0; i < countMat; i++)
		mark_mat[i] = stud.mark_mat[i];

	//delete[]mark_physic;
	mark_physic = new int[countPhysic];
	for (int i = 0; i < countPhysic; i++)
		mark_physic[i] = stud.mark_physic[i];

	//delete[]mark_rusian;
	mark_rusian = new int[countRusian];
	for (int i = 0; i < countRusian; i++)
		mark_rusian[i] = stud.mark_rusian[i];

}


//����� �.�.�.
void Student::getStudFIO()
{
	cout << surname << " " << name << " " << patronymic << endl;
}

//����� ������.
void Student::getMark(int* ar)
{
	int size = _msize(ar) / sizeof(ar[0]);
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}
//����� ������ (����.)
void Student::getStudMark()
{
	if (countMat) {
		cout << setw(14) << " ���������� : ";
		for (int i = 0; i < countMat; i++)
			cout << mark_mat[i] << " ";
		cout << endl;
	}
	if (countPhysic)
	{
		cout << setw(14) << " ������ : ";
		for (int i = 0; i < countPhysic; i++)
			cout << mark_physic[i] << " ";
		cout << endl;
	}
	if (countRusian)
	{
		cout << setw(14) << " ������� : ";
		for (int i = 0; i < countRusian; i++)
			cout << mark_rusian[i] << " ";
		cout << endl << endl;
	}
}

//���������� ������ (�������).
void Student:: setMarkMat(int mark)
{
	if (!countMat) {
		mark_mat = new int[1];
		mark_mat[0] = mark;
	}
	else
	{
		int* buf = new int[countMat + 1];
		for (int i = 0; i < countMat + 1; i++) {
			buf[i] = mark_mat[i];
		}
		buf[countMat] = mark;
		delete[]mark_mat;
		mark_mat = buf;
	}
	countMat++;
}

void Student::setMarkPhysic(int mark)
{
	if (!countPhysic) {
		mark_physic = new int[1];
		mark_physic[0] = mark;
	}
	else
	{
		int* buf = new int[countPhysic + 1];
		for (int i = 0; i < countPhysic + 1; i++) {
			buf[i] = mark_physic[i];
		}
		buf[countPhysic] = mark;
		delete[]mark_physic;
		mark_physic = buf;
	}
	countPhysic++;
}
void Student::setMarkRusian(int mark)
{
	if (!countRusian)
	{
		mark_rusian = new int[1];
		mark_rusian[0] = mark;
	}
	else
	{
		int* buf = new int[countRusian + 1];
		for (int i = 0; i < countRusian + 1; i++) {
			buf[i] = mark_rusian[i];
		}
		buf[countRusian] = mark;
		delete[]mark_rusian;
		mark_rusian = buf;
	}
	countRusian++;
}


//����������� ������ �� �������.
void Student::setCorrectGrades()
{
	int ipos, newmark;
	int* markAr = getchoice();
	cout << " ����������� ������: ";
	getMark(markAr);   // ����� ������.
	cout << " ������� ������� ������ (1,2 ��� 3 � �.�) ��� �����������:";
	cin >> ipos;
	cout << " ������� ����� ������:";
	cin >> newmark;
	int size = _msize(markAr) / sizeof(markAr[0]);
	if (ipos > 0 and ipos <= size)
		markAr[ipos - 1] = newmark;

}

//���� �.�.�.
void Student::setStudent()
{
	cout << " �������: ";
	cin >> surname;
	cout << " ���:";
	cin >> name;
	cout << " ��������:";
	cin >> patronymic;
}

   //���� ������ (���������).
	void Student::setRatings()
	{
		char x;
		do
		{
			cout << "  �������� ������� (���������� 1, ������ 2, ������� 3) :" << endl;
			int a, mark;
			cin >> a;
			// a=choice(); // �����.
			switch (a)
			{
			case 1:
				cout << " �� ������� ����������."
					<< endl << "(�� ��������� ����� ������� NULL)"
					<< endl << "������� ������ : " << endl;
				while (true) {
					cin >> mark; 
					if (mark >= 1 && mark <= 12)
						setMarkMat(mark);
					else break;
				}
				break;
			case 2:
				cout << " �� ������� ������."
					<< endl << "(�� ��������� ����� ������� NULL)"
					<< endl << "������� ������ : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkPhysic(mark);
					else break;
				}
				break;
			case 3:
				cout << " �� ������� �������."
					<< endl << "(�� ��������� ����� ������� NULL)"
					<< endl << "������� ������ : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkRusian(mark);
					else break;
				}
				break;
			default:
				cout << " �� ��������, ���������� ��� ���." << endl;
			}
			cout << " ���������� ���� ������ ( y / n )";
			cin >> x;
			cout << endl;
		} while (x == 'y');
	}


	//����� ��������.
	int* Student:: getchoice()
	{
		int x;
		cout << "  �������� ������� (���������� 1, ������ 2, ������� 3) :" << endl;
		cin >> x;
		switch (x) {
		case 1:
			cout << " ����������: " << endl;
			return mark_mat;
			break;
		case 2:
			cout << " ������:" << endl;
			return mark_physic;
			break;
		case 3:
			cout << " �������:" << endl;
			return mark_rusian;
			break;
		}
	}






















