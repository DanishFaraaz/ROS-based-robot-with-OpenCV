

/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Int16.h>

//motor 1
int EA = 10;


int in1 = 3;
int in2 = 2;

//motor 2
int EB = 9;
int in3 = 4;
int in4 = 5;
const int trigPin_middle = 11;
const int echoPin_middle = 12;
const int trigPin_left = 6;
const int echoPin_left = 7;
const int trigPin_right = A0;
const int echoPin_right = A1;
// defines variables
long duration_middle,duration_left,duration_right;
int distance,distanceCm_middle,distanceCm_left,distanceCm_right;

int a;
// ESC signal wire connected to pin 11 on arduino
int  val =100;

ros::NodeHandle  nh;

void messageCb( const std_msgs::Int16& msg)
{
  
      a=msg.data;
digitalWrite(trigPin_middle, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_middle, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_middle, LOW);
duration_middle = pulseIn(echoPin_middle, HIGH);
distanceCm_middle= duration_middle*0.034/2;

digitalWrite(trigPin_left, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_left, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_left, LOW);
duration_left = pulseIn(echoPin_left, HIGH);
distanceCm_left= duration_left*0.034/2;

digitalWrite(trigPin_right, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_right, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_right, LOW);
duration_right = pulseIn(echoPin_right, HIGH);
distanceCm_right= duration_right*0.034/2;



  
    if(a == 0)                                        // straight
 
 {

    nh.loginfo("The direction is straight");
 // nh.loginfo(distanceCm);
    analogWrite(EB, 130);
    analogWrite(EA, 130);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(10);
 
}
 if(a== 1)                                        // left

 {

  nh.loginfo("The direction is left ");
    analogWrite(EB, 130);
    analogWrite(EA, 130);
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(10);
 }
if(a== 2)                                        // left

 {
   nh.loginfo("The direction is left ");
  // nh.loginfo(distanceCm);
    analogWrite(EB, 130);
    analogWrite(EA, 130);
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(10);
 }

 if(a== 3)                                        //right
 {
  nh.loginfo("The direction is right ");
    analogWrite(EB, 130);
    analogWrite(EA, 130);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(10);

}


 if(a== 4)                                        //right
 {
  nh.loginfo("The direction is right ");
   analogWrite(EB, 130);
    analogWrite(EA, 130);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(10);

}

if( distanceCm_middle <= 30)
{
   nh.loginfo("The command is stop ");
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(200);
   do{
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   delay(3000);   
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   delay(1000);   
   }while(distanceCm_middle>=100);
}

if( distanceCm_left <= 30)
{
   nh.loginfo("The command is stop ");
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(200);
   do{
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   delay(3000);   
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   delay(1000);   
   }while(distanceCm_left>=100);
}

if( distanceCm_right <= 30)
{
   nh.loginfo("The command is stop ");
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   delay(200);
   do{
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   delay(3000);   
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(1000);   
   }while(distanceCm_right>=100);
}
}





ros::Subscriber<std_msgs::Int16> sub("chatter", &messageCb);
void setup()
{ 
  nh.initNode();
  nh.subscribe(sub);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(EA, OUTPUT);
  pinMode(EB, OUTPUT);
pinMode(trigPin_middle, OUTPUT);
pinMode(echoPin_middle, INPUT);
pinMode(trigPin_left, OUTPUT);
pinMode(echoPin_left, INPUT);
pinMode(trigPin_right, OUTPUT);
pinMode(echoPin_right, INPUT);
  
  
}

void loop()
{
 pinMode(trigPin_middle, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin_middle, INPUT); // Sets the echoPin as an Input
 pinMode(trigPin_left, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin_left, INPUT); // Sets the echoPin as an Inputv
 pinMode(trigPin_right, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin_right, INPUT); // Sets the echoPin as an Input
  nh.spinOnce();
  delay(1);
}
