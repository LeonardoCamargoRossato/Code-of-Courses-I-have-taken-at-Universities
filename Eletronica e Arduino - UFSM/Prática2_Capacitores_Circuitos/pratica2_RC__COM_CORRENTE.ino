#include <math.h>

//Define as variáveis
int pinoSaida = 11;
float tempoInicial;
float tempoFinal;
float tempoTotal;
double resistencia;
int pinoCapacitor;
int pinoEntrada;
double capacitancia=47;


void setup() {
// Configura o pino para saída
pinMode(pinoSaida, OUTPUT);
digitalWrite(pinoSaida,LOW);


// Configura a velocidade da serial
Serial.begin(19200);
}

void loop() {
  // Coloca o pino em estado para descarregar o capacitor
  digitalWrite(pinoSaida,LOW);
  //Marca tempo inicial em microsegundos
  tempoInicial=micros();
  //Lê a tensão no capacitor
  pinoCapacitor=analogRead (A0);
   

  // Continua a descaga do capacitor enquanto a sua tensão for maior que 0,05 V
  while(pinoCapacitor > 10) { 
    pinoCapacitor=analogRead (A0);
    //Lê a tensão de entrada
    pinoEntrada=analogRead (A1);
    // Marca tempo Final  em microsegundos
    tempoFinal = micros();
    //Calcula o tempo total  em microsegundos
    tempoTotal = tempoFinal-tempoInicial;
    
    delay(10000);

    
    Serial.print(tempoTotal/1000000);
    Serial.print("   ");
    Serial.print(pinoCapacitor);
    Serial.print("   ");
    Serial.println(pinoEntrada);

  }


  //Coloca o pino em estado alto para carregar o capacitor
  digitalWrite(pinoSaida, HIGH);
  //Marca tempo inicial  em microsegundos
  tempoInicial=micros();

  //Continua a carga do capacitor enquanto sua tensão for menor que 4,95 V 
  while (pinoCapacitor < 1013) { // Se 1023 corresponde a 5 V, 4,95 V corresponde a 1023
    pinoCapacitor = analogRead (A0);
    //Lê a tensão de entrada
    pinoEntrada=analogRead (A1);
    // Marca tempo Final  em microsegundos
    tempoFinal = micros();
    //Calcula o tempo total  em microsegundos
    delay(200);
    tempoTotal = tempoFinal-tempoInicial;

    float e = 2.71828 ; 
    double V = (pinoCapacitor*4.95)/1023;   // Voltagem
    double R = 100000; // Resistência
    float C = 0.000001; // Capacitância
    double t = tempoTotal/1000000; 
    double i = 1000000( V/R )*pow(e,-t/(R*C)); //Cálculo da Corrente em Circuito RC ;

    
    Serial.print(V);
    Serial.print("   ");
    Serial.print(i,12);
    Serial.print("        ");
  
    
    
    Serial.print(tempoTotal/1000000);
    Serial.print("   ");
    Serial.print(pinoCapacitor);
    Serial.print("   ");
    Serial.println(pinoEntrada);
   }


      
}
