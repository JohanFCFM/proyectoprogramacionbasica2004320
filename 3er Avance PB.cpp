#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Videojuego
{
	int num_articulo;
	int lanzamiento;
	string nombre;
	string descripcion;
	string genero;                      //Declaracion de variables de la estructura
	string clasificacion_edad;
	string consola;
	string status;
	float precio;
	float precioiva;
};
int alta;

Videojuego* Tienda; // Estructura con punteros
void Alta();
void Eliminar();
void Listas();
void Modificar();
void Archivos();

int main()         //Funcion principál para mostrar el menu principal y los casos de cada funcion void
{
	int opc;
	printf("BIENVENIDO A GAMERS \n");
	printf("1. Alta de articulos \n");
	printf("2. Lista de articulos \n");
	printf("3. Limpiar pantalla \n");
	printf("4. Modificar articulos \n");
	printf("5. Eliminar articulos \n");
	printf("6. Archivos \n");
	printf("7. Salir \n");
	scanf_s("%d", &opc);

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		Listas();
		return main();
		break;

	case 3:
		system("cls");
		return main();
		break;

	case 4:
		Modificar();
		return main();
		break;

	case 5:
		Eliminar();
		return main();
		break;

	case 6:
		Archivos();
		break;

	case 7:
		system("exit");
		break;
	}
}
void Alta()
{
	int n = 1;
	printf("Ingrese la cantidad de registros a dar de alta \n");
	scanf_s("%d", &alta);
	Tienda = new Videojuego[alta]; // uso de new para hacer el arreglo de la estructura dinamico
	for (int i = 0; i < alta; i++)
	{

		printf("Introduzca el numero del articulo: \n");
		scanf_s("%d", &Tienda[i].num_articulo);

		do
		{
			if (Tienda[i].num_articulo != Tienda[i - 1].num_articulo)
			{
				n = n + 1;
			}
			else
			{
				printf("el articulo ya existe\n");
				printf("Ingrese el articulo\n");
				scanf_s("%d", &Tienda[i].num_articulo);
			}
		} while (n < alta);

		printf("Introduzca la fecha de lanzamiento del articulo: \n");
		scanf_s("%d", &Tienda[i].lanzamiento);

		printf("Introduzca el nombre del articulo: \n");
		cin.ignore();
		getline(cin, Tienda[i].nombre);

		printf("Introduzca la descripcion del articulo: \n");
		getline(cin, Tienda[i].descripcion);

		printf("Introduzca el genero del articulo: \n");
		getline(cin, Tienda[i].genero);

		printf("Introduzca la clasificacion de edad del articulo: \n");
		getline(cin, Tienda[i].clasificacion_edad);

		printf("Introduzca la consola del articulo: \n");
		getline(cin, Tienda[i].consola);

		printf("Introduzca el precio del articulo: \n");
		scanf_s("%f", &Tienda[i].precio);
		Tienda[i].precioiva = Tienda[i].precio + (Tienda[i].precio * 0.16); //Impuesto IVA agregado al precio base del producto

	}
}

