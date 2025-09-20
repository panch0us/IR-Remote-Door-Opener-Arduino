#include <IRremote.h>

#define IR_RECEIVE_PIN 11 // Пин подключения ИК-приемника

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Инициализация с feedback LED
}

void loop() {
  if (IrReceiver.decode()) { // Если данные получены
    Serial.print("0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Вывод кода
    IrReceiver.resume(); // Ждем следующую команду
  }
}