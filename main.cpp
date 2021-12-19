#include <iostream>
#include <string>

class Persoana{

protected:
    int id;
    std::string nume;
public:
    Persoana(): id(0), nume("") {}
    Persoana(int Id): id(Id), nume("") {}
    Persoana(std::string Nume): id(0), nume(Nume) {}
    Persoana(int Id, std::string Nume): id(Id), nume(Nume) {}
    Persoana(Persoana &pers){ id=pers.id; nume=pers.nume;}
    Persoana operator=(Persoana pers){
        id=pers.id;
        nume=pers.nume;
    }
    friend std::istream &operator>>(std::istream &in, Persoana &pers){
        in >> pers.id;
        std::cin.get();
        getline(in, pers.nume);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &os, Persoana &pers){
        os << pers.id << ' ' << pers.nume << std::endl;
        return os;
    }
    virtual ~Persoana(){
        id=0;
        nume="";
    }
    std::string Get_id(){return std::to_string(id);}
    std::string Get_nume(){return nume;}

};
class Abonat : public Persoana{

protected:
    std::string nr_telefon;
public:
    Abonat() : nr_telefon("") {}
    Abonat(std::string numar) : nr_telefon(numar) {}
    Abonat operator=(Abonat abon){
        nr_telefon=abon.nr_telefon;
    }
    Abonat(int id, std::string nume, std::string nr_tel) : Persoana(id, nume), nr_telefon(nr_tel) {}
    friend std::istream &operator>>(std::istream &in, Abonat &abon){
        in >> abon.nr_telefon;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &os, Abonat &abon){
        os << abon.nr_telefon << std::endl;
    }
    virtual ~Abonat(){
        nr_telefon="";
    }

    std::string Get_nr_telefon(){return nr_telefon;}
};
class Abonat_Skype : public Abonat{

protected:
    std::string id_skype;
public:
    Abonat_Skype() : id_skype("") {}
    Abonat_Skype(std::string id_sky) : id_skype(id_sky) {}
    Abonat_Skype(int id, std::string nume, std::string nr_tel, std::string id_sky) : Abonat(id,nume,nr_tel), id_skype(id_sky) {}
    Abonat_Skype operator=(Abonat_Skype abon_skype){
        id_skype=abon_skype.id_skype;
    }
    friend std::istream &operator>>(std::istream &in, Abonat_Skype &abon_skype){
        in >> abon_skype.id_skype;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &os, Abonat_Skype &abon_skype){
        os << abon_skype.id_skype << std::endl;
    }
    virtual ~Abonat_Skype(){
        id_skype="";
    }
    std::string Get_id_skype(){return id_skype;}
};

class Abonat_Skype_Romania : public Abonat_Skype{

private:
    std::string adresa_mail;
public:
    Abonat_Skype_Romania() : adresa_mail("") {}
    Abonat_Skype_Romania(std::string adresa) : adresa_mail(adresa) {}
    Abonat_Skype_Romania(int id, std::string nume, std::string nr_tel, std::string id_sky, std::string adresa) : Abonat_Skype(id,nume,nr_tel,id_sky), adresa_mail(adresa) {}

    Abonat_Skype_Romania(std::string id_sky, std::string adresa) : Abonat_Skype(id_sky), adresa_mail(adresa) {}

    Abonat_Skype_Romania operator=(Abonat_Skype_Romania abon_skype_ro){

        adresa_mail=abon_skype_ro.adresa_mail;
    }
    friend std::istream &operator>>(std::istream &in, Abonat_Skype_Romania &abon_skype_ro){
        in >>abon_skype_ro.adresa_mail;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &os, Abonat_Skype_Romania &abon_skype_ro){
        os << "id skype: " << abon_skype_ro.id<< std::endl;
        os << "id nume: " << abon_skype_ro.nume << std::endl;
        os << "id numer telefon: " << abon_skype_ro.id << std::endl;
        os << "Adresa mail: " << abon_skype_ro.adresa_mail << std::endl;
        return os;
    }
    ~Abonat_Skype_Romania(){
        adresa_mail="";
    }
    std::string Get_adresa_mail(){return adresa_mail;}
};


