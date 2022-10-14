void displayCalorie(int b, int categ) {

    int calorie = 0;

    //Check which category

    if (categ == 1) {
        calorie = fruitcalories[b];
    }
    else if (categ == 2) {
        calorie = vegcalories[b];
    }
    else if (categ == 3) {
        calorie = grainscalories[b];
    }
    else if (categ == 4) {
        calorie = proteincalories[b];
    }
    else if (categ == 5) {
        calorie = dairycalories[b];
    }

    tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("Calories:");
    tft.setCursor((TEXT_X + 15), (TEXT_Y + 30));
    tft.setTextSize(3);
    tft.print(calorie);

    //delay(3000);

}

void clearInput() {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);
}

/*int addIntake(int calorie, int newCalorie) {
    int total = calorie + newCalorie;
    return total;
}*/

