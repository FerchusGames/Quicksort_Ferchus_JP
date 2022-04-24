#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
#include "Libro.h"
#include "Menu.h"
#include "Quicksort.h"

int main()
{
	setlocale(LC_ALL, "spanish");
	Libro libros[MAX];
	menu(libros);
}

