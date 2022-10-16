void displayCalorie(int b, int categ) {

    int calorie = 0;

    //Check which category

    if (categ == 1) {
        tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(TEXT_X + 15, TEXT_Y + 30);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(1);
        tft.println(fruitlabels[b]);
        calorie = fruitcalories[b];
    }
    else if (categ == 2) {
        tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(TEXT_X + 15, TEXT_Y + 30);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(1);
        tft.println(veglabels[b]);
        calorie = vegcalories[b];
    }
    else if (categ == 3) {
        tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(TEXT_X + 15, TEXT_Y + 30);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(1);
        tft.println(grainslabels[b]);
        calorie = grainscalories[b];
    }
    else if (categ == 4) {
        tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(TEXT_X + 15, TEXT_Y + 30);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(1);
        tft.println(proteinlabels[b]);
        calorie = proteincalories[b];
    }
    else if (categ == 5) {
        tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(TEXT_X + 15, TEXT_Y + 30);
        tft.setTextColor(ILI9341_BLACK);
        tft.setTextSize(1);
        tft.println(dairylabels[b]);
        calorie = dairycalories[b];
    }

    tft.setCursor((TEXT_X + 15), (TEXT_Y + 40));
    tft.setTextSize(3);
    tft.print(calorie);


}

void displaySave(int categ, int count) {

    //Display message when the calorie is saved
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(90, 140);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("SAVED");


    if (categ == 1) {
        tft.setCursor(30, 160);
        tft.setTextSize(2);
        tft.println(fruitlabels[count]);
        tft.setCursor(30, 180);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(30, 200);
        tft.setTextSize(2);
        tft.println(fruitcalories[count]);
        delay(2000);
        DrawFruits();
    }
    else if (categ == 2) {
        tft.setCursor(30, 160);
        tft.setTextSize(2);
        tft.println(veglabels[count]);
        tft.setCursor(30, 180);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(30, 200);
        tft.setTextSize(2);
        tft.println(vegcalories[count]);
        delay(2000);
        DrawVeg();
    }
    else if (categ == 3) {
        tft.setCursor(30, 160);
        tft.setTextSize(2);
        tft.println(grainslabels[count]);
        tft.setCursor(30, 180);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(30, 200);
        tft.setTextSize(2);
        tft.println(grainscalories[count]);
        delay(2000);
        DrawGrains();
    }
    else if (categ == 4) {
        tft.setCursor(30, 160);
        tft.setTextSize(2);
        tft.println(proteinlabels[count]);
        tft.setCursor(30, 180);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(30, 200);
        tft.setTextSize(2);
        tft.println(proteincalories[count]);
        delay(2000);
        DrawProtein();
    }
    else if (categ == 5) {
        tft.setCursor(30, 160);
        tft.setTextSize(2);
        tft.println(dairylabels[count]);
        tft.setCursor(30, 180);
        tft.setTextSize(2);
        tft.println("Calories:");
        tft.setCursor(30, 200);
        tft.setTextSize(2);
        tft.println(dairycalories[count]);
        delay(2000);
        DrawDairy();
    }
}

void errorSave() {
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("INVALID INPUT");
    tft.setCursor(35, 180);
    tft.setTextSize(2);
    tft.println("INPUT GOAL");
    delay(2000);
    HomeScreen();
}


void clearInput() {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);
}

