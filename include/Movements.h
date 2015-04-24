#ifndef MOVEMENTS_H
#define MOVEMENTS_H
#define PI 3.14159265
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
# include <winbgim.h>
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Movements
{
    private:
        bool pencilDown=true;
        int*colorRGB=new int [3];
        string color;
        int grosor;
        int grades;
        int coorX=450;
        int coorY=350;
        ArrayList <string> history;
        ArrayList <string> fileInstruction;
    public:
        Movements() {
            initwindow (900,700);
            grades=0;
            moveto (coorX,coorY);
            color="white";
            grosor=1;
            Turtle();
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
            coorX=x;
            coorY=y;
        }
void moveBack(int pDistance){
            int color= getcolor();
            if (grades>=360){
                grades=grades%360;
            }
            int tempGrades = grades;
            grades += 180;
            moveForward(pDistance);
            grades = tempGrades;
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
void setX(int pCoorX){
    coorX=pCoorX;
    moveto(coorX,coorY);
}
void setY(int pCoorY){
    coorY=pCoorY;
    moveto(coorX,coorY);
}
void setHeading(int pGrades){
    if (pGrades>=360){
        grades = pGrades%360;
    }else{
        grades = pGrades;
    }
}
void Home(){
        coorX=450;
        coorY=350;
        grades=0;
        moveto(coorX,coorY);
}
void Circle(int pRadio){
    circle(coorX,coorY,pRadio);
    int xx=coseno(grades,pRadio);
    int yy=seno(grades,pRadio);
    coorX+=xx;
    coorY+=yy;
    moveto(coorX,coorY);
}
void Pos(){
cout<< "La tortuga se encuentra en X= "<<getx()<<" y en Y= "<<gety()<<endl;
}
void xCor(){
cout<< "La tortuga se encuentra en X= "<<getx()<<endl;
}
void yCor(){
cout<< "La tortuga se encuentra en Y= "<<gety()<<endl;
}
void Heading(){
cout<< "La tortuga se encuentra con un rumbo de = "<<grades<<" grados"<<endl;
}
void penDown(){
pencilDown=true;
}
void penUp(){
pencilDown=false;
}
void PenSize(int pSize){
    setlinestyle (0,0,pSize);
    grosor=pSize;
}
void seTColor(int pColor){
    setcolor(pColor);
}
void setColors(int pUNO,int pDOS,int pTRES ){
    setcolor(COLOR(pUNO,pDOS,pTRES));
}
void pen(){
    cout<<"\n"<<"El estado del lapiz: ";
    if(pencilDown){
        cout<<"\n"<<"\t"<<"El lapiz esta abajo"<<endl;
    }else{
        cout<<"\n"<<"\t"<<"El lapiz esta inactivo"<<endl;
    }
    cout<<"\t"<<"El grosor es: "<<grosor<<endl;
    if (color.compare("no hay color string")==0){
        cout<<"\t"<< "El color actual es:\" ";
        for (int i=0;i!=3;i++){
            cout<<colorRGB[i]<<" ";
            }
        cout<<"\""<<endl;
    }else{
        cout<<"\t" <<"El color actual es: "<<color<<endl;
    }
}
void reset(){
    _clear();
    Home();
    color="white";
    grosor=1;
    penDown();
}
void _clear(){
cleardevice();
}
void write(int pSizeText,string pText){
    const char * text= pText.c_str();
    settextstyle(0,0,pSizeText);
    outtextxy (coorX,coorY,text);
}
void historyI(){
    history.printE();
}
void clearHistory(){
    history.Clear();
    cout <<"El historial ha sido borrado correctamente"<<endl;
}

int colorConversor(string pColor){
    if (pColor.compare("black")==0){
        return 0;
    }
    if (pColor.compare("blue")==0){
        return 1;
    }
    if (pColor.compare("green")==0){
        return 2;
    }
    if (pColor.compare("cyan")==0){
        return 3;
    }
    if (pColor.compare("red")==0){
        return 4;
    }
    if (pColor.compare("magenta")==0){
        return 5;
    }

    if (pColor.compare("brown")==0){
        return 6;
    }
    if (pColor.compare("lightgray")==0){
        return 7;
    }
    if (pColor.compare("darkgray")==0){
        return 8;
    }
    if (pColor.compare("lightblue")==0){
        return 9;
    }
    if (pColor.compare("lightgreen")==0){
        return 10;
    }
    if (pColor.compare("lightcyan")==0){
        return 11;
    }
    if (pColor.compare("lightred")==0){
        return 12;
    }
    if (pColor.compare("lightmagenta")==0){
        return 13;
    }
    if (pColor.compare("yellow")==0){
        return 14;
    }
    if (pColor.compare("white")==0){
        return 15;
    }else{
        return 16;
    }
}
void repeatInstruction(int pCantRepeat,string pInstructions){
    ArrayList<string> functions;
    string instruction;
    while(pInstructions.length()!=0){   1º
        int posSpace = pInstructions.find_first_of(" ");
        string _instruction;
        if (posSpace != -1){
            _instruction = convertToLowercase(pInstructions.substr(0,posSpace));
            pInstructions = pInstructions.substr(posSpace+1,pInstructions.length());
            if (_instruction.compare("forward")==0||_instruction.compare("back")==0||
                _instruction.compare("left")==0||_instruction.compare("right")==0
                ||_instruction.compare("sety")==0||_instruction.compare("setx")==0||
                _instruction.compare("setheading")==0||_instruction.compare("circle")==0||
                _instruction.compare("pensize")==0){
                string temp="";
                int posSpace1 = pInstructions.find_first_of(" ");
                if (posSpace1 != -1){
                    temp=_instruction+" "+pInstructions.substr(0,posSpace1);
                    functions.append(temp);
                    pInstructions=pInstructions.substr(posSpace1+1,pInstructions.length());
                }else{
                    temp=_instruction+" "+pInstructions.substr(0,pInstructions.length());
                    functions.append(temp);
                    pInstructions="";
                }
                }else{
                    if(_instruction.compare("write")==0){
                        int posSspace= pInstructions.find_first_of(" ");
                    string tempp=pInstructions.substr(0,posSspace);
                    int posComillaS=pInstructions.substr(posSspace+2,pInstructions.length()).find_first_of("\"");
                    tempp=_instruction+" "+pInstructions.substr(0,posComillaS+4);
                    functions.append(tempp);
                    int posSspacee=(pInstructions.substr(posComillaS+4,posComillaS+5)).find_first_of(" ");
                    if (posSspacee!=-1){
                                pInstructions=pInstructions.substr(posComillaS+5,pInstructions.length());
                            }else{
                                pInstructions="";
                            }

                    }else{
                        if(_instruction.compare("loadfile")==0){
                            pInstructions=pInstructions.substr(1,pInstructions.length());
                            int posComillas=pInstructions.find_first_of("\"");
                            string temp1=_instruction+" "+pInstructions.substr(0,posComillas);
                            functions.append(temp1);
                            int posSpacee=(pInstructions.substr(posComillas,posComillas+1)).find_first_of(" ");
                            if (posSpacee!=-1){
                                pInstructions=pInstructions.substr(posComillas+1,pInstructions.length());
                            }else{
                                pInstructions="";
                            }

                        }else{
                            if(_instruction.compare("color")==0){
                                const char * c = pInstructions.c_str();
                                string temP="";
                                if(isalpha(c[0])){
                                    int posSpacer=pInstructions.find_first_of(" ");
                                    temP=_instruction+" "+pInstructions.substr(0,posSpacer);
                                    functions.append(temP);
                                    if (posSpacer!=-1){
                                        pInstructions=pInstructions.substr(posSpacer+1,pInstructions.length());
                                    }else{
                                        pInstructions="";
                                    }
                                }else{
                                    int posSpacer1=pInstructions.find_first_of(" ");
                                    int posSpacer2=pInstructions.substr(posSpacer1+1,pInstructions.length()).find_first_of(" ");
                                    int posSpacer3=pInstructions.substr(posSpacer2+1,pInstructions.length()).find_first_of(" ");
                                    temP=_instruction+" "+pInstructions.substr(0,posSpacer3+4);
                                    functions.append(temP);
                                    if (posSpacer1!=-1){
                                        pInstructions=pInstructions.substr(posSpacer1+1,pInstructions.length());
                                    }else{
                                        pInstructions="";
                                    }

                                }

                            }
                        }
                    }
                }

            }else{
                functions.append(pInstructions);
                pInstructions="";
                break;
            }
        }
    for(int p=0;p!=pCantRepeat;p++){
        for(int y=0; y!=functions.getSize();y++){
            functions.goToPos(y);
            cout<<functions.getElement()<<endl;
            analizeInstructions(functions.getElement());
        }
    }

}
void exec(){
    for (int i=0;i!=fileInstruction.getSize();i++){
        fileInstruction.goToPos(i);
        analizeInstructions(fileInstruction.getElement());
    }
}
bool readFile(const char* pFile){
    fileInstruction.Clear();
    string line;
    ifstream myfile (pFile);
    if (myfile.is_open()){
        while(getline (myfile,line)){
            fileInstruction.append(line);
        }
    myfile.close();
    fileInstruction.printE();
    return true;
    }else {
        cout << "Unable to open file";
        return false;
    }
}
bool writeFile(const char* pFilePath){
    ofstream myfile (pFilePath);
    if (myfile.is_open())
    {
        for (int iLine = 0; iLine != fileInstruction.getSize(); iLine++){
            fileInstruction.goToPos(iLine);
            myfile << fileInstruction.getElement();
            myfile << "\n";
        }
    myfile.close();
    fileInstruction.goToStart();
    return true;
    }else {
        cout << "Unable to open file";
        return false;
    }
}
void refreshTurtle(){
    reset();
    ArrayList <string> arrayl;
    history.goToStart();
    for(int o=0;o!=history.getSize();o++){
            history.goToPos(o);
            if (history.getElement().compare("history")!=0 && history.getElement().compare("pen")!=0
                && history.getElement().compare("heading")!=0 && history.getElement().compare("ycor")!=0
                && history.getElement().compare("xcor")!=0 &&history.getElement().compare("pos")!=0)
            arrayl.append(history.getElement());
    }

    for(int i=0;i!=arrayl.getSize();i++){
        arrayl.goToPos(i);
        analizetorefresh(arrayl.getElement());
    }
    Turtle();
}

void Turtle(){
    int xPoint=coorX;
    int yPoint=coorY;
    int next_X= getx()+coseno(360-grades,15);
    int next_Y= gety()+seno(360-grades,15);
    fillellipse(xPoint,yPoint,13,13);
    ellipse(next_X,next_Y,0,360,7,7);
    ellipse(getx()+coseno((360-grades)-75,13),gety()+seno((360-grades)-75,13),0,360,4,4);
    ellipse(getx()+coseno((360-grades)+75,13),gety()+seno((360-grades)+75,13),0,360,4,4);
    ellipse(getx()+coseno((360-grades)-120,13),gety()+seno((360-grades)-120,13),0,360,4,4);
    ellipse(getx()+coseno((360-grades)+120,13),gety()+seno((360-grades)+120,13),0,360,4,4);
}

void analizeInstructions(string pInstruction){

    pInstruction=convertToLowercase(pInstruction);
//    history.append(pInstruction);
    bool endWord = false;
    string instruction;
    int *parameters= new int[3];
    string strParameters;
    int posSpace = pInstruction.find_first_of(" ");
    if (posSpace != -1){
        instruction = convertToLowercase(pInstruction.substr(0,posSpace));

        if(instruction.compare("repeat")==0){
                    strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
                    int posSpace1 = strParameters.find_first_of(" ");
                    parameters[0]=atoi(strParameters.substr(0,posSpace1).c_str());
                    int posSpaceE = strParameters.find_first_of("]");
                    strParameters=strParameters.substr(posSpace1+2,pInstruction.length()-11);
        }else{
            history.append(pInstruction);
            if(instruction.compare("loadfile")==0){
                strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
            }else {
                if(instruction.compare("write")==0){
                    strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
                    int posSpace1 = strParameters.find_first_of(" ");
                    parameters[0]=atoi(strParameters.substr(0,posSpace1).c_str());
                    strParameters=strParameters.substr(posSpace1+1,pInstruction.length());
                    cout<<strParameters<<endl;
                }
                else{
                    strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
                    const char * c = strParameters.c_str();
                    if(isalpha(c[0])){
                          strParameters = convertToLowercase(strParameters);
                    }else{
                        int iChar=0;
                        while(iChar!=3){
                            if(strParameters.length()==0){
                               parameters[iChar]=0;

                            }else {
                                int posSpace2 = strParameters.find_first_of(' ');
                                if (posSpace2 != -1){
                                    parameters[iChar]=atoi(strParameters.substr(0,posSpace2).c_str());
                                    strParameters = strParameters.substr(posSpace2+1,strParameters.length());
                                }else{
                                    parameters[iChar] = atoi(strParameters.substr(0,pInstruction.length()).c_str());
                                    strParameters ="";
                                }
                            }
                         iChar++;
                        }
                    }
                }
            }
        }
    }
    else{
        history.append(pInstruction);
        instruction = pInstruction;
    }

    executeInstruction(instruction,parameters,strParameters);


}
string convertToLowercase(string pString){
    char cadena[1024];
    strcpy(cadena, pString.c_str());
    int m;
    for(m = 0; cadena[m]; m++){
      cadena[m] = tolower(cadena[m]); //<--convierte a minusculas
    }
    string newString(cadena);
    return newString;
}
void executeInstruction(string pInstruction,int* Parameters,string pParameter){
    string Instruction= convertToLowercase(pInstruction);
    if (Instruction.compare("forward")==0){
        moveForward(Parameters[0]);
    }
    else if (Instruction.compare("back")==0){
        moveBack(Parameters[0]);
    }
    else if (Instruction.compare("left")==0){
        moveLeft(Parameters[0]);
    }
    else if (Instruction.compare("right")==0){
        moveRight(Parameters[0]);
    }
    else if (Instruction.compare("setpos ")==0){
        setPos(Parameters[0],Parameters[1]);
    }
    else if (Instruction.compare("setx")==0){
        setX(Parameters[0]);
    }
    else if (Instruction.compare("sety")==0){
        setY(Parameters[0]);
    }
    else if (Instruction.compare("setheading")==0){
        setHeading(Parameters[0]);
    }
    else if (Instruction.compare("home")==0){
        Home();
    }
    else if (Instruction.compare("circle")==0){
        Circle(Parameters[0]);
    }
    else if (Instruction.compare("pos")==0){
        Pos();
    }
    else if (Instruction.compare("xcor")==0){
        xCor();
    }
    else if (Instruction.compare("ycor")==0){
        yCor();
    }
    else if (Instruction.compare("heading")==0){
        Heading();
    }
    else if (Instruction.compare("pendown")==0){
        penDown();
    }
    else if (Instruction.compare("penup")==0){
        penUp();
    }
    else if (Instruction.compare("pensize")==0){
        PenSize(Parameters[0]);
    }
    else if (Instruction.compare("color")==0){
            if (pParameter.compare("")!=0){
                int numColor=colorConversor(pParameter);
                seTColor(numColor);
                color=pParameter;

            }else {
                setColors(Parameters[0],Parameters[1],Parameters[2]);
                colorRGB[0]=Parameters[0];
                colorRGB[1]=Parameters[1];
                colorRGB[2]=Parameters[2];
                color="no hay color string";
            }
    }
    else if (Instruction.compare("pen")==0){
        pen();
    }
    else if (Instruction.compare("reset")==0){
        reset();
    }
    else if (Instruction.compare("clear")==0){
        _clear();
    }
    else if (Instruction.compare("write")==0){
        write(Parameters[0],pParameter);
    }
    else if (Instruction.compare("repeat")==0){
        repeatInstruction(Parameters[0],pParameter);
    }
    else if(Instruction.compare("loadfile")==0){
        const char * text= pParameter.c_str();
        readFile(text);
    }
    else if(Instruction.compare("exec")==0){
        exec();
    }
    else if(Instruction.compare("clearhistory")==0){
        clearHistory();
    }
    else if(Instruction.compare("history")==0){
        historyI();
    }
    else if(Instruction.compare("exit")==0){
        Delete();
    }
    else{
        cout<<"Disculpe la instruccion ingresada no existe"<<endl;
    }

}

void analizetorefresh(string pInstruction){

    pInstruction=convertToLowercase(pInstruction);
    bool endWord = false;
    string instruction;
    int *parameters= new int[3];
    string strParameters;
    int posSpace = pInstruction.find_first_of(" ");
    if (posSpace != -1){
        instruction = convertToLowercase(pInstruction.substr(0,posSpace));

        if(instruction.compare("repeat")==0){
                    strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
                    int posSpace1 = strParameters.find_first_of(" ");
                    parameters[0]=atoi(strParameters.substr(0,posSpace1).c_str());
                    int posSpaceE = strParameters.find_first_of("]");
                    strParameters=strParameters.substr(posSpace1+2,pInstruction.length()-11);
        }else{
            if(instruction.compare("loadfile")==0){
                strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
            }else {
                if(instruction.compare("write")==0){
                    strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
                    int posSpace1 = strParameters.find_first_of(" ");
                    parameters[0]=atoi(strParameters.substr(0,posSpace1).c_str());
                    strParameters=strParameters.substr(posSpace1+1,pInstruction.length());
                    cout<<strParameters<<endl;
                }
                else{
                    strParameters = pInstruction.substr(posSpace+1,pInstruction.length());
                    const char * c = strParameters.c_str();
                    if(isalpha(c[0])){
                          strParameters = convertToLowercase(strParameters);
                    }else{
                        int iChar=0;
                        while(iChar!=3){
                            if(strParameters.length()==0){
                               parameters[iChar]=0;

                            }else {
                                int posSpace2 = strParameters.find_first_of(' ');
                                if (posSpace2 != -1){
                                    parameters[iChar]=atoi(strParameters.substr(0,posSpace2).c_str());
                                    strParameters = strParameters.substr(posSpace2+1,strParameters.length());
                                }else{
                                    parameters[iChar] = atoi(strParameters.substr(0,pInstruction.length()).c_str());
                                    strParameters ="";
                                }
                            }
                         iChar++;
                        }
                    }
                }
            }
        }
    }
    else{
        instruction = pInstruction;
    }

    executeInstruction(instruction,parameters,strParameters);
    //Turtle();

}










void MenuInstructions(){
    cout<<"**********************************************"<<endl;
    cout<<"**     Ingrese la instruccion que desea     **"<<endl;
    cout<<"**********************************************"<<endl;
    string instruction="";

        cout<<"> ";
        getline(cin,instruction);
        analizeInstructions(instruction);
        Turtle();

        //refreshTurtle();

        //analizeInstructions("seguir");

    //}


    //MenuInstructions();


}
};
#endif // MOVEMENTS_H
