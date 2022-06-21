#pragma once
#include <iostream>
#include <string>
using namespace std;


class Student                    //заголовок класса.(определение)
{
protected:                       //защищённые члены класса.
	string surname;              //перемен.data members class.
	string name;                 //поля класса.
	string patronymic;           //атрибуты класса.
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

	void getStudMark();                   //вывод (всех) оценок.
	void getStudFIO();                    //вывод Ф.И.О.
	void getMark(int* ar);                //вывод массива оценок.
	int* getchoice();                     //выбор предмета.
	void setMarkMat(int mark);            //ввод оценок по математике.
	void setMarkPhysic(int mark);         //ввод оценок по физике.
	void setMarkRusian(int mark);         //ввод оценок по русскому.
	void setCorrectGrades();              //исправление оценок по позиции.
	void setRatings();                    //ввод оценок (интерфейс).
	void setStudent();                    //ввод Ф.И.О.
    void operator = (Student& stud);      //оператор копирования.
	void getaver(Student& stud);          //средний бал.    
};


class Journal :public Student
{
private:                                   //модификатор доступа.
    Student* stud_journal ;                //массив студентов.
	static int countJournal;               //статический член класса.

public:                                    //модификатор доступа.
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
	Student getStud(int index)                        // возвращает эл. массива студентов. 
	{
		return stud_journal[index];
	}
	void interface();                                 //взаимодействие с пользователем.
	void getshowJournal();                            //вывод всего журнала.
	Student* creatAr(int size);                       //созд. массива под заказ.
    void addStud(Journal journal);                    //добавление студента в журнал.
	void deletStud(Student*& stud_Journal, int ipos); //удаление студ. из журнала.
	void getshowDebtors();                            //вывод задолжников.

};