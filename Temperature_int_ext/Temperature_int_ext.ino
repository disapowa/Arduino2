/*

*/
int switchS = 0;
int stateLight = 0;
float sateVariateur = 0;
float temperature = 0;

void setup() {
    pinMode(2, INPUT);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
}

void loop() {


    int btn = digitalRead(2);

/*
    Serial.print(btn);
    Serial.print(stateLight);
      Serial.print("\n");*/
    if( btn != switchS ){

      if( btn == 1 ){
        if( stateLight == 1 ){
            stateLight = 0;
        }else{
            stateLight = 1;
         }
      }

      delay(150);
    }
    switchS = btn;


    int variateur = ( ( float(analogRead( A4 )) / float(1024) ) * 250 ); //255

    if( stateLight != 0 ){
      analogWrite(9, variateur);
    }else{
      analogWrite(9, 0);
    }

    sateVariateur = variateur;
    



    int sensorVal = analogRead( A0 );

    float voltage = (sensorVal / 1024.0) * 5.0;
    float temperatureNow = (voltage - .5) * 100;

    
    if( int(temperatureNow) != int(temperature) ){
      temperature = temperatureNow;
      Serial.print(temperature);
      Serial.print("\n");
    }





     sensorVal = analogRead( A2 );

     voltage = (sensorVal / 1024.0) * 5.0;
     temperatureNow = (voltage - .5) * 100;
    Serial.print("dehors");
    Serial.print(temperatureNow);
      Serial.print("\n");
    delay(400);
}

