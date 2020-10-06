#include <iostream>

using namespace std;

class Persoana{
private:
    string nume;
public:
    Persoana(string nume){
        Persoana::nume = nume;
    }
    string getNume(){
        return Persoana::nume;
    }

    Persoana() {}
};

class Student : public Persoana{
private:
    string departament;
    int an;
public:
    Student(string nume,string departament,int an):Persoana(nume){
        Student::departament = departament;
        Student::an = an;
    }

    Student(){};

    string getDepartament(){
        return Student::departament;
    }

    int getAn(){
        return Student::an;
    }

};

class StudentLicenta: public Student{
private:
    float examenLicenta;
public:
    StudentLicenta(){};
    StudentLicenta(string nume,string departament,int an ,float examenLicenta):Student(nume,departament,an){
        StudentLicenta::examenLicenta = examenLicenta;
    }

    float getExamenLicenta(){
        return StudentLicenta::examenLicenta;
    }

    void print(){
        cout<<"Nume : "<<StudentLicenta::getNume()<<endl;
        cout<<"Departament : "<<StudentLicenta::getDepartament()<<endl;
        cout<<"An : "<<StudentLicenta::getAn()<<endl;
        cout<<"Examen : "<<StudentLicenta::examenLicenta<<endl;
    }
};

class StudentMaster : public Student{
private:
    float examenMaster;
public:
    StudentMaster(){};
    StudentMaster(string nume,string departament,int an ,float examenMaster):Student(nume,departament,an){
        StudentMaster::examenMaster = examenMaster;
    }

    float getExamenMaster(){
        return StudentMaster::examenMaster;
    }

    void print(){
        cout<<"Nume : "<<StudentMaster::getNume()<<endl;
        cout<<"Departament : "<<StudentMaster::getDepartament()<<endl;
        cout<<"An : "<<StudentMaster::getAn()<<endl;
        cout<<"Examen : "<<StudentMaster::examenMaster<<endl;
    }

};

class Doctorand : public Student{
private:
    string lucrareDoctorat;
public:
    Doctorand(){};
    Doctorand(string nume,string departament,int an ,string lucrareDoctorat):Student(nume,departament,an){
        Doctorand::lucrareDoctorat = lucrareDoctorat;
    }

    string getLucrareDoctorat(){
        return Doctorand::lucrareDoctorat;
    }

    void print(){
        cout<<"Nume : "<<Doctorand::getNume()<<endl;
        cout<<"Departament : "<<Doctorand::getDepartament()<<endl;
        cout<<"An : "<<Doctorand::getAn()<<endl;
        cout<<"Examen : "<<Doctorand::lucrareDoctorat<<endl;
    }
};

class Angajat : public Persoana{
private:
    unsigned int vechime;
public:
    Angajat(){};
    Angajat(string nume , unsigned int vechime):Persoana(nume){
        Angajat::vechime = vechime;
    }

   unsigned int getVechime(){
        return Angajat::vechime;
    }
};

class Profesor : public Angajat{
private:
    string materie;
public:
    Profesor(){};
    Profesor(string nume , unsigned int vechime,string materie):Angajat(nume,vechime){
        Profesor::materie = materie;
    }

    string getMaterie(){
        return Profesor::materie;
    }

    void print(){
        cout<<"Nume : "<<Profesor::getNume()<<endl;
        cout<<"Vechime : "<<Profesor::getVechime()<<endl;
        cout<<"Materie : "<<Profesor::materie<<endl;
    }
};

class Inginer : public Angajat{
private:
    string domeniu;
public:
    Inginer(){};
    Inginer(string nume,unsigned int vechime,string domeniu):Angajat(nume,vechime){
        Inginer::domeniu = domeniu;
    }

    void print(){
        cout<<"Nume : "<<Inginer::getNume()<<endl;
        cout<<"Vechime : "<<Inginer::getVechime()<<endl;
        cout<<"Materie : "<<Inginer::domeniu<<endl;
    }

    string getDomeniu(){
        return Inginer::domeniu;
    }
};

