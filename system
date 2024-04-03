
#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>

Servo watering_angle;

#define Angle_pin 9
#define limitofwatering 750
#define pump_pin 7
#define delay_time 60000

char sensor_pin[4]={A0,1,2,3};
int sensor_value[4];
int angle[4]={0,0,0,0};//from web
unsigned long previos_time[4]={0,0,0,0};
unsigned long watering_time[4]={0,0,0,0};//from web
int plant_id[4]={0,17,9,6} ;//from web

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "watechno.host22.com";    // name address for Google (using DNS)

String dataLocation = "GET /plants/add_data.php?id="; //for data base

String dataLocation2 = "GET /plants/get_plants_arduino.php";//from data base

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 170);//from switch 

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

//////////////////////////////////////////////


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Starting ...");
  
  watering_angle.attach(Angle_pin);
  
  pinMode(pump_pin,OUTPUT); //digital pin
  delay(500);
  Serial.println("Ethernet connection ...");
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
 
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    delay(10);
    get_data();
  delay(10);  
  }
  else {
    // kf you didn't get a connection to the server:
    Serial.println("connection failed");
    }
  
}
void loop()
{
  for (int i=1 ; i<4 ;i++){
    sensor_value[i] = analogRead(sensor_pin[i]);
    delay(50);   
    if(sensor_value[i] > limitofwatering)
     if((millis() - previos_time[i] > delay_time) || previos_time[i]==0){
       previos_time[i] = millis();
       Serial.print("plant ID:   ");
       Serial.println(plant_id[i]);
       Serial.print("Angle : ");
       Serial.println(angle[i]);
       Serial.print("analog : ");
       Serial.println(sensor_pin[i]);
       Serial.println( sensor_value[i]);
       
       senddata(i);
       watring(i);
       Serial.println("----------------------------------");
      }   
    }
 delay(2000);
  
}

////////////////////////////////// watring ///////////////////////////////
void watring(int plant_number){
Serial.println("Irrigation ...");
Serial.print("plant number:   ");
Serial.println(plant_number);
Serial.print("Angle : ");
Serial.println(angle[plant_number]);
delay(1);
watering_angle.write(angle[plant_number]);
digitalWrite(pump_pin,HIGH);
delay(watering_time[plant_number]*1000);//seconds
digitalWrite(pump_pin,LOW);
Serial.println("end of Irrigation.");
}


/////////////////////////send data ///////////////////////////////////

void senddata(int plant_number){
  
  Serial.println("connecting...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.print(dataLocation);
    client.print(plant_id[plant_number]); 
    client.println(" HTTP/1.1");
    client.println("Host: watechno.host22.com");
    client.println("Connection: close");
    client.println();
    delay(5);
  }
  else {
    // kf you didn't get a connection to the server:
    Serial.println("connection failed");
  } 
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    }
}

//////////////////// get data //////////////////////////////////


void get_data(){
  //HTTP Protocol
    client.println(dataLocation2 + " HTTP/1.1");
    client.println("Host: watechno.host22.com");
    client.println("Connection: close");
    client.println();
    delay(2000);
   if(Read_data("text/html" ,2000)){
     
    Serial.println("Getting data ...");
   
    Read_data( "\"id\":\"" ,2000);
    plant_id[1] = Read_data_to('"');
    Serial.print("plant_id[1]\t\t");
    Serial.println(plant_id[1]);
    Read_data( "watering_time\":\"" ,2000);
    watering_time[1] = Read_data_to('"');
    Serial.print("watering_time[1]:\t");
    Serial.println(watering_time[1]);    
    Read_data( "_angle\":\"" ,2000);
    angle[1] = Read_data_to('\"');
    Serial.print("watering_angle[1]:\t");
    Serial.println(angle[1]);
    
     Read_data( "\"id\":\"" ,2000);
    plant_id[2] = Read_data_to('"');
    Serial.print("plant_id[2]\t\t");
    Serial.println(plant_id[2]); 
    Read_data( "watering_time\":\"" ,2000);
    watering_time[2] = Read_data_to('"');
    Serial.print("watering_time[2]:\t");
    Serial.println(watering_time[2]);
    Read_data( "_angle\":\"" ,2000);
    angle[2] = Read_data_to('\"');
    Serial.print("watering_angle[2]:\t");
    Serial.println(angle[2]);    
    
    Read_data( "\"id\":\"" ,2000);
    plant_id[3] = Read_data_to('"');
    Serial.print("plant_id[3]\t\t");
    Serial.println(plant_id[3]);
    
    Read_data( "watering_time\":\"" ,2000);
    watering_time[3] = Read_data_to('"');
    Serial.print("watering_time[3]:\t");
    Serial.println(watering_time[3]);
    
    Read_data( "watering_angle\":\"" ,2000);
    angle[3] = Read_data_to( '\"');
    Serial.print("watering_angle[3]:\t");
    Serial.println(angle[3]);
    }
    Serial.print("getting data.\t\t done");
    while( client.available() > 0) client.read();    // Clean the input buffer
  
  delay(100);
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    }
}
 

int8_t Read_data ( char* expected_answer1, unsigned int timeout){

    uint8_t x=0,  answer=0;
    char response[200];
    unsigned long previous;
    memset(response, '\0', 200);    // Initialize the string
    delay(100);
      x = 0;
    previous = millis();
    // this loop waits for the answer
    do{
        if(client.available() != 0){                      
            response[x]= client.read();
     //        Serial.print(response[x]);
            delayMicroseconds(500);
             x++;
            // check if the desired answer is in the response of the module
            if (strstr(response, expected_answer1) != NULL)    
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }
    while((answer == 0) && ((millis() - previous) < timeout));    

    return answer;
}
 
int16_t Read_data_to( char to_char){
   String str =String("");
   while( client.available()){
    char c = client.read();
//  Serial.print(c);
    delay(2); 
   if(c == to_char)break;
    str += c;
   
   }
   
   return str.toInt();
 }
