#include "Journal.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ОПРЕДЕЛЕНИЕ МЕТОДОВ (функций членов классов).

int Journal::countJournal{ 0 };              //инициализация статического поля (обяз.вне класса)


void Journal::addStud(Journal stud)         //добавление студ. в журнал.
{
	cout << " Отработал addStud Journal" << endl;
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

//вывод всего журнала.
void Journal::getshowJournal()
{
	cout << endl<<"\t Журнал : " << endl;
	if (countJournal)
	{
		for (int i = 0; i < countJournal; i++)
		{
			cout << i + 1 << " Студент :" << endl;
			stud_journal[i].getStudFIO();     //вывод ФИО.
		    stud_journal[i].getStudMark();    //вывод оценок. 
	    }
		cout << endl << endl;
	}
	else cout << " Журнал пуст." << endl;

}

void Journal:: interface()
{
	cout << " Введите количество студентов\n"
		<< " (для заполнения журнала): ";
	

	do {
		cin >> countJournal;
		if (countJournal <= 0 or countJournal > 100)
     	cout << " Введите число заново: (от 0 до 100) : ";

	} while (countJournal <= 0 or countJournal > 100);

	//delete[] stud_journal;                           ///???????

	stud_journal = creatAr(countJournal);
	int i = 0;
	for (; i < countJournal;i++)
	{
		cout << i+1 << " Студент : " << endl << endl;
		stud_journal[i].setStudent();     //ввод ФИО.
		stud_journal[i].setRatings();     //выставить оценки.

	}

		 int x;
		do {
			cout << endl;
			cout << setw(44) << " Выставить (добавить) оценку:   1 " << endl;
			cout << setw(44) << " Исправить оценку:   2 " << endl;
			cout << setw(44) << " Вывод инф. о студенте:   3 " << endl;
			cout << setw(44) << " Вывод инф. всего журнала:   4 " << endl;
			cout << setw(44) << " Удаление студента  из журнала:   5 " << endl;
			cout << setw(44) << " Вывести всех задолжников (aver < 3):   6 " << endl;
			cout << setw(44) << " Выход:   7 " << endl;

			cin >> x;
			switch (x) {
			case 1:
				cout << " Введите номер студента : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					cout << " Ваш выбор: " << endl;
					stud_journal[x - 1].getStudFIO();
					stud_journal[x - 1].setRatings();
				}
				else
					cout<< " Студент с таким номером не существует." << endl;
				break;
			case 2:
				cout << " Введите номер студента : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					stud_journal[x - 1].getStudFIO();
					stud_journal[x - 1].getStudMark();
					stud_journal[x - 1].setCorrectGrades();
					stud_journal[x - 1].getStudMark();
				}
				else 
					cout << " Студент с таким номером не существует." << endl;
				break;
			case 3:
				cout << " Введите номер студента : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					stud_journal[x - 1].getStudFIO();
					stud_journal[x - 1].getStudMark();
				}
				else 
					cout << " Студент с таким номером не существует." << endl;
				break;
			case 4:
				getshowJournal();
				break;
			case 5:
				cout << " Вы выбрали удалить!" << endl;
				cout << " Введите номер студента : ";
				cin >> x;
				if (x >= 1 && x <= countJournal)
				{
					cout << " Ваш выбор: " << endl;
					stud_journal[x - 1].getStudFIO();
					cout << " Подтвердите удаление ( y / n ) : ";
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
					cout << " Студент с таким номером не существует." << endl;
				break;
			case 6:
				cout << " Список задолжников: " << endl << endl;
				getshowDebtors();        //вывод задолжников.

				break;
			case 7:
				cout << " Досвидание." << endl;//
				break;
			}

		} while (x != 7);
}


//удаление студ.из журнала.                   
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


//вывод задолжников          ///??????????


void Journal:: getshowDebtors()
{
	for (int i = 0; i < countJournal; i++)
	stud_journal[i].getaver( stud_journal[i]);

}

//**************************************************   
 

