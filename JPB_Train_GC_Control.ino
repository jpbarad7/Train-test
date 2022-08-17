int dt = 2000;                    // delay time
int sd = 500;                     // speed delay
 
int active = 0;
int direct = 0;
int forward = 0;
int tag_sensor = 0;
int park_sensor = 0;
int start_trigger = 0;
int stop1_trigger = 0;
int speed1 = 0;
int motion = 0;

int bell = 0;
int bell2 = 0;
int twhistle_cluster = 0;
int twhistle_long = 0;
int twhistle_long2 = 0;
int twhistle_short = 0;
int twhistle_short_RFID = 0;
int water_draining = 0;
int sound_on_off_reset = 0;
int brake_squeal = 0;
int shoveling_coal = 0;
int injector = 0;
int coupler_uncoupler = 0;
int coal_dropping = 0;
int steam = 0;
int sound_on_off_no_reset = 0;
int conductor_call = 0;
int generator = 0;
int steam_hammer = 0;
int coal_unloading = 0;
int water_filling_tank = 0;
int ready_bell = 0;

int motor = 0;
int sound = 0;
int light = 0;
int smoke = 0;

int RFID_input1;                  //  Whistle
int RFID_input2;                  //  Bell
int RFID_input3;                  //  Speed_input1
int RFID_input4;                  //  Speed_input2
int RFID_input5;                  //  Station_input1
int RFID_input6;                  //  Station_input2
int RFID_input7;                  //  Park_input1
int RFID_input8;                  //  Park_input2

char inString();


void setup() {
  
  Serial3.begin(115200);

  pinMode ( 2, INPUT);            // RFID Whistle              
  pinMode ( 3, INPUT);            // RFID Bell
  pinMode ( 4, INPUT);            // Speed input 1
  pinMode ( 5, INPUT);            // Speed input 2
  pinMode ( 6, INPUT);            // Station input 1
  pinMode ( 7, INPUT);            // Station input 2
  pinMode ( 9, INPUT);            // Park input 1
  pinMode (10, INPUT);            // Part input 2
  pinMode (13, INPUT);            // Input from WiFi when online

  pinMode (22, INPUT_PULLUP);            // Bell from user interface
  pinMode (23, INPUT_PULLUP);            // Whistle cluster from user interface
  pinMode (24, INPUT_PULLUP);            // Whistle long from user interface
  pinMode (25, INPUT_PULLUP);            // Whistle short from user interface
  pinMode (26, INPUT_PULLUP);            // Water draining from user interface
  pinMode (27, INPUT_PULLUP);            // Sound ON/OFF with reset from train control program
  pinMode (28, INPUT_PULLUP);            // Brake squeal from user interface
  pinMode (29, INPUT_PULLUP);            // Shoveling coal from user interface
  pinMode (30, INPUT_PULLUP);            // Injector from user interface
  pinMode (31, INPUT_PULLUP);            // Coupler/Uncoupler from user interface
  pinMode (32, INPUT_PULLUP);            // Coal dropping from user interface
  pinMode (33, INPUT_PULLUP);            // Steam from user interface
  pinMode (34, INPUT_PULLUP);            // Sound ON/OFF without reset from user interface
  pinMode (35, INPUT_PULLUP);            // Conductor call from user interface
  pinMode (36, INPUT_PULLUP);            // Generator from user interface
  pinMode (37, INPUT_PULLUP);            // Steam hammer from user interface
  pinMode (38, INPUT_PULLUP);            // Coal unloading from user interface
  pinMode (39, INPUT_PULLUP);            // Water filling tank from user interface
  pinMode (40, INPUT_PULLUP);            // Bell signaling 'WiFi Online' from WiFi control board

  pinMode (42, INPUT_PULLUP);            // Stop/Slow down push button from Argon
  pinMode (43, INPUT_PULLUP);            // Start/Speed up push button from Argon
  pinMode (44, INPUT);            // Tag sensor switch from Argon
  pinMode (45, INPUT);            // Twhistle push button from Argon
  pinMode (46, INPUT);            // Cwhistle push button from Argon
  pinMode (47, INPUT);            // Bell push button from Argon
  pinMode (48, INPUT);            // Light switch from Argon
  pinMode (49, INPUT);
  pinMode (50, INPUT);            // Motor switch from Argon
  pinMode (51, INPUT);            // Direction switch from Argon
  pinMode (52, INPUT);            // Smoke switch from Argon
  pinMode (53, OUTPUT);
  pinMode (54, INPUT);            
                  
  pinMode (A0, OUTPUT);           // Light relay                 
  pinMode (A1, OUTPUT);           // Smoke relay
  pinMode (A2, OUTPUT);           // Sound relay
  pinMode (A3, OUTPUT);           // Motor relay
    
/*  delay (10000);                   // Delay to allow sound board / decoder to wake up

  Serial3.write("<0>");           // Turns power to DCC++ rails (communication lines) off
  delay(100);
  Serial3.write("<1>");           // Turns power to DCC++ rails on
  delay(100);
  Serial3.write("<f 3 184>");     // Turns sound on
  delay(100);
*/    
}
    
