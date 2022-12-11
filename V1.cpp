

#include <iostream>

using namespace std;

const int MAX_ITEM = 65535;
int HOW_MANY_ITEMS = 0;



struct place
{
  unsigned short good = 0;
  int label[2];
};
struct shelf
{
  place pla[128];
  short max_size = 128;
};
struct rack
{
  shelf she[128];
  short max_size = 128;

};

struct warehouse
{
  rack ra[128];
  shelf handyShelf;
  short max_size = 128;

};

struct yard
{
  warehouse war[128];
  short max_size = 128;
  rack handyRack;
  shelf handyShelf;
};





void setsAP (int Wb, int Rb, int Sb, int Pe, yard ya)
{
  int MAX = ya.war[Wb].ra[Rb].she[Sb].max_size;
  for (int i = Pe; i < MAX; i++)
    {
      ya.war[Wb].ra[Rb].she[Sb].pla[i].good = 0;

    }
  ya.war[Wb].ra[Rb].she[Sb].max_size = Pe;


}

void setAS (int Wb, int Rb, int Sb, int P, yard ya)
{

  int MAX = ya.war[Wb].ra[Rb].max_size;

  for (int i = P; i < MAX; i++)
    {
      ya.war[Wb].ra[Rb].she[Sb].pla[i].good = 0;
      ya.war[Wb].ra[Rb].she[Sb].pla[i].label[0] = 0;
      ya.war[Wb].ra[Rb].she[Sb].pla[i].label[1] = 0;
    }

  if (P > MAX)
    {
      for (int i = MAX; i < P; i++)
	{
	  ya.war[Wb].ra[Rb].she[i].max_size = P;
	  for (int j = 0; j < P; j++)
	    {
	      ya.war[Wb].ra[Rb].she[Sb].pla[j].good = 0;
	      ya.war[Wb].ra[Rb].she[Sb].pla[j].label[0] = 0;
	      ya.war[Wb].ra[Rb].she[Sb].pla[j].label[1] = 0;


	    }

	}

    }

  ya.war[Wb].ra[Rb].max_size = P;

}


void put1 ( int w, int r, int s, int p, int A, yard ya)
{

  int addingReal = 0;
  int firstValue = ya.war[w].ra[r].she[s].pla[p].good;

  ya.war[w].ra[r].she[s].pla[p].good += A;
  addingReal += A;

  if (ya.war[w].ra[r].she[s].pla[p].good > MAX_ITEM)
    {
      ya.war[w].ra[r].she[s].pla[p].good = MAX_ITEM;
      addingReal = MAX_ITEM - firstValue;
    }





}

void put2 (int w, int p, int A, yard ya)
{

  int addingReal = 0;
  int firstValue = ya.war[w].handyShelf.pla[p].good;

  ya.war[w].handyShelf.pla[p].good += A;
  addingReal += A;

  if (ya.war[w].handyShelf.pla[p].good > MAX_ITEM)
    {
      ya.war[w].handyShelf.pla[p].good = MAX_ITEM;
      addingReal = MAX_ITEM - firstValue;
    }

  HOW_MANY_ITEMS += addingReal;

}

void put3 (int s, int p, int A, yard ya)
{

  int addingReal = 0;
  int firstValue = ya.handyRack.she[s].pla[p].good;

  ya.handyRack.she[s].pla[p].good += A;
  addingReal += A;

  if (ya.handyRack.she[s].pla[p].good > MAX_ITEM)
    {
      addingReal = MAX_ITEM - firstValue;
      ya.handyRack.she[s].pla[p].good = MAX_ITEM;
    }



  HOW_MANY_ITEMS += addingReal;



}

void put4 (int p, int A, yard ya)
{

  int addingReal = 0;
  int firstValue = ya.handyShelf.pla[p].good;

  ya.handyShelf.pla[p].good += A;
  addingReal += A;

  if (ya.handyShelf.pla[p].good > MAX_ITEM)
    {
      ya.handyShelf.pla[p].good = MAX_ITEM;
      addingReal = MAX_ITEM - firstValue;
    }
}




using namespace std;






int main ()
{


}
