/**
 * C++ zebrane
 * 
 * To jest zebranie składowych C++
 * 
 * author: Zbigniew Przemysław Szczepański
 *  
 */
 
//komentarz jednoliniowy
 
/*
 Komentarz wieloliniowy
*/ 

/**
 * Preprocesory
 */

#define STALA_A 1

#ifndef STALA_B
#define STALA_B (10*5)
#endif

#if STALA_B > 10
#define STALA_C (20*5)
#endif

/**
 * Załączanie
 */
#include <naglowek_wew.h>
#include "naglowek_lok.h"
#include "kod_lok.cpp"


/**
 * 
 */
extern int ta_zmienna_gdzies_jest;
const int STALA_NIEZMIENNA = 2;

/**
 * Przestrzeń nazw
 */
using namespace przestrzen_nazw_a;

namespace przestrzen_nazw_b {
	
	void lorem() {
		
	}
}

przestrzen_nazw_b::lorem();

/**
 * Funkcja główna 
 */
int main(int argc, char **argv)
{
	return 0;
}

/**
 * iostream, string i ciągi znaków
 */
bool ciagiZnakow()
{
	string tresc;
	
	cout << "Jakis tekst" "\n";
	
	cout << "Inny\ttekst" \
		"\tz\tabulatorami" << endl;

	cin >> tresc;		
	
	cout << "tekst pobrany:" << tresc << ", dlugi na: " 
		<< tresc.size() << " znaków." << endl;

	cerr << "Mamy problem : błąd " << endl;
	
	clog << "Zapisz mnie w logach " << str << endl;
	
	return true;
}

/***
 * Klasy
 */

//przygotowania interfejsu
class KalsaAbstrakcyjna
{
	int c;
	protected:
		virtual void metodaInterfejsowa() = 0;
}
 
//klasa dziedzicząca
class KlasaA : public KlasaAbstrakcyjna
{
	//tylko dla obiektów KlasaA
	private:
		int zmiennaUkryta;
		
		void metodaUkryta()
		{
		};
		
	//tylko dla obiektów KlasaA i ich dzieci
	protected:
		int zmiennaCzesciowoUkryta;
		
		void metodaCzesciowoUkryta()
		{
		};
	
	//dla wszystkich
	public:
		int zmiennaDostepna;
		
		int metodaDostepna()
		{
			return 1;
		};
		
		int metodaDostepna(int a)
		{
			return a;
		};
		
		int metodaDefiniownaZewnetrznie(int a);
		
		KlasaA()
		{
			//konstruktor, inicjujemy
		}
		
		~KlasaA()
		{
			//destructor, sprzątamy
		}
		
		void metodaInterfejsowa()
		{
			//konieczna do zdefiniownia, bo dziedziczona
		}
}

KlasaA::metodaDefiniownaZewnetrznie(int a)
{
	return 2;
}


//metody tworzenia i używania obiektów, bezpośrednio i przez wskaźnik
KlasaA obiektA;

obiektA.metodaDostepna();

KlasaA *obiektB = new KlasaA;

obiektB->metodaDostepna(2);


//enkapsulacja
class Enkapsulacja
{
	private:
		int a;
	public:
		void setA(int a)
		{
			this.a = a;
		}
		
		void getA()
		{
			return this.a;
		}
}

//przeładowanie operatorów
class A
{
	private:
		int a;
	public:
		A()
		{
			a = 1;
		}
		
		A operator+(const A& b)
		{
			this->a += 2 + b.a;
			
			return *this;
		}
		
		int getA()
		{
			return a;
		}
		
		bool operator <(const A&c)
		{
			++this->a;
			
			if(this->a < c.a)
			{			
				return true;
			}
			else
			{
				return false;
			}
		}
};

A aa;
cout << (aa + aa).getA() << endl;
	
A bb;
cout << ((aa < bb)?"true":"false") << endl;

//szablonowanie
template <class ZASTEPNIK> class Beztypowa
{
	private:
	ZASTEPNIK u;
	
	public:
	Beztypowa(ZASTEPNIK a)
	{
		this->u = a;
	}
	
	ZASTEPNIK zwrocWartosc()
	{
		return this->u;
	}
};

