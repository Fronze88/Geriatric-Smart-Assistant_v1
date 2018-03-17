#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 accelgyro;

int16_t ax, ay, az, gx, gy, gz;

double timeStep, time, timePrev;
double arx, ary, arz, grx, gry, grz, gsx, gsy, gsz, rx, ry, rz;

int i;
double gyroScale = 131;
int led[9]={0,1,2,3,4,5,6,7,8};
void setup() {

  Wire.begin();
  Serial.begin(9600);
  accelgyro.initialize();
  pinMode(led[6],OUTPUT);
  time = millis();

  i = 1;

}

void loop() {

  // set up time for integration
  timePrev = time;
  time = millis();
  timeStep = (time - timePrev) / 1000; // time-step in s

  // collect readings
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // apply gyro scale from datasheet
  gsx = gx/gyroScale;   gsy = gy/gyroScale;   gsz = gz/gyroScale;

  // calculate accelerometer angles
  arx = (180/3.141592) * atan(ax / sqrt(square(ay) + square(az))); 
  ary = (180/3.141592) * atan(ay / sqrt(square(ax) + square(az)));
  arz = (180/3.141592) * atan(sqrt(square(ax) + square(ay)) / az);

  // set initial values equal to accel values
  if (i == 1) {
    grx = arx;
    gry = ary;
    grz = arz;
  }
  // integrate to find the gyro angle
  else{
    grx = grx + (timeStep * gsx);
    gry = gry + (timeStep * gsy);
    grz = grz + (timeStep * gsz);
  }  

  // apply filter
  rx = (0.1 * arx) + (0.9 * grx);
  ry = (0.1 * ary) + (0.9 * gry);
  rz = (0.1 * arz) + (0.9 * grz);
if(arx>20&&arz>20)
{
  digitalWrite(6, HIGH);
}
else if(arx<20&&arz<20)
{
  digitalWrite(6, LOW);
}
  // print result
  Serial.print("AngleX= "); 
  Serial.println(arx);
  Serial.print("AngleY= ");
  Serial.println(ary);   
  Serial.print("AngleZ= ");
  Serial.println(arz);  
  Serial.println("-----------------------------------------");
  Serial.print("GxX = "); 
  Serial.println(gx); 
  Serial.print("GyY = "); 
  Serial.println(gy);
  Serial.print("GyZ = "); 
  Serial.println(gz);
  Serial.println("-----------------------------------------");
  i = i + 1;
  delay(1000);

}
