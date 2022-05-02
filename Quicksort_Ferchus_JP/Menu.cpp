#include "Menu.h"

void menu(Libro libros[])
{
	int select;

	system("CLS");
	std::cout << "Bienvenido a la librería Amerike, ¿Qué es lo que quieres hacer?" << std::endl << std::endl;

	std::cout << "1. Donar libros." << std::endl;
	std::cout << "2. Mostrar libros." << std::endl;
	std::cout << "3. Ordenar libros." << std::endl;
	std::cout << "4. Buscar un libro por ISBN." << std::endl;
	std::cin >> select;

	switch (select)
	{
		case 1:
			llenarArreglo(libros);
			break;

		case 2:
			mostrarArreglo(libros);
			break;

		case 3:
			quickSort(libros, 0, MAX - 1);
			system("CLS");
			std::cout << "Tus libros han sido ordenados por ISBN\n\nPresiona enter para volver al menú.";
			std::cin.ignore();
			std::cin.get();
			menu(libros);
			break;
		case 4:
			buscarLibro(libros);
			break;
		case 5:
			std::cout << "¡Gracias, tenga un gran día!" << std::endl;
			break;

		default:
			system("CLS");
			std::cout << "Opción inválida. Presione enter para intentar de nuevo" << std::endl;
			std::cin.ignore();
			std::cin.get();
			menu(libros);
			
	}
}

void llenarArreglo(Libro libros[])
{
	system("CLS");
	for (int i = 0; i < MAX; i++)
	{
		std::cout << "Libro [" << i << "]: " << std::endl << std::endl;
		std::cout << "ISBN: ";
		std::cin >> libros[i].isbn;
		std::cin.ignore();
		std::cout << "Nombre: ";
		std::getline(std::cin, libros[i].nombre);
		std::cout << "Autor: ";
		std::getline(std::cin, libros[i].autor);
		std::cout << "N. Páginas: ";
		std::cin >> libros[i].nPaginas;
		std::cout << std::endl;
	}
	system("CLS");
	std::cout << "¡Gracias por donar!\n\nPresiona enter para volver al menú.";
	std::cin.ignore();
	std::cin.get();
	menu(libros);
}

void mostrarArreglo(Libro libros[])
{
	system("CLS");
	for (int i = 0; i < MAX; i++)
	{
		std::cout << "Libro [" << i << "]: " << std::endl << std::endl;
		std::cout << "ISBN: " << libros[i].isbn << std::endl;
		std::cout << "Nombre: " << libros[i].nombre << std::endl;
		std::cout << "Autor: " << libros[i].autor << std::endl;
		std::cout << "N. Páginas: " << libros[i].nPaginas << std::endl << std::endl;
	}
	std::cout << "Presiona enter para volver al menu.";
	std::cin.ignore();
	std::cin.get();
	menu(libros);
}

void buscarLibro(Libro libros[])
{
	int isbnBuscar, inf = 0, sup = (MAX - 1), mitad;
	system("cls");
	std::cout << "Escriba el ISBN del libro que quiere buscar: ";
	std::cin >> isbnBuscar;
	std::cout << std::endl;
	while (inf <= sup)
	{
		mitad = (inf + sup) / 2;
		if (libros[mitad].isbn == isbnBuscar)
		{
			std::cout << "El ISBN proporcionado está ligado al libro: " << libros[mitad].nombre << ".\nCuyo autor es: " << libros[mitad].autor << ".\nY tiene: " << libros[mitad].nPaginas << " número de páginas." << std::endl;
			break;
		}
		if (libros[mitad].isbn > isbnBuscar)
		{
			sup = mitad - 1;
			mitad = (inf + sup) / 2;
		}
		if (libros[mitad].isbn < isbnBuscar)
		{
			inf = mitad + 1;
			mitad = (inf + sup) / 2;
		}
	}

	if (libros[mitad].isbn != isbnBuscar) std::cout << "No existe un libro con ese ISBN" << std::endl << std::endl;

	std::cout << "Presiona enter para volver al menu.";
	std::cin.ignore();
	std::cin.get();
	menu(libros);
}


