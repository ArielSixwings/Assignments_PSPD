struct params{
	char name[100];
	FILE *fptr;
};

program PROG{
	version VERSION{
		int WORDCOUNT(params)=1;
		FILE *GETFILE(params)=2;
	}=100;
}=55555555;