#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;



	struct user
	{
		char username[100];
		char userpass[100];
		
		bool tip;	//0-user,	1-admin
		int stare=1;
		
		int id; 
	};
	
	struct stud
	{
		char nume[150];
		char prenume[150];
		
		int ani;
		char IDNP[13];
		char grupa[150];
		
		int userID;
		
		bool stare=1;
	};	
	
	struct statistica
	{
		int id;
		int nrAccesari;
		int nrUsers;
		int nrStuds;
		int nrStudsEdit;
		int nrStudsDez;
	};
	
	user USER[1000];
	int NU=0;
	
	stud STUD[1000];
	int NS=0;
	
	FILE *fp;
	
int main()
{
	strcpy(USER[0].username,"admin");
	strcpy(USER[0].userpass,"admin");
	USER[0].tip=1;
	USER[0].id=0;
	
	
	fp=fopen("users.step","w+b");
	
	if(fp==NULL) {	cout<<"ERROR"<<endl;	exit(0); }
	else {	cout<<"OK w+b"<<endl;}
	
	fwrite(USER,sizeof(user),1,fp);
	
	

	return 0;
}