void Listas()
{
	int op2, busqueda;
	string busc;

	printf("Buscar por \n 1.-clasificacion \n 2.-Genero \n 3.- Lanzamiento \n 4.- Salir \n");
	scanf_s("%d", &op2);
	switch (op2)
	{
	case 1:
		printf("Ingrese la clasificacion de edad a buscar\n");   //Filtro de busqueda por edad
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < alta; i++)
		{
			if (Tienda[i].status == "ELIMINADO")
			{
				printf("REGISTRO ELIMINADO %d \n", i + 1);
			}
			else
			{
				if (Tienda[i].clasificacion_edad == busc)
				{
					if (Tienda[i].num_articulo != 0)
					{
						printf("Registro %d \n", i + 1);
						printf("Lanzamiento: %d \n", Tienda[i].lanzamiento);
						printf("Numero de articulo: %d \n", Tienda[i].num_articulo);
						printf("Nombre: %s \n", Tienda[i].nombre.c_str());
						printf("Descripcion: %s \n", Tienda[i].descripcion.c_str());
						printf("Genero: %s \n", Tienda[i].genero.c_str());
						printf("Clasificacion de edad: %s \n", Tienda[i].clasificacion_edad.c_str());
						printf("Consola: %s \n", Tienda[i].consola.c_str());
						printf("Precio con IVA: $ %f \n", Tienda[i].precioiva);
					}
				}
			}
		}
		return Listas();
		break;

	case 2:
		printf("Ingrese el genero a buscar\n");   //Filtro de busqueda por genero
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < alta; i++)
		{
			if (Tienda[i].status == "ELIMINADO")
			{
				printf("REGISTRO ELIMINADO %d \n", i + 1);
			}
			else
			{
				if (Tienda[i].genero == busc)
				{
					if (Tienda[i].num_articulo != 0)
					{
						printf("Registro %d \n", i + 1);
						printf("Lanzamiento: %d \n", Tienda[i].lanzamiento);
						printf("Numero de articulo: %d \n", Tienda[i].num_articulo);
						printf("Nombre: %s \n", Tienda[i].nombre.c_str());
						printf("Descripcion: %s \n", Tienda[i].descripcion.c_str());
						printf("Genero: %s \n", Tienda[i].genero.c_str());
						printf("Clasificacion de edad: %s \n", Tienda[i].clasificacion_edad.c_str());
						printf("Consola: %s \n", Tienda[i].consola.c_str());
						printf("Precio con IVA: $ %f \n", Tienda[i].precioiva);

					}

				}
			}
		}
		return Listas();
		break;

	case 3:
		printf("Ingrese la fecha de lanzamiento a buscar\n");     //Filtro de busqueda por lanzamiento
		scanf_s("%d", &busqueda);
		for (int i = 0; i < alta; i++)
		{
			if (Tienda[i].status == "ELIMINADO")
			{
				printf("REGISTRO ELIMINADO %d \n", i + 1);
			}
			else
			{
				if (Tienda[i].lanzamiento == busqueda)
				{
					if (Tienda[i].num_articulo != 0)
					{
						printf("Registro %d \n", i + 1);
						printf("Lanzamiento: %d \n", Tienda[i].lanzamiento);
						printf("Numero de articulo: %d \n", Tienda[i].num_articulo);
						printf("Nombre: %s \n", Tienda[i].nombre.c_str());
						printf("Descripcion: %s \n", Tienda[i].descripcion.c_str());
						printf("Genero: %s \n", Tienda[i].genero.c_str());
						printf("Clasificacion de edad: %s \n", Tienda[i].clasificacion_edad.c_str());
						printf("Consola: %s \n", Tienda[i].consola.c_str());
						printf("Precio con IVA: $ %f \n", Tienda[i].precioiva);

					}

				}
			}
		}
		return Listas();
		break;

	case 4:
		break;
	}
}
void Eliminar()
{
	int j;
	printf("ingrese el registro a eliminar \n");
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i <= j; i++)
	{
		printf("Eliminando registro %d \n", j + 1);
		Tienda[i].status = "ELIMINADO";

	}
}
void Modificar()
{
	int j, opcion, op2;
	do
	{
		printf("ingrese el numero del registro a modificar \n");
		scanf_s("%d", &j);
		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++)
		{
			if ((Tienda[i].status == "ELIMINADO"))
			{
				printf("Registro Eliminado %d \n", i + 1);
				printf("ingrese un registro valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("Ingrese que desea modificar \n");
	printf("1.-Numero de articulo \n");
	printf("2.-Fecha de lanzamiento \n");
	printf("3.-Nombre de articulo \n");
	printf("4.-Descripcion de articulo \n");
	printf("5.-Genero de articulo \n");
	printf("6.-Clasificacion de edad \n");
	printf("7.-Consola \n");
	printf("8.-Precio \n");

	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el numero del articulo \n");
			scanf_s("%d", &Tienda[i].num_articulo);
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese la fecha de lanzamiento del articulo \n");
			scanf_s("%d", &Tienda[i].lanzamiento);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');   //se vacia el buffer o el espacio
			printf("Ingrese el nombre del articulo \n");
			getline(cin, Tienda[i].nombre);
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese la descripcion del articulo \n");
			getline(cin, Tienda[i].descripcion);
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el genero del articulo \n");
			getline(cin, Tienda[i].genero);
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese la clasificacion de edad del articulo \n");
			getline(cin, Tienda[i].clasificacion_edad);
		}
		break;

	case 7:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese la consola del articulo \n");
			getline(cin, Tienda[i].consola);
		}
		break;

	case 8:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el precio del articulo \n");
			scanf_s("%f", &Tienda[i].precio);
			Tienda[i].precioiva = Tienda[i].precio + (Tienda[i].precio * 0.16);
		}
		break;

	default:
		printf("Registro invalido ingrese de nuevo \n");
		return Modificar();
		break;

	}


}

void Archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2;
	float texto3;

	nombrearchivo = "altastienda.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO \n");
		exit(1);
	}

	archivo << "NUMERO" << "\t";
	archivo << "LANZAMIENTO" << "\t";
	archivo << "NOMBRE" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "GENERO" << "\t";
	archivo << "CLASIFICACION" << "\t";
	archivo << "CONSOLA" << "\t";
	archivo << "PRECIO" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (Tienda[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = Tienda[i].num_articulo;
			archivo << texto << "\t" << "\t";
			texto = Tienda[i].lanzamiento;
			archivo << texto << "\t" << "\t";
			texto2 = Tienda[i].nombre;
			archivo << texto2 << "\t" << "\t";
			texto2 = Tienda[i].descripcion;
			archivo << texto2 << "\t " << "\t";         //Uso de tabuladores para dar formato al archivo
			texto2 = Tienda[i].genero;
			archivo << texto2 << "\t " << "\t";
			texto2 = Tienda[i].clasificacion_edad;
			archivo << texto2 << "\t " << "\t";
			texto2 = Tienda[i].consola;
			archivo << texto2 << "\t " << "\t";
			texto3 = Tienda[i].precioiva;
			archivo << texto3 << "\t " << "\n";
		}
	}
	archivo.close();
}