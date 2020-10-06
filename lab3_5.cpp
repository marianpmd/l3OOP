#include <iostream>
#include <unordered_map>

using namespace std;

class Carte{
private:
    string titlu;
public:
    Carte(string titlu){
        Carte::titlu = titlu;
    }

    string getTitlu(){
        return Carte::titlu;
    }
};

class FisaBiblioteca : public Carte{
private:
    string autor;
    string editura;
    bool rezervata;
public:
    FisaBiblioteca(string titlu,string autor,string editura):Carte(titlu){
    FisaBiblioteca::autor = autor;
    FisaBiblioteca::editura = editura;
    FisaBiblioteca::rezervata = false;
    }

    string getAutor(){
        return FisaBiblioteca::autor;
    }

    string getEditura(){
        return FisaBiblioteca::editura;
    }

    bool getRezervata(){
        return FisaBiblioteca::rezervata;
    }
    void setRezervata(bool val){
        FisaBiblioteca::rezervata = val;
    }

    void print(){
        cout<<"Titlu : "<<getTitlu()<<endl;
        cout<<"Autor : "<<FisaBiblioteca::autor<<endl;
        cout<<"Editura : "<<FisaBiblioteca::editura<<endl;
        cout<<"Rezervare : "<<FisaBiblioteca::rezervata<<endl;
    }
};

void meniu(){
    cout<<"Meniu"<<endl;
    cout<<"1.Adauga Carte."<<endl;
    cout<<"2.Imprumuta Carte."<<endl;
    cout<<"3.Restituie Carte."<<endl;
    cout<<"4.Sterge Carte."<<endl;
    cout<<"5.Cauta Carte."<<endl;
    cout<<"6.Afiseaza Carti."<<endl;
    cout<<"0.Exit"<<endl;
}

void adaugaCarte(unordered_map<string,FisaBiblioteca> &carti){
    string titlu;
    string autor;
    string editura;

    cout<<"Titlu : "<<endl;cin>>titlu;
    cout<<"Autor : "<<endl;cin>>autor;
    cout<<"Editura : "<<endl;cin>>editura;

    FisaBiblioteca carte(titlu,autor,editura);
    carti.insert(make_pair(titlu,carte));
}

void afiseazaCarti(unordered_map<string,FisaBiblioteca> carti){
    for(auto x : carti){
        x.second.print();
        cout<<endl;
    }
}

void imprumutaCarte(unordered_map<string,FisaBiblioteca>& carti){
    string titlu;
    cout<<"Dati titlul cartii pentru rezervare : "<<endl;
    cin>>titlu;
    unordered_map<string,FisaBiblioteca>::iterator iterator = carti.find(titlu);
    if (iterator!=carti.end()) {
        iterator->second.setRezervata(true);
        cout << "Cartea a fost rezervata!" << endl;
    } else{
        cout<<"Carte negasita!"<<endl;
    }
}

void restituieCarte(unordered_map<string,FisaBiblioteca>& carti){
    string titlu;
    cout<<"Dati titlul cartii pentru restituire : "<<endl;
    cin>>titlu;
    unordered_map<string,FisaBiblioteca>::iterator iterator = carti.find(titlu);
    if (iterator!=carti.end()) {
        iterator->second.setRezervata(false);
        cout << "Cartea a fost Restituita!" << endl;
    } else{
        cout<<"Carte negasita"<<endl;
    }
}

void stergeCarte(unordered_map<string,FisaBiblioteca>& carti){
    string titlu;
    cout<<"Dati titlul cartii pentru stergere : "<<endl;
    cin>>titlu;


    if(carti.erase(titlu)!=0) {
        cout <<"Cartea a fost stearsa!" << endl;
    } else{
        cout<<"Carte negasita!"<<endl;
    }
}

void cautaCarte(unordered_map<string,FisaBiblioteca> carti){
    string titlu;
    cout<<"Dati titlul cartii pentru cautare : "<<endl;
    cin>>titlu;
    cout<<"Cartea este : " <<endl;

    unordered_map<string,FisaBiblioteca>::iterator iterator=carti.find(titlu);
    if (iterator != carti.end()) {
        iterator->second.print();
    } else{
        cout<<"Carte negasita!"<<endl;
    }
}

int main(){
    int input;

    unordered_map<string,FisaBiblioteca> carti;
    do {
        meniu();
        cout<<" : ";cin>>input;

        switch (input) {
            case 1:
                adaugaCarte(carti);
                break;
            case 2:
                imprumutaCarte(carti);
                break;
            case 3:
                restituieCarte(carti);
                break;
            case 4:
                stergeCarte(carti);
                break;
            case 5:
                cautaCarte(carti);
                break;
            case 6:
                afiseazaCarti(carti);
                break;
            default:
                cout<<"Optiune gresita!"<<endl;
                break;
        }

    }while (input!=0);

}