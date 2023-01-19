#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* Gestire le prenotazioni dals lunedi a domenica 
   Una macchina può essere affittata solo per giornate intere
   Associare i numeri a i giorni della settimana
  
   1. Inserimento categoria mmacchina, giorni affitto
   2. Scelta del veicolo di categoria scelta   
*/

void controlla_disp(string Categoria, string Giorni)
{
    vector<string> macchine; 
    fstream f;
    f.open("auto.csv", ios::in | ios::out);

    if(f.is_open())
    {
        while (f.eof())
        {
            string linea;
            getline(f, linea);
            if(linea == Categoria)
                macchine.push_back(linea);  //Inserisce la linea nel vettore se trova la categoria inserita
                //Trovare e modificare la linea in base all'inserimento dell'utente
        }
        f.close();
    }   
    else {
        cout<<" Errore nell'apertura del file!\n";
    }
}

void Scegli_Auto()
{
    string scelta,scelta1;
    //string DaTrovare[8] = {"Utilitaria","utilitaria","Lusso","lusso","Sportiva","sportiva","Furgone","furgone"};

    cout<<" Benvenutx all'Autonoleggio!\n"
        <<" Selezionare categoria e giorni della macchina da voler affittare scegliendo tra le seguenti : \n\n"
        <<" 1. Utilitaria, 2. Lusso, 3. Sportiva, 4. Furgone\n"
        <<" >> ";
    cin>>scelta;

    cout<<"Inserisci i giorni della settimana in cui affitterai un veicolo, separando più giorni da uno spazio : "
        <<" Lunedi = 1, Martedi = 2, Mercoledi = 3, Giovedi = 4, Venerdi = 5, Sabato = 6, Domenica = 7\n";
    cin>>scelta1;

    controlla_disp(scelta, scelta1);
}

int main()
{
    Scegli_Auto();
    return 0;
}