
//declaration of motors

int right_motor_speed = 3;
int right_motor_backward = 5;
int right_motor_forward = 4;

int left_motor_speed = 6;
int left_motor_backward = 8;
int left_motor_forward = 7;

int Speed = 200 ;         //car speed 
int low_speed = Speed/2;     //(for rotaions)

// Voids:

void forward()
{
  //move both motors FORWARD
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}

void backward()
{
  //move both motors BACKWARD
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward,HIGH);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward, HIGH);
}

void right()
{
  //move car RIGHT
        analogWrite (right_motor_speed,   0   );
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}

void left ()
{
   //move car LEFT
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,    0   );
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward,  LOW);
}

void forward_left()
{
     //move the right motor with the full speed

        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);

      //move the right motor with a lower speed

        analogWrite(left_motor_speed,low_speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}


void forward_right ()
{
        //move the right motor with a low speed

      analogWrite (right_motor_speed,low_speed);
      digitalWrite(right_motor_forward,   HIGH);
      digitalWrite(right_motor_backward,   LOW);

     //move the right motor with the full speed
     
      analogWrite(left_motor_speed,      Speed);
      digitalWrite(left_motor_forward,    HIGH); 
      digitalWrite(left_motor_backward,    LOW);
}

void backward_left()
{
     //move the right motor with the full speed

        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward,HIGH);

      //move the right motor with a lower speed

        analogWrite(left_motor_speed,low_speed);
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward, HIGH);
}

void backward_right()
{
       //move the right motor with the full speed

        analogWrite (right_motor_speed,low_speed);
        digitalWrite(right_motor_forward,    LOW);
        digitalWrite(right_motor_backward,  HIGH);

        //move the right motor with a lower speed

        analogWrite(left_motor_speed,      Speed);
        digitalWrite(left_motor_forward,     LOW);        
        digitalWrite(left_motor_backward,   HIGH);
}
 
void Stop()
{
        analogWrite (right_motor_speed,     0   ); 
        analogWrite (left_motor_speed ,     0   );
} 

void setup() {

  Serial.begin(9600);
  
  pinMode(right_motor_speed,    OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_forward,  OUTPUT);

  pinMode(left_motor_speed,    OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_forward,  OUTPUT);

}

void loop() {
   
  if(Serial.available() > 0)
  {
    char input = Serial.read();
    Serial.println(input);
    switch (input)
    {
      case 'F': //FORWARD
        forward();
          break;
          
      case 'B': //REVERSE
        backward();
          break;

      case 'R': //Right
        right();
          break;

      case 'L': //LEFT
        left();
          break;

      case 'G': //FORWARD LEFT
        forward_left();
          break;
        
      case 'I': //FORWARD RIGHT
        forward_right();
          break;
        
      case 'H': //BACKWARD LEFT
        backward_left();
         break;
        
      case 'J':
        backward_right();
          break;

// our app
      case 'N': //FORWARD LEFT
        forward_left();
          break;
        
      case 'S': //FORWARD RIGHT
        forward_right();
          break;
        
      case 'E': //BACKWARD LEFT
        backward_left();
         break;
        
      case 'W':
        backward_right();
          break;  

          case 'k':
          Stop();
          break;
                
      default: //If bluetooth module receives any value not listed above, both motors turn off
        Stop();
        break;

// controlling speed:

      case '0':
        Speed = 0 ;
          break;

      case '1':
        Speed = 50 ;
          break;

      case '2':
        Speed = 100 ;
          break;

      case '3':
        Speed = 150 ;
          break;

      case '4':
        Speed = 255 ;
          break;
                           
    }
  }
}
