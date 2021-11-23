template <typename T>
int writeFILE(char*fn,T str[],int nr)
{
	fp = fopen(fn,"w+b");
	if(fp==NULL){ cout<<"ERROR::"<<endl; }
	else { cout<<"OK::"<<endl;}
	
	fwrite(str,sizeof(str[0]),nr,fp);
	fclose(fp);
}
template <typename T>
int readFILE(char *fn,T str[])
{
	fp = fopen(fn, "r+b");
	if(fp==NULL){ cout<<"ERROR::fisierul nu exista"<<endl;	exit(0); }
	else { cout<<"OK::fisierul exista"<<endl; }
	
	int x=fread(str,sizeof(str[0]),1000,fp);

	fclose(fp);
	return x;
}

void readFILEconf()
{
	fp=fopen("conf.ini","r+");
	if(fp==NULL){ cout<<"ERROR::fisierul conf.ini nu exista"<<endl;	system("pause");	exit(0); }
	else { cout<<"OK::fisierul conf.ini exista"<<endl; }
	
	fscanf(fp,"%s%s%s",&FILEuser,&FILEstud,&FILEstat);
	fclose(fp);
}

int login()
{
	char UN[100];
	char UP[100];
	int ID;
	int p=0;

	
	while(1)
	{
	
		system("cls");
	
		cout<<" \n\n\t Enter username:";
		cin>>UN;
	
		cout<<" \n\t Enter userpass:";
		while(1)
		{
			UP[p]=_getch();
			
			if( int(UP[p]) == 8 )
			{
				if( p > 0)
				{
				cout<<"\b \b";
				p--;
				}
			}
			
			else if( int(UP[p]) == 13 )
			{
				UP[p]=0;
				p=0;
				break;
			}
			
			else
			{
				cout<<"*";
				p++;
			}
		}
	
		bool OK=0;
	  	for(int i=0; i<NU; i++)
	  	{ 
	    	if( strcmp(USER[i].userpass, UP)==0 && strcmp(USER[i].username, UN)==0 )
	  		{
	  	  		ID=i; OK=1;cout<<"\n OK "<<endl;	 break;
			}
	  	}
		if(OK){ STAT[ID].NRAcces++; cout<<" Cont activ "<<endl; break;	}
	}
	return ID;	
}


void insertUSER()
{
	do
	{
		system("cls");
		cout<<"\t\tUSER["<<NU+1<<']'<<endl;
			
		cout<<"\n\tEnter username : ";	cin>>USER[NU].username;
		for(int i=0;i<NU;i++)
		{
			if(strcmp(USER[NU].username,USER[i].username)==0) 
			{
				cout<<"Acest utilizator exista!\nIncercati alt username!"<<endl;
				cout<<"\n\tEnter username : ";	cin>>USER[NU].username;
			}
			else break;
		}
			
		cout<<"\n\tEnter userpassword : ";	cin>>USER[NU].userpass;
		cout<<"\n\tEnter tip : ";	cin>>USER[NU].tip;
		cout<<"\n\tEnter stare : ";	cin>>USER[NU].stare;
		USER[NU].id=NU;
		NSt=NU;
		STAT[NU].id=NU;
		STAT[UID].nrUsers++;
		NU++;
		cout<<"Enter next user ? Any KEY or ESC for exit"<<endl;
	}while(_getch()!=27);
}


void editUSER()
{	
	int uid;
	char x;
	
	do
	{
		cout<<"\nEnter user id : ";	cin>>uid;
		cout<<"\tUSERNAME ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter username : ";	cin>>USER[uid].username;
		}
		
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tUSERPASS ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter userpass : ";	cin>>USER[uid].userpass;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tTIP ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter tip : ";	cin>>USER[uid].tip;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tSTARE ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter stare : ";	cin>>USER[uid].stare;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"Edit next user ? Any KEY or ESC for exit"<<endl;
	}while(_getch()!=27);
		
}