void meniuPrincipal(){
    cout<<"Alegeti tipul de persoana : "<<endl;
    cout<<"1.Student Licenta"<<endl;
    cout<<"2.Student Master"<<endl;
    cout<<"3.Student Doctorand"<<endl;
    cout<<"4.Profesor"<<endl;
    cout<<"5.Inginer"<<endl;
    cout<<"0.Exit"<<endl;
}

void meniuSecundar(){
    cout<<"Alegeti operatia : "<<endl;
    cout<<"1.Adaugare ."<<endl;
    cout<<"2.Afisare ."<<endl;
    cout<<"3.Cautare ."<<endl;
    cout<<"4.Stergere ."<<endl;
    cout<<"0.Exit"<<endl;
}

int countStudenti = 0;
int countMaster = 0;
int countDoctorand = 0;
int countProfesor = 0;
int countInginer = 0;

void adaugaStudentLicenta(StudentLicenta *studenti){
    string nume;
    string departament;
    int an;
    float examen;

    cout<<"Nume : ";cin>>nume;
    cout<<"Departament : ";cin>>departament;
    cout<<"An : ";cin>>an;
    cout<<"Examen : ";cin>>examen;

    StudentLicenta student(nume,departament,an,examen);
    studenti[countStudenti++] = student;

}

void afisareStudentiLicenta(StudentLicenta *studenti){
    for (int i = 0; i < countStudenti; ++i) {
        studenti[i].print();
        cout<<endl;
    }
}

void cautaStudentLicenta(StudentLicenta *studenti, string nume){
    bool flag = false;
    for (int i = 0; i < countStudenti; ++i) {
        if (nume == studenti[i].getNume()){
            flag = true;
            studenti[i].print();
            cout<<endl;
        }
    }
    if (!flag){
        cout<<"Student negasit!"<<endl;
    }
}

void stergeStudentLicenta(StudentLicenta *studenti, string nume){
    bool flag = false;
    for (int i = 0; i < countStudenti; ++i) {
        if (nume == studenti[i].getNume()){
            flag = true;
            for (int j = i; j < countStudenti; ++j) {
                studenti[j] = studenti[j+1];
            }
            countStudenti--;
            cout<<"Student sters !"<<endl;
        }
    }
    if (!flag){
        cout<<"Student negasit!"<<endl;
    }
}

void proiectareStudentiLicenta(StudentLicenta *studenti){
    int input;
    string nume;
    string numeSters;

    do {
        meniuSecundar();
        cout<<" : ";
        cin>>input;
        switch (input) {
            case 0:
                break;
            case 1:
                adaugaStudentLicenta(studenti);
                break;
            case 2:
                afisareStudentiLicenta(studenti);
                break;
            case 3:
                cout<<"Dati un nume de student : ";cin>>nume;
                cautaStudentLicenta(studenti, nume);
                break;
            case 4:
                cout<<"Dati un nume de student : ";cin>>numeSters;
                stergeStudentLicenta(studenti, numeSters);
                break;
            default:
                cout<<"Comanda gresita!"<<endl;
        }
    }while (input!=0);
}

void adaugaMasterand(StudentMaster masteranzi[]){
    string nume;
    string departament;
    int an;
    float examen;

    cout<<"Nume : ";cin>>nume;
    cout<<"Departament : ";cin>>departament;
    cout<<"An : ";cin>>an;
    cout<<"Examen : ";cin>>examen;

    StudentMaster student(nume,departament,an,examen);
    masteranzi[countMaster++] = student;

}

void afisareMasteranzi(StudentMaster masteranzi[]){
    for (int i = 0; i < countMaster; ++i) {
        masteranzi[i].print();
        cout<<endl;
    }
}

void cautaMasterand(StudentMaster masteranzi[] , string nume){
    bool flag = false;
    for (int i = 0; i < countMaster; ++i) {
        if (nume == masteranzi[i].getNume()){
            flag = true;
           masteranzi[i].print();
            cout<<endl;
        }
    }
    if (!flag){
        cout<<"Student negasit!"<<endl;
    }
}

