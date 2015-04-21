#include <iostream>
# include <winbgim.h>
#include <stdio.h>
#include <string.h>
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






bool writeFile(const char* pFilePath){
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
    return true;
    }else {
        cout << "Unable to open file";
        return false;
    }
}

////    Menu();
////    cout<<"diga la instruccion"<<endl;
////    string distancia;
////    cin.ignore();
////    getline(cin,distancia);
////    cout<<distancia;
//
//int main () {
    Movements hola();
    //hola.readFile("example.txt");
hola.seTColor();
////    int distancia1;
////    cin >> distancia1;
////    hola.setHeading(100);
//   // hola.Turtle();
////    hola.Pos();
//    hola.moveForward(100);
////    hola.Pos();
//hola.historyI();
//    hola.analizeInstructions(distancia);
//   // hola.moveLeft(45);
//   // hola.Turtle();
//
////    hola.Pos();
//
////    hola.Pos();
////    hola.pen();
////    hola.write(5,"TE AMO CHRISTIAN");
////    hola.seTColor(3);
//    hola.moveForward(100);
////    hola.moveLeft(45);
//       hola.moveForward(distancia);
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
//    //fillellipse (100,200,100,100);
//    int *punteros;
//    //fillpoly (4,punteros);
//    //floodfill (400,400,10);
//
    getch();


    closegraph();

    return 0;
}