void showUSER()
{
		cout<<setw(6)<<"Numar"<<setw(12)<<" Username "<<setw(12)<<" Userpass "<<setw(10)<<" Tip "<<setw(10)<<" Stare "<<endl;
   		cout<<"_______________________________________________________________________________"<<endl;
   		
  		for(int i=0; i < NU ;i++)
     	{
      		cout<<setw(5)<<i+1<<setw(10)<<USER[i].username<<setw(10)<<setw(12)<<USER[i].userpass<<setw(10)<<USER[i].tip<<setw(10)<<USER[i].stare<<endl;
      		cout<<"_______________________________________________________________________________"<<endl;
  		} 
}

void findUSER()
{
	int id;
	bool x=1;
	cout<<"\tEnter user ID ::";
	cin>>id;
	
	cout<<setw(6)<<"Numar"<<setw(12)<<" Username "<<setw(12)<<" Userpass "<<setw(10)<<" Tip "<<setw(10)<<" Stare "<<endl;
   	cout<<"____________________________________________________"<<endl;
   	
	for(int i=0;i<NU;i++)
	{
		if(USER[i].id==id)
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(10)<<USER[i].username<<setw(12)<<USER[i].userpass<<setw(10)<<USER[i].tip<<setw(10)<<USER[i].stare<<endl;
      		cout<<"____________________________________________________"<<endl;
		}
	}
	if(x){ cout<<"NU EXISTA"<<endl; }
}	

void insertSTUD()
{
	do
	{
		system("cls");
		cout<<"\t\tStudent["<<NS+1<<']'<<endl;
		cout<<"\n\tEnter nume : ";	cin>>STUD[NS].nume;
		cout<<"\n\tEnter prenume : ";	cin>>STUD[NS].prenume;
		cout<<"\n\tEnter ani : ";	cin>>STUD[NS].ani;
		cout<<"\n\tEnter IDNP : ";	cin>>STUD[NS].IDNP;
		cout<<"\n\tEnter grupa : ";	cin>>STUD[NS].grupa;
		STUD[NS].userID=NS;
		NS++;
		STAT[UID].nrStuds++;
		cout<<"Enter next user ? Any KEY or ESC for exit"<<endl;
	}while(_getch()!=27);
}


void showSTUD()
{
	int in=0,pas=4,ur=pas;
	int contor=0,Ptotal;
	while(1)
	{
		system("cls");
		cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" grupa "<<setw(10)<<" stare "<<endl;
   		cout<<"_______________________________________________________________________________________"<<endl;
   		
  		for(int i=in; i < ur ;i++)
     	{
      		cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
      		Ptotal=NS/pas;
  		} 
  		
  		cout<<"-- PAGINA "<<contor+1<<" din "<<Ptotal<<endl;
      	cout<<"---------------------------------"<<endl;
      	cout<<" + for ->\t- for <-"<<endl;
      	cout<<"\n . ESC for EXIT ---------------"<<endl;
      
     	int KEY=_getch();
  
    	if( KEY == 43 ){ in+=pas; ur+=pas; if(ur>NS){ in= NS-pas; ur=NS; } }
        if( KEY == 45 ){ in-=pas; ur-=pas; if(in<0){ in=0; ur=pas;	} }
        if( KEY == 27 ) break;
	}
		
}

void findSTUDnume()
{
	char nume[256];
	bool x;
	cout<<"\n\tEnter name : ";	cin>>nume;
	
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" grupa "<<setw(10)<<" stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
		if(strcmp( STUD[i].nume , nume )==0 )
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
		}
	}
	
	if(x){ cout<<"NU EXISTA"<<endl; }
}


void fintSTUDprenume()
{
	char prenume[256];
	bool x;
	cout<<"\n\tEnter prenume : ";	cin>>prenume;
	cout<<endl;
	
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" grupa "<<setw(10)<<" stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
		if( strcmp( STUD[i].prenume , prenume )==0 )
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
		}
	}
	
	if(x){ cout<<"NU EXISTA"<<endl; }
}

void fintSTUDidnp()
{
	int idnp;
	bool x;
	cout<<"\n\tEnter IDNP : ";	cin>>idnp;
	cout<<endl;
	
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" grupa "<<setw(10)<<" stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
		if( STUD[i].IDNP == idnp )
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
		}
	}
	
	if(x){ cout<<"NU EXISTA"<<endl; }
}