void stergeStudentMaster(StudentMaster masteranzi[] , string nume){
    bool flag = false;
    for (int i = 0; i < countMaster; ++i) {
        if (nume == masteranzi[i].getNume()){
            flag = true;
            for (int j = i; j < countStudenti; ++j) {
                masteranzi[j] = masteranzi[j+1];
            }
            countMaster--;
            cout<<"Student sters !"<<endl;
        }
    }
    if (!flag){
        cout<<"Student negasit!"<<endl;
    }
}

void proiectareStudentiMaster(StudentMaster masteranzi[]){
    int input;
    string nume;
    string numeSters;

    do {
        meniuSecundar();
        cout<<" : ";
        cin>>input;
        switch (input) {
            case 0:
                break;
            case 1:
                adaugaMasterand(masteranzi);
                break;
            case 2:
                afisareMasteranzi(masteranzi);
                break;
            case 3:
                cout<<"Dati un nume de student : ";cin>>nume;
                cautaMasterand(masteranzi, nume);
                break;
            case 4:
                cout<<"Dati un nume de student : ";cin>>numeSters;
                stergeStudentMaster(masteranzi, numeSters);
                break;
            default:
                cout<<"Comanda gresita!"<<endl;
        }
    }while (input!=0);
}

void adaugaDoctorand(Doctorand doctoranzi[]){
    string nume;
    string departament;
    int an;
    string lucrare;

    cout<<"Nume : ";cin>>nume;
    cout<<"Departament : ";cin>>departament;
    cout<<"An : ";cin>>an;
    cout<<"Lucrare : ";cin>>lucrare;

    Doctorand student(nume,departament,an,lucrare);
    doctoranzi[countDoctorand++] = student;
}

void afisareDoctoranzi(Doctorand doctoranzi[]){
    for (int i = 0; i < countDoctorand; ++i) {
        doctoranzi[i].print();
        cout<<endl;
    }
}

void cautaDoctorand(Doctorand doctoranzi[],string nume){
    bool flag = false;
    for (int i = 0; i < countDoctorand; ++i) {
        if (nume == doctoranzi[i].getNume()){
            flag= true;
            doctoranzi[i].print();
            cout<<endl;
        }
    }
    if (!flag){
        cout<<"Student negasit!"<<endl;
    }
}

void  stergeDoctorand(Doctorand doctoranzi[],string nume){
    bool flag = false;
    for (int i = 0; i < countDoctorand; ++i) {
        if (nume == doctoranzi[i].getNume()){
            flag = true;
            for (int j = i; j < countDoctorand; ++j) {
                doctoranzi[j] = doctoranzi[j+1];
            }
            countDoctorand--;
            cout<<"Student sters !"<<endl;
        }
    }
    if (!flag){
        cout<<"Student negasit!"<<endl;
    }
}

void proiectareStudentiDoctorat(Doctorand doctoranzi[]){
    int input;
    string nume;
    string numeSters;

    do {
        meniuSecundar();
        cout<<" : ";
        cin>>input;
        switch (input) {
            case 0:
                break;
            case 1:
                adaugaDoctorand(doctoranzi);
                break;
            case 2:
                afisareDoctoranzi(doctoranzi);
                break;
            case 3:
                cout<<"Dati un nume de student : ";cin>>nume;
                cautaDoctorand(doctoranzi, nume);
                break;
            case 4:
                cout<<"Dati un nume de student : ";cin>>numeSters;
                stergeDoctorand(doctoranzi, numeSters);
                break;
            default:
                cout<<"Comanda gresita!"<<endl;
        }
    }while (input!=0);
}

void adaugaProfesor(Profesor profesori[]){
    string nume;
    unsigned int vechime;
    string materie;

    cout<<"Nume : ";cin>>nume;
    cout<<"Vechime : ";cin>>vechime;
    cout<<"Materie : ";cin>>materie;

    Profesor angajat(nume,vechime,materie);
    profesori[countProfesor++] = angajat;
}

void afisareProfesori(Profesor profesori[]){
    for (int i = 0; i < countProfesor; ++i) {
        profesori[i].print();
        cout<<endl;
    }
}

void cautaProfesor(Profesor profesori[],string nume){
    bool flag = false;
    for (int i = 0; i < countProfesor; ++i) {
        if (nume == profesori[i].getNume()){
            flag=true;
            profesori[i].print();
            cout<<endl;
        }
    }
    if (!flag){
        cout<<"Angajat negasit!"<<endl;
    }
}

