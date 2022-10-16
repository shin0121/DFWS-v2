/*
 Name:		DFWS.ino
 Created:	10/5/2022 6:05:21 PM
 Author:	CABELIN
*/
//////////////////////////////////////////////////////////////// Everything important before the void setup

#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include <HX711_ADC.h> 
#include <Wire.h>



// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 47;
const int LOADCELL_SCK_PIN = 46;

HX711_ADC scale(47, 46);
int taree = A0;

// Color definitions
#define ILI9341_BLACK 0000 /* 0, 0, 0 */
#define ILI9341_NAVY 0x000F /* 0, 0, 128 */
#define ILI9341_DARKGREEN 0x03E0 /* 0, 128, 0 */
#define ILI9341_DARKCYAN 0x03EF /* 0, 128, 128 */
#define ILI9341_MAROON 0x7800 /* 128, 0, 0 */
#define ILI9341_PURPLE 0x780F /* 128, 0, 128 */
#define ILI9341_OLIVE 0x7BE0 /* 128, 128, 0 */
#define ILI9341_LIGHTGREY 0xC618 /* 192, 192, 192 */
#define ILI9341_DARKGREY 0x7BEF /* 128, 128, 128 */
#define ILI9341_BLUE 0x001F /* 0, 0, 255 */
#define ILI9341_GREEN 0x07E0 /* 0, 255, 0 */
#define ILI9341_CYAN 0x07FF /* 0, 255, 255 */
#define ILI9341_RED 0xF800 /* 255, 0, 0 */
#define ILI9341_MAGENTA 0xF81F /* 255, 0, 255 */
#define ILI9341_YELLOW 0xFFE0 /* 255, 255, 0 */
#define ILI9341_WHITE 0xFFFF /* 255, 255, 255 */
#define ILI9341_ORANGE 0xFD20 /* 255, 165, 0 */
#define ILI9341_GREENYELLOW 0xAFE5 /* 173, 255, 47 */
#define ILI9341_PINK 0xF81F
#define ILI9341_esti 0x794379
#define ILI9341_esti2 0x86923B
/******************* UI details */
#define BUTTON_X 120
#define BUTTON_Y 140
#define BUTTON_W 220
#define BUTTON_H 40
#define BUTTON_SPACING_X 10
#define BUTTON_SPACING_Y 10
#define BUTTON_TEXTSIZE 2

// text box where numbers go
#define TEXT_X 10
#define TEXT_Y 10
#define TEXT_W 150
#define TEXT_H 80
#define TEXT_TSIZE 3
#define TEXT_TCOLOR ILI9341_MAGENTA
// the data (phone #) we store in the textfield
#define TEXT_LEN 4
char textfield[TEXT_LEN + 1] = "";
uint8_t textfield_i = 0;

#define YP A3 // must be an analog pin, use "An" notation!
#define XM A2 // must be an analog pin, use "An" notation!
#define YM 9 // can be a digital pin
#define XP 8 // can be a digital pin

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define TS_MINX 100
#define TS_MAXX 920
#define TS_MINY 70
#define TS_MAXY 900
// We have a status line for like, is FONA working
#define STATUS_X 10
#define STATUS_Y 60

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

//int goal;

//button details for InputScreen
#define BUTTON_X_input 50
#define BUTTON_Y_input 120
#define BUTTON_W_input 60
#define BUTTON_H_input 30
#define BUTTON_SPACING_Xinput 10
#define BUTTON_SPACING_Yinput 10
#define BUTTON_TEXTSIZE_input 2
//Textbox Details for InputScreen
#define TEXT_X_input 10
#define TEXT_Y_input 10
#define TEXT_W_input 220
#define TEXT_H_input 50
#define TEXT_TSIZE_input 3
#define TEXT_TCOLOR_input ILI9341_MAGENTA
//SaveButton
#define BUTTON_X_save 120
#define BUTTON_Y_save 280
#define BUTTON_W_save 200
#define BUTTON_H_save 35
#define BUTTON_SPACING_Xsave 10
#define BUTTON_SPACING_Ysave 10

//Button Details for Side Buttons
#define SIDE_X 200
#define SIDE_Y 20
#define SIDE_W 75 //WIDTH
#define SIDE_H 25
#define SIDE_I 5
#define SIDE_TEXTSIZE 1
#define SIDE_SPACING_X 5
#define SIDE_SPACING_Y 5

