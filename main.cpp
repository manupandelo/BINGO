#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

void mostrarMensaje(string msj){
  cout<<msj<<endl;
}

int pedirInt(string msj){
  int num;
  cout<<msj<<endl;
  cin>>num;
  return num;
}

string pedirString(string msj){
  string palabra;
  cout<<msj<<endl;
  cin>>palabra;
  return palabra;
}

char pedirChar(string msj){
  char car;
  cout<<msj<<endl;
  cin>>car;
  return car;
}

int obtengoRandom(int max, int min){
  srand(time(NULL));
  int num;
  num=min+rand()%(max+1-min);
  return num;
}

bool busqueda(int vec[],int tope, int num){
 int i=0;
 while(vec[i]!=num && i<tope-1){
   i++;
 }
 if(i==tope-1){
   return false;
 }
 else{
   return true;
 }
}

void mostrarInt(int num){
  cout<<num<<endl;
}

int pedirBolilla(int max, int min, int vec[]){
  int bolilla;
  bolilla=obtengoRandom(max, min);
  while(vec[bolilla]==1){
    bolilla=obtengoRandom(max, min);
  }
  vec[bolilla]++;
  cout<<bolilla<<endl;
  return bolilla;
}

int busquedaNum(int bolilla, int tope, int vec[]){
  int num;
  int i=0;
  while(vec[i]!=bolilla && i<tope-1){
   i++;
  }
  if(vec[i]==bolilla){
    num=-1;
  }
  else{
    num=1;
  }
  return num;
}

bool mayorOMenor(int num, int max, int min){
  if(num>max || num<min){
    return true;
  }
  else{return false;}
}

int main() {
//variables
int bolilla;
int num;
string jugador;
string jugador2;
int cartonLleno1=0;
int cartonLleno2=0;
int forma;
char modo;
int i=0;
int a=0;
int e=0;
int posicionCarton1;
int posicionCarton2;
int posicion;


//constantes
const int MAX=10;
const int MIN=1;
const int TOPE=5;
const string BIENVENIDA="Bienvenido al Bingo. aqui podras jugar al bingo (daa obvio) pero puedes elgir la modalidad: si vos elegis tus numeros o si te dan un carton totalmente random. PRESIONE ENTER PARA CONTINUAR";
const string MODALIDAD_RANDOM="¿Quiere usted elegir los numeros de su carton o que salga uno aleatorio? 'a' para aleatorio y 'e' para elegir:";
const string RANDOM="Eligio que los cartones sean aleatorios";
const string ELEGIR="Eligio que usted elija sus numeros";

//vectores
int vecCarton1[TOPE];
int vecCarton2[TOPE];
int vecBolillas[MAX];

mostrarMensaje(BIENVENIDA);
cin.get();


modo=pedirChar(MODALIDAD_RANDOM);
while(modo!='a' && modo!='e'){
  modo=pedirChar("Hubo un error (recuerde que es 'e' para elegir y 'a' para aleatorio) Vuelva a ingresar:");
}
if (modo=='a'){
  mostrarMensaje(RANDOM);
}
else{
  mostrarMensaje(ELEGIR);
}




 if(modo=='a'){
 jugador=pedirString("Ingrese el nombre del primer jugador:");
 jugador2=pedirString("Ingrese el nombre del segundo jugador:");
  while(i<TOPE){
    posicion=obtengoRandom(MAX,MIN);
    while(busqueda(vecCarton1,TOPE, posicion)){
      posicion=obtengoRandom(MAX,MIN);
    }
    vecCarton1[i]=posicion;
    i++;
  }
  cout<<"El carton de "<<jugador<<" es: "<<vecCarton1[0]<<", "<<vecCarton1[1]<<", "<<vecCarton1[2]<<", "<<vecCarton1[3]<<" y "<<vecCarton1[4]<<endl;
  while(a<TOPE){
    posicion=obtengoRandom(MAX,MIN);
    while(busqueda(vecCarton2, TOPE, posicion)){
      posicion=obtengoRandom(MAX,MIN);
    }
    vecCarton2[a]=posicion;
    a++;
  }
  cout<<"El carton de "<<jugador2<<" es: " <<vecCarton2[0]<<", "<<vecCarton2[1]<<", "<<vecCarton2[2]<<", "<<vecCarton2[3]<<" y "<<vecCarton2[4]<<endl;
}

else{
  jugador=pedirString("Ingrese el nombre del primer jugador:");
  jugador2=pedirString("Ingrese el nombre del segundo jugador:");
  while(i<TOPE){
  posicion=pedirInt("Ingrese uno de los numeros para el carton del primer jugador:");
  while(busqueda(vecCarton1,TOPE,posicion)||mayorOMenor(posicion, MAX,MIN)){
    posicion=pedirInt("Ha habido un error, vuelve a intentar:");
  }
  vecCarton1[i]=posicion;
  i++;
 }
 cout<<"El carton de "<<jugador<<"es: "<<vecCarton1[0]<<", "<<vecCarton1[1]<<", "<<vecCarton1[2]<<", "<<vecCarton1[3]<<" y "<<vecCarton1[4]<<endl;
 while(a<TOPE){
    posicion=pedirInt("Ingrese uno de los numeros para el carton del segundo jugador:");
    while(busqueda(vecCarton2, TOPE, posicion) || mayorOMenor(posicion, MAX,MIN)){
      num=pedirInt("Ha habido un error, vuelve a intentar:");
    }
    vecCarton2[a]=posicion;
    a++;
  }
  cout<<"El carton de "<<jugador2<<" es: " <<vecCarton2[0]<<", "<<vecCarton2[1]<<", "<<vecCarton2[2]<<", "<<vecCarton2[3]<<" y "<<vecCarton2[4]<<endl;
}


  while (cartonLleno1!=TOPE && cartonLleno2!=TOPE){
    bolilla=pedirBolilla(MAX,MIN, vecBolillas);
    num=busquedaNum(bolilla, TOPE, vecCarton1);
    if(num==-1){
      cartonLleno1++;
    }
    
    num=busquedaNum(bolilla, TOPE, vecCarton2);
    if(num==-1){
      cartonLleno2++;
    }
    e++;
  }
  if(cartonLleno1>cartonLleno2){
    cout<<"El/la ganador/a es "<< jugador<<endl;
  }
  else if(cartonLleno1==cartonLleno2){
    mostrarMensaje("EMPATE");
  }
  else{cout<<"El/la ganador/a es "<<jugador2<<endl;}
}
