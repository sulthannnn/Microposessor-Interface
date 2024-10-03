// Pin definisi untuk seven segment
const int segPins[] = {2, 3, 4, 5, 6, 7, 8}; // Pin untuk setiap segmen A-G

// Digit untuk menampilkan angka pada seven segment (abcdefg)
const byte numbers[] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
};

// Variabel counter dan timer
int count = 0;
unsigned long previousMillis = 0;
const long interval = 1000; // Interval 1 detik

void setup() {
  // Setup pin mode untuk seven segment
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis(); // Mendapatkan waktu saat ini

  // Jika sudah melewati interval 1 detik
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Increment count
    count++;
    if (count > 9) {
      count = 0; // Reset ke 0 setelah mencapai 9
    }

    // Update seven segment display
    displayNumber(count);
  }
}

// Fungsi untuk menampilkan angka pada seven segment
void displayNumber(int number) {
  byte num = numbers[number];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], bitRead(num, i)); // Mengatur pin segmen sesuai angka
  }
}


