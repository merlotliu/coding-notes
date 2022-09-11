#pragma once
#include <string>

class Student {
public:
	Student(){}
	Student(std::string name, int no, int age): _name(name), _no(no), _age(age) {}

	void set(std::string name, int no, int age) {
		_name = name;
		_no = no;
		_age = age;
	}
public:
	std::string _name;
	int _no;
	int _age;
};

class Comp{
public:
	static void sort(int *arr, int len, int(*cmp)(const void*, const void*)) {
		qsort(arr, len, sizeof(int), cmp);
	}

	static void sortByDescendingOrder(int *arr, int len) {
		qsort(arr, len, sizeof(int), Comp::less);
	}

	static void sortByAscendingOrder(int *arr, int len) {
		qsort(arr, len, sizeof(int), Comp::greater);
	}

	static void studentSortByAgeAscendingOrder(Student *stus, int len) {
		qsort(stus, len, sizeof(Student), Comp::studentAgeGreater);
	}

	static int less(const void *a, const void *b) {
		// a < b С��ʱ�򷵻� 1����Ϊ����
		const int arg1 = *static_cast<const int*>(a);
		const int arg2 = *static_cast<const int*>(b);
		
		/*if (arg1 < arg2) return 1;
		if (arg1 > arg2) return -1;
		return 0;*/
		return (arg1 < arg2) - (arg1 > arg2);
	}

	static int greater(const void *a, const void *b) {
		// a < b С��ʱ�򷵻� -1����Ϊ����
		const int arg1 = *static_cast<const int*>(a);
		const int arg2 = *static_cast<const int*>(b);
		/*if (arg1 < arg2) return -1;
		if (arg1 > arg2) return 1;
		return 0;*/
		return (arg1 > arg2) - (arg1 < arg2);
		//return (*static_cast<const int*>(a) - *static_cast<const int*>(b)); 
		// ���� INT_MIN ʱ�����
	}
	
	static int studentAgeGreater(const void *a, const void *b) {
		// ����-1����һ��������ǰ��
		// ����1���ڶ���������ǰ��
		// �������˳�����ԭ�������ǰ��˳��

		// ��������
		const Student *stu1 = (static_cast<const Student*>(a));
		const Student *stu2 = (static_cast<const Student*>(b));
		if (stu1->_age < stu2->_age) {
			return -1;
		}
		if (stu1->_age > stu2->_age) {
			return 1;
		}
		// �������һ�� ѧ��С���ں���
		if (stu1->_no < stu2->_no) {
			return 1;
		}
		if (stu1->_no > stu2->_no) {
			return -1;
		}
		return 0;
		//return (arg1 > arg2) - (arg1 < arg2);
	}

	static void printStudents(Student *stus, int len) {
		if (stus == nullptr) {
			return;
		}
		for (int i = 0; i < len; i++) {
			std::cout << stus[i]._name << " " << stus[i]._no << " " << stus[i]._age << std::endl;
		}
		std::cout << std::endl;
	}
};