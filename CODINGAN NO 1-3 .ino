// Deklarasi pin
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
int delayTime = 500; // Waktu delay untuk pergeseran LED

// Setup pin mode
void setup() {
  // Setup untuk tombol
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
  // Setup untuk LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // Inisialisasi semua LED mati
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

// Fungsi untuk LED ke kiri
void runLeft() {
  digitalWrite(led1, HIGH); // Nyalakan LED pertama
  delay(delayTime);
  digitalWrite(led1, LOW);  // Matikan LED pertama
  digitalWrite(led2, HIGH); // Nyalakan LED kedua
  delay(delayTime);
  digitalWrite(led2, LOW);  // Matikan LED kedua
  digitalWrite(led3, HIGH); // Nyalakan LED ketiga
  delay(delayTime);
  digitalWrite(led3, LOW);  // Matikan LED ketiga
}

// Fungsi untuk LED ke kanan
void runRight() {
  digitalWrite(led3, HIGH); // Nyalakan LED ketiga
  delay(delayTime);
  digitalWrite(led3, LOW);  // Matikan LED ketiga
  digitalWrite(led2, HIGH); // Nyalakan LED kedua
  delay(delayTime);
  digitalWrite(led2, LOW);  // Matikan LED kedua
  digitalWrite(led1, HIGH); // Nyalakan LED pertama
  delay(delayTime);
  digitalWrite(led1, LOW);  // Matikan LED pertama
}

// Fungsi untuk LED zig-zag (kanan ke kiri, kemudian kiri ke kanan)
void runZigZag() {
  // Dari kanan ke kiri
  runRight();
  
  // Dari kiri ke kanan
  runLeft();
}

// Fungsi utama loop
void loop() {
  // Jika tombol 1 ditekan (ke kiri)
  if (digitalRead(button1) == HIGH) {
    runLeft();
  }

  // Jika tombol 2 ditekan (ke kanan)
  if (digitalRead(button2) == HIGH) {
    runRight();
  }

  // Jika tombol 3 ditekan (zig-zag: kanan ke kiri, lalu kiri ke kanan)
  if (digitalRead(button3) == HIGH) {
    runZigZag();
  }
}