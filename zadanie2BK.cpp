#include <iostream>

using namespace std;

/*******************************************************

nazwa funkcji: wypelnijTabliceWartLos()
parametry wejściowe: tabWyrLos[] -> tablica liczb losowych, dlugoscTab -> dlugosc tablicy
wartość zwracana: nie zwraca wartosci, funkcja void
informacje: losuje wartosci w zakresie <1; 100> i wprowadza je do tablicy
autor: Bartosz Kucharzyszyn

****************************************************/

void wypelnijTabliceWartLos(int tabWyrLos[], int dlugoscTab){
    srand(time(NULL));
    for(int i = 0; i<dlugoscTab; i++){
        tabWyrLos[i] = rand()%100+1;
    }
}

/*******************************************************

nazwa funkcji: sortPrzezWyb
parametry wejściowe: tabWartosci[] -> tablica liczb, n -> dlugosc tablicy
wartość zwracana: nie zwraca wartosci, funkcja void
informacje: porównuje wartosc, znajdujaca sie pod najmIndeksem (poczatkowo 0) 
jesli znajdzie mniejsza - przypisuje ja do zmiennej najmIndeks.
Jesli najmIndeks jest rozny od 0 -> zamiana miejscami, sortowanie elementow
autor: Bartosz Kucharzyszyn

****************************************************/

void sortPrzezWyb(int tabWartosci[], int n){
    int najmIndeks = 0;
    for(int i = 0; i<n-1; i++){
        najmIndeks = i;
        for(int j = i+1; j<n; j++){
            if(tabWartosci[j] < tabWartosci[najmIndeks]){
                najmIndeks = j;
            }
        }
        if(najmIndeks != i){
            int temp = tabWartosci[najmIndeks];
            tabWartosci[najmIndeks] = tabWartosci[i];
            tabWartosci[i] = temp;
        }
    }
}

/*******************************************************

nazwa funkcji: wyszukajZWart()
parametry wejściowe: tabPrzeszukiwana[] -> tablica wartosci liczbowych, szukana -> wartosc do wyszukania w tej tablicy
wartość zwracana: indeks pierwszego wystapienia szukanej w tablicy
informacje: na koniec tablicy dodajemy wartownika (wartosc -1) i przechodzimy po tablicy (liniowo) tak dlugo, az nie natrafimy na -1 lub szukana. Nastepnie zwracamy -1 (gdy trafi na wartownika - koniec tablicy) lub indeks+1 (gdy znajdzie wartosc)
autor: Bartosz Kucharzyszyn

****************************************************/

int wyszukajZWart(int tabPrzeszukiwana[], int szukana){
    int i = 0;
    int n = 50;
    
    tabPrzeszukiwana[n+1] = -1;
    
    for(int i = 0; i<n+1; i++){
        cout<<tabPrzeszukiwana[i]<<", ";
    }
    
    i = 0;
    
    while(tabPrzeszukiwana[i] != -1 && tabPrzeszukiwana[i] != szukana){
        ++i;
    }
    
    if(tabPrzeszukiwana[i] == -1){
        return -1;
    }
    else{
        return i+1;
    }
}

int main() {
    int n = 50;
    int szukana = 0;
    int tablicaLiczb[n+1];
    
    wypelnijTabliceWartLos(tablicaLiczb, n);
    sortPrzezWyb(tablicaLiczb, n);
    
    /*for(int i = 0; i<n; i++){
        cout<<tab[i]<<", ";
    }*/
    
    cout<<"Podaj wartosc do wyszukania: ";
    cin>>szukana;
    
    int indeksPierw = wyszukajZWart(tablicaLiczb, szukana);
    
    if(indeksPierw == -1){
        cout<<"\nSzukana wartosc ("<<szukana<<") nie znajduje sie w tym zbiorze liczb";
    }
    else{
        cout<<"\nIndeks pierwszego wystapienia szukanej ("<<szukana<<") wynosi: "<<indeksPierw<<endl;
    }
    

    return 0;
}