class Abonat_Skype_Extern : public Abonat_Skype{

private:
    std::string tara;
public:
    Abonat_Skype_Extern() : tara("") {}
    Abonat_Skype_Extern(std::string Tara) : tara(Tara) {}
    Abonat_Skype_Extern(std::string id_sky, std::string Tara) : Abonat_Skype(id_sky), tara(Tara) {}
    Abonat_Skype_Extern operator=(Abonat_Skype_Extern abon_skype_ext){
        tara=abon_skype_ext.tara;
    }
    friend std::istream &operator>>(std::istream &in, Abonat_Skype_Extern &abon_skype_ext){
        in >> abon_skype_ext.tara;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &os, Abonat_Skype_Extern &abon_skype_ext){
        os << abon_skype_ext.tara << std::endl;
    }
    ~Abonat_Skype_Extern(){
        tara="";
    }
    std::string Get_tara(){return tara;}
};
class Agenda{

private:
    std::string lista[1001];
    static int nr_persoane;
public:
    Agenda(){}
    ~Agenda(){}
    std::string operator[](int index)
    {
        return lista[index];
    }
    void Set_lista(int index, std::string cuv){lista[index]=lista[index]+cuv+", ";}
    static void Set_Nr_Persoane(int n){nr_persoane=n;}
    static int Get_Nr_Persoane(){return nr_persoane;}

};
int Agenda::nr_persoane;

void Afisare_Persoana(std::string nume,Agenda agenda){
        int i=0;
        size_t found = agenda[i].find(nume);
        while(i<Agenda::Get_Nr_Persoane())
        {
            size_t found = agenda[i].find(nume);
            if(found != std::string::npos)
                break;
            i++;
        }
        if(found == std::string::npos || i>=Agenda::Get_Nr_Persoane())
            std::cout<<"Nu exista abonat cu numele "<<nume<<std::endl;
        else
            std::cout<<agenda[i]<<std::endl;

    }

void MeniuInteractiv(){

    std::cout<<"1.Citeste n abonati"<<std::endl;
    std::cout<<"2.Afiseaza toti abonatii"<<std::endl;
    std::cout<<"3.Afiseaza abonatul cu numele precizat"<<std::endl;
    std::cout<<"4.Oprire";
    std::cout<<std::endl;
}
void Citire(Agenda &agenda){

    for(int i=0;i<Agenda::Get_Nr_Persoane();i++)
    {
        Persoana a;
        Abonat b;
        Abonat_Skype c;
        Abonat_Skype_Romania d;
        Abonat_Skype_Extern e;
        std::cout<<std::endl<<"Citeste id si nume: ";
        std::cin>>a;
        std::cout<<"Citeste nr_telefon: ";
        std::cin>>b;
        std::cout<<"Citeste id_skype: ";
        std::cin>>c;
        agenda.Set_lista(i,a.Get_id());
        agenda.Set_lista(i,a.Get_nume());
        agenda.Set_lista(i,b.Get_nr_telefon());
        agenda.Set_lista(i,c.Get_id_skype());
        std::cout<<"Citeste tara: ";
        std::cin>>e;
        if(e.Get_tara()=="Romania" || e.Get_tara()=="romania")
        {
            std::cout<<"Citeste adresa_mail: ";
            std::cin>>d;
            agenda.Set_lista(i,d.Get_adresa_mail());
        }
        else
            agenda.Set_lista(i,e.Get_tara());

    }
}
void Afisare(Agenda &agenda){

    for(int i=0;i<Agenda::Get_Nr_Persoane();i++)
        std::cout<<agenda[i]<<std::endl;
}
void Problema(){

    Agenda agenda;
    int option;
    int n;
    std::string nume_persoana;
    MeniuInteractiv();
    std::cin>>option;
    while(option!=4)
    {
        if(option==1)
        {
            std::cout<<"Citeste n: ";
            std::cin>>n;
            Agenda::Set_Nr_Persoane(n);
            Citire(agenda);
        }
        else if(option==2)
            Afisare(agenda);
        else if(option==3)
        {
            std::cout<<"Citeste numele persoanei: ";
            std::cin.get();
            getline(std::cin, nume_persoana);
            Afisare_Persoana(nume_persoana,agenda);
        }
        MeniuInteractiv();
        std::cin>>option;
    }
}

int main()
{
    Problema();
    return 0;
}
