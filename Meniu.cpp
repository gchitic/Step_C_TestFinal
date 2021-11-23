int adminMENIU1()
{
	system("cls");
	NIVEL=1;
	
	cout<<"\n\n\t   __MENIUL-DE-BAZA__"<<endl;
	cout<<"\t1.Management user"<<endl;
	cout<<"\t2.Insert student"<<endl;	
	cout<<"\t3.Show student"<<endl;	
	cout<<"\t4.Find student"<<endl;	
	cout<<"\t5.Edit student"<<endl;
	cout<<"\t6.Rapoarte"<<endl;
	cout<<"\tESC.Exit"<<endl;
	
	switch(_getch())
	{
		case 49 : NIVEL=12;	break;
		case 50 : return 102;
		case 51 : return 103;
		case 52 : NIVEL=42;	break;
		case 53 : return 105;
		case 54 : NIVEL=62; break;
		
		case 27 : return 107;
	}
	return 0;
}

int adminMENIU12()
{
	system("cls");
	NIVEL=12;
	
	cout<<"\n\n\t   -__MENIUL-1.2__"<<endl;
	cout<<"\t1.Insert user"<<endl;
	cout<<"\t2.Edit user"<<endl;
	cout<<"\t3.Show user"<<endl;
	cout<<"\t4.Find user"<<endl;
	cout<<"\tESC.Back"<<endl;
	
	
	switch(_getch())
	{
		case 49 : return 121;
		case 50 : return 122;
		case 51 : return 123;
		case 52 : return 124;
		
		case 27 : NIVEL=1; break;
	}
	return 0;
}

int adminMENIU42()
{
	system("cls");
	NIVEL=42;
	
	cout<<"\n\n\t   -__MENIUL-4.2__"<<endl;
	cout<<"\t1.Cautare dupa nume"<<endl;
	cout<<"\t2.Cautare dupa prenume"<<endl;
	cout<<"\t3.Cautare dupa IDNP"<<endl;
	cout<<"\t4.Cautare dupa grupa"<<endl;
	cout<<"\tESC.Back"<<endl;
	

	switch(_getch())
	{
		case 49 : return 421;
		case 50 : return 422;
		case 51 : return 423;
		case 52 : return 424;
		
		case 27 : NIVEL=1; break;
	}
	return 0;
}

int adminMENIU62()
{
	system("cls");
	NIVEL=62;
	
	cout<<"\n\n\t   -__MENIUL-6.2__"<<endl;
	cout<<"\t1.Rapoarte student"<<endl;
	cout<<"\t2.Rapoarte statistice"<<endl;
	cout<<"\tESC.Back"<<endl;
	
	switch(_getch())
	{
		case 49 : NIVEL=63; break;
		case 50 : return 622;
		
		case 27 : return NIVEL=1; break;
	}	
	return 0;
}

int adminMENIU63()
{
	system("cls");
	NIVEL=63;
	
	cout<<"\n\n\t   -__MENIUL-6.3__"<<endl;
	cout<<"\t1.Lista studentilor dupa o varsta"<<endl;
	cout<<"\t2.Lista studentilor dupa o grupa"<<endl;
	cout<<"\t3.Lista studentilor"<<endl;
	cout<<"\tESC.Back"<<endl;
	
	switch(_getch())
	{
		case 49 : return 631;
		case 50 : return 632;
		case 51 : return 633;
		
		case 27 : NIVEL=62; break;
	}
	return 0;
}

int adminMENIU()
{
	switch(NIVEL)
	{
		case 1  : return adminMENIU1();
		case 12 : return adminMENIU12();
		case 42 : return adminMENIU42();
		case 62 : return adminMENIU62();
		case 63 : return adminMENIU63();
	}
	return 0;
}


int userMENIU1()
{
	system("cls");
	NIVEL=1;
	
	cout<<"\n\n\t   -__MENIUL-USER__"<<endl;
	cout<<"\t1.Find stud"<<endl;
	cout<<"\t2.Show stud"<<endl;
	cout<<"\t3.Editare stud"<<endl;
	cout<<"\t4.Rapoarte"<<endl;
	cout<<"\tESC.Back"<<endl;
	
	switch(_getch())
	{
		case 49 : NIVEL=42;	break;
		case 50 : return 103;	
		case 51 : return 122;	
		case 52 : NIVEL=62;	break;
		
		case 27 : return 107;
	}
	return 0;
}

userMENIU()
{
	switch(NIVEL)
	{
		case 1  : return userMENIU1();
		case 42 : return adminMENIU42();
		case 62 : return adminMENIU62();
	}
	return 0;
}

