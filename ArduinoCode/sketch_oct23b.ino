#include <SoftwareSerial.h>

int Tx=6;
int Rx=7;

SoftwareSerial BTserial(Tx,Rx);
//DEVICE = YAY
//PIN=0000

int ledPin = 13; // LED 연결핀
int inputPin = 2; // 센서 시그널핀
int pirState = LOW; // PIR 초기상태
int val = 0; // Signal 입력값

void setup() {
    pinMode(ledPin, OUTPUT); // LED Output 설정
    pinMode(inputPin, INPUT); // 센서 Input 설정
    
    Serial.begin(9600);
    BTserial.begin(9600);
}
 
void loop(){
if(Serial.available()){
    val = digitalRead(inputPin); // 센서값 읽기
    if (val == HIGH) { // 인체감지시
        digitalWrite(ledPin, HIGH); // LED ON
        if (pirState == LOW) {
        // 시리얼모니터에 메시지 출력
         Serial.println("Motion detected!");
   
        BTserial.write(Serial.read());
        pirState = HIGH;
        }
    } else {
        digitalWrite(ledPin, LOW); // LED OFF
        if (pirState == HIGH){        
            // 시리얼모니터에 메시지 출력            
            Serial.println("Motion ended!");
           
            BTserial.write(Serial.read());
            pirState = LOW;
        }
    }
}
}

