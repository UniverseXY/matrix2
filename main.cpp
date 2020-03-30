#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

void matrix_addition(int **a, int **b, int m1, int n1, int m2, int n2);
void matrix_product(int	**a, int** b, int m1, int n1, int m2, int n2);
void print_matrix(int **a, int len1, int len2);


void main() {
	setlocale(LC_ALL, "Rus");

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);
	cout << "Content-type: text/html; charset=windows1251\n\n";
	int m1, n1, m2, n2;
	int **a;
	int **b;
	int **c;
	ifstream fm1("m1.txt");
	fm1 >> m1 >> n1;
	a = new int*[m1];
	for (int i = 0; i < m1; i++) {
		a[i] = new int[n1];
	}
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++)
			fm1 >> a[i][j];
	}

	fm1.close();

	ifstream fm2("m2.txt");
	fm2 >> m2 >> n2;
	b = new int*[m2];
	for (int i = 0; i < m2; i++) {
		b[i] = new int[n2];
	}
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++)
			fm2 >> b[i][j];
	}
	fm2.close();

	
	ifstream f("index.tmplt");
	char* ln = new char[1024];
	if (f.is_open()) {
		while (!f.eof()) {
			f.getline(ln, 1024);
			if (strcmp(ln, "<!--maincontent-->") == 0)
			{
				
				cout << "<div class = 'matr' id='m1' align = 'center'>";
				cout << "Matrix 1";
				print_matrix(a, m1, n1);
				cout << "</div>";
				cout << "<div class = 'matr' id='m2' align = 'center'>";
				cout << "Matrix 2";
				print_matrix(b, m2, n2);
				cout << "</div>";
				cout << "<div class = 'addMatr' align = center>";
				matrix_addition(a, b, m1, n1, m2, n2);
				cout << "</div>";
				cout << "<div class = 'multMatr' align = 'center'>";
				matrix_product(a, b, m1, n1, m2, n2);
				cout << "</div>";

			}
			else
				cout << ln;

		}
		f.close();
		delete[] ln;
	}

}

void matrix_addition(int **a, int **b, int m1, int n1, int m2, int n2) {
	if (m1 == m2 && n1 == n2) {
		cout << "Addition";
		cout << "<table border='5' width='100 %'  cellpadding='10'>";
		for (int i = 0; i < m1; i++) {
			cout << "<tr>";
			for (int j = 0; j < n1; j++) {
				cout << "<th bgcolor = '#FFDAB9'>" << a[i][j] + b[i][j] << "</th> ";
			}
			cout << "</tr>";
		}
		cout << "</table>";

	}
	else {
		cout << "<div class= 'error'>";
		cout << "<p>Нельзя сложить!</p>";
		cout << "</div>";
	}
}

void matrix_product(int** a, int** b, int m1, int n1, int m2, int n2) {
	if (n1 == m2) {
		cout << "Multiplication";
		cout << "<table border='5' width='100 %'  cellpadding='10'>";
		int s = 0;

		for (int i = 0; i < n1; i++) {
			cout << "<tr>";
			for (int j = 0; j < m2; j++) {
				
				for (int k = 0; k < m1; k++)
				
				{	
					
					s += a[i][k] * b[k][j];
					
				}
				cout << "<th bgcolor = '#FFDAB9'>" << s << "</th>";
				
				
				s = 0;	
			}
			cout << "</tr>";
		}
		cout << "</table>";
	}
	else {
		cout << "<div class= 'error'>";
		cout << "<p>Нельзя умножить!</p>";
		cout << "</div>";
	}
}

void print_matrix(int** a, int len1, int len2) {
	cout << "<table border='5' width='100 %'  cellpadding='10' >";
	for (int i = 0; i < len1; i++) {
		cout << "<tr>";
		for (int j = 0; j < len2; j++) {
			cout << "<th bgcolor='#FFDAB9'>" << a[i][j] << "</th> ";
		}
		cout << "</tr>";
	}
	cout << "</table>";
}
