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
            grades=300;
            moveto (x,y);
        }
        ~Movements() {}

        void Delete(){
            getch();
            closegraph();
        }
        int seno(int pAlpha, int pDistance){
            return (int)(pDistance * sin(pAlpha*PI/180));
        }
        int coseno(int pAlpha, int pDistance){
            return (int)(pDistance * cos(pAlpha*PI/180));
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

            //Delete();
        }
void moveBack(int pDistance){
            int color= getcolor();
            if (grades>=360){
                grades=grades%360;
            }
            int tempGrades = grades;
            cout << grades << endl;
            grades += 180;
            moveForward(pDistance);
            grades = tempGrades;
            cout << grades << endl;
            //Delete();
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
void setHeading(int pGrades){
    if (pGrades>=360){
        grades = pGrades%360;
    }else{
        grades = pGrades;
    }
}
void analizeInstructions(string pInstruction){
    bool endWord = false;
    string instruction;
    int *parameters= new int[3];
    int posSpace = pInstruction.find_first_of(' ');
    if (posSpace != -1){
        instruction = pInstruction.substr(0,posSpace);
        String strParameters = pInstruction.substr(posSpace,pInstruction.length());
        for(int iChar=0; iChar != pInstruction.length(); iChar++){

            int temp=
            if (strParameters[iChar] == ' '){
                parameter[0] = (int)(strParameters.substr(0,iChar));

            }
        }
    }
    else{
        instruction = pInstruction;
    }
//    int param1;
//    int param2;
//    int posFirstSpace = pInstruction.find_first_of(' ');
//    cout << posFirstSpace << endl;
//    if (posSpace != -1){
//        instruction = pInstruction.substr(0,posFristSpace);
//        cout << instruction << endl;
//    }else{
//        int posSecondSpace = pInstruction.find_last_of(' ');
//        if (posFirstSpace != posSecondSpace){
//            param1 = (int)pInstruction.substr(posFirstSpace+1,);
//        }else{
//            param2 = (int)pInstruction.substr(posFirstSpace+1,20);
//        }
//    }

//    switch(instruction){
//        case "forward":
//    }
}


};

#endif // MOVEMENTS_H