void loop() {
  
//  Sounds

ready_bell = digitalRead (13);
  if ((ready_bell == LOW) && (active == 0)) {
    Serial3.write("<0>");           // Turns power to DCC++ rails (communication lines) off
    delay(100);
    Serial3.write("<1>");           // Turns power to DCC++ rails on
    delay(100);
    Serial3.write("<f 3 184>");     // Turns sound on
    delay(100);
    active = 1; } 

 bell = digitalRead (23);
  if (bell == LOW) { 
    Serial3.write("<f 3 129>");         // Bell from GUI
    delay(dt);
    Serial3.write("<f 3 128>"); }       // Cancel bell   

  bell2 = digitalRead (22);
  if (bell2 == LOW) { 
    Serial3.write("<f 3 129>");         // Bell from RFID
    delay(dt);
    Serial3.write("<f 3 128>"); }       // Cancel bell     

//twhistle_cluster = digitalRead (23);
//  if (twhistle_cluster == LOW) { 
//    Serial3.write("<f 3 130>");         // Train whistle - single cluster
//   delay(dt); }
   
//twhistle_long = digitalRead (24);
//  if (twhistle_long == LOW) { 
//    Serial3.write("<f 3 132>");         // Train whistle - long (sustained)
//    delay(dt);
//    Serial3.write("<f 3 128>"); }       // Cancel train whistle

//twhistle_long2 = digitalRead (50);
//  if (twhistle_long2 == HIGH) { 
//    Serial3.write("<f 3 132>");         // Train whistle - long (sustained)
 //   delay(dt);
 //   Serial3.write("<f 3 128>"); }       // Cancel train whistle    

twhistle_short = digitalRead (25);
  if (twhistle_short == LOW) { 
    Serial3.write("<f 3 136>");         // Train whistle - single short
    delay(dt); }

twhistle_short_RFID = digitalRead (24);
  if (twhistle_short_RFID == LOW) { 
    Serial3.write("<f 3 136>");         // Train whistle - single short
    delay(dt); }
    
water_draining = digitalRead (26);
  if (water_draining == LOW) { 
    Serial3.write("<f 3 180>");         // Water draining
    delay(dt);
    Serial3.write("<f 3 176>"); }       // Cancel water draining  

sound_on_off_reset = digitalRead (27);
  if (sound_on_off_reset == LOW) { 
    Serial3.write("<f 3 184>");         // Sound ON toggle with reset
    delay(dt); 
    Serial3.write("<f 3 176>"); }       // Sound OFF  

brake_squeal = digitalRead (28);
  if (brake_squeal == LOW) { 
    Serial3.write("<f 3 161>");         // Brake squeal
    delay(dt);
    Serial3.write("<f 3 160>"); }       // Cancel brake squeal

shoveling_coal = digitalRead (29);
  if (shoveling_coal == LOW) { 
    Serial3.write("<f 3 162>");         // Shoveling coal
    delay(dt);
    Serial3.write("<f 3 160>"); }       // Cancel shoveling coal

injector = digitalRead (30);
  if (injector == LOW) { 
    Serial3.write("<f 3 164>");         // Injector
    delay(dt);
    Serial3.write("<f 3 160>"); }       // Cancel injector   

coupler_uncoupler = digitalRead (31);
  if (coupler_uncoupler == LOW) { 
    Serial3.write("<f 3 168>");         // Coupler/Uncoupler
    delay(dt); }

coal_dropping = digitalRead (32);
  if (coal_dropping == LOW) { 
    Serial3.write("<f 3 222 1>");      // Coal dropping
    delay(dt); }

steam = digitalRead (33);
  if (steam == LOW) { 
    Serial3.write("<f 3 222 2>");       // Steam
    delay(dt);
    Serial3.write("<f 3 222 0>"); }     // Cancel steam

sound_on_off_no_reset = digitalRead (34);
  if (sound_on_off_no_reset == LOW) { 
    Serial3.write("<f 3 222 8>");       // Sound OFF (resumes with any sound activation)
    delay(dt); }
 
conductor_call = digitalRead (35);
  if (conductor_call == LOW) { 
    Serial3.write("<f 3 222 16>");      // Conductor calling "All Aboard"
    delay(dt); }

generator = digitalRead (36);
  if (generator == LOW) { 
    Serial3.write("<f 3 222 32>");      // Generator
    delay(dt);
    Serial3.write("<f 3 222 0>"); }     // Cancel generator

steam_hammer = digitalRead (37);
  if (steam_hammer == LOW) { 
    Serial3.write("<f 3 222 64>");      // Steam hammer
    delay(dt);
    Serial3.write("<f 3 222 0>"); }     // Cancel steam hammer 

coal_unloading = digitalRead (38);
  if (coal_unloading == LOW) { 
    Serial3.write("<f 3 222 128>");     // Coal unloading into hopper
    delay(dt);
    Serial3.write("<f 3 222 0>"); }     // Cancel coal unloading 

water_filling_tank = digitalRead (39);
  if (water_filling_tank == LOW) { 
    Serial3.write("<f 3 223 1>");       // Water filling tank
    delay(dt);
    Serial3.write("<f 3 223 0>"); }     // Cancel water filling tank                   
                
//cwhistle = digitalRead (33);          // Uncomment for PaPa's train
//  if (cwhistle == LOW) { 
//    Serial3.write("<f 3 130>");       // Conductor whistle
//    delay(dt);
//    Serial3.write("<f 3 128>"); }     // Cancel conductor whistle 
/*   
motor = digitalRead (37); 
  if (motor == HIGH) { digitalWrite (A2, HIGH); } else { digitalWrite (A2, LOW); }

sound = digitalRead (43);
  if (sound == HIGH) { digitalWrite (A3, HIGH); } else { digitalWrite (A3, LOW); }

light = digitalRead (35);
  if (light == HIGH) { digitalWrite (A1, HIGH); } else { digitalWrite (A1, LOW); }

smoke = digitalRead (39); 
  if (smoke == HIGH) { digitalWrite (A0, HIGH); } else { digitalWrite (A0, LOW); }
   
direct = digitalRead (38);
  if (direct == HIGH) { forward = 1; } else { forward = 0; } 
  

// Start / Stop / Speed up / Speed down

start_trigger = digitalRead (30);     
  if ((start_trigger == HIGH) && (forward == 1) && (motion == 0) && (speed1 == 0)) { 
    Serial3.write("<t 1 03 10 1>");
    delay (sd);
    Serial3.write("<t 1 03 20 1>");
    delay (sd);
    Serial3.write("<t 1 03 30 1>");
    delay (sd);
    Serial3.write("<t 1 03 40 1>"); 
    delay (sd); 
    motion = 1; 
    speed1 = 1; }         // Forward, slow speed
    
    else if ((start_trigger == HIGH) && (forward == 1) && (motion == 1) && (speed1 == 1)) {
      Serial3.write("<t 1 03 50 1>");
      delay (sd);
      Serial3.write("<t 1 03 60 1>");
      delay (sd); 
      Serial3.write("<t 1 03 70 1>");
      delay (sd);  
      motion = 1; 
      speed1 = 2; }       // Forward, medium speed
      
    else if ((start_trigger == HIGH) && (forward == 1) && (motion == 1) && (speed1 == 2)) { 
      Serial3.write("<t 1 03 80 1>");
      delay (sd);
      Serial3.write("<t 1 03 90 1>");
      delay (sd);
      Serial3.write("<t 1 03 100 1>");
      delay (sd);  
      motion = 1; 
      speed1 = 3; }       // Forward, high speed

  if ((start_trigger == HIGH) && (forward == 0) && (motion == 0) && (speed1 == 0)) { 
    Serial3.write("<t 1 03 10 1>");
    delay (sd);
    Serial3.write("<t 1 03 20 1>");
    delay (sd);
    Serial3.write("<t 1 03 30 1>");
    delay (sd);
    Serial3.write("<t 1 03 40 0>"); 
    delay (sd); 
    motion = 1; 
    speed1 = 1; }         // Reverse, slow speed
    
    else if ((start_trigger == HIGH) && (forward == 0) && (motion == 1) && (speed1 == 1)) {
      Serial3.write("<t 1 03 50 1>");
      delay (sd);
      Serial3.write("<t 1 03 60 1>");
      delay (sd); 
      Serial3.write("<t 1 03 70 0>"); 
      delay (sd); 
      motion = 1; 
      speed1 = 2; }  // Reverse, medium speed
      
    else if ((start_trigger == HIGH) && (forward == 0) && (motion == 1) && (speed1 == 2)) {
      Serial3.write("<t 1 03 80 1>");
      delay (sd);
      Serial3.write("<t 1 03 90 1>"); 
      delay (sd);
      Serial3.write("<t 1 03 100 0>"); 
      delay (sd); 
      motion = 1; 
      speed1 = 3; }  // Reverse, high speed     

stop1_trigger = digitalRead (28); 
  if ((stop1_trigger == HIGH) && (forward == 1) && (motion == 1) && (speed1 == 1)) {
    Serial3.write("<t 1 03 30 1>");
    delay (sd); 
    Serial3.write("<t 1 03 20 1>");
    delay (sd);
    Serial3.write("<t 1 03 10 1>");
    delay (sd);
    Serial3.write("<t 1 03 0 1>"); delay (5000); Serial3.write("<t 1 03 -1 1>"); 
    motion = 0; 
    speed1 = 0; 
    delay (sd); }
    
    else if ((stop1_trigger == HIGH) && (forward == 1) && (motion == 1) && (speed1 == 2)) {
      Serial3.write("<t 1 03 60 1>");
      delay (sd);
      Serial3.write("<t 1 03 50 1>");
      delay (sd); 
      Serial3.write("<t 1 03 40 1>"); 
      delay (sd); 
      speed1 = 1; }
      
    else if ((stop1_trigger == HIGH) && (forward == 1) && (motion == 1) && (speed1 == 3)) {
      Serial3.write("<t 1 03 90 1>");
      delay (sd);
      Serial3.write("<t 1 03 80 1>");
      delay (sd); 
      Serial3.write("<t 1 03 70 1>"); 
      delay (sd); 
      speed1 = 2; }

  if ((stop1_trigger == HIGH) && (forward == 0) && (motion == 1) && (speed1 == 1)) {
    Serial3.write("<t 1 03 30 1>");
    delay (sd);
    Serial3.write("<t 1 03 20 1>");
    delay (sd);
    Serial3.write("<t 1 03 10 1>");
    delay (sd); 
    Serial3.write("<t 1 03 0 0>"); 
    delay (5000);
    Serial3.write("<t 1 03 -1 1>"); 
    motion = 0; 
    speed1 = 0; 
    delay (sd); }
    
    else if ((stop1_trigger == HIGH) && (forward == 0) && (motion == 1) && (speed1 == 2)) {
      Serial3.write("<t 1 03 60 1>");
      delay (sd);
      Serial3.write("<t 1 03 50 1>"); 
      delay (sd);
      Serial3.write("<t 1 03 40 0>"); 
      delay (sd); 
      speed1 = 1; }
      
    else if ((stop1_trigger == HIGH) && (forward == 0) && (motion == 1) && (speed1 == 3)) {
      Serial3.write("<t 1 03 90 1>");
      delay (sd);
      Serial3.write("<t 1 03 80 1>");
      delay (sd); 
      Serial3.write("<t 1 03 70 0>"); 
      delay (sd); 
      speed1 = 2; } 


//  Output speed to Argon then user interface GUI

if (speed1 == 0) { digitalWrite(40, LOW); digitalWrite(42, LOW); }
  else if (speed1 == 1) { digitalWrite(40, HIGH); digitalWrite(42, LOW);  }
  else if (speed1 == 2) { digitalWrite(40, LOW);  digitalWrite(42, HIGH); }
  else if (speed1 == 3) { digitalWrite(40, HIGH); digitalWrite(42, HIGH); } 


//  RFID tag initiated events

tag_sensor = digitalRead (31);

RFID_input1 = digitalRead( 2);                          //  Whistle 
RFID_input2 = digitalRead( 3);                          //  Bell
RFID_input3 = digitalRead( 4);                          //  Speed input 1
RFID_input4 = digitalRead( 5);                          //  Speed input 2
RFID_input5 = digitalRead( 6);                          //  Station input 1
RFID_input6 = digitalRead( 7);                          //  Station input 2

if ((RFID_input1 == HIGH) && (tag_sensor == HIGH)) { 
    Serial3.write("<f 3 130>");                         // Train whistle
    delay(dt);
    Serial3.write("<f 3 128>"); }                       // Cancel train whistle   

if ((RFID_input2 == HIGH) && (tag_sensor == HIGH)) { 
    Serial3.write("<f 3 129>");                         // Bell
    delay(dt);
    Serial3.write("<f 3 128>"); }                       // Cancel bell 
    
       
//  Speed (input from RFID tag)

if ((RFID_input3 == HIGH) && (RFID_input4 == LOW) &&  (forward == 1) && (tag_sensor == HIGH) && (speed1 == 2)) {
  Serial3.write("<t 1 03 60 1>");
  delay (sd);
  Serial3.write("<t 1 03 50 1>");
  delay (sd);
  Serial3.write("<t 1 03 40 1>");
  delay (sd); 
  motion = 1; 
  speed1 = 1; }

if ((RFID_input3 == HIGH) && (RFID_input4 == LOW) &&  (forward == 1) && (tag_sensor == HIGH) && (speed1 == 3)) {
  Serial3.write("<t 1 03 90 1>");
  delay (sd);
  Serial3.write("<t 1 03 80 1>");
  delay (sd);
  Serial3.write("<t 1 03 70 1>");
  delay (sd);
  Serial3.write("<t 1 03 60 1>");
  delay (sd);
  Serial3.write("<t 1 03 50 1>");
  delay (sd);
  Serial3.write("<t 1 03 40 1>");
  delay (sd); 
  motion = 1; 
  speed1 = 1; } 
   

if ((RFID_input3 == LOW)  && (RFID_input4 == HIGH) && (forward == 1) && (tag_sensor == HIGH) && (speed1 == 1)) { 
  Serial3.write("<t 1 03 50 1>");
  delay (sd);
  Serial3.write("<t 1 03 60 1>");
  delay (sd);
  Serial3.write("<t 1 03 70 1>");  
  delay (sd); 
  motion = 1; 
  speed1 = 2; }

if ((RFID_input3 == LOW)  && (RFID_input4 == HIGH) && (forward == 1) && (tag_sensor == HIGH) && (speed1 == 3)) { 
  Serial3.write("<t 1 03 90 1>");
  delay (sd);
  Serial3.write("<t 1 03 80 1>");
  delay (sd);
  Serial3.write("<t 1 03 70 1>");  
  delay (sd); 
  motion = 1; 
  speed1 = 2; }  
 

if ((RFID_input3 == HIGH) && (RFID_input4 == HIGH) && (forward == 1) && (tag_sensor == HIGH) && (speed1 == 1)) {
  Serial3.write("<t 1 03 50 1>");
  delay (sd);
  Serial3.write("<t 1 03 60 1>");
  delay (sd);
  Serial3.write("<t 1 03 70 1>");
  delay (sd);
  Serial3.write("<t 1 03 80 1>");
  delay (sd);
  Serial3.write("<t 1 03 90 1>");
  delay (sd);  
  Serial3.write("<t 1 03 100 1>"); 
  delay (sd); 
  motion = 1; 
  speed1 = 3; }

if ((RFID_input3 == HIGH) && (RFID_input4 == HIGH) && (forward == 1) && (tag_sensor == HIGH) && (speed1 == 2)) {
  Serial3.write("<t 1 03 80 1>");
  delay (sd);
  Serial3.write("<t 1 03 90 1>");
  delay (sd);  
  Serial3.write("<t 1 03 100 1>"); 
  delay (sd); 
  motion = 1; 
  speed1 = 3; }  


// Station number (input from RFID tag, output to Argon then user interface GUI)

if ((RFID_input5 == LOW)  && (RFID_input6 == LOW))  { digitalWrite (45, LOW);  digitalWrite (47, LOW);  }
if ((RFID_input5 == HIGH) && (RFID_input6 == LOW))  { digitalWrite (45, HIGH); digitalWrite (47, LOW);  }
if ((RFID_input5 == LOW)  && (RFID_input6 == HIGH)) { digitalWrite (45, LOW);  digitalWrite (47, HIGH); }
if ((RFID_input5 == HIGH) && (RFID_input6 == HIGH)) { digitalWrite (45, HIGH); digitalWrite (47, HIGH); }


// Park indicator (input from RFID tag to slow/stop/park)

park_sensor = digitalRead (33);
RFID_input7 = digitalRead ( 9);                          //  Park trigger input 1
RFID_input8 = digitalRead (10);                          //  Park trigger input 2

if ((park_sensor == HIGH) && (forward == 1) && (motion == 1)) {
  if ((RFID_input7 == HIGH) && (RFID_input8 == HIGH) && (speed1 >= 2))  {
    Serial3.write("<t 1 03 90 1>");
    delay (sd);
    Serial3.write("<t 1 03 80 1>");
    delay (sd); 
    Serial3.write("<t 1 03 70 1>"); 
    delay (sd); 
    speed1 = 2; }
    
  if ((RFID_input7 == HIGH) && (RFID_input8 == LOW) && (speed1 == 2)) {
    Serial3.write("<t 1 03 60 1>");
    delay (sd);
    Serial3.write("<t 1 03 50 1>"); 
    delay (sd);
    Serial3.write("<t 1 03 40 1>"); 
    delay (sd); 
    speed1 = 1; }
    
  if ((RFID_input7 == LOW)  && (RFID_input8 == HIGH))  {
    Serial3.write("<t 1 03 30 1>"); 
    delay (sd);
    Serial3.write("<t 1 03 20 1>");
    delay (sd);
    Serial3.write("<t 1 03 10 1>");
    delay (sd);
    Serial3.write("<t 1 03 0 1>");  
    delay (5000); 
    Serial3.write("<t 1 03 -1 1>");
    motion = 0;
    speed1 = 0;
    delay (sd); } 
}

*/

}

    
