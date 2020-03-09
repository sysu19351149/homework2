#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

class Identity 
{
public:
	Identity(long long int _num = 0, const char *_name = "") :num(_num)
	{
		s = _name;
		strcpy(name, s.c_str());
		cout << "constructor id" << endl;
	}
	Identity(const Identity& _id) 
	{
		num = _id.num;
		s = _id.name;
		strcpy(name, s.c_str()); 
		cout << "copy constructor id" << endl;
	}
	~Identity() 
	{
		cout << "distructor id" << endl; 
	}
	string get_name() { return (string)name; }
	long long int get_num() { return num; }
	void input_name(const char* _name) { s = _name; strcpy(name, s.c_str());}
	void input_num(long long int _num) { num = _num; }
private:
	string s;
	long long int num;
	char name[32];
};

class Student 
{
public:
	Student(Identity _id = Identity(), string _school = "") : id(_id), school(_school) { 
		cout << "constructor stu" << endl;
	}
	Student(const Student& _Stu) {
		id = _Stu.id;
		school = _Stu.school;
		cout << "copy constructor stu" << endl;
	}
	~Student() {
		cout << "distructor stu" << endl;
	}
	string get_school() { return school; }
	void input_school(string _school) { school = _school; }
	string get_name() { return id.get_name(); }
	long long int get_num() { return id.get_num(); }
	void input_name(const char *_name) { id.input_name(_name); }
	void input_num(long long int _num) { id.input_num  (_num); } 
private:
	Identity id;
	string school;
};

Student MakeStudent(long int num, const char *name, string school) {
	Student S;
	S.input_name(name);
	S.input_num(num);
	S.input_school(school);
	return S;
}

int main() 
    {
	Identity id1, id2;
	Student Stu1(id1,""), Stu2(id2,"");
	long long int num;
	string school;
	char name[32];
	char* name_p = name; 
	
	
	cout <<endl<< "������ѧ�����֤�ţ�������ѧУ����" << endl;
	cin >> num >> name_p >> school;
	cout << endl;
	Stu1 = MakeStudent(num, name_p, school);
	
	cout << endl<< "��һ�����֤�ţ�" << Stu1.get_num() << endl;
	cout << "��һ��������" << Stu1.get_name() << endl;
	cout << "��һ��ѧУ���ƣ�" << Stu1.get_school() << endl<<endl;
	
	
	Stu2 = Stu1;
	
	
	Stu2.input_name("Auto");
	Stu2.input_num(440044202002294040);
	Stu2.input_school("Auto"); 
	
	cout << "�ڶ������֤�ţ�" << Stu2.get_num() << endl;
	cout << "�ڶ���������" << Stu2.get_name() << endl;
	cout << "�ڶ���ѧУ���ƣ�" << Stu2.get_school() << endl<<endl;
}
