#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <atlalloc.h> 

void cut(int start, int end, int text_len, char *text)
{
	int i = start; //начальная позиция символа для обрезания
	int cut_len = end - start; // длина обрезания
	for (i; i < text_len - cut_len; i++) //Заменить цикл фо на вайл != "\0"
		*(text + i) = *(text + i + cut_len); //Сдвигаем элементы массива на место вырезанной части

	*(text + text_len - cut_len) = '\0'; //Добавляем символ конца строки
}

int find_char(int start, int lenght, char sign, char *text)
{
	int i = 0;
	for (i = start; i < lenght; i++)
	{
		if (sign == *(text + i))
			return i; // возвращает позицию символа
	}
	return -1; //символа в тексте нет

}

int main()
{

	FILE * file = fopen("file.txt", "r");

	int i = 0;

	char * text = NULL; //Переменная для хранения нашего текста
	char * temp = NULL; //Вспомогательная переменная

	int c, num_sign = 0;
	while ((c = fgetc(file)) != EOF) { //Пока не конец файла
		num_sign++; //Увеличиваем количество символов в тесте на 1
		temp = (char*)realloc(text, num_sign * sizeof(char)); // при считывании нового символа, увеличиваем массив на 1
		if (temp != NULL)
		{
			text = temp;  		
			text[num_sign - 1] = c; // добавляем к массиву символов (тексту) считанный символ
		}
		else  
		{
			free(temp); // удалить массив
			printf("Error! \n");
			return 0;
		}
	}
	printf("Text from file: \n");
	for (int i = 0; i < num_sign; i++)
		printf("%c", *(temp + i)); //Выводим посимволно текст
	printf("\n");


	char M = 'M'; //Символ, который нам нужен
	int len = num_sign; //число символов в тесте
	int sign_pos[3] = {0}; //Массив позиций символа
	sign_pos[0] = find_char(0, len, M, text);
	sign_pos[1] = find_char(sign_pos[0] + 1, len, M, text);
	sign_pos[2] = find_char(sign_pos[1] + 1, len, M, text);

	if (sign_pos[0] == -1 || sign_pos[1] == -1 || sign_pos[2] == -1) //Если символ не встречается в тексте 3 раза
	{
		printf("error! \n");
		system("pause");
		return 0;
	}
	cut(sign_pos[0], sign_pos[2], len, text); //Обрезаем
	printf("\nEditedText: %s\n", text); //Печатаем готовый текст

	system("pause");
	return 0;
}
