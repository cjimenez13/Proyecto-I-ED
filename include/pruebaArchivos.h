#ifndef PRUEBAARCHIVOS_H
#define PRUEBAARCHIVOS_H

#include <stdio.h>
FILE *alias;
 alias = fopen(“EJEMPLO.DAT”, “rb”);
 if (alias==NULL)
 {
 cout << “\n\r No se puede abrir el archivo !!!”;
 getch();
 return();
 }
class pruebaArchivos
{
    public:
        pruebaArchivos() {}
        virtual ~pruebaArchivos() {}
    protected:
    private:
};

#endif // PRUEBAARCHIVOS_H
