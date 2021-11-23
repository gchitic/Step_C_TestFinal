	struct user
	{
		char username[100];
		char userpass[100];
		bool tip;
		int stare=1;
		int id;
	};
	
	struct stud
	{
		char nume[200];
		char prenume[200];
		int ani;
		int IDNP;
		char grupa[100];
		int userID;
		bool stare=1;
	};
	
	struct statistica
	{
		int id;
		int NRAcces=0;
		int nrUsers=0;
		int nrStuds=0;
		int nrStudsEdit=0;
		int nrStudsDez=0;
	};
	
	
	user USER[1000];
	int NU=0;
	
	stud STUD[1000];
	int NS=0;
	
	statistica STAT[1000];
	int NSt=0;
	
	int UID;	//user id
	
	FILE *fp;
	
	char FILEuser[200];
	char FILEstud[200];
	char FILEstat[200];
	
	int contorERROR=0;
	
	int NIVEL=1;
	int SYSTEM;
