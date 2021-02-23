// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
using namespace std;

int prefix_find(char*, char*, size_t*);
int length(char*);

int main()
{
	
	char stroka[]="“We were together. I forget the rest.” - Walt Whitman“Soul meets soul on lovers' lips.” - Percy Bysshe Shelley“In all the world, there is no heart for me like yours.” - Maya Angelou“Love is like the wind, you can't see it but you can feel it.” - Nicholas Sparks“I loved her and I loved no one else and we had a lovely magic time while we were alone.” - Ernest Hemingway“You are my today and all of my tomorrows.“ - Leo Christopher“When we are in love, we open to all that life has to offer with passion, excitement, and acceptance.“ - John Lennon“Love makes you want to be better. But maybe love, real love, also gives you permisq";
	char podstroka[]="love";
	size_t *pi=new size_t[length(podstroka)];
	//cin >> stroka;
	//cin >> podstroka;
	int index= prefix_find(stroka, podstroka, pi);
	if (index >= 0) {
		printf("%d\n", index);
	}
	return 0;
}
// пример функции обработки, которая выводит индекс начала найденного образца
int f(size_t i)
{
	printf("%d\n", i);
	return 1;
}
// str строка поиска.
// obr образец, который ищем.
// pi массив длин префиксов для образца (минимум  сколько символов в образце).
// int f(size_t i) когда образец найден, вызывается эта функция, 
// ей передается индекс начала найденного в str образца.
// функция возвращает 0, если надо прекратить поиск и 1, если надо продолжить.
int prefix_find(char* str, char* obr, size_t* pi)//, int(*f)(size_t))
{
	pi[0] = 0;     // в i-м элементе (его индекс i-1) количество совпавших 
				   // символов в начале образца и в конце подстроки длины i. 
				   // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых 
	size_t l;    // будет длина образца
				 // заполняем массив длин префиксов для образца
	int count1 = 0, count2 = 0;
	for (l = 1; obr[l]; ++l)
	{
		size_t j = pi[l - 1];
		count1++;
		while ((j > 0) && (obr[l] != obr[j])) // не равны
		{
			j = pi[j - 1];	         // берем ранее рассчитанное значение (начиная с максимально возможных)
			count1++;
		}
			
		if (obr[l] == obr[j])      // равны 
			++j;
		pi[l] = j;
	}
	size_t j = 0; // количество совпавших символов, оно же индекс сравниваемого 
				  // символа в образце. В строке сравниваемый символ будет иметь индекс i
	for (size_t i = 0; str[i]; ++i)
	{
		count1++;
		while ((j > 0) && (str[i] != obr[j])) {
			// Очередной символ строки не совпал с символом в образце. Сдвигаем образец, 
// причем точно знаем, что первые j символов образца совпали с символами строки 
// и надо сравнить j+1й символ образца (его индекс j) с i+1м символом строки.
			j = pi[j - 1];    // если j=0, то достигли начала образца и цикл следует прервать
			count1++;
		}
		
		if (str[i] == obr[j]) // есть совпадение очередного символа 
			++j;              // увеличиваем длину совпавшего фрагмента на 1
		if (j == l)
			if (!f(i - l + 1)) // образец найден, вызовем функцию обработки
				return -1;  // и выйдем из процедуры, если она вернет 0. 
	}
	return count1;
}

int length(char* str) {
	int n=0;
	for(int i = 0; str[i] != '\0'; i++) {
		n++;
	}
	return n;
}

