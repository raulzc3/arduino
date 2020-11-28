void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(12, INPUT);
  	Serial.begin(9600);
}

//Función que permite mostrar en el display el número introducido como parámetro
void digit(int num){
  //Creo un array que incluye para cada número la salida que le corresponde en cada pin
  //[num 1[[pin1, estado],[pin2, estado]...],num2 [[pin1, estado][pin2, estado]...]...]
  
    int numsArray[][7][2] = {
      {{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,0}},//0
      {{3,0},{4,1},{5,1},{6,0},{7,0},{8,0},{9,0}},//1
      {{3,1},{4,1},{5,0},{6,1},{7,1},{8,0},{9,1}},//2
      {{3,1},{4,1},{5,1},{6,1},{7,0},{8,0},{9,1}},//3
      {{3,0},{4,1},{5,1},{6,0},{7,0},{8,1},{9,1}},//4
      {{3,1},{4,0},{5,1},{6,1},{7,0},{8,1},{9,1}},//5
      {{3,1},{4,0},{5,1},{6,1},{7,1},{8,1},{9,1}},//6
      {{3,1},{4,1},{5,1},{6,0},{7,0},{8,0},{9,0}},//7
      {{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1}},//8
      {{3,1},{4,1},{5,1},{6,1},{7,0},{8,1},{9,1}} //9
    };
  
   //Recorremos el estado de los pines del numero indicado al llamar a la funcion
    for(int i = 0 ;i <7; i++){
  	digitalWrite(numsArray[num][i][0],numsArray[num][i][1]);
  }
}

//Función que activa el punto del display
void dot(){
    digitalWrite(2, 1);
}

//Función que apaga todos los segmentos del display
void numOff(){  
  for(int i = 3; i<=9; i++){
  digitalWrite(i, 0);
  }
}

//Función que muestra un número aleatorio en el display de 7 segmentos
void rollDice(){
  numOff();
  int randomNum = random(1, 6+1);
  Serial.println(randomNum);

  digit(randomNum);
}

//Función principal
void loop()
{  
  if(digitalRead(12)){
    //Imitamos el comportamiento del dado rodando
    for(int i = 0; i<8; i+=1){
  	  rollDice();
   	  delay(150);
    }
    
    rollDice();
  }

}