void fintSTUDgrupa()
{
	char grupa[256];
	bool x;
	cout<<"\n\tEnter grupa : ";	cin>>grupa;
	cout<<endl;
	
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" grupa "<<setw(10)<<" stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
		if( strcmp( STUD[i].grupa , grupa)==0 )
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
		}
	}
	
	if(x){ cout<<"NU EXISTA"<<endl; }
}

void editSTUD()
{	
	int sid;
	char x;
	
	do
	{
		cout<<"\nEnter student id : ";	cin>>sid;
		cout<<"\tNUME ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter nume : ";	cin>>STUD[sid].nume;
		}
		
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tPRENUME ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter prenume : ";	cin>>STUD[sid].prenume;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tANI ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter ani : ";	cin>>STUD[sid].ani;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tIDNP ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter idnp : ";	cin>>STUD[sid].IDNP;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tGRUPA ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter grupa : ";	cin>>STUD[sid].grupa;
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		
		cout<<"\tSTARE ?  [D]-da / [N]-nu"<<endl;
		x=_getch();
		if(toupper(x)=='D')
		{
			cout<<"Enter stare : ";	cin>>STUD[sid].stare;
			if(STUD[sid].stare==0){ STAT[UID].nrStudsDez++; }
		}
		else if(toupper(x)=='N')
		{
			cout<<"\n\t Next-ANY KEY / exit-ESC "<<endl;
			x=_getch();
		}
		STAT[UID].nrStudsEdit++;
		cout<<"Edit next student ? Any KEY or ESC for exit"<<endl;
	}while(_getch()!=27);
		
}

void raportVarsta()
{
	int ani;
	bool x;
	cout<<"\n\tEnter varsta stud : ";	cin>>ani;
	cout<<endl;
	
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" Grupa "<<setw(10)<<" Stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
		if( STUD[i].ani == ani )
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
		}
	}
	if(x){ cout<<"Nu exista aceasta varsta!!!"<<endl; }
	
	fp = fopen("raport.doc", "w+");
	if(fp==NULL) {  cout<<" Eroare:: Fisierul "<<" nu exista "<<endl;  }
	else {  cout<<"\n OK "<<endl; }
	
	fprintf(fp,"_________________________________________________________________\n");
	fprintf(fp," %6s %10s %10s %6s %10s %6s %6s\n","Numar"," Nume "," Prenume "," Ani ","IDNP","Grupa","Stare");
	fprintf(fp,"_________________________________________________________________\n");
	for(int i=0; i < NS; i++)
    {
    	if( STUD[i].ani == ani )
    	{
    		fprintf(fp," %6d %10s %10s %6d %10d %6s %6d\n",i+1,STUD[i].nume,STUD[i].prenume,STUD[i].ani,STUD[i].IDNP,STUD[i].grupa,STUD[i].stare);
	  		fprintf(fp,"_________________________________________________________________\n");
		}
    } 
	
	
	fclose(fp);
	system("raport.doc");
}

void raportGrupa()
{
	char grupa[200];
	bool x;
	cout<<"\n\tEnter grupa stud : ";	cin>>grupa;
	cout<<endl;
	
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" Grupa "<<setw(10)<<" Stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
		if( strcmp( STUD[i].grupa,grupa ) == 0 )
		{
			x=0;
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
		}
	}
	if(x){ cout<<"Nu exista student in aceasta grupa!!!"<<endl; }
	
	fp = fopen("raport.doc", "w+");
	if(fp==NULL) {  cout<<" Eroare:: Fisierul "<<" nu exista "<<endl;  }
	else {  cout<<"\n OK "<<endl; }
	
	fprintf(fp,"_________________________________________________________________\n");
	fprintf(fp," %6s %15s %15s %10s %15s %10s %10s\n","Numar"," Nume "," Prenume "," Ani ","IDNP","Grupa","Stare");
	fprintf(fp,"_________________________________________________________________\n");
	for(int i=0; i < NS; i++)
    {
    	if( strcmp( STUD[i].grupa,grupa ) == 0 )
    	{
    		fprintf(fp," %6d %10s %10s %6d %10d %6s %6d\n",i+1,STUD[i].nume,STUD[i].prenume,STUD[i].ani,STUD[i].IDNP,STUD[i].grupa,STUD[i].stare);
	  		fprintf(fp,"_________________________________________________________________\n");
		}
      
    } 
	fclose(fp);
	system("raport.doc");
}

