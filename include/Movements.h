#ifndef MOVEMENTS_H
#define MOVEMENTS_H
#include <iostream>
# include <winbgim.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Movements
{
    private:
        int grades;
        int x=450;
        int y=350;
    public:
        Movements() {
            initwindow (900,700);
            grades=390;
            moveto (x,y);


        }
        ~Movements() {}

        void Delete(){
            getch();
            closegraph();
        }

        void moveForward(int cantMove){
            int x=getx();
            cout<<"este x:"<<x;
            int y=gety();
            cout<<"  este y:"<<y;

            int color= getcolor();
            if (grades>=360){
                grades=grades%360;
            }
            switch(grades){
            case 0:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        x++;
                    }
                }break;
            case 90:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        y--;
                    }
                }break;
            case 180:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        x--;
                    }
                }break;
            case 270:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        y++;
                    }
                }break;
            default:
                if (grades>0&&grades<90){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x++;
                    y--;
                    }
                }
                if (grades>90&&grades<180){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x--;
                    y--;
                    }
                }
                if (grades>180&&grades<270){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x--;
                    y++;
                    }
                }
                if (grades>270&&grades<360){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x++;
                    y++;
                    }
                }
            }

            Delete();
        }
void moveBack(int cantMove){
            int x=getx();
            cout<<"este x:"<<x;
            int y=gety();
            cout<<"  este y:"<<y;

            int color= getcolor();
            if (grades>=360){
                grades=grades%360;
            }
            switch(grades){
            case 0:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        x--;
                    }
                }break;
            case 90:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        y++;
                    }
                }break;
            case 180:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        x++;
                    }
                }break;
            case 270:
                {
                    for(int m=0;m<=cantMove;m++){
                        putpixel (x,y,color);
                        y--;
                    }
                }break;
            default:
                if (grades>0&&grades<90){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x--;
                    y++;
                    }
                }
                if (grades>90&&grades<180){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x++;
                    y++;
                    }
                }
                if (grades>180&&grades<270){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x++;
                    y--;
                    }
                }
                if (grades>270&&grades<360){
                    for(int m=0;m<=cantMove;m++){
                    putpixel (x,y,color);
                    x--;
                    y--;
                    }
                }
            }

            Delete();
        }
void moveRight(int pGrades){
    if (grades==0){
        grades=360;
        grades-=pGrades;
    }
    if (pGrades>grades){
        int temp= pGrades-grades;
        grades=360;
        grades-=temp;
    }else{
        grades-=pGrades;
    }
}
void moveLeft(int pGrades){
    grades+=pGrades;
}
void setPos(int pCoorX,int pCoorY){
//    if (pencil==true){
//        int x=getx();
//        int y=gety();
//        //pCoorX=
//    }
    moveto (pCoorX,pCoorY);
}


};

#endif // MOVEMENTS_H
