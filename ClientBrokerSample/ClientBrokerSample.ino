#include "Library/ClientBroker/clientBuffer.h"

//#include <FreeRTOS_ARM.h>

  char *msg1 = "Hello";
  char *msg2 = "Those semicolons";
  char *msg3 = "World";
  char *msg4 = "low power";
  char *msg5 = "You just brought piss to a shit fight";

static void test(void *arg) {
  clientBuffer::getInstance()->publish("42", msg1);
  clientBuffer::getInstance()->publish("42", msg2);
  clientBuffer::getInstance()->publish("42", msg3);
  clientBuffer::getInstance()->publish("42", msg4);
  clientBuffer::getInstance()->publish("42", msg5);
}

void setup() {
  // put your setup code here, to run once:
  //char *Message = "What's going on";
  //String test = String(Message);

  SerialUSB.begin(0);

  while(!SerialUSB);


  clientBuffer::getInstance()->initialize("42", "43");

  xTaskCreate(test, NULL, 500, NULL, 1, NULL);
  vTaskStartScheduler();

  while(1);

  //Wifi_init(appid, pdid);

}

void loop() {
  // put your main code here, to run repeatedly:

}
