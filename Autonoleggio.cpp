#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InfoAuto
{
    string categoria;
    string marca;
    string modello;
    string colore;
    char lun, mar, mer, gio, ven, sab, dom;
};
InfoAuto VettInfoAuto[7]

void CaricaVett(InfoAuto VettInfoAuto[])
{
    ifstream f("auto.csv", ios::in);
    string linea;

    while(f.eof())
    {
        getline(f, linea);
        for(int i=0; i<6; i++)
        {
            f>>VettInfoAuto[i].categoria
             >>VettInfoAuto[i].marca
             >>VettInfoAuto[i].modello
             >>VettInfoAuto[i].modello
             >>VettInfoAuto[i].colore
             >>VettInfoAuto[i].lun
             >>VettInfoAuto[i].mar
             >>VettInfoAuto[i].mer
             >>VettInfoAuto[i].gio
             >>VettInfoAuto[i].ven
             >>VettInfoAuto[i].sab
             >>VettInfoAuto[i].dom;
        }
    }
}

string controlla_giorno(int contatore, char vett[])
{
    if(vett[contatore] == 'L')
        return " Disponibile";
    else 
        return " Non disponibile";
}

void controlla_disp(string Categoria, int Giorni)
{
    string linea, appoggio, modello;
    int giorno, cont;
    string giorni_sett[7] = {"Lunedi", "Martedi", "Mercoledi", "Giovedi", "Venerdi", "Sabato", "Domenica"};
    fstream f("auto.csv", ios::in | ios::out);

    if(!f) cout<<" Errore nell'apertura del file!";
    else
    {   
        cout<<" Le macchine disponibili per la categoria selezionata sono : \n ";  
        
        //Ciclo di ricerca vettura per la categoria selezionata
        
        
        //Scelta della vettura in base alla categoria selezionata
        cout<<"\n\n Selezionare il modello della vettura da noleggiare : ";
        cin>>modello;

        if((modello!="FIAT")||(modello!="KIA")||(modello!="Mercedes")||(modello!="Lamborghini")||(modello!="Ford")||(modello!="BMW")||(modello!="Peugeot")||(modello!="Audi"))
            cout<<" La vettura selezionata non fa parte della categoria scelta!\n";
        else 
        {
            //Output disponibilità modelllo vettura selezionata
            cout<<" I giorni i cui si può prenotare la vettura sono : \n ";
            
            for(int i=0; i<6; i++)
            {
                cout<<giorni_sett[i];
                if(VettInfoAuto[i].lun == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";

                cout<<giorni_sett[i];
                if(VettInfoAuto[i].mar == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";

                cout<<giorni_sett[i];
                if(VettInfoAuto[i].mer == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";
                
                cout<<giorni_sett[i];
                if(VettInfoAuto[i].gio == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";

                cout<<giorni_sett[i];
                if(VettInfoAuto[i].ven == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";
                
                cout<<giorni_sett[i];
                if(VettInfoAuto[i].sab == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";

                cout<<giorni_sett[i];
                if(VettInfoAuto[i].dom == 'L') cout<<": Disponibile\n"; 
                    else cout<<" : Non disponibile\n";       
            }

            //Output dei giorni in cui la vettura e disponibile o meno
            //La funzione "controlla_giorno" si occupa di visualizzare in output "Disponibile" o "Non diponibile" in base alle lettere di noleggio sulla riga della vettura selezionata, evitando di fare un contrllo per ogni output del giorno settimanale

            cout<<"\n\n Inserire giorno usando un numero, esempio: '4' per selezionare 'Venerdi' :\n";

            //Ciclo che prende in input i giorni e modifica il vettore dei giorni relativi alla vettura selezionata in base ai giorni inseriti dall'utente
            for(int j=0; j<Giorni; j++)
            {
                cout<<" >> ";
                cin>>giorno;

                if((giorno>7)||(giorno<0))
                    cout<<" Giorno non valido!\n";
                else
                    vett_giorni[giorno] = 'A'; 
            }

            cout<<" Vettura prenotata correttamente!\n";
        }  
        f.close();
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