Beztypowa<int> *a = new Beztypowa<int>(1);

cout << a->zwrocWartosc() << endl;	

Beztypowa<string> *b = new Beztypowa<string>("a tu nagle ciąg znaków");

cout << b->zwrocWartosc() << endl;

/**
 * Wskaźniki, referencje i wywoływanie funkcji
 */

int zmienna = 1222;
int *wskaznik;
int *pustyWskaznik = NULL;
int **wskaznikWskaznika;

int& refZmiennej =  zmienna;

wskaznik = &zmienna;

wskaznikWskaznika = &wskaznik;

void * przekazaniePrzezWskaznik(int *przekaznyWskaznik)
{
	int *wskaznik;
	
	wskaznik = przekaznyWskaznik;
	
	return wskaznik; //zwrot wskaznika
}

void przekazaniePrzezWartosc(int przekazanaWartosc)
{	
}

przekazaniePrzezWskaznik(wskaznik);
przekazaniePrzezWskaznik(&zmienna);

przekazaniePrzezWartosc(*wskaznik);
przekazaniePrzezWartosc(zmienna);

//przy czym
int tablica[] = {1, 2, 3, 4};
int *wskaznik;

wskaznik = tablica; //bo tablica to wskaznik

/**
 * Typy zmiennych
 */

int jestem_globalna = 1; 

void zmienne(int jestem_argumentowa)
{
	int jestem_lokalna = 2;
	
	//1b
	bool a;
	
	//1B
	char a;
	signed char b;
	unsigned char c;
	
	printf("%c, %c, %c", a, b, c);
	printf("%hhi, %hhu", b, c);
	
	//2B lub 4B
	wchar_t d;

	//4B
	int x;		
	signed int y;
	unsigned int z;
	
	//2B
	short int x;
	short x;
	signed short int y;
	unsigned short int z;
	
	//8B
	long int x;
	long x;
	signed long int y;
	unsigned long int z;
	
	//4B
	float x;
	
	//8B
	double y;
	
	//16B
	double z;
	
	//lista predefiniowana
	enum wyliczanka {skladowa1 = 5, skladowa2, skladowa3} lista;
	
	//aliasy
	typedef unsigned int liczba_naturalna;	
	liczba_naturalna ab = 10;
	
	//paczka danych
	struct zbitkaZmiennowa {
		int id;
		char nazwa[100];
	};
	
	struct zbitkaZmiennowa struktura;
	
	struktura.id = 1;
	struktura.nazwa = "Nazwa A";
	
	struct zbitkaZmiennowa *struktura2 = new zbitkaZmiennowa;
	
	struktura2->id = 2;
	struktura2->nazwa = "Nazwa B";
}

/**
 * instrukcje, pętle i algebra boolowska
 */
