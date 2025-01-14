//Final Project
//Shintaro Aso 200597145
//08/09/2024
#include <Keypad.h>
#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd( 12,11,5,4,3,2);
char keymap[4][4]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte row[4] = {13,10,9,8};
byte col[4]= {7,6,A4,A5};

Keypad pad = Keypad(makeKeymap(keymap), row, col, 4, 4);

//variables
const int max = 15;

void setup()
{
//Initialize the LCD.
lcd.begin (16,2);
Serial.begin(9600);
}
void loop(){
  bool error = false;
  //initialize an array that store user input
  char input[16] = {'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
  //print the main menu
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Select Mode");
  lcd.setCursor(0,1);
  lcd.print("1: DtoB  2: BtoD");
  char mode = NULL;
  
  //get mode selection
  //Any key doesn't work except 1 and 2
  while(mode != '1' && mode != '2'){
  	mode = pad.getKey();
  }
  
  //mode 1 DtoB
  if(mode == '1'){
  	lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input D num & *");
    //digit is a variable that takes user input each time
    char digit = NULL;
    int position = 0;
    //Set maximum length to 16 digits
    while(position < 16){
      lcd.setCursor(position, 1);
      lcd.print('<');
      while(digit != '*' && !checkNum(digit)){
      	digit = pad.getKey();
      }
      //get out of the loop when user input *
      if(digit == '*'){
      	break;
      } else {
		input[position] = digit;
      	lcd.setCursor(position, 1);
      	lcd.print(digit);
      	position++;
      	digit = NULL;
      }
    }
    lcd.clear();
  	long newNumber = toInt(input);
    Serial.print("newNumber: ");
    Serial.println(newNumber);
  	DtoB(newNumber);
    char next = NULL;
    //wait until any button is pressed and go back to the menu
    while(next == NULL){
      next = pad.getKey();
    }
  }
  
  //mode 2 B to D
  if(mode == '2'){
  	lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input B num & *");
    char digit = NULL;
    int position = 0;
    //Set the maximum length to 16 digits
    while(position < 16){
      lcd.setCursor(position, 1);
      lcd.print('<');
      while(digit != '*' && digit != '1' && digit != '0'){
      	digit = pad.getKey();
      }
      if(digit == '*'){
      	break;
      } else {
		input[position] = digit;
      	lcd.setCursor(position, 1);
      	lcd.print(digit);
      	position++;
      	digit = NULL;      
      }
    }
    lcd.clear();
    //Convert number stored in array to integer
    long newNumber = toInt(input);
    BtoD(newNumber);
    char next = NULL;
    //wait until any button is pressed and go back to the menu
    while(next == NULL){
      next = pad.getKey();
    }    
  }
}

//check if the char is number
bool checkNum(char c){
	if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0'){
    	return true;
    } else {
    	return false;
    }
}

//convert char number to int number
int CtoI(char c){
  switch(c){
  	case '1':
    	return 1;
   		break;
    case '2':
    	return 2;
    	break;
    case '3':
    	return 3;
    	break;
    case '4':
    	return 4;
    	break;
    case '5':
    	return 5;
    	break;
    case '6':
    	return 6;
    	break;
    case '7':
    	return 7;
    	break;
    case '8':
    	return 8;
    	break;
    case '9':
    	return 9;
    	break;
    case '0':
    	return 0;
    	break;
  }
}


//convert input array to int num
long toInt(char arr[]){
  int countA = 0;
  int count0 = 0;
  //count how many 'a' left
  for(int i=15; i>=0; i--){
    if(arr[i] == 'a'){
    	countA++;
    } else {
    	break;
    }
  }
  
  //count how many 0 ahead the number
  for(int i=0; i<=15; i++){
    if(arr[i] == '0'){
    	count0++;
    } else {
    	break;
    }
  }
  
  //convert char array to integer number;
  long total = 0;
  long pValue = 1;
  for(int i=max-countA; i>=count0; i--){
    long p = CtoI(arr[i]) * pValue;
  	total = total + p;
    Serial.print(CtoI(arr[i]));
    Serial.print("*");
    Serial.print(pValue);
    Serial.print("=");
    Serial.println(p);
    Serial.println(total);
    pValue = pValue * 10;
  }
  return total;
}

//Decimal to Binaly
void DtoB(long num){
  Serial.println(num);
  lcd.setCursor(0,0);
  lcd.print("Result:");
  if(num > 65535 || num < 0){
    lcd.setCursor(0,1);
    lcd.print("Num is too big!");
  } else {
  	int nums[16] = {0};
  	int i = 0;
  	while(num > 0){
  	  nums[i] = num % 2;
      num = num / 2;
      i++;
  	}

    for(int i=15; i>=0; i--){
      lcd.setCursor(15-i, 1);
      lcd.print(nums[i]);
    }
    
  }
}

//Binary to Decimal
void BtoD(long num){
  lcd.setCursor(0,0);
  lcd.print("Result:");
  if(num < 0){
  	lcd.setCursor(0,1);
    lcd.print("Upto 10 digits");
  } else {
  	long sum = 0;
  	long pValue = 1;
  	while(num > 0){
  		sum = sum + (num%10)*pValue;
    	pValue = pValue * 2;
    	num = num / 10;
  	}
  	lcd.setCursor(0,1);
  	lcd.print(sum);
  }
}