#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
	float precio;
	int menu, no, sn;
	char gen[30], clas[30];
	string articulo1, articulo2, articulo3, desc, cons;

	printf("BIENVENIDO A GAMERS \n");
	printf("1.Alta de articulos \n");
	printf("2.Modificacion de articulos \n");
	printf("3.Baja de articulos \n");
	printf("4.Lista de articulos \n");
    printf("5.Limpiar pantalla \n");
	printf("6.Salir \n");
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << "Ingrese los datos del articulo" << endl;
		cout << "No. de articulo" << endl;
		cin >> no;

		cout << "Nombre del articulo" << endl;
		cin.ignore();
		getline(cin, articulo1);

		cout << "Descripcion o reseña" << endl;
		cin.ignore();
		getline(cin, desc);

		cout << "Genero" << endl;
		cin >> gen;

		cout << "Clasificacion de edad" << endl;
		cin >> clas;

		cout << "Consola" << endl;
		cin.ignore();
		getline(cin, cons);

		cout << "Precio" << endl;
		cin >> precio;

		precio = precio + (precio * 0.16);

		cout << "No." << no << endl;
		cout << articulo1 << endl;
		cout << "Descripcion: " << desc << endl;
		cout << "Genero: " << gen << endl;
		cout << "Clasificacion: " << clas << endl;
		cout << "Consola: " << cons << endl;
		cout << "$" << precio << endl;
		cout << "Desea agregar otro articulo? 1.Si 2.No" << endl;
		cin >> sn;
		if (sn == 1)
		{
			return main();
		}
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		system("cls");
		return main();
		break;

	case 6:
		system("exit");
		break;

	default:
		cout << "Opcion invalida" << endl;
		return main();
		break;
	}
}