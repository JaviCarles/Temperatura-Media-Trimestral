/*
Se desea saber la temperatura media trimestral de cuatro paises pequeños. Para ello se tiene como dato las temperaturas medias mensuales de dichos paises.
Se debe ingresar el nombre del país y seguidamente las tres temperaturas medias mensuales.
Seleccionar las estructuras de datos adecuadas para el almacenamiento de los datos en memoria.
a - Cargar por teclado los nombres de los países y las temperaturas medias mensuales.
b - Imprimir los nombres de los países y las temperaturas medias mensuales de las mismas.
c - Calcular la temperatura media trimestral de cada país.
d - Imprimir los nombres de los países y las temperaturas medias trimestrales.
e - Imprimir el nombre del país con la temperatura media trimestral mayor. */

#include<iostream>
using namespace std;

class TempMediaTrimestral {
private:
    char pais[4][25];
    float tresTemperaturas[4][3];
    float tempTrimestral[4];
public:
    void carga();
    void imprimirTempMensual();
    void calculoTrimestral();
    void impriTempTrimestral();
    void tempMayor();
};

void TempMediaTrimestral::carga()
{   for(int f=0; f<4; f++)
    {   cout<<"\nIngrese nombre del País :";
        cin.get(pais[f],25);
        for(int c=0; c<3; c++)
        {   cout<<"Ingrese temperatura media mensual del mes "<<c+1;
            cin>>tresTemperaturas[f][c];
        }
        cin.get();
    }
}

void TempMediaTrimestral::imprimirTempMensual()
{   cout<<"\nPaíses y sus temperaturas medias mensuales :\n";
    for(int f=0; f<4; f++)
    {   cout<<"\n"<<pais[f]<<": ";
        for(int c=0; c<3; c++)
        {   cout<<tresTemperaturas[f][c];
            if(c<2)
            {   cout<<" - ";
            }
        }
    }
}

void TempMediaTrimestral::calculoTrimestral()
{   float prom;
    for(int f=0; f<4; f++)
    {   float suma=0;
        for(int c=0; c<3; c++)
        {
            suma=suma+tresTemperaturas[f][c];
        }
        prom=suma/3;
        tempTrimestral[f]=prom;
    }
}

void TempMediaTrimestral::impriTempTrimestral()
{   for(int f=0; f<4; f++)
    {   cout<<"\nLa temperatura media trimestral de "<<pais[f]<<" es: "<<tempTrimestral[f];
    }
}

void TempMediaTrimestral::tempMayor()
{   float may=tempTrimestral[0];
    int p=0;
    for(int f=1; f<4; f++)
    {   if(may<tempTrimestral[f])
        {   may=tempTrimestral[f];
            p=f;
        }
    }
    cout<<"\nEl país con mayor temperatura media trimestral es: "<<pais[p];
}

int main()
{
    TempMediaTrimestral tempe;
    tempe.carga();
    tempe.imprimirTempMensual();
    tempe.calculoTrimestral();
    tempe.impriTempTrimestral();
    tempe.tempMayor();
    return 0;
}