void stergeProfesor(Profesor profesori[],string nume){
    for (int i = 0; i < countProfesor; ++i) {
        if (nume == profesori[i].getNume()){
            for (int j = i; j < countProfesor; ++j) {
                profesori[j] = profesori[j+1];
            }
            countProfesor--;
            cout<<"Angajat sters !"<<endl;
        } else{
            cout<<"Angajat negasit!"<<endl;
        }
    }
}

void proiectareProfesori(Profesor profesori[]){
    int input;
    string nume;
    string numeSters;

    do {
        meniuSecundar();
        cout<<" : ";
        cin>>input;
        switch (input) {
            case 0:
                break;
            case 1:
                adaugaProfesor(profesori);
                break;
            case 2:
                afisareProfesori(profesori);
                break;
            case 3:
                cout<<"Dati un nume de angajat : ";cin>>nume;
                cautaProfesor(profesori, nume);
                break;
            case 4:
                cout<<"Dati un nume de angajat : ";cin>>numeSters;
                stergeProfesor(profesori, numeSters);
                break;
            default:
                cout<<"Comanda gresita!"<<endl;
        }
    }while (input!=0);
}

void adaugaInginer(Inginer ingineri[]){
    string nume;
    unsigned int vechime;
    string domeniu;

    cout<<"Nume : ";cin>>nume;
    cout<<"Vechime : ";cin>>vechime;
    cout<<"Domeniu : ";cin>>domeniu;

    Inginer angajat(nume,vechime,domeniu);
    ingineri[countInginer++] = angajat;
}

void afisareIngineri(Inginer ingineri[]){
    for (int i = 0; i < countInginer; ++i) {
        ingineri[i].print();
        cout<<endl;
    }
}

void cautaInginer(Inginer ingineri[],string nume){
    bool flag = false;
    for (int i = 0; i < countInginer; ++i) {
        if (nume == ingineri[i].getNume()){
            flag=true;
            ingineri[i].print();
            cout<<endl;
        }
    }
    if (!flag){
        cout<<"Angajat negasit!"<<endl;
    }
}

void stergeInginer(Inginer ingineri[],string nume){
    bool flag = false;
    for (int i = 0; i < countInginer; ++i) {
        if (nume == ingineri[i].getNume()){
            flag = true;
            for (int j = i; j < countInginer; ++j) {
                ingineri[j] = ingineri[j+1];
            }
            countInginer--;
            cout<<"Angajat sters !"<<endl;
        }
    }
    if (!flag){
        cout<<"Angajat negasit!"<<endl;
    }
}

void proiectareInginer(Inginer ingineri[]){
    int input;
    string nume;
    string numeSters;

    do {
        meniuSecundar();
        cout<<" : ";
        cin>>input;
        switch (input) {
            case 0:
                break;
            case 1:
                adaugaInginer(ingineri);
                break;
            case 2:
                afisareIngineri(ingineri);
                break;
            case 3:
                cout<<"Dati un nume de angajat : ";cin>>nume;
                cautaInginer(ingineri, nume);
                break;
            case 4:
                cout<<"Dati un nume de angajat : ";cin>>numeSters;
                stergeInginer(ingineri, numeSters);
                break;
            default:
                cout<<"Comanda gresita!"<<endl;
        }
    }while (input!=0);
}

int main(){
    int input;
    StudentLicenta studenti[20];
    StudentMaster masteranzi[20];
    Doctorand doctoranzi[20];
    Profesor profesori[20];
    Inginer ingineri[20];

    do {
        meniuPrincipal();
        cout<<" : ";
        cin>>input;

        switch (input) {
            case 1:
                proiectareStudentiLicenta(studenti);
                break;
            case 2:
                proiectareStudentiMaster(masteranzi);
                break;
            case 3:
                proiectareStudentiDoctorat(doctoranzi);
                break;
            case 4:
                proiectareProfesori(profesori);
                break;
            case 5:
                proiectareInginer(ingineri);
                break;
            default:
                cout<<"Optiune gresita!"<<endl;

        }

    }while (input!=0);

 }