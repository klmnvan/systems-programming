#pragma once
//������� ��������

/// <summary>
/// ������� ��� ����� ������
/// </summary>
/// <param name="titles">�������� ������� ����������</param>
/// <param name="count">����������</param>
/// <returns>������ � ������������ �������� �����������</returns>
double* inputParameters(char** titles, int count) {
	double* parameters = calloc(count, 4); //���������� ������� ����� ��� ���������� �������� ����������
	for (int i = 0; i < count; i++) {
		printf("������� %s: ", titles[i]);
		scanf("%lf", &parameters[i]);
	}
	return parameters;
}

/// <summary>
/// ������� ��� ������ ������
/// </summary>
/// <param name="outputData">�������� �������� ����������</param>
/// <param name="values">�������� �������� ����������</param>
/// <param name="size">���������� ���������</param>
void showInfo(char** outputData, double values[], int size) {
	printf("�������� ����������� �� 1 ��������������. �����:");
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%s: %.4lf", outputData[i], values[i]);
		printf("\n");
	}
}

/// <summary>
/// ���������� ������ ����������� ���������
/// </summary>
void T1Z1() {
	printf("������� ������������ ����������� ���������:");
	printf("\n");
	char** titles[] = { {"a"}, {"b"}, {"c"} };
	double* params = inputParameters(titles, 3);
	if (params[0] != 0 && params[0] != 0 && params[0]) {
		double D = pow(params[1], 2.0) - (4.0 * params[0] * params[2]);
		char** outputData[] = { {"x1"}, {"x2"} };
		if (D > 0)
		{
			double values[2] = { (-params[1] + sqrt(D)) / (2.0 * params[0]), (-params[1] - sqrt(D)) / (2.0 * params[0]) };
			showInfo(outputData, values, 2);
		}
		else if (D == 0)
		{
			double values[1] = { (-params[1] + sqrt(D)) / 2.0 * params[0] };
			showInfo(outputData, values, 1);
		}
		else
		{
			printf("����� ��������� ��� �� �� �����");
		}
	}
	else
	{
		printf("x - ����� �����");
	}
}

/// <summary>
/// ������� ������� ���� �������� ���������
/// </summary>
void T1Z2() {
	printf("������� ������������ ������� ���������:");
	printf("\n");
	char** titles[] = { {"a1"}, {"b1"}, {"c1"}, {"a2"}, {"b2"}, {"c2"} };
	double* params = inputParameters(titles, 6);
	double D = (params[0] * params[4]) - (params[1] * params[3]);
	if (D != 0) {
		char** outputData[] = { {"x"}, {"y"} };
		double values[2] = { ((params[2] * params[4]) - (params[1] * params[5])) / D, ((params[1] * params[5]) - (params[2] * params[3])) / D };
		showInfo(outputData, values, 2);
	}
	else
	{
		printf("������� ��������� ���� �� ����� �������, ���� ����� ���������� ����� �������.");
	}
}

//����������� ������� ��� ���������� ����������
int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

/// <summary>
/// ������� ������� ���� �������� ���������
/// </summary>
void T1Z3() {
	char** titles[] = { {"n"} };
	double* params;
	while (true)
	{
		printf("������� ���������� ��������� (�� 19):\n");
		params = inputParameters(titles, 1);
		double r = ((int)(params[0] * 10.0) % 10) / 10.0;
		if (params[0] >= 0 && r == 0 && params[0] > 1)
		{
			if (params[0] < 20) {
				break;
			}
		}
		printf("���������� ��������� ������ ���� ������������� � �����, � �� 19\n");
	}
	char** outputData[] = { {"���������"} };
	double f = factorial(params[0]);
	double values[1] = { f };
	showInfo(outputData, values, 1);
}
