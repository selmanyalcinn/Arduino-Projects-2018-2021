#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRrecv irrecv(2);
decode_results results;


void setup() {
Serial.begin(9600);
irrecv.enableIRIn();

}

void loop() {
if(irrecv.decode(&results))
Serial.println(results.value, HEX);
Serial.println("fg");
irrecv.resume();
}




