#include <Mouse.h>
#include <Keyboard.h>

// Utility function
void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  // Button Code to Disable executing
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW) {
    while (1);
  }
  // Start Keyboard and Mouse
  Mouse.begin();
  Keyboard.begin();

  // Start Payload
  delay(3000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114); // Simulates Win + R
  Keyboard.releaseAll();

  delay(500);

  // Change the URL to any other link
  Keyboard.print("https://www.youtube.com/watch?v=pL9q2lOZ1Fw");

  delay(500);

  typeKey(KEY_RETURN); // Press Enter to open the URL

  delay(2000); // Wait for the page to load

  typeKey('f'); // Press 'f' to enter full screen
  delay(500);   // Brief delay to ensure full screen is applied
  typeKey('m'); // Press 'm' to mute the video

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
  Mouse.end();
}

// Unused
void loop() {}