bool instrukcje()
{
	//od 0, póki nie 20, zwiększaj o jeden
	for(int a = 0; a < 20; a++)
	{
		//krok pętli
	}

	//przejście przez wyszystkie elementy
	int lista[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
	for(int a : lista)
	{
		//krok pętli
	}	
	
	//sprawdź: przypadek 1, przypadek 2 lub załuż
	switch(x)
	{
		case 1:
			//przypadek 1
			break;
		case 2:
			//przypadek 2
			break;
		default:
			//domyślnie
	}
	
	//dopóki, rób
	while(1 == 1)
	{
		//krok pętli, tu: nieskończony
	}
	
	//rób, dopóki
	do 
	{
		//krok pętli, tu: nieskończony
	}
	while(2 > 1)
	
	//jeśli, to; inaczej, tamto
	if(1 < 2)
	{
		return true;
	} 
	else if(2 == 2)
	{
		return !((0 || 1) && 1);
	}
	else
	{
		return (1 != 1)? true : false;
	}
}

/**
 * SŁOWNICZEK NAZW ZAREZERWOWANYCH:
 * 
 * asm
 * 
 * else - pozostała częśc instrukcji if, "w odwrotnym przypadku:"
 * 
 * new - utworzenie nowego obiektu
 * 
 * this - wskaźnik na bieżący obiekt we jego wnętrzu
 * 
 * auto - automatyczne przypisywanie odpowiedniego typu
 * 
 * enum - typ zmiennej wyliczającej możliwe wartości
 * 
 * operator - wskazanie na przeciążany operator
 * 
 * throw - rzucenie wyjątkiem, identyfikowalnym przez try i "łapalnym" przez catch
 * 
 * bool - typ zmiennej jednobitowej 0 lub 1, "fałsz" lub "prawda"
 * 
 * explicit 	
 * 
 * private - oznaczenie prywatnego elementu obiektu
 * 
 * true	- wartość jednobitowa "prawda", domyślnie: 1
 * 
 * break - przerwanie pętli
 * 
 * export 
 * 
 * protected - oznaczenie chronionego elementu obiektu
 * 
 * try - oznaczenie początku sprawdzania bloku pod względem wyjątków
 * 
 * case	- oznaczenie przypadku dla switch
 * 
 * extern - wyciągnięcie zmiennej do przestrzeni globalnej
 * 
 * public - oznaczenie publicznej składowej obiektu
 * 
 * typedef - utworzenie aliasu dla typu zmiennej
 * 
 * catch - "złapanie" wyjątku "wyrzuconego" z bloku try
 * 
 * false - wartość jednobitowa "fałsz", domyślnie: 0
 * 
 * register - wskazanie na umieszczenie zmiennej bezpośrednio w rejestrze zamiast w pamięci
 * 
 * typeid - 
 * 
 * char - typ zmiennej jednobajtowej, znakowej
 * 
 * float - typ zmiennej dla liczb całkowitych
 * 
 * reinterpret_cast 
 * 
 * typename - oznaczenie nazwy uabstrakcyjnienia typu w szablonach funkcji/metod klasy
 * 
 * class - oznaczenie klasy
 * 
 * for - instrukcja petli, for(start; sprawdzenie; krok)
 * 
 * return - zwrot z funkcji
 * 
 * union
 * 
 * const - stała niezmienna
 * 
 * friend - oznaczenie funkcji wspólnej dla wielu klas, która ma dostęp do ich prywatnych składowych
 * 
 * short - typ zmiennej całkowitej, połowy zmiennej int
 * 
 * unsigned - oznaczenie zmiennej z zakresu od 0
 * 
 * const_cast 	
 * 
 * goto - skacze do linii z etykietką
 * 
 * signed - oznaczenie, że typ zmiennej zawiera wartość mniejsze od 0 (po połowie przed 0 i po 0 np.: -127 do 127)	
 * 
 * using - wskazanie na użycie np. danego namespace jako bieżącego
 * 
 * continue - przerwij i kontynuuj następną iterację pętli
 * 
 * if - instrukcja sprawdzająca prawdziwość założenia: if(zalozenie)
 * 
 * sizeof - sprawdź wielkość
 * 
 * virtual - oznaczenie metody w klasie jako koniecznej do "rozwinięcia", zdeklarowania
 * 
 * default 	
 * 
 * inline - oznaczenie funkcji, która ma być wrzucona podczas kompilacji w miejsce jej wywołania
 * 
 * static - oznaczenie, że dostępna jest tylko jedna instancja
 * 
 * void - typ "nic"
 * 
 * delete - usuwanie z pamięci, ekwiwalent do free w C
 * 
 * int - typ zmiennej dla liczby całkowitej
 * 
 * static_cast - jawna konwersja typu
 * 
 * volatile
 * 
 * do - rozpoczyna blok "rób, dopóki"
 * 
 * long - podwojenie typu zmiennej
 * 
 * struct - zgrupowanie zmiennych różnych typów
 * 
 * wchar_t - typ zmiennej 2 lub 4 bajtowej, znakowej
 * 
 * double - typ zmiennej zmiennoprzecinkowej podwójnej do float
 * 
 * mutable - oznacza możliwość nadpisywania stałej z klasy
 * 
 * switch - instrukcja sprawdzająca przypadki wyrazenia
 * 
 * while - instrukcja petli "dopóki"
 * 
 * dynamic_cast 
 * 
 * namespace - oznaczenie przestrzenie nazw
 * 
 * template - oznaczenie szablonu
 * 
 */
