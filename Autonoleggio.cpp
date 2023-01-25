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
    char VettGiorni[6];
};
InfoAuto VettInfoAuto[6];

void CaricaVett()
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
             >>VettInfoAuto[i].colore;

             for(int j=0; j<6; j++)
             {
                f>>VettInfoAuto[i].VettGiorni[i];
             }
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
    CaricaVett();

    string linea,modello,str_intera;
    bool contr = false;
    int giorno, cont, q;
    string giorni_sett[7] = {"Lunedi", "Martedi", "Mercoledi", "Giovedi", "Venerdi", "Sabato", "Domenica"};
    fstream f("auto.csv", ios::in | ios::out);

    if(!f) cout<<" Errore nell'apertura del file!";
    else
    {           
        //Ciclo di ricerca vettura per la categoria selezionata
        cout<<" Le macchine disponibili per la categoria selezionata sono : \n"; 

        for(int a=0; a<6; a++)
        {
            if(VettInfoAuto[a].categoria == Categoria)
                cout<<"- "<<VettInfoAuto[a].modello<<endl;
        }                             
        
        //Scelta della vettura in base alla categoria selezionata
        cout<<"\n\n Selezionare il modello della vettura da noleggiare : ";
        cin>>modello;

        for(q=0; q<6; q++)
        {
            if(VettInfoAuto[q].modello==modello)
            {
                contr = true;
                break;
            }
            else cout<<" La vettura inserita non fa parte della categoria scelta!\n";
        }

        if(contr)
        {
            //Output disponibilità modelllo vettura selezionata
            cout<<" I giorni i cui si può prenotare la vettura sono : \n ";
            
            for(int i=0; i<6; i++)
            {
                if (VettInfoAuto[q].VettGiorni[q] == 'L')
                    cout<<giorni_sett[i]<<" : Disponibile\n";     
                else cout<<giorni_sett[i]<<" : Non Disponibile\n";     

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
                    VettInfoAuto[j].VettGiorni[j] = 'A'; 
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

    cout<<"\n\n Benvenutx all'Autonoleggio!\n"
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