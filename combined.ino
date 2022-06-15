
#include <LiquidCrystal.h>
//initialise the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int resval = 0;  // holds the value
int respin = A3; // sensor pin used

void setup() {
  Serial.begin (9600);
  pinMode (2 , INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("  WATER LEVEL : ");
}

void loop() {
  int rain = digitalRead(2);
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);

  resval = analogRead(respin); //Read data from analog pin and store it to resval variable

  if (resval <= 100) {
    lcd.println("     Empty    ");
    Serial.println("Water level: Empty tank- ");
    
    
    if (rain == 1)
    {
      Serial.println("Its Raining");
      delay(500);
    }
    else if (rain == 0)
    {
      Serial.println("No Rain");
      delay(500);
    }
  }
  else if (resval > 100 && resval <= 300) {
    lcd.println("       Low      ");
    Serial.println("Water level:low ");
    if (rain == 1)
    {
      Serial.println("Its Raining");
      delay(500);
    }
    else if (rain == 0)
    {
      Serial.println("No Rain");
      delay(500);
    }
  }
  else if (resval > 300 && resval <= 330) {
    lcd.println("     Medium     ");
    Serial.println("Water level:Medium ");
  }
  else if (resval > 330) {
    lcd.println("      High      ");
    Serial.println("Water level:High ");
    
  }
  delay(1000);
}