//средний бал.                  //??????????????
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
			cout << " Задолжность по Математике: " << averMat << " (ср. оценка)" << endl;
			cout << "оценки: ";
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
			cout << " Задолжность по Физике: " << averPhysic << " (ср. оценка)" << endl;
			cout << " оцеки: ";
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
			cout << " Задолжность по Русскому: " << averRusian << " (ср. оценка)" << endl;
			cout << " оценки: ";
			for (int i = 0; i < countRusian; i++) {
				cout << mark_rusian[i]<<" ";
			}
			cout << endl;
		}

}


//оператор копирования.
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


//вывод Ф.И.О.
void Student::getStudFIO()
{
	cout << surname << " " << name << " " << patronymic << endl;
}

//вывод оценок.
void Student::getMark(int* ar)
{
	int size = _msize(ar) / sizeof(ar[0]);
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}
//вывод оценок (студ.)
void Student::getStudMark()
{
	if (countMat) {
		cout << setw(14) << " Математика : ";
		for (int i = 0; i < countMat; i++)
			cout << mark_mat[i] << " ";
		cout << endl;
	}
	if (countPhysic)
	{
		cout << setw(14) << " Физика : ";
		for (int i = 0; i < countPhysic; i++)
			cout << mark_physic[i] << " ";
		cout << endl;
	}
	if (countRusian)
	{
		cout << setw(14) << " Русский : ";
		for (int i = 0; i < countRusian; i++)
			cout << mark_rusian[i] << " ";
		cout << endl << endl;
	}
}

//добавление оценки (отметки).
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


//исправление оценок по позиции.
void Student::setCorrectGrades()
{
	int ipos, newmark;
	int* markAr = getchoice();
	cout << " Исправление оценок: ";
	getMark(markAr);   // вывод оценок.
	cout << " Введите позицию оценки (1,2 или 3 и т.д) для исправления:";
	cin >> ipos;
	cout << " Введите новую оценку:";
	cin >> newmark;
	int size = _msize(markAr) / sizeof(markAr[0]);
	if (ipos > 0 and ipos <= size)
		markAr[ipos - 1] = newmark;

}

//ввод Ф.И.О.
void Student::setStudent()
{
	cout << " Фамилия: ";
	cin >> surname;
	cout << " Имя:";
	cin >> name;
	cout << " Отчество:";
	cin >> patronymic;
}

   //ввод оценок (интерфейс).
	void Student::setRatings()
	{
		char x;
		do
		{
			cout << "  Выберите предмет (Математика 1, Физика 2, Русский 3) :" << endl;
			int a, mark;
			cin >> a;
			// a=choice(); // выбор.
			switch (a)
			{
			case 1:
				cout << " Вы выбрали Математику."
					<< endl << "(по окончанию ввода нажмите NULL)"
					<< endl << "Введите оценки : " << endl;
				while (true) {
					cin >> mark; 
					if (mark >= 1 && mark <= 12)
						setMarkMat(mark);
					else break;
				}
				break;
			case 2:
				cout << " Вы выбрали Физику."
					<< endl << "(по окончанию ввода нажмите NULL)"
					<< endl << "Введите оценки : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkPhysic(mark);
					else break;
				}
				break;
			case 3:
				cout << " Вы выбрали Русский."
					<< endl << "(по окончанию ввода нажмите NULL)"
					<< endl << "Введите оценки : " << endl;
				while (true) {
					cin >> mark;
					if (mark >= 1 && mark <= 12)
						setMarkRusian(mark);
					else break;
				}
				break;
			default:
				cout << " Вы ошиблись, попробуйте ещё раз." << endl;
			}
			cout << " Продолжить ввод оценок ( y / n )";
			cin >> x;
			cout << endl;
		} while (x == 'y');
	}


	//выбор предмета.
	int* Student:: getchoice()
	{
		int x;
		cout << "  Выберите предмет (Математика 1, Физика 2, Русский 3) :" << endl;
		cin >> x;
		switch (x) {
		case 1:
			cout << " Математика: " << endl;
			return mark_mat;
			break;
		case 2:
			cout << " Физика:" << endl;
			return mark_physic;
			break;
		case 3:
			cout << " Русский:" << endl;
			return mark_rusian;
			break;
		}
	}






