void raportSTUD()
{
	cout<<setw(6)<<"Numar"<<setw(15)<<" Nume "<<setw(15)<<" Prenume "<<setw(10)<<" Ani "<<setw(15)<<" IDNP "<<setw(10)<<" Grupa "<<setw(10)<<" Stare "<<endl;
   	cout<<"_______________________________________________________________________________________"<<endl;
	for(int i=0;i<NS;i++)
	{
			cout<<setw(5)<<i+1<<setw(15)<<STUD[i].nume<<setw(15)<<STUD[i].prenume<<setw(10)<<STUD[i].ani<<setw(15)<<STUD[i].IDNP<<setw(15)<<STUD[i].grupa<<setw(5)<<STUD[i].stare<<endl;
      		cout<<"_______________________________________________________________________________________"<<endl;
	}
	
	fp = fopen("raport.doc", "w+");
	if(fp==NULL) {  cout<<" Eroare:: Fisierul "<<" nu exista "<<endl;  }
	else {  cout<<"\n OK "<<endl; }
	
	fprintf(fp,"_________________________________________________________________\n");
	fprintf(fp," %6s %15s %15s %10s %15s %10s %10s\n","Numar"," Nume "," Prenume "," Ani ","IDNP","Grupa","Stare");
	fprintf(fp,"_________________________________________________________________\n");
	for(int i=0; i < NS; i++)
    {
    		fprintf(fp," %6d %10s %10s %6d %10d %6s %6d\n",i+1,STUD[i].nume,STUD[i].prenume,STUD[i].ani,STUD[i].IDNP,STUD[i].grupa,STUD[i].stare);
	  		fprintf(fp,"_________________________________________________________________\n");
    } 
	
	
	fclose(fp);
	system("raport.doc");
}

void raportSTAT()
{
	cout<<setw(6)<<"Numar"<<setw(15)<<" Username "<<setw(10)<<" Tip "<<setw(10)<<" Stare "<<setw(10)<<" Nr.accesari "<<setw(10)
		<<" Nr.users inserati "<<setw(10)<<" Nr.stud inserati "<<setw(10)<<" Nr.stud editati "<<setw(10)<<" Nr.stud dezactivati "<<endl;
   	cout<<"________________________________________________________________________________________________________________________________________________________"<<endl;
	for(int i=0;i<NU;i++)
	{
			cout<<setw(6)<<i+1<<setw(15)<<USER[i].username<<setw(10)<<USER[i].tip<<setw(10)<<USER[i].stare<<setw(10)<<STAT[i].NRAcces<<setw(15)
				<<STAT[i].nrUsers<<setw(20)<<STAT[i].nrStuds<<setw(20)<<STAT[i].nrStudsEdit<<setw(20)<<STAT[i].nrStudsDez<<endl;
      		cout<<"________________________________________________________________________________________________________________________________________________________"<<endl;
	}
	
	fp = fopen("raport.doc", "r+");
	if(fp==NULL) {  cout<<" Eroare:: Fisierul "<<" nu exista "<<endl;  }
	else {  cout<<"\n OK "<<endl; }
	
	fprintf(fp,"________________________________________________________________________________________________________________________________________________________\n");
	fprintf(fp," %6s %15s %10s %10s %20s %20s %20s %20s %20s\n","Numar"," Username "," Tip "," Stare ","Nr.acces","Nr.users inserati","Nr.stud inserati","Nr.stud editati","Nr.stud dezactivati");
	fprintf(fp,"________________________________________________________________________________________________________________________________________________________\n");
	for(int i=0; i < NU; i++)
    {
    		fprintf(fp," %6s %15s %10s %10s %20s %15s %20s %20s %20s\n",i+1,USER[i].username,STUD[i].prenume,USER[i].tip,USER[i].stare,STAT[i].NRAcces,STAT[i].nrUsers,STAT[i].nrStuds,STAT[i].nrStudsEdit,STAT[i].nrStudsDez);
	  		fprintf(fp,"________________________________________________________________________________________________________________________________________________________\n");
    } 
	
	fclose(fp);
	system("raport.doc");
}
