#include <cstdlib>

struct IntListElem {
  IntListElem* next;  // Zeiger auf nächstes Element
  int value;          // Daten zu diesem Element
} ;
// Ein Listenelement
struct IntListElem2 {
  IntListElem2* next;  // Zeiger auf nächstes Element
  IntListElem2* previous; //Zeiger auf vorheriges Element
  int value;          // Daten zu diesem Element
} ;

// Eine Liste
struct IntList {
  int count;          // Anzahl Elemente in der Liste
  IntListElem* first; // Zeiger auf erstes Element der Liste
} ;

// Eine Liste
struct IntList2 {
  int count;          // Anzahl Elemente in der Liste
  IntListElem2* first; // Zeiger auf erstes Element der Liste
  IntListElem2* last;  // Zeiger auf letztes Element der Liste
} ;

// Initialisiere eine Listenstruktur
void empty_list (IntList* l)
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->count = 0;
}

// Initialisiere eine Listenstruktur
void empty_list2 (IntList2* l)
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->last = 0;
  l->count = 0;
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list (IntList* list, IntListElem* ins)
{
      ins->next = list->first;
      list->first = ins;
      list->count = list->count + 1;
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list2 (IntList2* list, IntListElem2* ins)
{
      ins->next = list->first;
      ins->previous = 0;
      list->first = ins;
      list->count = list->count + 1;
}

// Entferne ein Element nach einem gegebenem
// Liefere das entfernte Element zurueck
IntListElem* remove_from_list (IntList* list)
{
  IntListElem* p1 = list->first;  // das entfernte Element

  if (p1 != 0)
  {
	  IntListElem* p2 = p1->next;
	  if (p2 != 0)
	  {
		  while (p2->next != 0)
		  {
			  p1 = p2;
		  	  p2 = p2->next;
		  }
		  p1->next = 0;
		  return p2;
	  }
	  else
		  list->first = 0;
  }
  return p1;
}

// Entferne ein Element nach einem gegebenem
// Liefere das entfernte Element zurueck
IntListElem2* remove_from_list2 (IntList2* list)
{
  IntListElem2* p;  // das entfernte Element

  p = list->last;

  if (p != 0)
  {
	  list->last = p->previous;
	  list->count = list->count - 1;
  }
  return p;
}

int main()
{
	const int queue_size = 1e5;
	IntList* queue = new IntList;
	IntList2* queue2 = new IntList2;

	for (int i=0; i<queue_size; i++) // O(n)
	{
		IntListElem* p = new IntListElem;
		p->value = rand();
		insert_in_list(queue, p);
	}

	for (int i=0; i<queue_size; i++) // O(n)
	{
		IntListElem2* p = new IntListElem2;
		p->value = rand();
		insert_in_list2(queue2, p);
	}

	IntListElem* p = new IntListElem;
	IntListElem2* p2 = new IntListElem2;


	do // O(n²)
	{
		p = remove_from_list(queue);
		delete p;
	} while (p != 0);

	do // O(n)
	{
		p2 = remove_from_list2(queue2);
		delete p2;
	} while (p2 != 0);


	delete queue;
	delete queue2;
	return 0;
}

/* Laufzeit einfach verkettete Liste: O(n) + O(n²) = O(n²)
 * Laufzeit doppelt verkettete Liste: O(n) + O(n)  = O(n)
 */