// Button Details Food Category
#define CATEG_X 120
#define CATEG_Y 120
#define CATEG_W 220
#define CATEG_H 30
#define CATEG_SPACING_X 5
#define CATEG_SPACING_Y 5
#define CATEG_TEXTSIZE 2

// Button Details Fruit Category
#define FRUIT_X 120 //Left border
#define FRUIT_Y 110 //Top
#define FRUIT_W 220 //110
#define FRUIT_H 30 //25 //lower
#define FRUIT_SPACING_X 10
#define FRUIT_SPACING_Y 8
#define FRUIT_TEXTSIZE 2

//NextButton
#define FRUIT_X_next 120
#define FRUIT_Y_next 280
#define FRUIT_W_next 200
#define FRUIT_H_next 35
#define BUTTON_SPACING_X 10
#define BUTTON_SPACING_Y 10

//TRACKER
#define TRACKER_X 50
#define TRACKER_Y 20

//GOAL
#define GOAL_X 25
#define GOAL_Y 120

//INTAKE
#define In_X 140
#define In_Y 120

//REMAINING CALORIES
#define rCal_X 10
#define rCal_Y 250

#define MINPRESSURE 10
#define MAXPRESSURE 1000

char currentPage, categoryPage, unit;
int newCalorie = 0;
int newcurrent = 0, current = 0, count = 0, counter = 0, check = 0, calorie = 0;
int x = 0, y = 0, z = 0;
int totalIntake = 0;
bool buttonEnabled = true;
int weight = 0;
int finalWeight = 0;


Adafruit_GFX_Button i_buttons[12];
/* create 15 buttons, in classic candybar phone style */
char i_buttonlabels[12][5] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "Back", "9", "Clr" };
uint16_t i_buttoncolors[12] = { ILI9341_BLACK, ILI9341_BLACK, ILI9341_BLACK,
ILI9341_BLACK, ILI9341_BLACK, ILI9341_BLACK, ILI9341_BLACK, ILI9341_BLACK,
ILI9341_BLACK, ILI9341_BLUE, ILI9341_BLACK, ILI9341_RED };

Adafruit_GFX_Button SaveButton[1];

Adafruit_GFX_Button BackButton[1], NextButton[1], CancelButton[1];
Adafruit_GFX_Button inputButton[1];
Adafruit_GFX_Button tareButton[1];
Adafruit_GFX_Button trackButton[1];
Adafruit_GFX_Button ResetButton[1];

//Category Buttons
Adafruit_GFX_Button category[5];
char categorylabels[6][24] = { "Fruits","Vegetables","Grains", "Protein", "Dairy", "Save"};
uint16_t categorycolors[6] = { ILI9341_DARKGREY, ILI9341_RED, ILI9341_esti2, ILI9341_esti, ILI9341_PINK, ILI9341_DARKGREEN};

//Category Buttons
Adafruit_GFX_Button fruit[10];
char fruitlabels[10][24] = { "Apple","Avocado","Banana", "Durian", "Grape", "Guava", "Jackfruit", "Lemon","Lime","Mango" };
int fruitcalories[10] = { 67, 100, 126, 44, 163, 83, 70, 111, 64, 42 };
uint16_t colors = ILI9341_esti2;

Adafruit_GFX_Button veg[10];
char veglabels[10][50] = { "Apat Fern", "Bamboo Shoot", "Banana Heart", "Bottle Gourd", "Cabbage", "Carrot", "Cauliflower", "Cucumber", "Eggplant", "Garlic Leaves" };
int vegcalories[10] = { 131, 28, 39, 20, 31, 42, 32, 16, 29, 50 };

Adafruit_GFX_Button grains[10];
char grainslabels[10][50] = { "Bread", "Cashew", "Coconut Meat", "Mung Bean", "Pasta", "Peanut", "Peanut Butter", "Pili", "Rice", "Watermelon Seed" };
int grainscalories[10] = { 329, 603, 102, 348, 361, 617, 616, 699, 356, 562 };

