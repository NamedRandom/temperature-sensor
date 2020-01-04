    #include <string.h>
     
    int pin;
    double* last1000;
    int i;
    boolean arrFilled;
     
    void setup() {
      last1000 = new double[1000];
      i=0;
      pin = A0;
      arrFilled = false;
      
      Serial.begin(115200);
      pinMode(pin,INPUT);
     
      
    }

    void updateI(){
      if(i==999){
        arrFilled = true;
        i=0;
      }
      else i++;      
    }

    double average(double arr[]){
      double sum=arr[0];
      
      for(int j=1;j<1000;j++)
        sum+=arr[j];
     
      return sum/1000;
      
    }
    
    void loop() {
      last1000[i] = (analogRead(pin)*5000.0/1024.0-500)/10;
      
      if(arrFilled){
     
        Serial.println("$"+String(average(last1000))+";");
        
        //Serial.println("$"+String(last1000[i])+";");
      }

      updateI();
      
      return;
    }
