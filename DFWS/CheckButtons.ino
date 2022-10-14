void DrawButtons() {

    BackButton[1].initButton(&tft, 40, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_ORANGE, ILI9341_ORANGE, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();

    NextButton[1].initButton(&tft, 200, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_RED, ILI9341_RED, ILI9341_BLACK,
        "Next", 1.5);
    NextButton[1].drawButton();

    CancelButton[0].initButton(&tft, 200, 20, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "CANCEL", SIDE_TEXTSIZE);
    CancelButton[0].drawButton();

    SaveButton[0].initButton(&tft, 200, 60, 75, 40, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "SAVE", SIDE_TEXTSIZE);
    SaveButton[0].drawButton();
}

void displaySave(int categ) {

    //Display message when the calorie is saved
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("INVALID! ENTER GOAL");
    tft.setCursor(90, 180);
    tft.setTextSize(3);
    tft.println(goal);

    delay(2000);

    if (categ == 1) {
        DrawFruits();
    }
    else if (categ == 2) {
        DrawVeg();
    }
    else if (categ == 3) {
        DrawGrains();
    }
    else if (categ == 4) {
        DrawProtein();
    }
    else if (categ == 5) {
        DrawDairy();
    }
    
}

void errorSave(int goal, int calories, int categ) {
    // Display 
    if (goal < 1200 && goal > 2000) {
        tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
        tft.setCursor(35, 140);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("SAVED:");
        tft.setCursor(90, 180);
        tft.setTextSize(3);
        tft.println(goal);

        delay(2000);
    }

    if (categ == 1) {
        DrawFruits();
    }
    else if (categ == 2) {
        DrawVeg();
    }
    else if (categ == 3) {
        DrawGrains();
    }
    else if (categ == 4) {
        DrawProtein();
    }
    else if (categ == 5) {
        DrawDairy();
    }
}


