#ifndef MOVEMENTS_H
#define MOVEMENTS_H
#define PI 3.14159265
#include <math.h>
#include <iostream>
# include <winbgim.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Movements
{
    private:
        bool pencilDown=true;
        int grades;
        int x=450;
        int y=350;
    public:
        Movements() {
            initwindow (900,700);
            grades=135;
            moveto (x,y);
        }
        ~Movements() {}

        void Delete(){
            getch();
            closegraph();
        }
        int seno(int alpha, int distance){
            return (int)(distance * sin(alpha*PI/180));
        }
        int coseno(int alpha, int distance){
            return (int)(distance * cos(alpha*PI/180));
        }

        void moveForward(int pDistance){
            int x=getx();
            int y=gety();
            int color= getcolor();
            if (grades>=360){
                grades=grades%360;
            }
            switch(grades){
            case 0:
                {
                    x+=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            case 90:
                {
                    y-=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            case 180:
                {
                    x-=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            case 270:
                {
                    y+=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            default:
                {

                if (grades>0&&grades<90){
                    int xNext= coseno(grades,pDistance);
                    int yNext= seno(grades,pDistance);
                    x+=(xNext);
                    y-=(yNext);
                    }
                if (grades>90&&grades<180){
                    int xNext= coseno(grades-90,pDistance);
                    int yNext= seno(grades-90,pDistance);
                    x-=(xNext);
                    y-=(yNext);
                    }

                if (grades>180&&grades<270){
                    int xNext= coseno(grades-180,pDistance);
                    int yNext= seno(grades-180,pDistance);
                    x-=(xNext);
                    y+=(yNext);
                    }
                if (grades>270&&grades<360){
                    int xNext= coseno(grades-270,pDistance);
                    int yNext= seno(grades-270,pDistance);
                    x+=(xNext);
                    y+=(yNext);
                    }
                if(pencilDown==true){
                    line(getx(),gety(),x,y);
                }
                moveto(x,y);
                }
            }

            Delete();
        }
void moveBack(int pDistance){
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
                    x-=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            case 90:
                {
                    y+=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            case 180:
                {
                    x+=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            case 270:
                {
                    y-=pDistance;
                    if (pencilDown==true){
                        line(getx(),gety(),x,y);
                    }
                    moveto(x,y);
                }break;
            default:
                {
                if (grades>0&&grades<90){
                    int xNext= coseno(grades,pDistance);
                    int yNext= seno(grades,pDistance);
                    x-=(xNext);
                    y+=(yNext);
                    }

                if (grades>90&&grades<180){
                    int xNext= coseno(grades-90,pDistance);
                    int yNext= seno(grades-90,pDistance);
                    x+=(xNext);
                    y+=(yNext);
                    }
                if (grades>180&&grades<270){
                    int xNext= coseno(grades-180,pDistance);
                    int yNext= seno(grades-180,pDistance);
                    x+=(xNext);
                    y-=(yNext);
                    }
                if (grades>270&&grades<360){
                    int xNext= coseno(grades-270,pDistance);
                    int yNext= seno(grades-270,pDistance);
                    x-=(xNext);
                    y-=(yNext);
                    }
                line(getx(),gety(),x,y);
                moveto(x,y);
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
        if (pencilDown==true){
            line(getx(),gety(),pCoorX,pCoorY);
        }
        moveto (pCoorX,pCoorY);
}


};

#endif // MOVEMENTS_H
