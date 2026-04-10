// ===============================
// 入力ピン
// ===============================
const int inA0 = A0;
const int inA1 = A1;
const int inA2 = A2;
const int inA3 = A3;
const int inA4 = A4;   // A4 → D10 ロック
const int inA5 = A5;   // シーケンス開始ボタン

// ===============================
// 出力ピン
// ===============================
const int sol4A  = 2;   // A0
const int sol910 = 3;   // A1
const int sol3A  = 4;   // A2
const int sol3B  = 5;   // A3

// シーケンス対象
const int seq1 = 6;     // D6
const int seq2 = 7;     // D7
const int seq3 = 8;     // D8
const int seq4 = 9;     // D9

const int sol4B = 10;   // ロック
const int accel = 12;   // アクセル（D2〜D9 と完全連動）

// ===============================
// A4 → D10（押した瞬間 → 0.5秒後に 2秒 ON）
// ===============================
bool prevA4 = HIGH;
bool a4Pending = false;
unsigned long a4PendingStart = 0;
bool a4Active = false;
unsigned long a4Start = 0;

// ===============================
// シーケンス制御
// ===============================
bool prevA5 = HIGH;
bool seqRunning = false;
bool seqPaused = false;
unsigned long seqTimer = 0;
int seqStep = 0;

// ===============================
// 初期設定
// ===============================
void setup() {
  pinMode(inA0, INPUT_PULLUP);
  pinMode(inA1, INPUT_PULLUP);
  pinMode(inA2, INPUT_PULLUP);
  pinMode(inA3, INPUT_PULLUP);
  pinMode(inA4, INPUT_PULLUP);
  pinMode(inA5, INPUT_PULLUP);

  pinMode(sol4A, OUTPUT);
  pinMode(sol910, OUTPUT);
  pinMode(sol3A, OUTPUT);
  pinMode(sol3B, OUTPUT);

  pinMode(seq1, OUTPUT);
  pinMode(seq2, OUTPUT);
  pinMode(seq3, OUTPUT);
  pinMode(seq4, OUTPUT);

  pinMode(sol4B, OUTPUT);
  pinMode(accel, OUTPUT);

  allSeqOff();
  digitalWrite(sol4B, LOW);
  digitalWrite(accel, LOW);
}

// ===============================
// メインループ
// ===============================
void loop() {

  // -------- A0〜A3 ミラー出力 --------
  bool out2 = (digitalRead(inA0) == LOW);
  bool out3 = (digitalRead(inA1) == LOW);
  bool out4 = (digitalRead(inA2) == LOW);
  bool out5 = (digitalRead(inA3) == LOW);

  digitalWrite(sol4A,  out2 ? HIGH : LOW);
  digitalWrite(sol910, out3 ? HIGH : LOW);
  digitalWrite(sol3A,  out4 ? HIGH : LOW);
  digitalWrite(sol3B,  out5 ? HIGH : LOW);

  // -------- A4 → D10（押した瞬間 → 0.5秒後に 2秒 ON）--------
  bool nowA4 = (digitalRead(inA4) == LOW);

  if (prevA4 == HIGH && nowA4 == LOW) {
    a4Pending = true;
    a4PendingStart = millis();
  }
  prevA4 = nowA4;

  if (a4Pending && millis() - a4PendingStart >= 500) {
    a4Pending = false;
    a4Active = true;
    a4Start = millis();
    digitalWrite(sol4B, HIGH);
  }

  if (a4Active && millis() - a4Start >= 2000) {
    digitalWrite(sol4B, LOW);
    a4Active = false;
  }

  // -------- シーケンス --------
  handleSequence();


// -------- D12（accel）完全連動 --------
bool anyOutput =
  digitalRead(sol4A)  == HIGH ||
  digitalRead(sol910) == HIGH ||
  digitalRead(sol3A)  == HIGH ||
  digitalRead(sol3B)  == HIGH ||
  digitalRead(seq1)   == HIGH ||
  digitalRead(seq2)   == HIGH ||
  digitalRead(seq3)   == HIGH ||
  digitalRead(seq4)   == HIGH;

digitalWrite(accel, anyOutput ? HIGH : LOW);

}

// ===============================
// シーケンス出力 OFF
// ===============================
void allSeqOff() {
  digitalWrite(seq1, LOW);
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, LOW);
}

// ===============================
// シーケンス本体
// ===============================
void handleSequence() {
  bool nowA5 = (digitalRead(inA5) == LOW);

  if (prevA5 == LOW && nowA5 == HIGH) {

    if (!seqRunning && !seqPaused) {
      seqRunning = true;
      seqPaused = false;
      seqStep = 0;
      seqTimer = millis();
      allSeqOff();
    }
    else if (seqRunning && !seqPaused) {
      seqRunning = false;
      seqPaused = true;
      allSeqOff();
    }
    else if (!seqRunning && seqPaused) {
      seqRunning = true;
      seqPaused = false;
      seqTimer = millis();
    }
  }

  prevA5 = nowA5;

  if (!seqRunning) return;

  unsigned long now = millis();

  switch (seqStep) {

    case 0:
      digitalWrite(seq1, HIGH);
      if (now - seqTimer >= 2000) {
        digitalWrite(seq1, LOW);
        seqStep = 1;
        seqTimer = now;
      }
      break;

    case 1:
      if (now - seqTimer >= 300) {
        seqStep = 2;
        seqTimer = now;
      }
      break;

    case 2:
      digitalWrite(seq2, HIGH);
      if (now - seqTimer >= 2000) {
        digitalWrite(seq2, LOW);
        seqStep = 3;
        seqTimer = now;
      }
      break;

    case 3:
      if (now - seqTimer >= 300) {
        seqStep = 4;
        seqTimer = now;
      }
      break;

    case 4:
      digitalWrite(seq3, HIGH);
      if (now - seqTimer >= 2000) {
        digitalWrite(seq3, LOW);
        seqStep = 5;
        seqTimer = now;
      }
      break;

    case 5:
      if (now - seqTimer >= 300) {
        seqStep = 6;
        seqTimer = now;
      }
      break;

    case 6:
      digitalWrite(seq4, HIGH);
      if (now - seqTimer >= 2000) {
        digitalWrite(seq4, LOW);
        seqRunning = false;
        seqPaused = false;
      }
      break;
  }
}