Adafruit_GFX_Button protein[10];
char proteinlabels[10][50] = { "Beef Lean", "Beef Liver", "Beef Sirloin", "Beef Spleen", "Carabeef Lean Meat", "Carabeef Spleen", "Chicken Breast", "Chicken Feet", "Chicken Leg", "Chicken Wing" };
int proteincalories[10] = { 134, 144, 132, 95, 90, 98, 131, 187, 204, 194 };

Adafruit_GFX_Button dairy[10];
char dairylabels[10][50] = { "Cheese", "Chic Spread", "Cream", "Buttermilk", "Cara Milk", "Cow Milk", "Egg", "Egg Duck", "Goat Milk", "Yoghurt" };
int dairycalories[10] = { 297, 210, 241, 43, 124, 65, 139, 177, 73, 83 };



void setup() {

    Serial.begin(9600);
    tft.reset();
    tft.begin(0x9341);
    tft.setRotation(0);

    //clear_LCD();


    //Serial.println("HomeScreen Display");

    HomeScreen();
    //currentPage = '0';
    //newcurrent = '0';
    scale.begin(); // start connection to HX711
    scale.start(1000); // load cells gets 1000ms of time to stabilize
    //Calibarate your LOAD CELL with 100g weight, and change the value according to readings
    scale.setCalFactor(216.83);

}




