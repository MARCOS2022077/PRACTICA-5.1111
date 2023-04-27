#include <Keypad.h>//se crea la libreria para iniciar el teclado matricial
const int FILAS = 4;//se crean el numero de filas
const int COLUMNAS= 4;//se crean el numero de filas
const int buz=10;//se indidca el pin que llevara el buzzer
const int radar = 11;//se indica el pin para el sensor radar
int lee;//se crea para usarse depues
char keys[FILAS][COLUMNAS]={ //se ajustan como van las columnas y filas del teclado matricial
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFila[FILAS]={9,8,7,6};//se indica que pines llevan las filas
byte pinesColumna[COLUMNAS]={5,4,3,2};//se indican que pines llevan las columnas
Keypad teclado=Keypad(makeKeymap(keys), pinesFila, pinesColumna,FILAS,COLUMNAS);//se le indica como van las filas y columas del teclado matricial
char teclaPrecionada;//se crea una variable de tipo caracter para depues leer lo que se envie en el teclado matricial
char pass[6]="90210"; //Poner en el arreglo 1 posicion mas a la que tendra la contraseña correcta
char ingresaPass[6]; // tiene que tener el mismo tamaño del arreglo de la contraseña correcta
int indice=0;//se crea esta variable para que cuando se de un codigo para ingresar siempre se inicie desde 0
#define salida(pin) pinMode(pin,OUTPUT);//se define la función pin mode con salida
#define entrada(pin) pinMode(pin,INPUT);//se define la función pin mode con entrada
#define encender_b(pin) tone(pin,100);//se sustituye el tone por encender_b
#define apagar_b(pin) noTone(pin);//se sustituye el notone por apagar_b
void setup()
{
	Serial.begin(9600);
  entrada(radar);//se indica la entrada
  salida(buz);// se indica la salida
  encender_b(buz);//se indica el encender_b
  apagar_b(buz);//se indica el apagar_b
}

void loop(){
  teclaPrecionada=teclado.getKey(); //detecta que en el teclado se pulso un boton
  if(teclaPrecionada){//se crea la condición
    ingresaPass[indice]=teclaPrecionada; // le asigna lo que ingresamos a el arreglo que va a ser comparado
    indice++; //cambiara la posicion del arreglo para poder asignar los caracteres
    Serial.print(teclaPrecionada);
  }
   lee=digitalRead(radar);//se indica que lee va a ser = qie digitalRead(radar)
  if (lee == 1)//se crea la condición
  {
    encender_b(buz);//se dise que si cumple hace esto
  }

  if(indice==5){ //cuando se llegue al limite del arreglo verificara si esta correcta o no la contraseña
    if(strcmp(pass,ingresaPass)==0){ //Verifica que la contraseña esta correcta
      apagar_b(buz);//se indica que si pasa esto esto pasa
    }
    indice=0;
  }
}


  
