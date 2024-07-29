///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////         Equipo de Sistema de Gestion de prestamos de equipos de computo           Fecha:21/11/2022  /////
///// Por.                                                                                                /////
///// LUIS EMILIANO REYES GUTIERREZ <RGLO210933@upemor.edu.mx>                                            /////
///// VALERIA SANCHEZ PEREZ <SPVO210190@upemor.edu.mx>                                                    /////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Add_Lab ();
void Regist_Prest_Adm ();
void Regist_Prest_Tech ();
void Damage_Regist();
void Mod_PC_Lab();
void Regist_San ();
void Regist_San_Tech ();
void show_Prest();
void Use_Free();
void Menu_Tech();
void menu_Adm();
void Adm_F_Access ();
void Tech_Access_Def ();
void Mod_Regist_Adm();
int Adm_Login ();
int Tech_Login ();

int main(){
    int Opcion_1 = 0;
    int Conf_Existencia = 0;
    char Pulse;
    int Var_Valid_Adm_Log = 0;
    int Var_Valid_Tech_Log = 0;
    FILE *file;
    FILE *Archivo;
    
    while (Opcion_1!=3){
        
       if (file = fopen("Passwd_Admin.bin", "r")) { //comprobar si existe
           fclose(file);
           printf("\e[1;1H\e[2J");//////////////////////////////////////////////
           printf("\n*****************************************************************\n");
           printf("\n\tPrograma de gestión para prestamos de equipos de computo\n");
           printf("\tSeleccione la opcion que desee:\n");
           printf("\n\t\t1.-Iniciar como administrador");
           printf("\n\t\t2.-Iniciar como tecnico");
           printf("\n\t\t3.-Cerrar el programa\n");
           printf("\n*****************************************************************\n------> ");
           scanf("%d%*c",&Opcion_1);
           printf("\e[1;1H\e[2J");//////////////////////////////////
           
           if(Opcion_1==1){
               Var_Valid_Adm_Log = Adm_Login ();
               if (Var_Valid_Adm_Log==1){
                   menu_Adm();
               }
               printf("\e[1;1H\e[2J");//////////////////////////////////////////
               printf("\n****************************************************\n\n");
               printf("\n\t\tPresione ENTER para continuar...\n");
               printf("\n\n****************************************************\n\t\t");
               scanf("%c%*c",&Pulse);
               printf("\e[1;1H\e[2J");//////////////////////////////////////////
           }
           if(Opcion_1 == 2){
               if(Archivo = fopen("Passwd_Tech.bin", "r")){
                   
                   printf("\n************************************************\n\n");
                   printf("\n\tHaz seleccionado usuario Técnico\n");
                   printf("\n\tPresione ENTER para continuar...\n");
                   printf("\n\n************************************************\n         ");
                   scanf("%c%*c",&Pulse);
                   
                   Var_Valid_Tech_Log = Tech_Login();
                   
                   if (Var_Valid_Tech_Log==1){
                       
                       Menu_Tech();
                   }
                   printf("\e[1;1H\e[2J");///////////////////////////////////////
               }
               else{
                   
                   printf("\e[1;1H\e[2J");//////////////////////////////////////
                   printf("\n************************************************************\n\n");
                   printf("\t\tNo Hay usuarios Tecnicos registrados\n");
                   printf("\t\tComunicate con un Administrador para que los registre\n");
                   printf("\n\t\tPresione ENTER para continuar...\n");
                   printf("\n\n************************************************************\n\t\t");
                   scanf("%c%*c",&Pulse);
                   printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                   
               }
           }
       }
       else {
            Adm_F_Access();
           printf("\n************************************************************\n\n");
           printf("\n\t\tPresione ENTER para continuar...\n");
           printf("\n\n************************************************************\n\t");
           scanf("%c%*c",&Pulse);
           printf("\e[1;1H\e[2J");//////////////////////////////////////////////////
       } 
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------
int Adm_Login (){//En esta funcion se hace el inicio de sesion del usuario
    int Num_Int = 0;
    int Valid_Adm_Log = 0;
    int Valid_Adm_Pass = 0;
    int Var_Valid_Adm_Log = 0;
    char Pulse;
    char Ing_PssAdm[20];
    char Ing_UsrAdm[20];
    char Buffer_PssAdm[20];
    char Buffer_UsrAdm[20];
    
    for(Num_Int=0;Num_Int<3;Num_Int++){
        
        printf("\e[1;1H\e[2J");////////////////////////////////////////////////////////////
        printf("\n\n********************************************************************\n");
        printf("\n\tHaz seleccionado Administrador, tienes %d intentos para iniciar\n",3-Num_Int);
        printf("\n\tIngrese el nombre de usuario\n");
        printf("\n********************************************************************\n\n------------> ");
        scanf("%[^\n]%*c",Ing_UsrAdm);
        printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
        
        FILE *file;
        file = fopen("Passwd_Admin.bin","rb");
        while(!feof(file)){
            
            fread(Buffer_UsrAdm, sizeof(Buffer_UsrAdm), 1, file);
            fread(Buffer_PssAdm, sizeof(Buffer_PssAdm), 1, file);
            Valid_Adm_Log = strcmp(Buffer_UsrAdm,Ing_UsrAdm);
            if(Valid_Adm_Log==0){
                
                printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                printf("\n\n************************************************************\n\n");
                printf("\tUsuario Existente\n");
                printf("\t\t%s   ",Ing_UsrAdm);
                printf("\n\tIngrese la contraseña del usuario\n");
                printf("\n\n************************************************************\n\n------> ");
                scanf("%[^\n]%*c",Ing_PssAdm);
                printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                //fread(Buffer_PssAdm, sizeof(Buffer_PssAdm), 1, file);
                
                Valid_Adm_Pass = strcmp(Buffer_PssAdm,Ing_PssAdm);
                if(Valid_Adm_Pass !=0){
                    
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    printf("\n\n************************************************************\n");
                    printf("\tContraseña no coincide\n");
                    printf("\n\tPresione ENTER para continuar...\n");
                    printf("\n\n************************************************************\n\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                }
                if(Valid_Adm_Pass==0){
                    
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    printf("\n\n************************************************************\n");
                    printf("\n\tInicio de Sesion Exitoso\n");
                    printf("\n\tPresione ENTER para continuar...\n");
                    printf("\n************************************************************\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    Var_Valid_Adm_Log = 1;
                    Num_Int = 4;
                    break;
                }
                else{
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    printf("\n\n************************************************************\n");
                    printf("\n\tContraseña no coincide\n");
                    printf("\n\tPresione ENTER para continuar...\n");
                    printf("\n\n************************************************************\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                }
            
            }
        }
        fclose(file);
    }
 
 return (Var_Valid_Adm_Log);//Aqui definimos que esta funcion te dice 1 o 0 dependiendo de si el inicio de sesion es valido
}
//------------------------------------------------------------------------------------------------------------------------------------
void Adm_F_Access (){//Admin first acces. Es el primer inicio del programa, aqui se definen los usuarios de admin

    char Def_PssAdm[20];
    char Def_UsrAdm[20];
    
    int Num_Admin, OPT;
    int Ciclo = 0;
    int Validador = 0;
    char Pulse;
    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////////////
    printf("\n\n************************************************************************************************************\n\n");
    printf("\n\t\tBIENVENIDO AL SISTEMA DE GESTION PARA PRESTAMOS DE EQUIPOS DE COMPUTO");
    printf("\n\n\tAl ser tu primer inicio, es necesario que generes usuarios y contraseñas de Administrador-\n");
    printf("\n ");
    
    FILE *file;
    
    
    printf("\n\n\t\tRecuerda que el máximo de Admin en el primer inicio es 3\n");
    printf("\n\n¿Cuantos administradores vas a usar?\n");
    printf("\n************************************************************************************************************\n\n-----------> ");
    scanf("%d%*c",&Num_Admin);
    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////////////
    
    while((Num_Admin>=1)&&(Num_Admin<=3)&&(Validador!=1)){
        
        
        for(Ciclo=0;Ciclo<Num_Admin;Ciclo++){
            
            
            
            file = fopen("Passwd_Admin.bin","ab+");
            
            printf("\n************************************************\n\n");
            printf("\tIngrese el nombre del usuario No. %d\n\n\t\t",Ciclo + 1);
            scanf("%[^\n]%*c",Def_UsrAdm);
            printf("\t\nIngrese la contraseña del usuario No. %d\n\n",Ciclo + 1);
            printf("************************************************\n\n---------> ");
            scanf("%[^\n]%*c",Def_PssAdm);
            printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            fwrite(Def_UsrAdm , 1 , sizeof(Def_UsrAdm) , file);
            fwrite(Def_PssAdm , 1 , sizeof(Def_PssAdm) , file);
            fclose(file);
        
        }
        //fseek(file,sizeof(Def_PssAdm),SEEK_END);
        
        Validador = 1;
        
    }
    if((Num_Admin<1)||(Num_Admin>3)||(Validador==0)){
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n********************************************************\n\n");
        printf("\n\tIngrese un numero de Administradores válido\n");
        printf("\tPresione ENTER para continuar\n\n\n");
        printf("********************************************************\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    }
   
    //OPT =3;
    //return(OPT); //Con esto cierro el programa porque no encontre una mejor solucion
}
//-------------------------------------------------------------------------------------------------------------
int Tech_Login(){
    
    int Num_Int = 0;
    int Valid_Tech_Log = 0;
    int Valid_Tech_Pass = 0;
    int Var_Valid_Tech_Log = 0;
    char Pulse;
    char Ing_PssTech[20];
    char Ing_UsrTech[20];
    char Buffer_PssTech[20];
    char Buffer_UsrTech[20];
    
    for(Num_Int=0;Num_Int<3;Num_Int++){
        
        printf("\e[1;1H\e[2J");////////////////////////////////////////////////////////////
        printf("\n\n********************************************************************\n");
        printf("\n\tHaz seleccionado Tecnico, tienes %d intentos para iniciar\n",3-Num_Int);
        printf("\n\tIngrese el nombre de usuario\n");
        printf("\n********************************************************************\n\n------------> ");
        scanf("%[^\n]%*c",Ing_UsrTech);
        printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
        
        FILE *Archivo;
        Archivo = fopen("Passwd_Tech.bin","rb");
        
        while(!feof(Archivo)){
            
            fread(Buffer_UsrTech, sizeof(Buffer_UsrTech), 1, Archivo);
            fread(Buffer_PssTech, sizeof(Buffer_PssTech), 1, Archivo);
           
            Valid_Tech_Log = strcmp(Buffer_UsrTech,Ing_UsrTech);
            if(Valid_Tech_Log==0){
                
                printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                printf("\n\n************************************************************\n\n");
                printf("\tUsuario Existente\n");
                printf("\t\t%s   ",Ing_UsrTech);
                printf("\n\tIngrese la contraseña del usuario\n");
                printf("\n\n************************************************************\n\n--------> ");
                scanf("%[^\n]%*c",Ing_PssTech);
                
                //fread(Buffer_PssAdm, sizeof(Buffer_PssAdm), 1, file);
                
                Valid_Tech_Pass = strcmp(Buffer_PssTech,Ing_PssTech);
                
                if(Valid_Tech_Pass !=0){
                    
                    printf("\n\n************************************************************\n");
                    printf("\tusuario no coincide\n");
                    printf("\n\tPresione ENTER para continuar...\n");
                    printf("\n\n************************************************************\n\t");
                    scanf("%c%*c",&Pulse);
                }
                if(Valid_Tech_Pass==0){
                    
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    printf("\n\n************************************************************\n");
                    printf("\n\tInicio de Sesion Exitoso\n");
                    printf("\n\tPresione ENTER para continuar...\n");
                    printf("\n************************************************************\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    Var_Valid_Tech_Log = 1;
                    Num_Int = 4;
                    break;
                }
                else{
                    
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    printf("\n\n************************************************************\n");
                    printf("\n\tContraseña no coincide\n");
                    printf("\n\tPresione ENTER para continuar...\n");
                    printf("\n\n************************************************************\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
                    
                }
                
                
                
            
            }
        }
        fclose(Archivo);
        
    }
 
 return (Var_Valid_Tech_Log);
}
//-------------------------------------------------------------------------------------------------------------
void Tech_Access_Def (){
    int Num_Tecnicos = 0;
    int Contador = 0;
    char Pulse;
    int Opcion_Tech_Def = 0;
    char Def_PssTech[20];
    char Def_UsrTech[20];
    char Buffer_PssTech[20];
    char Buffer_UsrTech[20];
    FILE *Archivo;
    
    while(Opcion_Tech_Def!=3){
        
        printf("\e[1;1H\e[2J");/////////////////////////////////////////////
        printf("*********************************************************************\n\n");
        printf("\n\tHaz seleccionado crear o modificar un usuario tecnico\n");
        printf("\t¿Que deseas hacer?\n\n");
        printf("\t\t1.-Crear usuario Tecnico\n");
        printf("\t\t2.-Cambiar contraseña de Tecnico\n");
        printf("\t\t3.-Salir\n");
        printf("\n\n*************************************************************\n------------->");
        scanf("%d%*c",&Opcion_Tech_Def);
        printf("\e[1;1H\e[2J");/////////////////////////////////////////////
        
        if(Opcion_Tech_Def==1){
            
            Archivo = fopen("Passwd_Tech.bin","ab+");
            printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            printf("***********************************************\n\n");
            printf("\n  Ingrese el nombre del usuario tecnico\n\t");
            scanf("%[^\n]%*c",Def_UsrTech);
            printf("\tIngrese la contraseña del usuario tecnico\n\t");
            scanf("%[^\n]%*c",Def_PssTech);
            printf("\n\n***********************************************");
            printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                    
            fwrite(Def_UsrTech , 1 , sizeof(Def_UsrTech) , Archivo);
            fwrite(Def_PssTech , 1 , sizeof(Def_PssTech) , Archivo);
            fclose(Archivo);
        }
        if(Opcion_Tech_Def==2){
            
            printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            printf("***********************************************\n\n");
            printf("\n\tIngrese el nombre del usuario tecnico\n------> ");
            scanf("%[^\n]%*c",Def_UsrTech);
            printf("\n\n\tIngrese la contraseña nueva del usuario tecnico\n");
            printf("\n\n***********************************************\n--------> ");
            scanf("%[^\n]%*c",Def_PssTech);
            printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            Archivo = fopen("Passwd_Tech.bin","rb+");
            while(!feof(Archivo)){
            
                fread(Buffer_UsrTech, sizeof(Buffer_UsrTech), 1, Archivo);
                fread(Buffer_PssTech, sizeof(Buffer_PssTech), 1, Archivo);
                if(strcmp(Buffer_UsrTech,Def_UsrTech)==0){
                    
                    fseek(Archivo, -20 , SEEK_CUR);//20 bits
                    fwrite(Def_PssTech, 1 , sizeof(Def_PssTech), Archivo);
                    fclose(Archivo);
                    printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                    printf("\n*********************************************\n");
                    printf("\n\t\tRegistro Exitoso\n");
                    printf("\tPresione ENTER para continuar...\n");
                    printf("\n*********************************************\n\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                }
            }
            fclose(Archivo);
            if(strcmp(Buffer_UsrTech,Def_UsrTech)!=0){
                
                printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                printf("\n*********************************************\n");
                printf("\n\t\tUsuario No esta registrado\n");
                printf("\tPresione ENTER para continuar...\n");
                printf("\n*********************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            }
        }
    }
}
//-------------------------------------------------------------------------------------------------------------
void Menu_Tech(){
    
    int Opcion_Menu_Tech = 0;
    char Pulse;
    int Usr_Type = 2;
    FILE * Arch_Labs;
    while(Opcion_Menu_Tech!=5){
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("*****************************************************\n\n");
        printf("\tBienvenido usuario Tecnico\n");
        printf("\t¿Qué deseas hacer?\n");
        printf("\n\t\t1.- Registrar equipos de cómputo fuera de servicio");
        printf("\n\t\t2.- Gestionar sanciones por Alumno");
        printf("\n\t\t3.- Registrar un prestamo");
        printf("\n\t\t4.- Ver Regitro de prestamos");
        printf("\n\t\t5.- Salir\n");
        printf("\n\n*****************************************************\n------------> ");
        scanf("%d%*c",&Opcion_Menu_Tech);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        
        if(Opcion_Menu_Tech==1){
            
            if(Arch_Labs = fopen("LT1.bin", "r")){

                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**************************************************************\n\n");
                printf("\n\t\tDesea Liberar una PC o Registrar un daño en una PC?");
                int Opc_Lib_Reg=0;
                printf("\n\t\t1.- Liberar");
                printf("\n\t\t2.- Registrar PC dañada");
                printf("\n\n\n**************************************************************\n-------> ");
                scanf("%d%*c",&Opc_Lib_Reg);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                if(Opc_Lib_Reg == 1){
                    Use_Free();
                }
                if(Opc_Lib_Reg == 2){
                    Damage_Regist();
                }
                printf("\n**************************************************************\n\n\n");
                printf("\tGracias Por participar\n");
                printf("\n\t\tPresiona ENTER para continuar\n");
                printf("\n\n\n**************************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
            else{
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("\n*******************************************************\n\n");
                printf("\tNo hay PC's registradas.\n");
                printf("\tPor favor registre al menos una primero");
                printf("\n\n\t\tPresiona ENTER para continuar...\n");
                printf("\n*******************************************************\n\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
        }
        if(Opcion_Menu_Tech==2){
            
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////

            Regist_San_Tech ();
            printf("\nPresiona ENTER para continuar\n");
            scanf("%c%*c",&Pulse);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
        if(Opcion_Menu_Tech==3){

            Regist_Prest_Tech ();
            //printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            printf("***************************************");
            printf("\n\n\tPresiona ENTER para continuar\n");
            printf("\n***************************************\n\n\t\t");
            scanf("%c%*c",&Pulse);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
        if(Opcion_Menu_Tech==4){
            FILE *Arch_Prest;
            if (Arch_Labs = fopen("Regist_Prest.txt", "r")) {
                show_Prest();
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**************************************************\n\n");
                printf("\n\tPresione ENTER para continuar...\n");
                printf("\n\n**************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
            else{
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**************************************************\n\n");
                printf("\n\t\t!No hay prestamos registrados aun!\n");
                printf("\n\t\t Registre al menos uno para consultar\n");
                printf("\n\tPresione ENTER para continuar...\n");
                printf("\n\n**************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
        }
    }
    
}
//-------------------------------------------------------------------------------------------------------------
void Mod_Regist_Adm(){
    char Pulse;
    FILE *file;
    int Opc_Mod_Regist_Adm = 0;
    char Def_UsrAdm[20];
    char Def_PssAdm[20];
    char Buffer_UsrAdm[20];
    char Buffer_PssAdm[20];
    
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    printf("**********************************************************\n");
    printf("\n\tHaz seleccionado registro de Administradores\n");
    printf("\tSeleccione la opcion que desee\n\n");
    printf("\t\t1.- Registrar nuevo usuario Administrador\n");
    printf("\t\t2.- Cambiar contraseña Administrador\n");
    printf("\t\t3.- Salir\n\n");
    printf("**********************************************************\n----------> ");
    scanf("%d%*c",&Opc_Mod_Regist_Adm);
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    if(Opc_Mod_Regist_Adm == 1){
        
        file = fopen("Passwd_Admin.bin","ab+");
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("***************************************************************\n");
        printf("\n\tHaz seleccionado registrar un usuario administrador\n\n");
        printf("***************************************************************\n\n");
        printf("\n  Ingrese el nombre del usuario administrador\n\n---------> ");
        scanf("%[^\n]%*c",Def_UsrAdm);
        printf("\n\nIngrese la contraseña del usuario administrador\n");
        printf("\n\n***********************************************\n\n---------> ");
        scanf("%[^\n]%*c",Def_PssAdm);
        printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                    
        fwrite(Def_UsrAdm , 1 , sizeof(Def_UsrAdm) , file);
        fwrite(Def_PssAdm , 1 , sizeof(Def_PssAdm) , file);
        fclose(file);
        
    }
    if(Opc_Mod_Regist_Adm == 2){
        
        printf("\e[1;1H\e[2J");/////////////////////////////////////////////
        printf("***************************************************************\n\n");
        printf("\n\tIngrese el nombre del usuario administrador\n------> ");
        scanf("%[^\n]%*c",Def_UsrAdm);
        printf("\n\n\tIngrese la contraseña nueva del usuario administrador\n");
        printf("\n\n***************************************************************\n--------> ");
        scanf("%[^\n]%*c",Def_PssAdm);
            
            printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            file = fopen("Passwd_Admin.bin","rb+");
            while(!feof(file)){
            
                fread(Buffer_UsrAdm, sizeof(Buffer_UsrAdm), 1, file);
                fread(Buffer_PssAdm, sizeof(Buffer_PssAdm), 1, file);
                
                if(strcmp(Buffer_UsrAdm,Def_UsrAdm)==0){
                    
                    fseek(file, -20 , SEEK_CUR);//20 bits
                    fwrite(Def_PssAdm, 1 , sizeof(Def_PssAdm), file);
                    fclose(file);
                    
                    printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                    printf("\n*********************************************\n");
                    printf("\n\t\tRegistro Exitoso\n");
                    printf("\tPresione ENTER para continuar...\n");
                    printf("\n*********************************************\n\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                    
                }
            }
            fclose(file);
            
            if(strcmp(Buffer_UsrAdm,Def_UsrAdm)!=0){
                printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                printf("\n*********************************************\n");
                printf("\n\t\tUsuario No esta registrado\n");
                printf("\tPresione ENTER para continuar...\n");
                printf("\n*********************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");/////////////////////////////////////////////
            }
    }
}
//-------------------------------------------------------------------------------------------------------------
void menu_Adm(){
    int Opcion_Menu_Adm = 0;
    int Ext_File_Labs =1;
    int Ext_PC = 1;
    char Pulse;
    FILE *Arch_Labs;
    int Usr_Type = 1;
    while(Opcion_Menu_Adm!=9){
    
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("****************************************************************************\n\n");
        printf("\tBienvenido usuario Administrador\n");
        printf("\t¿Qué deseas hacer?\n");
        printf("\n\t\t1.- Crear o modificar usuarios de tecnicos");
        printf("\n\t\t2.- Crear Laboratorios");
        printf("\n\t\t3.- Modificar equipos de cómputo por Laboratorios");
        printf("\n\t\t4.- Registrar equipos de cómputo fuera de servicio");
        printf("\n\t\t5.- Gestionar sanciones por Alumno");
        printf("\n\t\t6.- Registrar prestamo");
        printf("\n\t\t7.- Ver registro de prestamos");
        printf("\n\t\t8.- Crear o modificar usuarios de administradores");
        printf("\n\t\t9.- Salir\n");
        printf("\n\n****************************************************************************\n------------> ");
        scanf("%d%*c",&Opcion_Menu_Adm);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        
        if(Opcion_Menu_Adm == 1){
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            Tech_Access_Def ();
            printf("\n***********************************************\n\n");
            printf("\n       Presiona ENTER para continuar\n");
            printf("\n\n***********************************************\n         ");
            scanf("%c%*c",&Pulse);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
        if(Opcion_Menu_Adm == 2){

            Add_Lab ();

            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            printf("\n*******************************************************\n\n");
            printf("\n\tPresiona ENTER para continuar\n");
            printf("\n\n*******************************************************\n\t\t");
            scanf("%c%*c",&Pulse);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
        if(Opcion_Menu_Adm == 3){

            if(Arch_Labs = fopen("LT1.bin", "r")){


                Mod_PC_Lab ();
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
            else {

                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("\n*****************************************************\n");
                printf("\tNo Laboratorios registrados.\n");
                printf("\tPor favor registre al menos uno primero\n");
                printf("\t\t\t\nPresiona ENTER para continuar\n");
                printf("\n*****************************************************\n");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////

            }
        }
        if(Opcion_Menu_Adm == 4){
            if(Arch_Labs = fopen("LT1.bin", "r")){

                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**************************************************************\n\n");
                printf("\n\t\tDesea Liberar una PC o Registrar un daño en una PC?");
                int Opc_Lib_Reg=0;
                printf("\n\t\t1.- Liberar");
                printf("\n\t\t2.- Registrar PC dañada");
                printf("\n\n\n**************************************************************\n-------> ");
                scanf("%d%*c",&Opc_Lib_Reg);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                if(Opc_Lib_Reg == 1){
                    
                    Use_Free();
                    
                }
                if(Opc_Lib_Reg == 2){
                    
                    Damage_Regist();
                    
                }
                
                printf("\n**************************************************************\n\n\n");
                printf("\tGracias Por participar\n");
                printf("\n\t\tPresiona ENTER para continuar\n");
                printf("\n\n\n**************************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////

            }
            else{

                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("\n*******************************************************\n\n");
                printf("\tNo hay PC's registradas.\n");
                printf("\tPor favor registre al menos una primero");
                printf("\n\n\t\tPresiona ENTER para continuar...\n");
                printf("\n*******************************************************\n\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////

            }
        }
        if(Opcion_Menu_Adm == 5){
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////

            Regist_San ();
            printf("\n*****************************************\n");
            printf("\n\tPresiona ENTER para continuar\n");
            printf("\n*****************************************\n\n\t\t");
            scanf("%c%*c",&Pulse);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
        if(Opcion_Menu_Adm == 6){

            Regist_Prest_Adm ();
            //printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            printf("\n*****************************************\n");
            printf("\n\tPresiona ENTER para continuar\n");
            printf("\n*****************************************\n\n\t\t");
            scanf("%c%*c",&Pulse);
            //printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
        if(Opcion_Menu_Adm == 7){
            FILE *Arch_Prest;
            if (Arch_Labs = fopen("Regist_Prest.txt", "r")) {
                show_Prest();
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**************************************************\n\n");
                printf("\n\tPresione ENTER para continuar...\n");
                printf("\n\n**************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
            else{
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**************************************************\n\n");
                printf("\n\t\t!No hay prestamos registrados aun!\n");
                printf("\n\t\t Registre al menos uno para consultar\n");
                printf("\n\tPresione ENTER para continuar...\n");
                printf("\n\n**************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
        }
        if(Opcion_Menu_Adm == 8){
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    
            Mod_Regist_Adm();
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            printf("\n*****************************************\n");
            printf("\n\tPresiona ENTER para continuar\n");
            printf("\n*****************************************\n\n\t\t");
            scanf("%c%*c",&Pulse);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        }
    }
    
}
//-------------------------------------------------------------------------------------------------------------
void Add_Lab (){

    char Lab_Nombre[4];
    const char *Lab_Nom = "LT";
    char PC_Nombre[4];
    const char *PC_Nom = "PC";
    char Disponibilidad [7];
    const char* Si_Disp = "En_Fun";
    const char* No_Disp = "No_Fun";
    char Usabilidad [7];
    const char* Si_Usable = "No_Uso";
    const char* No_Usable = "Si_Uso";
    char n [3];
    char b [3];
    char Pulse;
    char Reg_Lab[4];
    char Lab_Nombre_Cpy[10];
    char  Finalizador;
    const char* Bin = ".bin";

    //char Final;
    int Contador, Num_Labs, Num_PCs, i, a;
    a =i = Num_PCs = Num_Labs = Contador = 0;

    FILE *Arch_Labs;
    Finalizador = 'a';
    //
    if(Arch_Labs = fopen("LT1.bin", "r")){
        printf("\n**************************************************************************\n\n");
        printf("\nYa haz creado los laboratorios\n");
        printf("\t\t Presione ENTER para continuar...\n");                                  //    una variable char
        printf("\n**************************************************************************\n\n---------> ");  //     y de ahí condicionar
        scanf("%c%*c",&Pulse);
    }
    else{

        while(Finalizador != 'x'){
            Finalizador = 'a';//<----------------------------------------------------------------//

            if(Arch_Labs = fopen("LT1.bin", "r")){
                break;
            }

            printf("\e[1;1H\e[2J");//////////////////////////////////////////////              //
            printf("\n**************************************************************************\n\n");             //
            printf("\tHaz seleccionado Agregar un laboratorio\n");
            printf("\tAl ser tu primer inicio, es necesario que crees almenos 1 laboratorio\n\n"); //
            printf("\tPresione x para salir de esta opcion\n");                                  //<---Esto es para leer
            printf("\t\to Presione cualquier otra cosa para continuar...\n");                                  //    una variable char
            printf("\n**************************************************************************\n\n---------> ");  //     y de ahí condicionar
            scanf("\n%c%*c",&Finalizador);
                                //     que el while termine
                                                                                              //en otras palabras
            if(Finalizador == 'x'){                                                    //     o usarlo como un Continuar
                break;//<--------------------------------------------------------------------------//     o en mi caso un Pulse
            }

            if(Finalizador != 'x') {

                printf("\e[1;1H\e[2J");//////////////////////////////////////////////<---Estos clear estan comentados para ver
                printf("\n*******************************************************\n\n");//  que pringaos sucede con esta varible
                printf("\t\tNota. El maximo de laboratorios es 20\n");
                printf("No olvide que al menos debe existir 1 laboratorio\n\n");
                printf("\tIngrese el numero de laboratorios que desea");
                printf("\n*******************************************************\n---------> ");
                scanf("\n%d%*c",&Num_Labs);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////

            }

            printf("El numero de labs es %d, no?", Num_Labs);
            if((Num_Labs<=20)&&(Num_Labs>=1)){

                //Arch_Labs = fopen("Regist_Labs.bin","ab+");

                for(i=1;i<=Num_Labs;i++)
                {

                    printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                    printf("***********************************************\n\n");

                    sprintf(b, "%d", i);

                    strcpy ( Lab_Nombre, Lab_Nom );

                    strcat(Lab_Nombre, b);


                    strcpy(Lab_Nombre_Cpy,Lab_Nombre);
                    strcat(Lab_Nombre_Cpy, Bin);
                    //printf("\n\t%s\n",Lab_Nombre_Cpy);
                    //fwrite(Lab_Nombre_Cpy , 1 , sizeof(Lab_Nombre_Cpy) , Arch_Labs);

                    printf("\n\t\tEste es lab. %s \n",Lab_Nombre);
                    //Arch_Labs = fopen("Regist_Labs.bin","ab+");
                    Arch_Labs = fopen(Lab_Nombre_Cpy,"ab+");

                    printf("\t¿Cuántas PC's va a tener?\n");
                    printf("\n***********************************************\n--------> ");
                    scanf("%d",&Num_PCs);

                    for(int o=1;o<=Num_PCs;o++){
                        sprintf(n, "%d", o);
                        strcpy ( PC_Nombre, PC_Nom );
                        strcat(PC_Nombre, n);
                        fwrite(PC_Nombre , 1 , sizeof(PC_Nombre) , Arch_Labs);
                        strcpy(Disponibilidad, Si_Disp);
                        fwrite(Disponibilidad, 1 , sizeof(Disponibilidad), Arch_Labs);
                        strcpy(Usabilidad, Si_Usable);
                        fwrite(Usabilidad, 1 , sizeof(Usabilidad), Arch_Labs);
                    }
                    fclose(Arch_Labs);
                }


            }


            if((Num_Labs>20)||(Num_Labs<1)){

                printf("\e[1;1H\e[2J");/////////////////////////////////////////////
                printf("\n*************************************************\n");
                printf("\n\tSolo pueden ser 20 laboratorios\n");
                printf("\n\tPresione ENTER para continuar...\n");
                printf("\n*************************************************\n\t\t");
                scanf("%c%*c",&Pulse);
            }
            //printf("\t\n");

        }

    }


}
//-------------------------------------------------------------------------------------------------------------
void Damage_Regist(){

    int i, Opcion_Est = 0;
    char Pulse;
    char n[3];
    char o[2];
    int PC_Num;
    int Lab_Num, valid_PC = 0;
    char Buffer_PC_Nombre[4];
    char Lab_Nombre[4];
    char Lab_Nombre_Cpy[10];
    const char *Lab_Nom = "LT";
    char PC_Nombre[4];
    const char *PC_Nom = "PC";
    const char* Bin = ".bin";
    const char* Si_Disp = "En_Fun";
    const char* No_Disp = "No_Fun";
    char Buffer_Disponibilidad [7];
    char Disponibilidad [7];
    char Buffer_Usabilidad [7];
    char Usabilidad [7];
    const char* Si_Usable = "No_Uso";
    const char* No_Usable = "Si_Uso";
    int valid_PC_For_Edt = 1;

    FILE * Arch_Labs;

    printf("\n*****************************************************\n");
    printf("\tHaz seleccionado registro de equipos de computo dañados.\n");
    printf("\tIngresa el numero del laboratorio\n");
    printf("\n*****************************************************\n\n-------> ");
    scanf("%d%*c",&Lab_Num);
    sprintf(n, "%d", Lab_Num);
    strcpy( Lab_Nombre, Lab_Nom );
    strcat(Lab_Nombre, n);
    strcpy(Lab_Nombre_Cpy,Lab_Nombre);
    strcat(Lab_Nombre_Cpy, Bin);
    if(Arch_Labs = fopen( Lab_Nombre_Cpy , "r")){

        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\tExistencia del laboratorio verificada...\n");
        printf("\tPresione ENTER para continuar...\n");
        printf("\n*****************************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);

        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\n\t¿De que PC desea cambiar su estado?\n");
        printf("\n\t\tIngrese el numero de PC\n");
        printf("\n\n-------> ");
        scanf("%d%*c",&i);
        printf("\n\tDesea registrar como: \n\n\t1.- En servicio\n\t2.- Fuera de Servicio\n");
        printf("\n*****************************************************\n\n-------> ");
        scanf("%d%*c",&Opcion_Est);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        if (Opcion_Est==1){

            strcpy(Disponibilidad,Si_Disp);

        }
        if(Opcion_Est==2){

            strcpy(Disponibilidad, No_Disp);

        }
        else{

            printf("\n*****************************************************\n");
            printf("\tOpcion, no válida, se asignará a En servicio...\n");
            printf("\tPresione ENTER para continuar...\n");
            printf("\n*****************************************************\n\n\t\t");
            scanf("%c%*c",&Pulse);
            strcpy(Disponibilidad,Si_Disp);
        }

        sprintf(o, "%d", i);
        strcpy ( PC_Nombre, PC_Nom );
        strcat(PC_Nombre, o);

        Arch_Labs = fopen(Lab_Nombre_Cpy,"rb+");

        while(!feof(Arch_Labs)){

            fread(Buffer_PC_Nombre, sizeof(Buffer_PC_Nombre), 1, Arch_Labs);
            fread(Buffer_Disponibilidad, sizeof(Buffer_Disponibilidad), 1, Arch_Labs);
            fread(Buffer_Usabilidad, sizeof(Buffer_Usabilidad), 1, Arch_Labs);

            if (strcmp(Buffer_PC_Nombre,PC_Nombre)==0){
                //existe esa PC
                fseek(Arch_Labs, -14 , SEEK_CUR);
                fwrite(Disponibilidad, 1 , sizeof(Disponibilidad), Arch_Labs);
                strcpy(Usabilidad, Si_Usable);
                fwrite(Usabilidad, 1 , sizeof(Usabilidad), Arch_Labs);
                valid_PC = 1;
                break;
            }


        }
        if(valid_PC==0){
                printf("\n*****************************************************\n");
                printf("\tEsta PC no esta registrada\n\t\tporfavor agreguela o intente otra diferente ...\n");
                printf("\tPresione ENTER para continuar...\n");
                printf("\n*****************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
            }
        fclose(Arch_Labs);

    }
    else{

        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\tEste laboratorio No existe\n");
        printf("\tPresiona ENTER para continuar...\n");
        printf("\n*****************************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    }


}
//----------------------------------------------------------------------------------------------------------------
void Use_Free(){
    
    int i, Opcion_Est = 0;
    char Pulse;
    char n[3];
    char o[2];
    int PC_Num;
    int Lab_Num, valid_PC = 0;
    char Buffer_PC_Nombre[4];
    char Lab_Nombre[4];
    char Lab_Nombre_Cpy[10];
    const char *Lab_Nom = "LT";
    char PC_Nombre[4];
    const char *PC_Nom = "PC";
    const char* Bin = ".bin";
    const char* Si_Disp = "En_Fun";
    const char* No_Disp = "No_Fun";
    char Buffer_Disponibilidad [7];
    char Disponibilidad [7];
    char Buffer_Usabilidad [7];
    char Usabilidad [7];
    const char* Si_Usable = "No_Uso";
    const char* No_Usable = "Si_Uso";
    int valid_PC_For_Edt = 1;
    
    FILE * Arch_Labs;

    printf("\n*****************************************************\n");
    printf("\tHaz seleccionado liberar PC's.\n");
    printf("\tIngresa el numero del laboratorio\n");
    printf("\n*****************************************************\n\n-------> ");
    scanf("%d%*c",&Lab_Num);
    sprintf(n, "%d", Lab_Num);
    strcpy( Lab_Nombre, Lab_Nom );
    strcat(Lab_Nombre, n);
    strcpy(Lab_Nombre_Cpy,Lab_Nombre);
    strcat(Lab_Nombre_Cpy, Bin);
    
    if(Arch_Labs = fopen( Lab_Nombre_Cpy , "r")){
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\tExistencia del laboratorio verificada...\n");
        printf("\tPresione ENTER para continuar...\n");
        printf("\n*****************************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);

        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\n\t¿Que PC desea liberar?\n");
        printf("\n\t\tIngrese el numero de PC\n");
        printf("\n*****************************************************\n");
        printf("\n\n-------> ");
        scanf("%d%*c",&i);
        sprintf(o, "%d", i);
        strcpy ( PC_Nombre, PC_Nom );
        strcat(PC_Nombre, o);

        Arch_Labs = fopen(Lab_Nombre_Cpy,"rb+");

        while(!feof(Arch_Labs)){
            
            fread(Buffer_PC_Nombre, sizeof(Buffer_PC_Nombre), 1, Arch_Labs);
            fread(Buffer_Disponibilidad, sizeof(Buffer_Disponibilidad), 1, Arch_Labs);
            fread(Buffer_Usabilidad, sizeof(Buffer_Usabilidad), 1, Arch_Labs);
            if (strcmp(Buffer_PC_Nombre,PC_Nombre)==0){
                printf("\n*****************************************************\n");
                printf("\tEsta PC existe\n");
                printf("\tEn proceso de liberacion\n\n");
                printf("\t\tPresiona ENTER para continuar...\n");
                printf("\n*****************************************************\n\n\t\t");
                fseek(Arch_Labs, -7 , SEEK_CUR);
                strcpy(Usabilidad, Si_Usable);
                fwrite(Usabilidad, 1 , sizeof(Usabilidad), Arch_Labs);
                valid_PC=1;
                break;
            }
            
        }
        if(valid_PC==0){
            
                printf("\n*****************************************************\n");
                printf("\tEsta PC no esta registrada\n\t\tporfavor agreguela o intente otra diferente ...\n");
                printf("\tPresione ENTER para continuar...\n");
                printf("\n*****************************************************\n\n\t\t");
                scanf("%c%*c",&Pulse);
            }
        fclose(Arch_Labs);
        
    }
    
    else{
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\tEste laboratorio No existe\n");
        printf("\tPresiona ENTER para continuar...\n");
        printf("\n*****************************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        
    }
    
}
//-------------------------------------------------------------------------------------------------------------
void Mod_PC_Lab(){
    int i = 0;
    char Pulse;
    char n[3];
    char o[2];
    int PC_Num;
    int Lab_Num = 0;
    char Lab_Nombre[4];
    char Lab_Nombre_Cpy[10];
    const char *Lab_Nom = "LT";
    char PC_Nombre[4];
    const char *PC_Nom = "PC";
    const char* Bin = ".bin";
    const char* Si_Disp = "En_Fun";
    const char* No_Disp = "No_Fun";
    char Disponibilidad [7];
    char Usabilidad [7];
    const char* Si_Usable = "No_Uso";
    const char* No_Usable = "Si_Uso";

    FILE * Arch_Labs;

    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    printf("\n*****************************************************\n");
    printf("\tHaz seleccionado editar PC's por laboratorio\n");
    printf("\tIngresa el numero del laboratorio\n");
    printf("\n*****************************************************\n\n-------> ");
    scanf("%d%*c",&Lab_Num);
    sprintf(n, "%d", Lab_Num);
    strcpy( Lab_Nombre, Lab_Nom );
    strcat(Lab_Nombre, n);
    strcpy(Lab_Nombre_Cpy,Lab_Nombre);
    strcat(Lab_Nombre_Cpy, Bin);
    if(Arch_Labs = fopen( Lab_Nombre_Cpy , "r")){

        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\tExistencia del laboratorio verificada...\n");
        printf("\tPresione ENTER para continuar...\n");
        printf("\n*****************************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\n\t¿Cuantas PC's desea que tenga el laboratorio ahora?\n");
        printf("\n*****************************************************\n\n-------> ");
        scanf("%d%*c",&PC_Num);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////

        Arch_Labs = fopen(Lab_Nombre_Cpy,"wb+");

        for(i=1;i<=PC_Num;i++){
            sprintf(o, "%d", i);
            strcpy ( PC_Nombre, PC_Nom );
            strcat(PC_Nombre, o);
            fwrite(PC_Nombre , 1 , sizeof(PC_Nombre) , Arch_Labs);
            strcpy(Disponibilidad, Si_Disp);
            fwrite(Disponibilidad, 1 , sizeof(Disponibilidad), Arch_Labs);
            strcpy(Usabilidad, Si_Usable);
            fwrite(Usabilidad, 1 , sizeof(Usabilidad), Arch_Labs);
        }
        fclose(Arch_Labs);

    }
    else{
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************************\n");
        printf("\tEste laboratorio No existe\n");
        printf("\tPresiona ENTER para continuar...\n");
        printf("\n*****************************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////

    }
}
//------------------------------------------------------------------------------------------------------------------------
void Regist_San (){
    
    char Pulse;
    char Matricula[15];
    char Buffer_Matricula[15];
    char Sancion[15];
    char Buffer_Sancion[15];
    const char* Sancionado = "Si_San";
    const char* No_Sancionado = "No_San";
    int Matricula_Valida,Num_Alums,a;
    int Quit_San, Si_Sancionado,Wish_San;
    FILE*Arch_Alum;
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    printf("\n*****************************************************\n");
    printf("\tBienvenido al registro de sanciones\n");
    printf("\tPresiona ENTER para continuar...\n");
    printf("\n*****************************************************\n\n\t\t");
    scanf("%c%*c",&Pulse);
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////

    if(Arch_Alum = fopen( "Regist_Alumns.bin" , "r"))//EN CASO DE QUE EXISTA EL ARCHIVO
    {
        fclose(Arch_Alum);
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************\n");
        printf("\n\tIngrese la matricula del Alumno");
        printf("\n\n*****************************************\n------> ");
        scanf("%[^\n]%*c",Matricula);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        
        Arch_Alum = fopen("Regist_Alumns.bin","rb+");
        while(!feof(Arch_Alum)){
            
            //fread(Buffer_UsrAdm, sizeof(Buffer_UsrAdm), 1, file);
            fread(Buffer_Matricula, sizeof(Buffer_Matricula), 1, Arch_Alum);
            fread(Buffer_Sancion, sizeof(Buffer_Sancion), 1, Arch_Alum);

            Matricula_Valida = strcmp(Buffer_Matricula,Matricula);
            if(Matricula_Valida == 0){
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("\n*****************************************\n");
                printf("\n\tEl alumno ya existe en el registro");
                printf("\n\tSu estado es %s ",Buffer_Sancion);
                printf("\n\tPresione ENTER para continuar...");
                printf("\n*****************************************\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                strcpy(Sancion,Sancionado);
                Si_Sancionado = strcmp(Buffer_Sancion,Sancion);

                if(Si_Sancionado==0){
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                    printf("\n*****************************************\n");
                    printf("\n\tEl alumno se encuentra sancionado");
                    printf("\n\tDesea quitar su sancion?");
                    printf("\n\n\t1.-Si\n\t2.-No\n");
                    printf("\n*****************************************\n------> ");
                    scanf("%d%*c",&Quit_San);
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////

                    if (Quit_San==1){
                        strcpy(Sancion,No_Sancionado);
                    }
                    if(Quit_San==2){
                        strcpy(Sancion,Sancionado);
                    }
                    if((Quit_San!=1)&&(Quit_San!=2)){
                        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                        printf("\n*****************************************\n");
                        printf("\n\tOpcion Invalida");
                        printf("\n\tPresione ENTER para continuar...");
                        printf("\n*****************************************\n\t\t");
                        scanf("%c%*c",&Pulse);
                        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                        strcpy(Sancion,Sancionado);
                    }
                    fseek(Arch_Alum, -15 , SEEK_CUR);//15 bits
                    fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                    fclose(Arch_Alum);
                    break;
                }
                else{
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                    printf("\n*****************************************\n");
                    printf("\n\tEl alumno no se encuentra sancionado");
                    printf("\n\tDesea sancionar?");
                    printf("\n\n\t1.-Si\n\t2.-No\n");
                    printf("\n*****************************************\n------> ");
                    scanf("%d%*c",&Wish_San);
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////

                    if(Wish_San== 1){
                        strcpy(Sancion,Sancionado);
                    }
                    if(Wish_San==2){
                        strcpy(Sancion,No_Sancionado);
                    }
                    if((Wish_San!=1)&&(Wish_San!=2)){
                        printf("\n*****************************************\n");
                        printf("\n\tOpcion Invalida");
                        printf("\n\tPresione ENTER para continuar...");
                        printf("\n*****************************************\n\t\t");
                        scanf("%c%*c",&Pulse);
                        strcpy(Sancion,No_Sancionado);
                    }
                    fseek(Arch_Alum, -15 , SEEK_CUR);//15 bits
                    fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                    fclose(Arch_Alum);
                }
                

            }
        }
        if(Matricula_Valida != 0){
            
            fclose(Arch_Alum);
            Arch_Alum = fopen("Regist_Alumns.bin","ab+");
            strcpy(Sancion,Sancionado);
            fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
            fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
            fclose(Arch_Alum);
        }
    }
    else{
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n************************************************************\n");
        printf("\n\tDame el numero de alumnos que deseas Registrar\n");
        printf("\n************************************************************\n------> ");
        scanf("%d%*c",&Num_Alums);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        //fclose(Arch_Alum);
        
        for(a=1;a<=Num_Alums;a++){
            
            Arch_Alum = fopen("Regist_Alumns.bin","ab+");
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            printf("\n*****************************************\n");
            printf("\n\tDame la matricula del Alumno No. %d",a);
            printf("\n*****************************************\n------> ");
            scanf("%[^\n]%*c",Matricula);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            strcpy(Sancion,Sancionado);
            //fwrite()matricula
            fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
            fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
            //fwrite()sancion
            fclose(Arch_Alum);
        }
        

    }//En caso de que no exista el archivo
}
//---------------------------------------------------------------------------------------------------------------------------------
void Regist_San_Tech(){
    char Pulse;
    char Matricula[15];
    char Buffer_Matricula[15];
    char Sancion[15];
    char Buffer_Sancion[15];
    const char* Sancionado = "Si_San";
    const char* No_Sancionado = "No_San";
    int Matricula_Valida,Num_Alums,a;
    int Quit_San, Si_Sancionado,Wish_San;
    FILE*Arch_Alum;
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    printf("\n*****************************************************\n");
    printf("\tBienvenido al registro de sanciones\n");
    printf("\tPresiona ENTER para continuar...\n");
    printf("\n*****************************************************\n\n\t\t");
    scanf("%c%*c",&Pulse);
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////

    if(Arch_Alum = fopen( "Regist_Alumns.bin" , "r"))//EN CASO DE QUE EXISTA EL ARCHIVO
    {
        fclose(Arch_Alum);
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n*****************************************\n");
        printf("\n\tIngrese la matricula del Alumno");
        printf("\n\n*****************************************\n------> ");
        scanf("%[^\n]%*c",Matricula);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        
        Arch_Alum = fopen("Regist_Alumns.bin","rb+");
        while(!feof(Arch_Alum)){
            
            //fread(Buffer_UsrAdm, sizeof(Buffer_UsrAdm), 1, file);
            fread(Buffer_Matricula, sizeof(Buffer_Matricula), 1, Arch_Alum);
            fread(Buffer_Sancion, sizeof(Buffer_Sancion), 1, Arch_Alum);

            Matricula_Valida = strcmp(Buffer_Matricula,Matricula);
            if(Matricula_Valida == 0){
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("\n************************************************\n");
                printf("\n\tEl alumno ya existe en el registro");
                printf("\n\tSu estado es %s ",Buffer_Sancion);
                printf("\n\tPresione ENTER para continuar...");
                printf("\n**********************************************\n\t\t");
                scanf("%c%*c",&Pulse);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                strcpy(Sancion,Sancionado);
                Si_Sancionado = strcmp(Buffer_Sancion,Sancion);

                if(Si_Sancionado==0){
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                    printf("\n***************************************************\n");
                    printf("\n\tEl alumno se encuentra sancionado");
                    printf("\n\tComuniquese con un Administrador \n\t\tpara retirar sancion");
                    printf("\n\n\tPresione ENTER para continuar...");
                    printf("\n***************************************************\n\t\t");
                    scanf("%c%*c",&Pulse);
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                    strcpy(Sancion,Sancionado);
                    
                    fseek(Arch_Alum, -15 , SEEK_CUR);//15 bits
                    fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                    fclose(Arch_Alum);
                    break;
                }
                else{
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                    printf("\n*****************************************\n");
                    printf("\n\tEl alumno no se encuentra sancionado");
                    printf("\n\tDesea sancionar?");
                    printf("\n\n\t1.-Si\n\t2.-No\n");
                    printf("\n*****************************************\n------> ");
                    scanf("%d%*c",&Wish_San);
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////

                    if(Wish_San== 1){
                        strcpy(Sancion,Sancionado);
                    }
                    if(Wish_San==2){
                        strcpy(Sancion,No_Sancionado);
                    }
                    if((Wish_San!=1)&&(Wish_San!=2)){
                        printf("\n*****************************************\n");
                        printf("\n\tOpcion Invalida");
                        printf("\n\tPresione ENTER para continuar...");
                        printf("\n*****************************************\n\t\t");
                        scanf("%c%*c",&Pulse);
                        strcpy(Sancion,No_Sancionado);
                    }
                    fseek(Arch_Alum, -15 , SEEK_CUR);//15 bits
                    fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                    fclose(Arch_Alum);
                    break;
                    
                }
                
                /*strcpy(Sancion,Sancionado);
                fclose(Arch_Alum);
                Arch_Alum = fopen("Regist_Alumns.bin","rb+");
                fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
                fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                fclose(Arch_Alum);
                //break;*/

            }
        }
        if(Matricula_Valida != 0){
            fclose(Arch_Alum);
            Arch_Alum = fopen("Regist_Alumns.bin","ab+");
            strcpy(Sancion,Sancionado);
            fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
            fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
            fclose(Arch_Alum);
            
        }
    }
    else{
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("\n************************************************************\n");
        printf("\n\tDame el numero de alumnos que deseas Registrar\n");
        printf("\n************************************************************\n------> ");
        scanf("%d%*c",&Num_Alums);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        //fclose(Arch_Alum);
        
        for(a=1;a<=Num_Alums;a++){
            Arch_Alum = fopen("Regist_Alumns.bin","ab+");
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            printf("\n*****************************************\n");
            printf("\n\tDame la matricula del Alumno No. %d",a);
            printf("\n*****************************************\n------> ");
            scanf("%[^\n]%*c",Matricula);
            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            strcpy(Sancion,Sancionado);
            //fwrite()matricula
            fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
            fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
            //fwrite()sancion
            fclose(Arch_Alum);
        }
        

    }//En caso de que no exista el archivo
}
//---------------------------------------------------------------------------------------------------------------------------------
void Regist_Prest_Adm (){
    
    int Registrar = 0;
    const char* Sancionado = "Si_San";
    const char* No_Sancionado = "No_San";
    int valid_PC_For_Edt = 1;
    const char* Si_Disp = "En_Fun";
    const char* No_Disp = "No_Fun";
    char Buffer_Disponibilidad [7];
    char Disponibilidad [7];
    char Buffer_Usabilidad [7];
    char Usabilidad [7];
    const char* Si_Usable = "No_Uso";
    const char* No_Usable = "Si_Uso";
    char Alum_Nom[40];
    char Fecha[10];
    char PC_Nombre[4];
    char Buffer_PC_Nombre[4];
    char Pulse;
    char Ing_UsrAdm[20];
    char Ing_PssAdm[20];
    char Buffer_UsrAdm[20];
    char Buffer_PssAdm[20];
    char Lab_Nombre[4];
    char Lab_Nombre_Cpy[10];
    int Valid_Adm_Pass = 1;
    int Valid_Adm_Log = 0;
    int Seguir_PC = 1;
    int Seguir = 1;
    int Ext_File_Labs=1;
    const char* Bin = ".bin";
    char Matricula[15];
    char Buffer_Matricula[15];
    char Sancion[15];
    char Buffer_Sancion[15];
    
    FILE *Arch_Labs;
    FILE *file;
    FILE *Arch_Alum; 
    FILE *Arch_Prest;

    //printf("\e[1;1H\e[2J");////////////////////////////////////////////////////////////
    printf("\n\n********************************************************************\n");
    printf("\n\tHaz seleccionado Registrar prestamo");
    printf("\n\tEs necesario que vuelvas a registrar tu usuario");
    printf("\n********************************************************************\n\n------------> ");
    fflush(stdin);
    scanf("%[^\n]%*c",Ing_UsrAdm);
    //scanf("%c%*c",&Pulse);
    
    file = fopen("Passwd_Admin.bin","rb");
    while(!feof(file)){
        
        fread(Buffer_UsrAdm, sizeof(Buffer_UsrAdm), 1, file);
        fread(Buffer_PssAdm, sizeof(Buffer_PssAdm), 1, file);
        Valid_Adm_Log = 1;
        Valid_Adm_Log = strcmp(Buffer_UsrAdm,Ing_UsrAdm);
        if(Valid_Adm_Log == 0){
            
            printf("\n\n********************************************************************\n");
            printf("\n\tHay coincidencia.");
            printf("\n\tEs necesario que vuelvas a registrar tu contraseña");
            printf("\n********************************************************************\n\n------------> ");
            fflush(stdin);
            scanf("%[^\n]%*c",Ing_PssAdm);
            Valid_Adm_Pass = strcmp(Buffer_PssAdm,Ing_PssAdm);
            break;
            
        }
    }
    fclose(file);
    
    if(Valid_Adm_Log != 0){
        //printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("*******************************************\n\n");
        printf("\tEste usuario no esta registrado");
        printf("\n\tpresione ENTER para continuar...\n\n");
        printf("*******************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        
    }
    
    if(Valid_Adm_Pass == 0){
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("*****************************************************************\n\n");
        printf("\n\t\t\t|Usuario Registrado|\n");
        printf("\n\tIngrese el laboratorio en el que se encuentra.");
        printf("\n\t\tRecuerde que la nomenclatura es LT+Numero del laboratorio");
        printf("\n\t\t\tEjemplo... \"LT1\", \"LT2\",...,\"LTX\".\n\n\n");
        printf("*****************************************************************\n------> ");
        scanf("%[^\n]%*c",Lab_Nombre);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        strcpy(Lab_Nombre_Cpy,Lab_Nombre);
        strcat(Lab_Nombre_Cpy, Bin);
        do {
            if (Arch_Labs = fopen(Lab_Nombre_Cpy, "r")) {
            
                Ext_File_Labs = 0;
                fclose(Arch_Labs);
                break;
            }
            else{
                
                printf("*********************************************");
                printf("\n\n\n\tEl laboratorio que ingreso no existe");
                printf("\n\tDesea seguir intentando?");
                printf("\n\n\t\t\t1.- Si");
                printf("\n\t\t\t2.- No\n\n\n");
                printf("*********************************************\n------> ");
                scanf("%d%*c",&Seguir);
            }
            
        }while( Seguir != 2 );
        if(Ext_File_Labs == 0){
            while(Seguir_PC!=2){
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**********************************************************\n\n");
                printf("\n\t\t\tEl laboratorio existe!");
                printf("\n\n\tPor favor ingresa el nombre de la PC\n\n\n");
                printf("\n\t\tRecuerde que la nomenclatura es PC+Numero de la PC");
                printf("\n\t\t\tEjemplo... \"PC1\", \"PC2\",...,\"PCX\".\n\n\n");
                printf("**********************************************************\n-----> ");
                scanf("%[^\n]%*c",PC_Nombre);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                Arch_Labs = fopen(Lab_Nombre_Cpy,"rb+");
            
                while(!feof(Arch_Labs)){
                    fread(Buffer_PC_Nombre, sizeof(Buffer_PC_Nombre), 1, Arch_Labs);
                    fread(Buffer_Disponibilidad, sizeof(Buffer_Disponibilidad), 1, Arch_Labs);
                    fread(Buffer_Usabilidad, sizeof(Buffer_Usabilidad), 1, Arch_Labs);
                    if (strcmp(Buffer_PC_Nombre,PC_Nombre)==0){
                        strcpy(Usabilidad, Si_Usable);
                        if(strcmp(Buffer_Disponibilidad,Disponibilidad)==0){
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            printf("****************************************************************\n");
                            printf("\n\tEsta PC está registrada como %s",Buffer_Disponibilidad);
                            printf("\n\tLibere primero en el Registro de PC's fuera de servicio");
                            printf("\n\n\t\t\t1.- Si");
                            printf("\n\t\t\t2.- No\n\n\n");
                            printf("****************************************************************\n------> ");
                            scanf("%d%*c",&Seguir_PC);
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            fclose(Arch_Labs);
                            break;
                        }
                        if(strcmp(Buffer_Usabilidad,Usabilidad)==0){
                            strcpy(Usabilidad,No_Usable);
                            fseek(Arch_Labs, -7 , SEEK_CUR);
                            fwrite(Usabilidad, 1 , sizeof(Usabilidad), Arch_Labs);
                            fclose(Arch_Labs);
                            valid_PC_For_Edt = 0;
                            Seguir_PC=2;
                            break;
                        }
                        else{
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            printf("****************************************************************\n");
                            printf("\n\tEsta PC está registrada como %s",Buffer_Usabilidad);
                            printf("\n\tLibere primero en el Registro de PC's fuera de servicio");
                            printf("\n\n\t\t\t1.- Si");
                            printf("\n\t\t\t2.- No\n\n\n");
                            printf("****************************************************************\n------> ");
                            scanf("%d%*c",&Seguir_PC);
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            fclose(Arch_Labs);
                            break;
                        }
                    }
                }
                if(strcmp(Buffer_PC_Nombre,PC_Nombre)!=0){
                    printf("**********************************************************\n\n");
                    printf("\n\t\t\tLa PC igresada no existe!");
                    printf("\n\t\tRecuerde que la nomenclatura es PC+Numero de la PC");
                    printf("\n\t\t\tEjemplo... \"PC1\", \"PC2\",...,\"PCX\".\n\n");
                    printf("\n\tDesea volver a intentar?");
                    printf("\n\n\t\t\t1.- Si");
                    printf("\n\t\t\t2.- No\n\n\n");
                    printf("**********************************************************\n-------> ");
                    scanf("%d%*c",&Seguir_PC);
                }
            }
            if(valid_PC_For_Edt==0){
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("****************************************************\n\n");
                printf("\n\tDe momento, los datos son correctos.\n");
                printf("\tPor favor ingrese la matrícula del Alumno\n\n\n");
                printf("****************************************************\n------> ");
                scanf("%[^\n]%*c",Matricula);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                if(Arch_Alum = fopen( "Regist_Alumns.bin" , "r")){
                    fclose(Arch_Alum);
                    Arch_Alum = fopen( "Regist_Alumns.bin" , "rb");
                    while(!feof(Arch_Alum)){

                        fread(Buffer_Matricula, sizeof(Buffer_Matricula), 1, Arch_Alum);
                        fread(Buffer_Sancion, sizeof(Buffer_Sancion), 1, Arch_Alum);
                        if(strcmp(Buffer_Matricula,Matricula)==0){
                            strcpy(Sancion,Buffer_Sancion);
                            break;
                        }
                        
                    }
                    if(strcmp(Buffer_Matricula,Matricula)!=0){
                        fclose(Arch_Alum);
                        Arch_Alum = fopen( "Regist_Alumns.bin" , "ab+");
                        strcpy(Sancion,No_Sancionado);
                        fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
                        fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                        fclose(Arch_Alum);
                    }
                }
                else{
                    Arch_Alum = fopen( "Regist_Alumns.bin" , "wb+");
                    strcpy(Sancion,No_Sancionado);
                    fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
                    fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                    fclose(Arch_Alum);
                }
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("****************************************************\n\n");
                printf("\n\tProceso Matricula terminado...\n");
                printf("\tPor favor ingrese la fecha en formato dd/mm/aaaa\n\n-------> ");
                scanf("%[^\n]%*c",Fecha);
                printf("\n\n\tPor favor ingrese el nombre del alumno\n\n\n");
                printf("****************************************************\n------> ");
                scanf("%[^\n]%*c",Alum_Nom);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("****************************************************\n\n");
                printf("\n\tTodo el proceso está listo...\n");
                printf("\n\tEl alumno %s esta registrado como %s \n",Alum_Nom,Sancion);
                printf("\t\tDesea Registrar el prestamo?\n\n");
                printf("\t\t\t1.-Si\n");
                printf("\t\t\t2.-No\n");
                printf("****************************************************\n------> ");
                scanf("%d%*c",&Registrar);
                if (Registrar==1){
                    Arch_Prest=fopen("Regist_Prest.txt","a+");
                    fprintf(Arch_Prest, "El Administrador: %s registro el prestamo de la %s en el %s , el dia %s al alumno %s con matricula %s.\n",Ing_UsrAdm, PC_Nombre,Lab_Nombre,Fecha,Alum_Nom,Matricula);
                    fclose(Arch_Prest);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
void Regist_Prest_Tech (){

    int Registrar = 0;
    const char* Sancionado = "Si_San";
    const char* No_Sancionado = "No_San";
    int valid_PC_For_Edt = 1;
    const char* Si_Disp = "En_Fun";
    const char* No_Disp = "No_Fun";
    char Buffer_Disponibilidad [7];
    char Disponibilidad [7];
    char Buffer_Usabilidad [7];
    char Usabilidad [7];
    const char* Si_Usable = "No_Uso";
    const char* No_Usable = "Si_Uso";
    char Alum_Nom[40];
    char Fecha[10];
    char PC_Nombre[4];
    char Buffer_PC_Nombre[4];
    char Pulse;
    char Ing_UsrTech[20];
    char Ing_PssTech[20];
    char Buffer_UsrTech[20];
    char Buffer_PssTech[20];
    char Lab_Nombre[4];
    char Lab_Nombre_Cpy[10];
    int Valid_Tech_Pass = 1;
    int Valid_Tech_Log = 0;
    int Seguir_PC = 1;
    int Seguir = 1;
    int Ext_File_Labs=1;
    const char* Bin = ".bin";
    char Matricula[15];
    char Buffer_Matricula[15];
    char Sancion[15];
    char Buffer_Sancion[15];
    
    FILE *Arch_Labs;
    FILE *Archivo;
    FILE *Arch_Alum; 
    FILE *Arch_Prest;

    //printf("\e[1;1H\e[2J");////////////////////////////////////////////////////////////
    printf("\n\n********************************************************************\n");
    printf("\n\tHaz seleccionado Registrar prestamo");
    printf("\n\tEs necesario que vuelvas a registrar tu usuario");
    printf("\n********************************************************************\n\n------------> ");
    fflush(stdin);
    scanf("%[^\n]%*c",Ing_UsrTech);
    //scanf("%c%*c",&Pulse);
   // printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
    
    Archivo = fopen("Passwd_Tech.bin","rb");
    while(!feof(Archivo)){
        
        fread(Buffer_UsrTech, sizeof(Buffer_UsrTech), 1, Archivo);
        fread(Buffer_PssTech, sizeof(Buffer_PssTech), 1, Archivo);
        Valid_Tech_Log = 1;
        Valid_Tech_Log = strcmp(Buffer_UsrTech,Ing_UsrTech);
        if(Valid_Tech_Log == 0){
            
            printf("\n\n********************************************************************\n");
            printf("\n\tHay coincidencia.");
            printf("\n\tEs necesario que vuelvas a registrar tu contraseña");
            printf("\n********************************************************************\n\n------------> ");
            fflush(stdin);
            scanf("%[^\n]%*c",Ing_PssTech);
            //printf("\e[1;1H\e[2J");///////////////////////////////////////////////////////////////
            
            Valid_Tech_Pass = strcmp(Buffer_PssTech,Ing_PssTech);
            break;
        }
    }
    fclose(Archivo);
    
    if(Valid_Tech_Log != 0){
        //printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("*******************************************\n\n");
        printf("\tEste usuario no esta registrado");
        printf("\n\tpresione ENTER para continuar...\n\n");
        printf("*******************************************\n\n\t\t");
        scanf("%c%*c",&Pulse);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    }
    
    if(Valid_Tech_Pass == 0){
        
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        printf("*****************************************************************\n\n");
        printf("\n\t\t\t|Usuario Registrado|\n");
        printf("\n\tIngrese el laboratorio en el que se encuentra.");
        printf("\n\t\tRecuerde que la nomenclatura es LT+Numero del laboratorio");
        printf("\n\t\t\tEjemplo... \"LT1\", \"LT2\",...,\"LTX\".\n\n\n");
        printf("*****************************************************************\n------> ");
        scanf("%[^\n]%*c",Lab_Nombre);
        printf("\e[1;1H\e[2J");//////////////////////////////////////////////
        strcpy(Lab_Nombre_Cpy,Lab_Nombre);
        strcat(Lab_Nombre_Cpy, Bin);
        do {
            if (Arch_Labs = fopen(Lab_Nombre_Cpy, "r")) {
                Ext_File_Labs = 0;
                fclose(Arch_Labs);
                break;
            }
            else{
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("*********************************************");
                printf("\n\n\n\tEl laboratorio que ingreso no existe");
                printf("\n\tDesea seguir intentando?");
                printf("\n\n\t\t\t1.- Si");
                printf("\n\t\t\t2.- No\n\n\n");
                printf("*********************************************\n------> ");
                scanf("%d%*c",&Seguir);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
            }
            
        }while( Seguir != 2 );
        if(Ext_File_Labs == 0){
            while(Seguir_PC!=2){
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("**********************************************************\n\n");
                printf("\n\t\t\tEl laboratorio existe!");
                printf("\n\n\tPor favor ingresa el nombre de la PC\n\n\n");
                printf("\n\t\tRecuerde que la nomenclatura es PC+Numero de la PC");
                printf("\n\t\t\tEjemplo... \"PC1\", \"PC2\",...,\"PCX\".\n\n\n");
                printf("**********************************************************\n-----> ");
                scanf("%[^\n]%*c",PC_Nombre);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                Arch_Labs = fopen(Lab_Nombre_Cpy,"rb+");
            
                while(!feof(Arch_Labs)){
                    fread(Buffer_PC_Nombre, sizeof(Buffer_PC_Nombre), 1, Arch_Labs);
                    fread(Buffer_Disponibilidad, sizeof(Buffer_Disponibilidad), 1, Arch_Labs);
                    fread(Buffer_Usabilidad, sizeof(Buffer_Usabilidad), 1, Arch_Labs);
                    if (strcmp(Buffer_PC_Nombre,PC_Nombre)==0){
                        strcpy(Usabilidad, Si_Usable);
                        if(strcmp(Buffer_Disponibilidad,Disponibilidad)==0){
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            printf("****************************************************************\n");
                            printf("\n\tEsta PC está registrada como %s",Buffer_Disponibilidad);
                            printf("\n\tLibere primero en el Registro de PC's fuera de servicio");
                            printf("\n\n\t\t\t1.- Si");
                            printf("\n\t\t\t2.- No\n\n\n");
                            printf("****************************************************************\n------> ");
                            scanf("%d%*c",&Seguir_PC);
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            fclose(Arch_Labs);
                            break;
                        }
                        if(strcmp(Buffer_Usabilidad,Usabilidad)==0){
                            strcpy(Usabilidad,No_Usable);
                            fseek(Arch_Labs, -7 , SEEK_CUR);
                            fwrite(Usabilidad, 1 , sizeof(Usabilidad), Arch_Labs);
                            fclose(Arch_Labs);
                            valid_PC_For_Edt = 0;
                            Seguir_PC=2;
                            break;
                        }
                        else{
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            printf("****************************************************************\n");
                            printf("\n\tEsta PC está registrada como %s",Buffer_Usabilidad);
                            printf("\n\tLibere primero en el Registro de PC's fuera de servicio");
                            printf("\n\n\t\t\t1.- Si");
                            printf("\n\t\t\t2.- No\n\n\n");
                            printf("****************************************************************\n------> ");
                            scanf("%d%*c",&Seguir_PC);
                            printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                            fclose(Arch_Labs);
                            break;
                        }
                    }
                }
                if(strcmp(Buffer_PC_Nombre,PC_Nombre)!=0){
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                    printf("**********************************************************\n\n");
                    printf("\n\t\t\tLa PC igresada no existe!");
                    printf("\n\t\tRecuerde que la nomenclatura es PC+Numero de la PC");
                    printf("\n\t\t\tEjemplo... \"PC1\", \"PC2\",...,\"PCX\".\n\n");
                    printf("\n\tDesea volver a intentar?");
                    printf("\n\n\t\t\t1.- Si");
                    printf("\n\t\t\t2.- No\n\n\n");
                    printf("**********************************************************\n-------> ");
                    scanf("%d%*c",&Seguir_PC);
                    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                }
            }
            if(valid_PC_For_Edt==0){
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("****************************************************\n\n");
                printf("\n\tDe momento, los datos son correctos.\n");
                printf("\tPor favor ingrese la matrícula del Alumno\n\n\n");
                printf("****************************************************\n------> ");
                scanf("%[^\n]%*c",Matricula);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                if(Arch_Alum = fopen( "Regist_Alumns.bin" , "r")){
                    fclose(Arch_Alum);
                    Arch_Alum = fopen( "Regist_Alumns.bin" , "rb");
                    while(!feof(Arch_Alum)){

                        fread(Buffer_Matricula, sizeof(Buffer_Matricula), 1, Arch_Alum);
                        fread(Buffer_Sancion, sizeof(Buffer_Sancion), 1, Arch_Alum);
            
                        if(strcmp(Buffer_Matricula,Matricula)==0){
                            strcpy(Sancion,Buffer_Sancion);
                            break;
                        }
                    }
                    if(strcmp(Buffer_Matricula,Matricula)!=0){
                        fclose(Arch_Alum);
                        Arch_Alum = fopen( "Regist_Alumns.bin" , "ab+");
                        strcpy(Sancion,No_Sancionado);
                        fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
                        fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                        fclose(Arch_Alum);
                    }
                }
                else{
                    Arch_Alum = fopen( "Regist_Alumns.bin" , "wb+");
                    strcpy(Sancion,No_Sancionado);
                    fwrite(Matricula, 1 , sizeof(Matricula), Arch_Alum);
                    fwrite(Sancion, 1 , sizeof(Sancion), Arch_Alum);
                    fclose(Arch_Alum);
                }
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("****************************************************\n\n");
                printf("\n\tProceso Matricula terminado...\n");
                printf("\tPor favor ingrese la fecha en formato dd/mm/aaaa\n\n-------> ");
                scanf("%[^\n]%*c",Fecha);
                printf("\n\n\tPor favor ingrese el nombre del alumno\n\n\n");
                printf("****************************************************\n------> ");
                scanf("%[^\n]%*c",Alum_Nom);
                
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                printf("****************************************************\n\n");
                printf("\n\tTodo el proceso está listo...\n");
                printf("\n\tEl alumno %s esta registrado como %s \n",Alum_Nom,Sancion);
                printf("\t\tDesea Registrar el prestamo?\n\n");
                printf("\t\t\t1.-Si\n");
                printf("\t\t\t2.-No\n");
                printf("****************************************************\n------> ");
                scanf("%d%*c",&Registrar);
                printf("\e[1;1H\e[2J");//////////////////////////////////////////////
                if (Registrar==1){
                    Arch_Prest=fopen("Regist_Prest.txt","a+");
                    fprintf(Arch_Prest, "El Tecnico: %s registro el prestamo de la %s en el %s , el dia %s al alumno %s con matricula %s.\n",Ing_UsrTech, PC_Nombre,Lab_Nombre,Fecha,Alum_Nom,Matricula);
                    fclose(Arch_Prest);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
void show_Prest(){
    
    char Pulse;
    char Transcript;
    
    FILE * Arch_Prest = fopen("Regist_Prest.txt","rb");
    
    if(Arch_Prest == NULL){
        perror("Upa! Se ha detectado un error en la apertura del registro!");
    }
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
    printf("\n*****************************************************************************************\n\n");
    while(feof(Arch_Prest)==0){
        Transcript = fgetc(Arch_Prest);
        printf("%c",Transcript);
    }
    fclose(Arch_Prest);
    printf("\n*****************************************************************************************\n\n");
    printf("\n\t\t\t\t\tLectura completa!");
    printf("\n\n\t\t\tpresione ENTER para continuar\n\n");
    printf("\n*****************************************************************************************\n\n\t\t");
    scanf("%c%*c",&Pulse);
    printf("\e[1;1H\e[2J");//////////////////////////////////////////////
}