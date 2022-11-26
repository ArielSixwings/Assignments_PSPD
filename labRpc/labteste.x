struct params{
    char arqName[100];
};

typedef string words<>;

struct result {
    words object<>;
    int count[1000];
    int index;
};

program PROG{
	version VERSAO{
		result WORDCOUNT(params)=1;
	}=100;
}=55555555;