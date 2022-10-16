void DrawButtons() {

    BackButton[1].initButton(&tft, 40, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_ORANGE, ILI9341_ORANGE, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();

    NextButton[1].initButton(&tft, 200, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_RED, ILI9341_RED, ILI9341_BLACK,
        "Next", 1.5);
    NextButton[1].drawButton();

    CancelButton[1].initButton(&tft, 200, 20, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "CANCEL", SIDE_TEXTSIZE);
    CancelButton[1].drawButton();

    SaveButton[1].initButton(&tft, 200, 60, 75, 40, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "SAVE", SIDE_TEXTSIZE);
    SaveButton[1].drawButton();
}

