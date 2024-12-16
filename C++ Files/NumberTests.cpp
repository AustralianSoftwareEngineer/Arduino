void CycleTestsOnStartUp() {
    TEST_Display_ZERO_TEST();
    delay(1000);
    TEST_Display_ONE_TEST();
    delay(1000);
    TEST_Display_TWO_TEST();
    delay(1000);
    TEST_Display_THREE_TEST();
    delay(1000);
    TEST_Display_FOUR_TEST();
    delay(1000);
    TEST_Display_FIVE_TEST();
    delay(1000);
    TEST_Display_SIX_TEST();
    delay(1000);
    TEST_Display_SEVEN_TEST();
    delay(1000);
    TEST_Display_EIGHT_TEST();
    delay(1000);
    TEST_Display_NINE_TEST();
    delay(1000);
}

void TEST_Display_ZERO_TEST() {
    dOn[0] = 1;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 1;
    dOn[6] = 0;
    Serial.println("Testing the number ZERO : 0");
}

void TEST_Display_ONE_TEST() {
    dOn[0] = 0;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number ONE : 1");
}

void TEST_Display_TWO_TEST() {
    dOn[0] = 1;
    dOn[1] = 1;
    dOn[2] = 0;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 0;
    dOn[6] = 1;
    Serial.println("Testing the number TWO : 2");
}

void TEST_Display_THREE_TEST() {
    dOn[0] = 1;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 1;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 1;
    Serial.println("Testing the number THREE : 3");
}

void TEST_Display_FOUR_TEST() {
    dOn[0] = 0;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 1;
    Serial.println("Testing the number FOUR : 4");
}

void TEST_Display_FIVE_TEST() {
    dOn[0] = 1;
    dOn[1] = 0;
    dOn[2] = 1;
    dOn[3] = 1;
    dOn[4] = 0;
    dOn[5] = 1;
    dOn[6] = 1;
    Serial.println("Testing the number FIVE : 5");
}

void TEST_Display_SIX_TEST() {
    dOn[0] = 1;
    dOn[1] = 0;
    dOn[2] = 1;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 1;
    dOn[6] = 1;
    Serial.println("Testing the number SIX : 6");
}

void TEST_Display_SEVEN_TEST() {
    dOn[0] = 1;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number SEVEN : 7");
}

void TEST_Display_EIGHT_TEST() {
    dOn[0] = 1;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 1;
    dOn[6] = 1;
    Serial.println("Testing the number EIGHT : 8");
}

void TEST_Display_NINE_TEST() {
    dOn[0] = 1;
    dOn[1] = 1;
    dOn[2] = 1;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 1;
    dOn[6] = 1;
    Serial.println("Testing the number NINE : 9");
}