void loop() {

  
    digitalWrite(13, HIGH);
    TSPoint p = ts.getPoint();
    digitalWrite(13, LOW);
    // if sharing pins, you'll need to fix the directions of the touchscreen pins
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
        // scale from 0->1023 to tft.width
        p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
        p.y = (tft.height() - map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    }

    

    if (currentPage == '0') {

        scale.update();
        int w = scale.getData();
        weight = computeWeight(w);
        DisplayWeight(weight);

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            inputButton[0].press(true);
            Serial.println("input button");
            DrawInput();
            currentPage = '2';

        }

        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            tareButton[0].press(true);
            Serial.println("tare button");
            currentPage = '3';
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 80 && p.y <= 100) {
            trackButton[0].press(true);
            Serial.println("track button");
            DrawTrack(x,y,z);
            currentPage = '4';
        }

        else {
            inputButton[0].press(false);
            tareButton[0].press(false);
            trackButton[0].press(false);

            for (uint8_t b = 0; b < 6; b++) {
                if (category[b].contains(p.x, p.y)) {
                    category[b].press(true); // tell the button it is pressed

                    if (b == 0) {  //currentPage = 5
                        tft.setRotation(0);
                        DrawFruits();
                        currentPage = '5';
                        Serial.println("Fruits");
                    }
                    if (b == 1) { //currentPage = 6
                        tft.setRotation(0);
                        DrawVeg();
                        currentPage = '6';
                        Serial.println("Veg");
                    }
                    if (b == 2) { //currentPage = 7
                        tft.setRotation(0);
                        DrawGrains();
                        currentPage = '7';
                    }
                    if (b == 3) { //currentPage = 8
                        tft.setRotation(0);
                        DrawProtein();
                        currentPage = '8';
                    }
                    if (b == 4) { //currentPage = 9
                        tft.setRotation(0);
                        DrawDairy();
                        currentPage = '9';
                    }

                    if (b == 5) {
                        tft.setRotation(0);     
                        finalWeight = weight;
                        Serial.print(finalWeight);
                        SaveWeightButton(finalWeight);
                        //HomeScreen();
                    }
                    else {
                        category[b].press(false); // tell the button it is NOT pressed
                    }
                }
                
            }
               
        }
        
    }


    //INPUT
    if (currentPage == '2') {
        
        for (uint8_t b = 0; b < 12; b++) {
            if (i_buttons[b].contains(p.x, p.y)) {
                i_buttons[b].press(true); // tell the button it is pressed
            }
            else {
                i_buttons[b].press(false); // tell the button it is NOT pressed
            }
            
        }
        // now we can ask the buttons if their state has changed
        for (uint8_t b = 0; b < 12; b++) {
            if (i_buttons[b].justReleased()) {
                i_buttons[b].drawButton(); // draw normal
            }

            if (i_buttons[b].justPressed()) {
                i_buttons[b].drawButton(true); // draw invert!

                // if a numberpad button, append the relevant # to the textfield
                if (b >= 0 && b != 9 && b != 11) {
                    if (textfield_i < TEXT_LEN) {
                        textfield[textfield_i] = i_buttonlabels[b][0];
                        textfield_i++;
                        textfield[textfield_i] = 0; // zero terminate
                    }
                }


                // clr button
                if (b == 11) {
                    textfield[textfield_i] = 0;
                    if (textfield > 0) {
                        textfield_i--;
                        textfield[textfield_i] = ' ';
                    }
                }

                if (textfield_i == 255) {
                    //Serial.print("THIS IS 255  ");
                    //Serial.println(textfield_i);
                    textfield_i = 0;
                }

                // update the current text field
                Serial.println(textfield);
                tft.setCursor(TEXT_X + 2, TEXT_Y + 10);
                tft.setTextColor(ILI9341_BLACK, ILI9341_DARKGREY);
                tft.setTextSize(TEXT_TSIZE);
                tft.print(textfield);

                //Back Button
                if (b == 9) {
                    textfield_i = 0;
                    //void fillscreen();
                    HomeScreen();
                }

                
            }
            
        }

        if (p.x >= 120 && p.x <= 320 && p.y >= 280 && p.y <= 315) {
            Serial.println("save button");

            x = atoi(textfield);
            Serial.println(x);

            if (x < 1200 || x > 2000 ) {
                displayErrorGoal();
                textfield_i = 0;
                x = 0;
                y = 0;
                z = 0;
            }
            else {
                Serial.println(x);
                y = 0;
                z = 0;
               
                textfield_i = 0;
                displayTargetGoal(x);
            }     
        }    
    }

    
    if (currentPage == '3') {
        tft.fillRect(20, 120, 200, 50, ILI9341_WHITE);
        tft.setCursor(90, 140);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("TARE");

        weight = 0;
        DisplayWeight(weight);
        scale.start(1000);
        HomeScreen();
    }

    //Tracker
    if (currentPage == '4') {

        if (BackButton[1].contains(p.x, p.y)) {
            BackButton[1].press(true); // tell the button it is pressed
        }
        else {
            BackButton[1].press(false); // tell the button it is NOT pressed
        }

        if (BackButton[2].justReleased()) {
            BackButton[1].drawButton(); // draw normal
        }

        if (BackButton[1].justPressed()) {
            BackButton[1].drawButton(true);
            void fillscreen();
            HomeScreen();
        }

        if (ResetButton[1].contains(p.x, p.y)) {
            ResetButton[1].press(true); 
        }
        else {
            ResetButton[1].press(false);
        }
        
        if (ResetButton[1].justReleased()) {
            ResetButton[1].drawButton(); 
        }

        if (ResetButton[1].justPressed()) {
            ResetButton[1].drawButton(true);
            Serial.println("reset button");
            y = 0;
            z = 0;
            Serial.println(x);
            Serial.println(y);
            Serial.println(z);
            DrawTrack(x, y, z);

        }
    }

    //Fruits
    if (currentPage == '5') {


        void fillscreen();

        int categ = 1;

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            clearInput();
        }
        if (p.x >= 10 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            HomeScreen();
        }
        else {
            BackButton[0].press(false);
            CancelButton[0].press(false);

            if (p.x >= 120 && p.x <= 340 && p.y >= 110 && p.y <= 140) {
                clearInput();
                fruit[0].press(true);
                Serial.println("b = 1");
                count = 0;
                displayCalorie(0, categ);

            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 148 && p.y <= 178) {
                clearInput();
                fruit[1].press(true);
                Serial.println("b = 2");
                count = 1;
                displayCalorie(1, categ);

            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 186 && p.y <= 216) {
                clearInput();
                fruit[2].press(true);
                Serial.println("b = 3");
                count = 2;
                displayCalorie(2, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 224 && p.y <= 254) {
                clearInput();
                fruit[3].press(true);
                Serial.println("b = 4");
                count = 3;
                displayCalorie(3, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 262 && p.y <= 292) {
                clearInput();
                fruit[4].press(true);
                Serial.println("b = 5");
                count = 4;
                displayCalorie(4, categ);
            }
            else {
                if (p.x >= 200 && p.x <= 275 && p.y >= 60 && p.y <= 100) { // Save Button
                    SaveButton[0].press(true);
                    Serial.println("Save");
                    if (x == 0) {
                        errorSave();
                    }
                    else {
                        displaySave(categ, count);
                        clearInput();
                        calorie = fruitcalories[count]; // Calorie = contains the saved calorie
                        Serial.print("Calorie before: ");
                        Serial.println(calorie);
                        Serial.println(finalWeight);
                        calorie = ceil(double((float)finalWeight / 100) * calorie);
                        Serial.print("Calorie: ");
                        Serial.println(calorie);
                        totalIntake += calorie;
                        Serial.println(totalIntake);
                        y = totalIntake;
                        z = x - y;

                    }

                }
                else {
                    SaveButton[0].press(false);
                }

            }
        }


    }
    //Veg
    if (currentPage == '6') {

        int categ = 2;
        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            clearInput();
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            BackButton[0].press(false);
            CancelButton[0].press(false);

            if (p.x >= 120 && p.x <= 340 && p.y >= 110 && p.y <= 140) {
                clearInput();
                veg[0].press(true);
                Serial.println("b = 1");
                count = 0;
                displayCalorie(0, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 148 && p.y <= 178) {
                clearInput();
                veg[1].press(true);
                Serial.println("b = 2");
                count = 1;
                displayCalorie(1, categ);

            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 186 && p.y <= 216) {
                clearInput();
                veg[2].press(true);
                Serial.println("b = 3");
                count = 2;
                displayCalorie(2, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 224 && p.y <= 254) {
                clearInput();
                veg[3].press(true);
                Serial.println("b = 4");
                count = 3;
                displayCalorie(3, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 262 && p.y <= 292) {
                clearInput();
                veg[4].press(true);
                Serial.println("b = 5");
                count = 4;
                displayCalorie(4, categ);
            }
            else {
                if (p.x >= 200 && p.x <= 275 && p.y >= 60 && p.y <= 90) { // Save Button
                    SaveButton[0].press(true);
                    Serial.println("Save");
                    if (x == 0) {
                        errorSave();
                    }
                    else {
                        displaySave(categ, count);
                        clearInput();
                        calorie = vegcalories[count]; // Calorie = contains the saved calorie
                        Serial.print("Calorie before: ");
                        Serial.println(calorie);
                        Serial.println(finalWeight);
                        calorie = ceil(double((float)finalWeight / 100) * calorie);
                        Serial.print("Calorie: ");
                        Serial.println(calorie);
                        totalIntake += calorie;
                        Serial.println(totalIntake);
                        y = totalIntake;
                        z = x - y;

                    }

                }
                else {
                    SaveButton[0].press(false);
                }

            }
        }
    }
    //Grains
    if (currentPage == '7') {
        void fillscreen();

        int categ = 3;

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            clearInput();
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            void fillscreen();
            HomeScreen();
        }
        else {
            BackButton[0].press(false);
            CancelButton[0].press(false);

            if (p.x >= 120 && p.x <= 340 && p.y >= 110 && p.y <= 140) {
                clearInput();
                grains[0].press(true);
                Serial.println("b = 1");
                count = 0;
                displayCalorie(0, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 148 && p.y <= 178) {
                clearInput();
                grains[1].press(true);
                Serial.println("b = 2");
                count = 1;
                displayCalorie(1, categ);

            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 186 && p.y <= 216) {
                clearInput();
                grains[2].press(true);
                Serial.println("b = 3");
                count = 2;
                displayCalorie(2, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 224 && p.y <= 254) {
                clearInput();
                grains[3].press(true);
                Serial.println("b = 4");
                count = 3;
                displayCalorie(3, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 262 && p.y <= 292) {
                clearInput();
                grains[4].press(true);
                Serial.println("b = 5");
                count = 4;
                displayCalorie(4, categ);
            }
            else {
                if (p.x >= 200 && p.x <= 275 && p.y >= 60 && p.y <= 90) { // Save Button
                    SaveButton[0].press(true);
                    Serial.println("Save");
                    if (x == 0) {
                        errorSave();
                    }
                    else {
                        displaySave(categ, count);
                        clearInput();
                        calorie = grainscalories[count]; // Calorie = contains the saved calorie
                        Serial.print("Calorie before: ");
                        Serial.println(calorie);
                        Serial.println(finalWeight);
                        calorie = ceil(double((float)finalWeight / 100) * calorie);
                        Serial.print("Calorie: ");
                        Serial.println(calorie);
                        totalIntake += calorie;
                        Serial.println(totalIntake);
                        y = totalIntake;
                        z = x - y;

                    }

                }
                else {
                    SaveButton[0].press(false);
                }

            }
        }
    }
    //Protein
    if (currentPage == '8') {
        void fillscreen();

        int categ = 4;

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            clearInput();
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            BackButton[0].press(false);
            CancelButton[0].press(false);

            if (p.x >= 120 && p.x <= 340 && p.y >= 110 && p.y <= 140) {
                clearInput();
                protein[0].press(true);
                Serial.println("b = 1");
                count = 0;
                displayCalorie(0, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 148 && p.y <= 178) {
                clearInput();
                protein[1].press(true);
                Serial.println("b = 2");
                count = 1;
                displayCalorie(1, categ);

            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 186 && p.y <= 216) {
                clearInput();
                protein[2].press(true);
                Serial.println("b = 3");
                count = 2;
                displayCalorie(2, categ);
            }

            if (p.x >= 120 && p.x <= 340 && p.y >= 224 && p.y <= 254) {
                clearInput();
                protein[3].press(true);
                Serial.println("b = 4");
                count = 3;
                displayCalorie(3, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 262 && p.y <= 292) {
                clearInput();
                protein[4].press(true);
                Serial.println("b = 5");
                count = 4;
                displayCalorie(4, categ);
            }
            else {
                if (p.x >= 200 && p.x <= 275 && p.y >= 60 && p.y <= 90) { // Save Button
                    SaveButton[0].press(true);
                    Serial.println("Save");
                    if (x == 0) {
                        errorSave();
                    }
                    else {
                        displaySave(categ, count);
                        clearInput();
                        calorie = proteincalories[count]; // Calorie = contains the saved calorie
                        Serial.print("Calorie before: ");
                        Serial.println(calorie);
                        Serial.println(finalWeight);
                        calorie = ceil(double((float)finalWeight / 100) * calorie);
                        Serial.print("Calorie: ");
                        Serial.println(calorie);
                        totalIntake += calorie;
                        Serial.println(totalIntake);
                        y = totalIntake;
                        z = x - y;

                    }

                }
                else {
                    SaveButton[0].press(false);
                }

            }
        }
    }
    //Dairy
    if (currentPage == '9') {
        void fillscreen();

        int categ = 5;

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            clearInput();
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            BackButton[0].press(false);
            CancelButton[0].press(false);

            if (p.x >= 120 && p.x <= 340 && p.y >= 110 && p.y <= 140) {
                clearInput();
                dairy[0].press(true);
                Serial.println("b = 1");
                count = 0;
                displayCalorie(0, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 148 && p.y <= 178) {
                clearInput();
                dairy[1].press(true);
                Serial.println("b = 2");
                count = 1;
                displayCalorie(1, categ);

            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 186 && p.y <= 216) {
                clearInput();
                dairy[2].press(true);
                Serial.println("b = 3");
                count = 2;
                displayCalorie(2, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 224 && p.y <= 254) {
                clearInput();
                dairy[3].press(true);
                Serial.println("b = 4");
                count = 3;
                displayCalorie(3, categ);
            }
            if (p.x >= 120 && p.x <= 340 && p.y >= 262 && p.y <= 292) {
                clearInput();
                dairy[4].press(true);
                Serial.println("b = 5");
                count = 4;
                displayCalorie(4, categ);
            }
            else {
                if (p.x >= 200 && p.x <= 275 && p.y >= 60 && p.y <= 90) { // Save Button
                    SaveButton[0].press(true);
                    Serial.println("Save");
                    if (x == 0) {
                        errorSave();
                    }
                    else {
                        displaySave(categ, count);
                        clearInput();
                        calorie = dairycalories[count]; // Calorie = contains the saved calorie
                        Serial.print("Calorie before: ");
                        Serial.println(calorie);
                        Serial.println(finalWeight);
                        calorie = ceil(double((float)finalWeight / 100) * calorie);
                        Serial.print("Calorie: ");
                        Serial.println(calorie);
                        totalIntake += calorie;
                        Serial.println(totalIntake);
                        y = totalIntake;
                        z = x - y;

                    }

                }
                else {
                    SaveButton[0].press(false);
                }

            }
        }
    }


    
}

