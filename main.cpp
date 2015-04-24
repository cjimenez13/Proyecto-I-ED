#include <iostream>
# include <winbgim.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Movements.h"
using namespace std;
void menuAux(Movements turtle){
    turtle.MenuInstructions();
    //turtle.refreshTurtle();
    //menuAux(turtle);
}
void Menu(){
    cout<<"******************************************************"<<endl;
    cout<<"**                      Bienvenido                  **"<<endl;
    cout<<"******************************************************"<<endl;
    cout<<"**     Este programa es un graficador de figuras    **"<<endl;
    cout<<"******************************************************"<<endl;
}

int main () {
    Movements turtle;
    Menu();
    while(!kbhit()){
    turtle.MenuInstructions();
    turtle.refreshTurtle();
    }
    //turtle.MenuInstructions();
//    hola.readFile("example1.txt");
 //   hola.exec();
//    hola.writeFile("example1.txt");
//hola.seTColor();

////    int distancia1;
////    cin >> distancia1;
////    hola.setHeading(100);
// hola.Turtle();
//////    hola.Pos();
 //  hola.moveForward(100);
//////    hola.Pos();
////hola.historyI();
    //hola.analizeInstructions("write 5 \"hola soy la tortuga\"");
// hola.moveLeft(45);
// hola.Turtle();
//
////    hola.Pos();
//
////    hola.Pos();
////    hola.pen();
////    hola.write(5,"TE AMO CHRISTIAN");
////    hola.seTColor(3);
    //hola.analizeInstructions("repeat 3 [color blue forward 100 color yellow left 90 forward 100]");

//    hola.analizeInstructions("left 30");
    //hola.analizeInstructions("Left 45");
    //hola.analizeInstructions("forward 100");
    //hola.refreshTurtle();

////     hola.Turtle();
//    hola.analizeInstructions("Forward 100");
//  hola.refreshTurtle();
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
