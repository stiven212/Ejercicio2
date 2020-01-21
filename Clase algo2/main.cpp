#include <iostream>

using namespace std;
const int Max = 100;
int a[Max];
int menu();

#include <fstream>

void ingres(int tam);
void muestra(int tam);
void orden(int tam);
void imprim (int tam);

int main()
{
    int op, tam;


    op = menu();
    while (op != 0)
    {
        switch (op)
        {
    case 1:
        {
        cout << "ingrese el tamaño del arreglo: ";
        cin >> tam;
           ingres(tam);

        }
        break;
       case 2:
        {
            cout << "Los valores son: " << endl;
            muestra(tam);
        }
        break;
       case 3:
        {
            cout << "Los valores ordenados son: " << endl;
            orden(tam);
            imprim (tam);
        }
        break;
        }

         op = menu();
    }

    return 0;
}
void ingres(int tam)
{
    double y;
   for (int i = 0; i < tam; i++)
    {

        cout << "Ingrese " << i+1 << " valor: ";
        cin >> y;

        a[i] = y;
    }

}

void muestra(int tam)
{

    for (int i = 0; i < tam; i++)
    {
        cout << "|" << a[i] << "|" << " ";
    }
    cout << endl;
}

void orden(int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (a[i] > a[j])
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;

            }
        }
    }
}
void imprim (int tam)
{
	ofstream archivo;
	archivo.open("orden.txt");
	
    for (int i = 0; i < tam; i++)
    {
    	if(archivo.is_open()){
    		        cout << "|" << a[i] << "|" << " ";
					archivo << "|" << a[i] << "|" << " ";
		}
    }
    archivo.close();
    cout << endl;
}

int menu()
{
    int x = -1;
    while ((x < 0)||(x > 3))
    {
        cout << "------------Menu----------------" << endl;
        cout << "1 - Ingresar los elemntos" << endl;
        cout << "2 - Mostrar los elemntos" << endl;
        cout << "3 - vector ordenado" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: "<< endl;
        cin >> x;
    }
    return x;
}

