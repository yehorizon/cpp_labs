#include "DYN08.h"

int main()
{
	int m; // ���������� ������ - m
	int X, Y; // ���������� ����� ��������
	double** P = new double*[3]; // ������ �� ������
	double** P1 = new double*[3];
	double** P2 = new double*[3];
	double** P3 = new double*[3];
	double** P4 = new double*[3];
	double** FM = new double* [3];
	double F; // ���� ��������
	int h; // ���������� ����������� ������

	fstream f;

	f.open("input.txt", ios_base::in); // ���������� ���������� ������ � ������
	f >> m;


	/////////////////////////////////////// ���������� �������� ///////////////////////////////////////
	P[0] = new double[m];	// ������ ��������� �
	P[1] = new double[m];	// ������ ��������� Y
	P[2] = new double[m];	// ������ ������������ ������������



	P1[0] = new double[m];	// ������ ��������� �
	P1[1] = new double[m];	// ������ ��������� Y
	P1[2] = new double[m];	// ������ ������������ ������������



	P2[0] = new double[m];	// ������ ��������� �
	P2[1] = new double[m];	// ������ ��������� Y
	P2[2] = new double[m];	// ������ ������������ ������������

	for (int i = 0; i < 3; i++)
	{
		P3[i] = new double[m];
	}


	for (int i = 0; i < 3; i++)
	{
		P4[i] = new double[m];
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////

	for (int j = 0; j < m; j++) // ��������� ������ �� �����
	{
		f >> P[0][j];
		f >> P[1][j];
		f >> P[2][j];
	}


	for (int j = 0; j < m; j++) // Outnput in the consol
	{
		for (int i = 0; i < 3; i++)
		{
			cout << P[i][j] << " ";
		}
		cout << endl;
	}
	 
	cout << endl;

	//////////////////////////////// ������� ��������� ������� //////////////////////////////////////

	/*
		������ ������ �����, � �� � DYN08.cpp ���� �� ��������� ������� � �������������� ��������� ��������� ��������� �������.
		��������, � ����� ���������... ����� ������� ������� ������?)))
	*/

	double **E = new double*[3]; 

	for (int i = 0; i < 3; i++)
	{
		E[i] = new double[m]; // �������� ������� ��������
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == j) // ������������ ��������
				E[i][j] = 1;
			else
				E[i][j] = 0;
			cout << E[i][j] << " ";
		}
		cout << endl;
	}
	
	//////////////////////////////////// ������ ����� (��)�������� /////////////////////////////////////

	cout << endl;
	cout << "Enter the coordinates of an arbitrary point (X, Y): " << endl; // ������ ���������� ����� ��������
	cin >> X;
	cin >> Y;
	cout << endl;


	E[0][m-1] = -X; //������� ������ �������� ������������ �� ������������ ����� � ������ ���������
	E[1][m-1] = -Y;


	Output_E(m, E);


	Multiply_Matrix(P1, P, E, m);


	for (int j = 0; j < m; j++) // Outnput in the consol
	{
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << P1[i][j] << " ";
		}
	}

	cout << endl;
	cout << endl << "Enter angle of rotation: ";
	cin >> F;
	cout << endl;

	
	//////////////////////////////// ������� ������� �������� ////////////////////////////////////////

	/*
		double *R[3][3] = { {cos(F),	sin(F),		0},
							{-sin(F),	cos(F),		0},
							{0	,		0,			1} };
	*/

	double **R = new double*[3]; 

	for (int i = 0; i < 3; i++)
	{
		R[i] = new double[m]; 
	}


	for (int i = 0; i < 3; i++) // ��� � ���������, �� � �������� �� ����� � �������
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == j)
				R[i][j] = 1;
			else
				R[i][j] = 0;
		}
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	F = F * (3.1415926 / 180); // ��������� � ���� ��� �����-��... sin() � cos() ���������� �������� � ��������. ������ ����� ������ ������� � �������.

	///////////////////////////////////////////////////////////////////////////////////////////////

	R[0][0] = cos(F); // ���, ����������, � ���� ������
	R[0][1] = -sin(F);

	R[1][0] = sin(F);
	R[1][1] = cos(F);

	////////////////////////////////////////////////////////////////////////////////////////////////

	for (int j = 0; j < m; j++) 
	{
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << R[i][j] << " ";
		}
	}
	cout << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////

	Rotate(P2, P1, R, m);

	////////////////////////////////////////////////////////////////////////////////////////////////

	for (int j = 0; j < m; j++) 
	{
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << P2[i][j] << " ";
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////


	E[0][m - 1] = X; // ������� ������ �������� �������
	E[1][m - 1] = Y;

	////////////////////////////////////////////////////////////////////////////////////////////////

	Output_E(m, E);

	////////////////////////////////////////////////////////////////////////////////////////////////

	Multiply_Matrix2(P4, E, P2, m);

	///////////////////////////////// ����� ������ ����� �������� //////////////////////////////////  

	for (int j = 0; j < m; j++) 
	{
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << P4[i][j] << " ";
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "Enter the range h: " << endl; 
	cin >> h;
	///////////////////////////////////////////////////////////////////////////////////////////////

	Transfer(m, h, FM, P4);
	
	///////////////////////////////////////////////////////////////////////////////////////////////

	Output_Final_Matrix(m, FM, P4);


	/* �������� �������
	for (int i = 0; i < m; i++)
	{
		delete[] E[i]; // ������� ������ �������
	}
	delete[] E; // � ����� ������
	*/

	return 0;
}