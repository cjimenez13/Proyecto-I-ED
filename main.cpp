#include <iostream>
# include <winbgim.h>
#include <stdio.h>
#include <stdlib.h>
#include "Movements.h"
using namespace std;
void Menu(){
    cout<<"******************************************************"<<endl;
    cout<<"**                      Bienvenido                  **"<<endl;
    cout<<"******************************************************"<<endl;
    cout<<"**     Este programa es un graficador de figuras    **"<<endl;
    cout<<"******************************************************"<<endl;
    cout<<"** 1. Interraccion directa con el usuario           **"<<endl;
    cout<<"** 2. Cargar instrucciones desde un archivo         **"<<endl;
    cout<<"\n"<<"** Elija una  opcion para iniciar la graficacion    **"<<endl;
    int opcion;
    cin>>opcion;
}

int main()
{
    Menu();


    cout<<"diga la distancia"<<endl;
    int distancia;
    cin>>distancia;
    Movements hola;
    hola.moveBack(distancia);
        hola.analizeInstructions("for 90");






//    int distancia1;
//    cin >> distancia1;
//    hola.setHeading(100);
//    hola.moveForward(distancia1);
//    hola.moveLeft(45);
//    hola.moveForward(distancia1);
               // setcolor(15);
//cout<<"soy x: "<<getx();
//cout<<"soy y: "<<gety();
//                line(30,30,80,80);
//cout<<"soy x: "<<getx();
//cout<<"soy y: "<<gety();
//                outtext("HOLA");

//                outtext(".....HOLA");
//                setlinestyle(1, 0, 1);
//                line(0, 0, 200, 300);

    //bar(40, 100, 200, 70);
    //bar3d (20, 100, 300, 90, 20, 20);
    //circle (150,150, 150);
    //ellipse (100, 100, 100, 100, 100,100);
    //fillellipse (100,200,100,100);
    int *punteros;
    //fillpoly (4,punteros);
    //floodfill (400,400,10);

    getch();


    closegraph();

    return 0;
}
