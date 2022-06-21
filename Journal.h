#pragma once
#include <iostream>
#include <string>
using namespace std;


class Student                    //��������� ������.(�����������)
{
protected:                       //���������� ����� ������.
	string surname;              //�������.data members class.
	string name;                 //���� ������.
	string patronymic;           //�������� ������.
	int* mark_mat;               
	int* mark_physic;
	int* mark_rusian;
	int countMat = 0;
	int countPhysic = 0;
	int countRusian = 0;

	double averMat = 0;                       //???
	double averPhysic = 0;                        //???
	double averRusian = 0;                      //???
public:

	Student()         //(ctor)
	{
		mark_mat = nullptr;
		mark_physic = nullptr;
		mark_rusian = nullptr;
	}
	
	Student(string surname, string name, string patronymic)
    {
	    this->surname = surname;
	    this->name = name;
	    this->patronymic = patronymic;
    }
	Student(string surname, string name,
		string patrnymic, int countMat,
		int countPhysic, int countRusian)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
		this->countMat = countMat;
		this->countPhysic = countPhysic;
		this->countRusian = countRusian;
	}
	~Student()                   //(dtor)
	{
		cout << " dtor Student." << endl;
		if (mark_mat != nullptr)
			delete[]mark_mat;
		if (mark_physic != nullptr)
			delete[]mark_physic;
		if (mark_rusian != nullptr)
			delete[]mark_rusian;
	}

	void getStudMark();                   //����� (����) ������.
	void getStudFIO();                    //����� �.�.�.
	void getMark(int* ar);                //����� ������� ������.
	int* getchoice();                     //����� ��������.
	void setMarkMat(int mark);            //���� ������ �� ����������.
	void setMarkPhysic(int mark);         //���� ������ �� ������.
	void setMarkRusian(int mark);         //���� ������ �� ��������.
	void setCorrectGrades();              //����������� ������ �� �������.
	void setRatings();                    //���� ������ (���������).
	void setStudent();                    //���� �.�.�.
    void operator = (Student& stud);      //�������� �����������.
	void getaver(Student& stud);          //������� ���.    
};


class Journal :public Student
{
private:                                   //����������� �������.
    Student* stud_journal ;                //������ ���������.
	static int countJournal;               //����������� ���� ������.

public:                                    //����������� �������.
	Journal()
	{
		cout << " ctor Journal " << endl;

		stud_journal = nullptr;
	}

	~Journal()
	{
		cout << " dtor Journal" << endl;
			if (stud_journal != nullptr)
				delete[] stud_journal;
	}
	Student getStud(int index)                        // ���������� ��. ������� ���������. 
	{
		return stud_journal[index];
	}
	void interface();                                 //�������������� � �������������.
	void getshowJournal();                            //����� ����� �������.
	Student* creatAr(int size);                       //����. ������� ��� �����.
    void addStud(Journal journal);                    //���������� �������� � ������.
	void deletStud(Student*& stud_Journal, int ipos); //�������� ����. �� �������.
	void getshowDebtors();                            //����� �����������.

};