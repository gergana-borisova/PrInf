#include "fcpp.hh"

int rpuffer[10];
const int start = 4; //Startindex

int out = start;
int in = out+1;

void inc_out() //inkrementiere out
{
	out++;
	if (out == 10) //Buffer-Overflow
		out = 0;
}

void inc_in()  //inkrementiere in
{
	in++;
	if (in == 10) //Buffer-Overflow
		in = 0;
	if (in == out)
	{
		printf("Puffer voll!\n");
		inc_out();
	}
}

void write(int n) //schreibe n an Stelle in
{
	if (n == 0) //Element löschen
	{
		printf("out=%d\n", rpuffer[out]);
		rpuffer[out] = 0;
		inc_out();
	}
	else
	{
		rpuffer[in] = n;
		inc_in();
	}
}

void print_puffer() //Ringpuffer-Ausgabe
{
	for (int i=0; i<10; i++)
	{
		if (i == in)
			printf(">");
		if (i == out)
			printf("<");
		printf("\t%d\n", rpuffer[i]);
	}
}

int main()
{
	rpuffer[out] = 1;   //Startkonfiguration mit einer 1 an Stelle "out".

	while (true)        //Programm wird nicht beendet, solange positive Zahlen oder 0 angegeben wird.
	{
		int n = enter_int("Eingabe: ");
		if (n < 0)
			return 0;
		write(n);
		print_puffer();
	}
}
