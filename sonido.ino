const int sensorSonido = A0;
const int foco1 = 9,foco2=5,foco3=8;   // <--- Nuevo pin para el foco/LED
int umbral = 19;     



void setup() {
  pinMode(foco1, OUTPUT); // Configurar el foco como salida
   pinMode(foco2, OUTPUT);
      pinMode(foco3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorSonido = analogRead(sensorSonido);
  Serial.println(valorSonido);

  if (valorSonido > umbral) {
    digitalWrite(foco2, LOW);
    // --- Acción cuando hay sonido ---
    digitalWrite(foco3, HIGH); // Enciende el foco
    delay(5000);
    digitalWrite(foco3, LOW);
    digitalWrite(foco1, HIGH);
    delay(5000);
    digitalWrite(foco1, LOW); 
   // Apaga el foco
  } else {
    // --- Acción en silencio ---

    digitalWrite(foco1, LOW);
    digitalWrite(foco3, LOW);
     digitalWrite(foco2, HIGH);
  }

  delay(100);
}