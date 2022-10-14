void DrawGrains() {
    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            grains[col + row].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, colors, ILI9341_WHITE,
                grainslabels[col + row], FRUIT_TEXTSIZE);
            grains[col + row].drawButton();
        }
    }

    DrawButtons();
}