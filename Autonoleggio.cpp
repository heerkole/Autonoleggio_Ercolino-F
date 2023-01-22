#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void controlla_giorno(int contatore, string vett[])
{
    if(strcmp(vett[contatore], 'L')==0)
        cout<<" Disponibile";
    else 
        cout<<" Non disponibile";
}

void controlla_disp(string Categoria, int Giorni)
{
    string linea, appoggio, macchina;
    int giorno, cont;
    string vett_giorni[7];
    fstream f("auto.csv", ios::in | ios::out);

    if(f.is_open())
    {   
        cout<<" Le macchine disponibili per la categoria selezionata sono : \n ";  
        
        //Ciclo di ricerca vettura per la categoria selezionata
        while(getline(f, linea))
        {
            if(linea == Categoria)
                cout<<linea; 
        }
        
        //Scelta della vettura in base alla categoria selezionata
        cout<<"\n\n Selezionare il modello della vettura da noleggiare : ";
        cin>>macchina;

        if(macchina!=Categoria)
            cout<<" La vettura selezionata non fa parte della categoria scelta!\n";
        else 
        {
            //Ciclo che riempie il vettore "vett_giorni" con i giorni relativi alla vettura selezionata
            for(int i=0; i<linea.length(); i++)
            {
                if((strcmp(linea[i], 'L')==0)||(strcmp(linea[i], 'A')==0))
                    vett_giorni[i] = linea[i];
            }

            //Output dei giorni in cui la vettura e disponibile o meno
            //La funzione "controlla_giorno" si occupa di visualizzare in output "Disponibile" o "Non diponibile" in base alle lettere di noleggio sulla riga della vettura selezionata, evitando di fare un contrllo per ogni output del giorno settimanale
            cout<<" I giorni i cui si può prenotare la vettura sono : \n ";
            cont = 0;
            cout<<" Lunedi (0) : "<<controlla_giorno(cont, vett_giorni[cont]);
            cont = 1;
            cout<<" \nMartedi (1) : "<<controlla_giorno(cont, vett_giorni[cont]);
            cont = 2;
            cout<<" \nMercoledi (2) : "<<controlla_giorno(cont, vett_giorni[cont]);
            cont = 3;
            cout<<" \nGiovedi (3) : "<<controlla_giorno(cont, vett_giorni[cont]);
            cont = 4;
            cout<<" \nVenerdi (4) : "<<controlla_giorno(cont, vett_giorni[cont]);
            cont = 5;
            cout<<" \nSabato (5) : "<<controlla_giorno(cont, vett_giorni[cont]);
            cont = 6;
            cout<<" \nDomenica (6) : "<<controlla_giorno(cont, vett_giorni[cont]);

            cout<<"\n\n Inserire giorno usando un numero, esempio: '4' per selezionare 'Venerdi' :\n";

            //Ciclo che prende in input i giorni e modifica il vettore dei giorni relativi alla vettura selezionata in base ai giorni inseriti dall'utente
            for(int j=0; j<Giorni; j++)
            {
                cout<<" >> ";
                cin>>giorno;

                if((giorno>7)||(giorno<0))
                    cout<<" Giorno non valido!\n";
                else
                    vett_giorni[giorno] = "A"; 
            }

            cout<<" Vettura prenotata correttamente!\n";
        }  
        f.close();
    }   
    else {
        cout<<" Errore nell'apertura del file!\n";
    }
}

void Scegli_Auto()
{
    string categoria;
    int giorni;

    cout<<" Benvenutx all'Autonoleggio!\n"
        <<" Selezionare categoria e giorni della vettura da voler affittare scegliendo tra le seguenti : \n\n"
        <<" 1. Utilitaria, 2. Lusso, 3. Sportiva, 4. Furgone\n"
        <<" >> ";
    cin>>categoria;

    cout<<" Per quanti giorni affittare la vettura? : \n >> ";
    cin>>giorni;

    controlla_disp(categoria, giorni);
}

int main()
{
    Scegli_Auto();
    return 0;
}