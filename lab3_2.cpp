#include <iostream>

using namespace std;

class Mamifer{
    private:
    string nume;
    float greutate;
public:
    Mamifer(string nume , float greutate){
        Mamifer::nume = nume;
        Mamifer::greutate = greutate;
    }

     string getNume()  {
        return nume;
    }

    void setNume(string nume) {
        Mamifer::nume = nume;
    }

     float getGreutate() {
        return greutate;
    }

    void setGreutate(float greutate) {
        Mamifer::greutate = greutate;
    }
};

class Cangur: public Mamifer{
private:
    float lungimeSaritura;
public:
    Cangur(string nume , float greutate, float lungimeSaritura):Mamifer(nume,greutate){
        Cangur::lungimeSaritura = lungimeSaritura;
    }
    void setLungimeSaritura(float lungimeSaritura){
        Cangur::lungimeSaritura = lungimeSaritura;
    }

    float getLungimeSaritura(){
        return Cangur::lungimeSaritura;
    }

};

class Urs: public Mamifer{
private:
    string culoare;
public:
    Urs(string nume , float greutate , string culoare):Mamifer(nume,greutate){
        Urs::culoare = culoare;
    }

    void setCuloare(string culoare){
        Urs::culoare = culoare;
    }

    string getCuloare(){
        return Urs::culoare;
    }
};

int main() {
    Mamifer mamifer("mamifer",12);
    cout<<"Nume Mamifer : "<<mamifer.getNume()<<endl;
    cout<<"Greutate Mamifer : "<<mamifer.getGreutate()<<endl;
    cout<<endl;

    Cangur cangur("un_cangur",120,2);
    cout<<"Nume Cangur : "<<cangur.getNume()<<endl;
    cout<<"Greutate Cangur : "<<cangur.getGreutate()<<endl;
    cout<<"Lungime Saritura Cangur : "<<cangur.getLungimeSaritura()<<endl;
    cout<<endl;

    Urs urs("un_urs",200,"brun");
    cout<<"Nume Urs : "<<urs.getNume()<<endl;
    cout<<"Greutate Urs : "<<urs.getGreutate()<<endl;
    cout<<"Culoare Urs : "<<urs.getCuloare()<<endl;
}
