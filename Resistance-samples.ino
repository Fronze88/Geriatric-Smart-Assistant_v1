#define N 6

#define basis 20000.0

int potpin = A4;
float val, r,R1,R2,R3,R4,R5,R6,sum;


void setup()
{
    Serial.begin(9600);
}

void loop()
{
    val = analogRead(potpin);

    r = ((basis * 1023.0) / (1023.0 - val)) - basis;

    delay(100);

    Serial.print(" R:  ");
    if(filter() >= 1000)
    {
        if(filter() >= 500.0*1000.0)
        {
            Serial.println("Infinity!!");
        }
        else
        {
            Serial.print(filter() / 1000.0);
            Serial.println("K ohm");
        }
    }

    else
    {
        Serial.print(filter());
        Serial.println(" ohm");
    }
}


float filter()
{
  
    float sum = R1+R2+R3+R4+R5+R6;
    R1=r;
    delay(100);
    R2=r;
    delay(100);
    R3=r;
    delay(100);
    R4=r;
    delay(100);
    R5=r;
    delay(100);
    R6=r;
    return (float)(sum / N);
}
