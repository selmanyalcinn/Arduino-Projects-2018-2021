/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

WiFiClient client;

String MakerIFTTT_Key ;
;String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;

void setup()
{
  WiFi.disconnect();
  delay(3000);
  WiFi.begin("LinyitNet_yalcin","kamil1616");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  if (client.connect("maker.ifttt.com",80)) {
    MakerIFTTT_Key ="g6HLCwXlVmgZDSfBK_XeNxiTXuVvY9GJlJ_QPRELjlx";
    MakerIFTTT_Event ="email";
    p = post_rqst;
    p = append_str(p, "POST /trigger/");
    p = append_str(p, MakerIFTTT_Event);
    p = append_str(p, "/with/key/");
    p = append_str(p, MakerIFTTT_Key);
    p = append_str(p, " HTTP/1.1\r\n");
    p = append_str(p, "Host: maker.ifttt.com\r\n");
    p = append_str(p, "Content-Type: application/json\r\n");
    p = append_str(p, "Content-Length: ");
    content_length_here = p;
    p = append_str(p, "NN\r\n");
    p = append_str(p, "\r\n");
    json_start = p;
    p = append_str(p, "{\"value1\":\"");
    p = append_str(p, "selmanyalcin16@gmail.com");
    p = append_str(p, "\",\"value2\":\"");
    p = append_str(p, "asdafcrqwderqzxqxrwxrzxqrxzrxqrewzreqxzrexqwzx");
    p = append_str(p, "\",\"value3\":\"");
    p = append_str(p, "asxafzcsafxqxdxzdxdsssssssssssaa");
    p = append_str(p, "\"}");

    compi= strlen(json_start);
    content_length_here[0] = '0' + (compi/10);
    content_length_here[1] = '0' + (compi%10);
    client.print(post_rqst);

  }

}


void loop()
{


}
