
//Weighing Scale
int computeWeight(int w) {

        if (w < 0)
        {
            w = w * (-1);
        }

        if (w >= 10000)
        {
            w = 0;
            OverWeight();
            delay(200);
        }

    return w;
}

void DisplayWeight(int weight) {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_BLACK);
    tft.setCursor(23, 30);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(5);
    tft.print(weight);

    delay(50);

}

void OverWeight() {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(20, 30);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(3);
    tft.print("Over Loaded");
}

int SaveWeightButton (int weight) {
    tft.fillRect(20, 120, 200, 100, ILI9341_BLACK);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Saved Weight is : ");
    tft.setCursor(60, 170);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(4);
    tft.println(weight);

    delay(2000);
    HomeScreen();
}