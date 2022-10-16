//Homescreen
void HomeScreen() {

    currentPage = '0';
    tft.fillScreen(ILI9341_BLACK);

    //tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_WHITE);
    for (uint8_t row = 0; row < 6; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            category[col + row].initButton(&tft, CATEG_X + col * (CATEG_W + CATEG_SPACING_X),
                CATEG_Y + row * (CATEG_H + CATEG_SPACING_Y), // x, y, w, h, outline, fill, text
                CATEG_W, CATEG_H, ILI9341_WHITE, categorycolors[col + row],
                ILI9341_WHITE,
                categorylabels[col + row], CATEG_TEXTSIZE);
            category[col + row].drawButton();
        }
    }
    

    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_BLACK);


    inputButton[1].initButton(&tft, 200, 20, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "INPUT", SIDE_TEXTSIZE);
    inputButton[1].drawButton();

    tareButton[1].initButton(&tft, 200, 50, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "TARE", SIDE_TEXTSIZE);
    tareButton[1].drawButton();

    trackButton[1].initButton(&tft, 200, 80, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "TRACK", SIDE_TEXTSIZE);
    trackButton[1].drawButton();

    

}

void DisplayFinalWeight (int val) {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_BLACK);
    tft.setCursor(23, 30);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(5);
    tft.print(weight);
}







