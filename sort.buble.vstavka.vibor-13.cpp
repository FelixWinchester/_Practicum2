#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct people {
	int year, p1, p2, p3, p4, p5;
	string name, surname, secname;
};

bool comp(people s1, people s2) {
	if (s1.surname > s2.surname) {
		return 1;
	}
	else if (s1.surname == s2.surname && s1.year > s2.year) {
		return 1;
	}
	else {
		return 0;
	}
}


void bubble(people* a, int n) {
	people temp;
	int j, k;
	for (int i = 0; i < n-1; i++) {
		for (int j = n - 1; j > i;j--) {
			if (comp(a[j-1], a[j])) {
				swap(a[j], a[j - 1]);
			}
		}
	}
}

void choose_sort(people* a, int n) {
	for (int i = 0; i < n; i++) {
		int mind = i;
		for (int j = i + 1; j < n; j++) {
			if (comp(a[mind], a[j])) {
				mind = j;
			}
		}
		if (mind != i) {
			swap(a[i], a[mind]);
		}
	}
}

void in_sort(people* a, int n) {
	for (int i = 1; i < n; i++) {
		people key = a[i];
		int j = i - 1;
		while (j >= 0 && comp(a[j], key)) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}


ifstream in("input.txt");
ofstream out("output.txt");

int main() {

	int num, n = 0;
	string ss;

	while (in.peek() != EOF) {
		getline(in, ss, '\n');
		n++;
	}
	n--;

	//cout << n;

	in.clear();
	in.seekg(0);

	in >> num;

	people* a = new people[n];

	for (int i = 0; i < n; i++) {
		in >> a[i].surname >> a[i].name >> a[i].secname >> a[i].year >> a[i].p1 >> a[i].p2 >> a[i].p3 >> a[i].p4 >> a[i].p5;
	}

	for (int i = 0; i < n; i++) {
		out << a[i].surname << ' ' << a[i].name << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << endl;
	}

	out << endl;

	//bubble(a, n);
	//in_sort(a, n);
	choose_sort(a, n);

	out << num << endl;

	for (int i = 0; i < n; i++) {
		out << a[i].surname << ' ' << a[i].name << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << endl;
	}

	in.close();
	out.close();

}


/*
141
Sekiro Dark Soulsovich 2001 3 4 3 4 5
Bankir Nikolay Gvyndoline 1995 3 4 3 4 3
Info Kokya Uio 2000 3 3 3 4 5
Gihu Dima Pan 2011 3 4 3 4 3
Buhanka Nikolay Gynotsid 1996 3 4 3 4 3
Android Lui Pandro 2004 2 2 1 0 4
*//*
Сортировка пузырьком (Bubble Sort) - это один из простейших алгоритмов сортировки. Он проходит по массиву несколько раз, 
сравнивая соседние элементы и меняя их местами, если они стоят в неправильном порядке. Циклы продолжаются до тех пор, пока массив не будет отсортирован. 
*//*
Сортировка вставкой (Insertion Sort) - это алгоритм сортировки, который проходит по массиву от начала до конца 
и каждый элемент вставляет на свое место в уже отсортированной части массива.
*//*
Сортировка выбором (Selection Sort) - это алгоритм сортировки, который проходит по массиву несколько раз, выбирая 
каждый раз минимальный элемент и меняя его местами с первым элементом в неотсортированной части массива. 
*/






















