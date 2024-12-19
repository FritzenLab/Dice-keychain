

int bitsresultados[6];
int passagem= 0;

// Variables used on this code
unsigned long time1;
unsigned long previousTime;
boolean enterFunction = true;
unsigned long time2;
unsigned long previousTime2;
boolean enterFunction2 = true;
//-----------------------

int digitoaentrar = 1;


void setup() {
  
  //Serial.begin(9600);
}

void loop() {

  time1 = micros();
  time2 = micros();
  if (enterFunction == true) {
    previousTime = time1;
    passagem++;
    // Start your code below
    //-----------------------

    
    if (digitoaentrar == 1 && passagem == 1) {
      if (bitsresultados[5] == 1) {
        pinMode(3, OUTPUT);
        pinMode(0, OUTPUT);
        pinMode(1, OUTPUT);
        digitalWrite(0, HIGH);
        digitalWrite(1, LOW);
      }
      digitoaentrar = 2;
    }
    if (digitoaentrar == 2 && passagem == 2) {
      if (bitsresultados[4] == 1) {
        pinMode(3, OUTPUT);
        pinMode(0, OUTPUT);
        pinMode(1, OUTPUT);
        digitalWrite(0, LOW);
        digitalWrite(1, HIGH);
      }
      digitoaentrar = 3;
    }
    if (digitoaentrar == 3 && passagem == 3) {
      if (bitsresultados[3] == 1) {
        pinMode(0, INPUT);
        pinMode(0, OUTPUT);
        pinMode(2, OUTPUT);
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
      }
      digitoaentrar = 4;
    }
    if (digitoaentrar == 4 && passagem == 4) {
      if (bitsresultados[2] == 1) {
        pinMode(0, INPUT);
        pinMode(0, OUTPUT);
        pinMode(2, OUTPUT);
        digitalWrite(1, LOW);
        digitalWrite(2, HIGH);
      }
      digitoaentrar = 5;
    }
    if (digitoaentrar == 5 && passagem == 5) {
      if (bitsresultados[1] == 1) {
        pinMode(3, OUTPUT);
        pinMode(1, INPUT);
        pinMode(2, OUTPUT);
        digitalWrite(0, HIGH);
        digitalWrite(2, LOW);
      }
      digitoaentrar = 6;
    }
    if (digitoaentrar == 6 && passagem == 6) {
      if (bitsresultados[0] == 1) {
        pinMode(3, OUTPUT);
        pinMode(1, INPUT);
        pinMode(2, OUTPUT);
        digitalWrite(0, LOW);
        digitalWrite(2, HIGH);
      }
      digitoaentrar= 1;
      passagem= 0;
    }

    //-----------------------
    // End of your code
  }

  if (enterFunction2 == true) {
    previousTime2 = time2;

   
    //Serial.println (t-273.0);

    for (int i = 0; i < 7; i++) {


      bitsresultados[i] = bitRead(88, i); //This is where the magic happens, I get the "t" value (temperature),
      // round it, convert it to integer and extract every bit of its binary equivalent. The bits are then used to enter
      // each charlieplexed LED bit value
      
    }
       

  }


  // The DELAY time is adjusted in the constant below >>
  if (time1 - previousTime < 990) { // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */
    enterFunction = false;
  }
  else {
    enterFunction = true;
  }
  if (time2 - previousTime2 < 4999990) { // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */
    enterFunction2 = false;
  }
  else {
    enterFunction2 = true;
  }

}
