#include <iostream>
#define TAM 50

class persona{
private:
    std::string nombre;
public:
    persona(){};
    friend std::ostream & operator<<(std::ostream &O, persona &x){
            O<<"\n Nombre: "<<x.nombre<<std::endl;
            return O;
    }
    friend std::istream & operator>>(std::istream &O, persona &x){
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            return O;
    }
};

class Constancia
{
    private:
        std::string nombre;
        std::string carrera;
        int materias;
        float promedio;

    public:
        friend std::ostream & operator<<(std::ostream &O, Constancia &x){
            O<<"\n Nombre del alumno: "<<x.nombre<<std::endl;
            O<<"\n Carrera del alumno: "<<x.carrera<<std::endl;
            O<<"\n Mateiras aprovadas: "<<x.materias<<std::endl;
            O<<"\n Promedio del alumno: "<<x.promedio<<std::endl;
            return O;
        }
        friend std::istream & operator>>(std::istream &O, Constancia &x){
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            std::cout<<"\n Carrera: ";
            O>>x.carrera;
            std::cout<<"\n Materias: ";
            O>>x.materias;
            std::cout<<"\n Promedio: ";
            O>>x.promedio;
            return O;
        }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            persona x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    Cola<Constancia> MiCola;
    Constancia x;
    int opc;

    do
    {
        system("cls");
        std::cout<<"Elija una opcion\n"<<std::endl;
        std::cout<<"1. Dar de alta una solicitud"<<std::endl;
        std::cout<<"2. Elaborar una constancia"<<std::endl;
        std::cout<<"3. Salir"<<std::endl<<"  : ";
        std::cin>>opc;

        switch (opc)
        {
            case 1:
                system("cls");
                std::cout<<"Dar de alta una solicitud\n"<<std::endl;
                std::cout<<"Ingrese los datos de la constancia"<<std::endl;
                std::cin>>x;
                MiCola.Queue(x);
                system("pause");
            break;
            case 2:
                system("cls");
                std::cout<<"Elaborar una constancia\n"<<std::endl;
                if (!MiCola.vacia())
                {
                    std::cout<<"Estos son los datos de la constancia"<<std::endl;
                    x = MiCola.Front();
                    std::cout<<x;
                    std::cout<<"nSeguro de elaborar esta?\n 1. SI  2. NO   : ";
                    std::cin>>opc;
                    if (opc == 1)
                    {
                        MiCola.Dequeue();
                    }
                }
                else
                {
                    std::cout<<"No hay solicitudes de constancias"<<std::endl;
                }

                system("pause");

            break;
        }
    } while (opc != 3);

    return 0;
}
