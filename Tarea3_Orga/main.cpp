#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void CrearArchivo(string nombre_archivo)
{
    ofstream out;
    out.open(nombre_archivo.c_str());
    out.close();
}

void ModificarArchivo(string nombre_archivo,string linea)
{
    ofstream out(nombre_archivo.c_str(),ios::in|ios::binary);
    out.write(linea.c_str(),100);
    out.close();
}

void VerArchivo(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());

    char linea[100];
    in.read(linea,100);
    cout<<linea<<endl;
}

void ListarArchivos()
{
    unsigned char isFile = 0x8;
    DIR* dir;
    dir = opendir("./");
    struct dirent *tipo = NULL;

    if(dir !=NULL)
    {
        while(tipo = readdir(dir))
        {
            //if(tipo->d_type == isFile) muestra solo los archivow pero se supone que solo funciona para linux por lo que investigue
            cout<<tipo->d_name<<endl;
        }
    }

//http://foro.elhacker.net/programacion_cc/listar_directorio_en_c-t382560.0.html
//Funcion de listar archivos para windows
//    WIN32_FIND_DATA findFileData;
//    HANDLE hFind;
//
//    hFind = FindFirstFile("*", &findFileData);
//
//    if(hFind==INVALID_HANDLE_VALUE)
//    {
//       cout<<"No se encontraron archivos"<<endl;
//    }
//    else
//    {
//        do
//        {
//            if(findFileData.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE)
//            {
//                cout<<findFileData.cFileName<<endl;
//            }
//        }while(FindNextFile(hFind,&findFileData)!=0);
//
//        FindClose(hFind);
//    }
}

void Ayuda()
{
    cout<<"*****************  COMANDOS A UTILIZAR   *****************************"<<endl;
    cout<<"****** Para Crear Archivo: creararchivo 'nombre del archivo' *********"<<endl;
    cout<<"****** Para Modificar Archivo: modificararchivo 'nombre del archivo' *"<<endl;
    cout<<"****** Para Ver Archivo: verarchivo 'nombre del archivo' *************"<<endl;
    cout<<"****** Para Listar Archivos: listararchivos  *************************"<<endl;
    cout<<"****** Para Salir: salir  ********************************************"<<endl;
}

int main()
{
    string nombre_archivo;
    string comando;

    cout<<"***** Para Mostrar Comandos de ayuda Ingresa 'help'  *****"<<endl;

    while(comando != "salir")
    {
        cout<<"> ";
        cin>>comando;
        if(comando == "salir")
        {break;}
        if(comando == "help")
            {Ayuda();}
        if(comando == "listararchivos")
            {ListarArchivos();}
       else
       {
           cin>>nombre_archivo;
            if(comando == "creararchivo")
                {   CrearArchivo(nombre_archivo);}
            if(comando == "modificararchivo")
                {   string linea;
                    cin.ignore();
                    getline(cin,linea);
                    ModificarArchivo(nombre_archivo,linea);
                }
            if(comando == "verarchivo")
                {   VerArchivo(nombre_archivo);}
       }
    }

    return 0;
}
