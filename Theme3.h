#pragma once
//ЗАДАНИЕ НА СОЗДАНИЕ ДЕЛЕГАТОВ

//определить указатель на функцию и массив указателей на функцию как новый тип данных
//реализовать функцию добавления функций в делегат
//реализовать функцию удаления функций из делегата
//реализовать функцию запуска всех функций из делегата
//реализовать функцию по удалению всех повторяющихся функций 
//в делегате(чтобы каждая функция встречалась только один раз)

//Делегат — это тип, который представляет ссылки на методы с 
//определённым списком параметров и типом возвращаемого значения.
//массив, который хранит указатели на функции
//Делегат - это функция, которая может выполнять другие функции и хранить (коробка для функций)

typedef int (*fp_int)(int, int); //указатель на функцию
typedef fp_int* parr; //массив указателей на функцию? (делегат?)

fp_int add_delegat(parr array_delegate, fp_int new_func, int size) {
	array_delegate = realloc(array_delegate, sizeof(fp_int) * (size + 1));
	array_delegate[size] = new_func;
	return array_delegate;
}

fp_int delete_delegat(parr array_delegate, fp_int new_func, int size) {
	for (size_t i = 0; i < size; i++)
	{
		if (array_delegate[i] == new_func) {
			//здесь i чему-то равен
			for (size_t j = i+1; j < size; j++)
			{
				fp_int temp;
				temp = array_delegate[j - 1];
				array_delegate[j - 1] = array_delegate[j];
				array_delegate[j] = temp;
			}
			array_delegate = realloc(array_delegate, sizeof(fp_int) * (size - 1));
			break;
		}
	}
	return array_delegate;
}

void start_all_fucntion(parr array_delegate, int size, int a, int b) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", array_delegate[i](a, b));
	}
}

parr get_distinct_parr(parr array_delegate, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (array_delegate[i] == array_delegate[j]) {
				//чтобы избежать исключительной ситуации, когда элемент, который нужно удалитьь стоит в конце
				if (j + 1 != size) {
					for (size_t k = j + 1; k < size; k++)
					{
						fp_int temp;
						temp = array_delegate[k - 1];
						array_delegate[k - 1] = array_delegate[k];
						array_delegate[k] = temp;
					}
				}
				array_delegate = realloc(array_delegate, sizeof(fp_int) * (size - 1));
				size -= 1;
			}
		}
	}
	return array_delegate;
}

int sum(int a, int b) {
	return a + b;
}

int razn(int a, int b) {
	return a - b;
}

int proiz(int a, int b) {
	return a * b;
}

void T3Z1() {
	parr array_delegate = malloc(0 * sizeof(fp_int));
	//тут происходит добавление
	array_delegate = add_delegat(array_delegate, sum, 0);
	array_delegate = add_delegat(array_delegate, sum, 0);
	array_delegate = add_delegat(array_delegate, razn, 1);
	array_delegate = add_delegat(array_delegate, razn, 1);
	array_delegate = add_delegat(array_delegate, proiz, 2);
	array_delegate = add_delegat(array_delegate, proiz, 2);
	array_delegate = add_delegat(array_delegate, razn, 3);
	array_delegate = add_delegat(array_delegate, proiz, 2);

	array_delegate = get_distinct_parr(array_delegate, 8);
	start_all_fucntion(array_delegate, 3, 10, 5);

	//тут происходит демонстрация добавления
	//start_all_fucntion(array_delegate, 3, 10, 5);
	////тут происходит удаление
	//array_delegate = delete_delegat(array_delegate, razn, 3);
	////тут происходит запуск всех функций
	//start_all_fucntion(array_delegate, 2, 10, 5);
}

