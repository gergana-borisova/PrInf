#include "fcpp.hh"

// Ein Listenelement
struct IntListElem {
  IntListElem* next;  // Zeiger auf nächstes Element
  int value;          // Daten zu diesem Element
} ;

// Eine Liste
struct IntList {
  int count;          // Anzahl Elemente in der Liste
  IntListElem* first; // Zeiger auf erstes Element der Liste
} ;


// Initialisiere eine Listenstruktur
void empty_list (IntList* l)
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->count = 0;
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list (IntList* list, IntListElem* where, IntListElem* ins)
{
  if (where==0) // fuege am Anfang ein
    {
      ins->next = list->first;
      list->first = ins;
      list->count = list->count + 1;
    }
  else         // fuege nach where ein
    {
      ins->next = where->next;
      where->next = ins;
      list->count = list->count + 1;
    }
}

// Entferne ein Element nach einem gegebenem
// Liefere das entfernte Element zurueck
IntListElem* remove_from_list (IntList* list, IntListElem* where)
{
  IntListElem* p;  // das entfernte Element

  // where==0 dann entferne erstes Element
  if (where==0)
    {
      p = list->first;
      if (p!=0)
	{
	  list->first = p->next;
	  list->count = list->count - 1;
	}
      return p;
    }

  // entferne Element nach where
  p = where->next;
  if (p!=0)
    {
      where->next = p->next;
      list->count = list->count - 1;
    }
  return p;
}

IntListElem* durchlaufe_liste(IntList liste, int j)
{
 IntListElem* p = liste.first;
 for (int i=0; i < j; i++)
  p=p->next;
 return p;
}

IntListElem* ZyklusListe(int k, int n, int m)
{
  IntList l_linear;
  IntList l_zyklus;
  empty_list(&l_linear);
  empty_list(&l_zyklus);

  if(k==0&&n==0) return l_linear.first;

  if(k=0&&n!=0)
  {
     IntListElem* l_zyklus_last = new IntListElem;
     insert_in_list(&l_zyklus, 0, l_zyklus_last);

     for (int i=1; i<n; i++)
       insert_in_list(&l_zyklus, 0, new IntListElem);
     l_zyklus_last->next = l_zyklus.first;

     l_linear.first= durchlaufe_liste(l_zyklus, m);
     return l_linear.first;
  }

  if (n==0&&k!=0)
  {
     for (int j=0; j<k; j++)
       insert_in_list(&l_linear, 0, new IntListElem);
     return l_linear.first;
  }

  if (n!=0&&k!=0)
  {
     IntListElem* l_zyklus_last = new IntListElem;
     IntListElem* l_linear_last = new IntListElem;
     insert_in_list(&l_zyklus, 0, l_zyklus_last);
     insert_in_list(&l_linear, 0, l_linear_last);

     for (int i=1; i<n; i++)
       insert_in_list(&l_zyklus, 0, new IntListElem);
     l_zyklus_last->next = l_zyklus.first;

     for (int j=1; j<k; j++)
       insert_in_list(&l_linear, 0, new IntListElem);
     l_linear_last->next = durchlaufe_liste(l_zyklus, m);

     return l_linear.first;
  }
}

IntListElem* laufen(IntListElem* elem, int schritte)
{
  IntListElem* elem_h = elem;
  for (int i=0; i<schritte; i++)
    elem_h = elem_h->next;
  return elem_h;
}

int zykluslaenge(IntList rho)
{
  IntListElem* hase = rho.first;
  IntListElem* igel = rho.first;
  do
  {
   igel = laufen(igel, 1);
   hase = laufen(hase, 2);
  }
  while (igel != hase || igel!=0 || hase!=0);

  if (igel==0||hase==0)
    return 0;
  if (igel!=hase)
  {
   int i=0;
   do
   {
    igel = laufen(igel, 1);
    hase = laufen(hase, 2);
    i++;
   }
   while (igel != hase);
   return i;
  }
}
int main()
{
  IntList s;
  s.first= ZyklusListe(1, 3, 2);
  print("n=",zykluslaenge(s));

  return 0;
}




