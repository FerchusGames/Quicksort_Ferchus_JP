#include "Quicksort.h"

void quickSort(Libro libros[], int ini, int fin)
{
	if (ini < fin) // Caso base de recursividad
	{
		int pivote, izq, der;
		Libro temp = libros[ini]; // Para poder hacer el cambio de estructuras
		pivote = temp.isbn; // Número a comparar

		izq = ini;
		der = fin;

		while (izq < der) // Se repetirá hasta que los números se encuentren
		{
			while (der > izq && libros[der].isbn > pivote) // Recorre de derecha a izquierda hasta encontrar un numero menor del lado derecho 
				der--;
			if (der > izq) // Checa que no se hayan cruzado
			{
				libros[izq] = libros[der];				
				izq++;
			}

			while (izq < der && libros[izq].isbn < pivote) // Recorre de derecha a izquierda hasta encontrar un numero mayor del lado izquierdo
				izq++;
			if (izq < der) // Checa que no se hayan cruzado
			{
				libros[der] = libros[izq];
				der--;
			}
		}

		libros[der] = temp; // Ponemos la estructura con el pivote en su posición correcta

		quickSort(libros, ini, der - 1);
		quickSort(libros, der + 1, fin);
	}
}