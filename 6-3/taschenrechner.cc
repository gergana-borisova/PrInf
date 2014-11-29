#include"fcpp.hh"
#include<string.h> // fuer strlen, Laenge eines C-Strings

// Definieren Sie hier Ihren Stack und legen Sie eine Instanz als globale
// Variable an
const int stack_size = 16;

struct Stack {
	float value[stack_size];
	int top;
};
Stack stack_rpn;


void push (float new_element)
{
	stack_rpn.value[stack_rpn.top] = new_element;
	stack_rpn.top++;
}

float pop ()
{
	stack_rpn.top--;
	return stack_rpn.value[stack_rpn.top];
}

// Funktion, die auf dem Stack eine Rechenoperation durchführt
// Rückgabewert: ob die Berechnung durchgeführt werden konnte
bool rechne(char operation)
{
  // Pruefen Sie zunaechst, ob genuegend Zahlen auf dem Stack liegen, und
  // achten Sie bei der Berechnung auf die Reihenfolge der Zahlen
	if (stack_rpn.top > 1)
	{
		float op2 = pop();
		float op1 = pop();
		switch (operation)
		{
			case 43: push(op1+op2); break;
			case 45: push(op1-op2); break;
			case 42: push(op1*op2); break;
			case 47: push(op1/op2); break;
			default: push(op1); push(op2); return false; break;
		}
		return true;
	}
	else
		return false;
}

int main(int argc, char* argv[])
{
  // arg enthaelt die als Eingabe uebergebene Zeichenfolge
  char* arg = argv[1];
  stack_rpn.top = 0;
  int number = 0;
  bool read_num = false;

  // Schleife, die die Zeichen der Eingabe nacheinander ablaeuft
  for (int i = 0; i <= strlen(arg); i = i+1)
  {
    char zeichen = arg[i]; // aktuelles Zeichen
    // Beachten Sie: der Inhalt der Variable zeichen ist der ASCII-Code
    // des entsprechenden Zeichens. Dieser stimmt im Falle der Zeichen '0'..'9'
    // nicht mit der entsprechenden Ziffer überein.

    // Fuegen Sie hier Code ein, der das Zeichen verarbeitet, also Ziffern
    // zu Zahlen zusammenfügt, Operatoren anwendet und andere Zeichen
    // ignoriert
    if ((zeichen >= 48) && (zeichen <= 57)) //Ziffer gelesen
    {
    	if (read_num) //vorherige Eingabe war Ziffer
    		number *= 10;
    	number += zeichen-48;
    	read_num = true;
    }
    else //keine Ziffer gelesen
    {
    	if (read_num) //vorherige Eingabe war Ziffer
    	{
			push(number);
			number = 0;
			read_num = false;
    	}
    	rechne(zeichen);
    }
  }

  // Hier muessen Sie evtl. den Sonderfall behandeln, dass die Formel keine
  // Operatoren enthält

  // Pruefen Sie, ob der Stack genau eine Zahl (das Ergebnis) enthält, und
  // geben Sie sie gegebenenfalls aus

  if (stack_rpn.top == 1)
  {
	  float result = pop();
	  print(result);
	  return result;
  }
  else
  {
	  printf("Stack enthält mehr als 1 Element!\n");
	  return 0;
  }
}
