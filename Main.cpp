#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <conio.h>
using namespace std;
#include "Struct.cpp"
#include "Functii.cpp"
#include "Meniu.cpp"
int main()
{
	//pas1
	readFILEconf();
	
	//pas2 
	NU=readFILE(FILEuser,USER);
	NS=readFILE(FILEstud,STUD);
	NSt=readFILE(FILEstat,STAT);
	
	if(contorERROR>0)	exit(0);
	
	//pas 3
	system("cls");
	UID=login();

	
	while(1)
	{
		system("cls");
		
		switch(USER[UID].tip)
		{
			case 0 : SYSTEM=userMENIU();	
			case 1 : SYSTEM=adminMENIU();  
		}
		
		switch(SYSTEM)
		{
			//1.2
			case 121 : system("cls"); 	insertUSER(); break; 
			case 122 : system("cls");	editUSER();	break;
			case 123 : system("cls");	showUSER();	system("pause"); break;		
			case 124 : system("cls");   findUSER(); system("pause"); break;
		
			case 102 : system("cls"); insertSTUD();  break; 
			case 103 : system("cls"); showSTUD(); system("pause"); break; 	
			
			//4.2
			case 421 : system("cls"); findSTUDnume(); system("pause"); break;
			case 422 : system("cls"); fintSTUDprenume(); system("pause"); break;
			case 423 : system("cls"); fintSTUDidnp(); system("pause"); break;
			case 424 : system("cls"); fintSTUDgrupa(); system("pause"); break;
			 
			case 105 : system("cls"); editSTUD(); system("pause"); break; 
			
			//6.2
			case 622 : system("cls"); raportSTAT(); system("pause"); break; 
			
			//6.3
			case 631 : system("cls"); raportVarsta(); system("pause"); break; 
			case 632 : system("cls"); raportGrupa(); system("pause"); break; 
			case 633 : system("cls"); raportSTUD(); system("pause"); break;
				
			case 107 : writeFILE(FILEuser,USER,NU);
					   writeFILE(FILEstud,STUD,NS);
					   writeFILE(FILEstat,STAT,NSt);
					   exit(0);
		}
	}
	
	return 0;
}
