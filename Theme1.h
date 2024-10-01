#pragma once
//ВХОДНОЙ КОНТРОЛЬ

/// <summary>
/// Функция для ввода данных
/// </summary>
/// <param name="titles">Названия входных параметров</param>
/// <param name="count">Количество</param>
/// <returns>Массив с заполненными входными параметрами</returns>
double* inputParameters(char** titles, int count) {
	double* parameters = calloc(count, 4); //Объявление массива чисел для заполнения значений переменных
	for (int i = 0; i < count; i++) {
		printf("Введите %s: ", titles[i]);
		scanf("%lf", &parameters[i]);
	}
	return parameters;
}

/// <summary>
/// Функция для вывода ответа
/// </summary>
/// <param name="outputData">названия выходных параметров</param>
/// <param name="values">значения выходных параметров</param>
/// <param name="size">количество парметров</param>
void showInfo(char** outputData, double values[], int size) {
	printf("Значение округляются до 1 десятитысячной. Ответ:");
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%s: %.4lf", outputData[i], values[i]);
		printf("\n");
	}
}

/// <summary>
/// Вычисление корней квадратного уравнения
/// </summary>
void T1Z1() {
	printf("Введите коэффициенты квадратного уравнения:");
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
			printf("Такое уравнение мне не по силам");
		}
	}
	else
	{
		printf("x - любое число");
	}
}

/// <summary>
/// Решение системы двух линейных уравнений
/// </summary>
void T1Z2() {
	printf("Введите коэффициенты системы уравнений:");
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
		printf("Система уравнений либо не имеет решений, либо имеет бесконечно много решений.");
	}
}

//Рекурсивная фукнция для вычисления факториала
int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

/// <summary>
/// Решение системы двух линейных уравнений
/// </summary>
void T1Z3() {
	char** titles[] = { {"n"} };
	double* params;
	while (true)
	{
		printf("Введите количество элементов (до 19):\n");
		params = inputParameters(titles, 1);
		double r = ((int)(params[0] * 10.0) % 10) / 10.0;
		if (params[0] >= 0 && r == 0 && params[0] > 1)
		{
			if (params[0] < 20) {
				break;
			}
		}
		printf("Количество элементов должно быть положительным и целым, и до 19\n");
	}
	char** outputData[] = { {"Факториал"} };
	double f = factorial(params[0]);
	double values[1] = { f };
	showInfo(outputData, values, 1);
}
