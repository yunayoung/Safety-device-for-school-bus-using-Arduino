#include <SoftwareSerial.h>     //블루투스 통신을 하기위하여 아두이노에서 기본 제공해주는 SoftwareSerial.h를 사용하겠다는 선언문 입니다.
SoftwareSerial BTSerial(6, 7);  // HC - 06 통신을 위한 TX, RX의 PIN번호를 입력 합니다.(TX = 7 , RX = 6)


int ledPin = 13; // LED 연결핀
int inputPin = 2; // 센서 시그널핀
int pirState = LOW; // PIR 초기상태
int val = 0; // Signal 입력값
 
void setup() {
    pinMode(ledPin, OUTPUT); // LED Output 설정
    pinMode(inputPin, INPUT); // 센서 Input 설정

   BTSerial.begin(9600);    //블루투스 통신을 위해 통신속도를 설정하였습니다.
    Serial.begin(9600);
}
 
void loop(){
 
if (BTSerial.available()) {//조건문중 하나인 if문을 사용하였습니다. `만약 블루투스로 신호가 온다면..아래를 실행시켜라` 입니다.                   
    
    val = digitalRead(inputPin); // 센서값 읽기
    Serial.println(val);  //cmd변수에 저장된 내용을 사용자가 `시리얼모니터`를 사용하여 쉽게 확인하는 명령어 입니다.
    
    
    if (val == HIGH) { // 인체감지시
        digitalWrite(ledPin, HIGH); // LED ON
        if (pirState == LOW) {
        // 시리얼모니터에 메시지 출력
        Serial.println("Motion detected!");
        pirState = HIGH;
        }
    } else {
        digitalWrite(ledPin, LOW); // LED OFF
        if (pirState == HIGH){        
            // 시리얼모니터에 메시지 출력            
            Serial.println("Motion ended!");
            pirState = LOW;
        }
    }
}
}

