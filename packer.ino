// ===============================
// 入力ピン
// ===============================
const int inA0 = A0;
const int inA1 = A1;
const int inA2 = A2;
const int inA3 = A3;
const int inA4 = A4;   // ★新：A4 でロック動作
const int inA5 = A5;   // ★シーケンス開始ボタン

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

const int sol4B = 10;   // ロック（A4で動作）
const int accel = 12;   // アクセル（シーケンス中も ON）

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
  pinMode(inA4, INPUT_PULLUP);   // ★追加
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
  digitalWrite(sol4A,  digitalRead(inA0) == LOW ? HIGH : LOW);
  digitalWrite(sol910, digitalRead(inA1) == LOW ? HIGH : LOW);
  digitalWrite(sol3A,  digitalRead(inA2) == LOW ? HIGH : LOW);
  digitalWrite(sol3B,  digitalRead(inA3) == LOW ? HIGH : LOW);

  // -------- A4 → D10（押した瞬間 → 0.5秒後に 2秒 ON）--------
  bool nowA4 = (digitalRead(inA4) == LOW);  // 押されている = LOW

  // ★押された瞬間（HIGH → LOW）
  if (prevA4 == HIGH && nowA4 == LOW) {
    a4Pending = true;
    a4PendingStart = millis();   // 0.5秒待つ
  }

  prevA4 = nowA4;

  // ★0.5秒経過したらロック開始
  if (a4Pending && millis() - a4PendingStart >= 500) {
    a4Pending = false;
    a4Active = true;
    a4Start = millis();
    digitalWrite(sol4B, HIGH);     // D10 ON
  }

  // ★2秒経過でロックOFF
  if (a4Active && millis() - a4Start >= 2000) {
    digitalWrite(sol4B, LOW);
    a4Active = false;
  }

  // -------- シーケンス --------
  handleSequence();
}

// ===============================
// シーケンス出力 OFF
// ===============================
void allSeqOff() {
  digitalWrite(seq1, LOW);
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, LOW);
  digitalWrite(accel, LOW);   // ★休止・停止時は必ず OFF
}

// ===============================
// シーケンス本体
// ===============================
void handleSequence() {
  bool nowA5 = (digitalRead(inA5) == LOW);

  // -------- A5 押して離した瞬間 --------
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

    case 0:   // D6 + D12 → 2秒
      digitalWrite(seq1, HIGH);
      digitalWrite(accel, HIGH);
      if (now - seqTimer >= 2000) {
        digitalWrite(seq1, LOW);
        digitalWrite(accel, LOW);
        seqStep = 1;
        seqTimer = now;
      }
      break;

    case 1:   // 休止 0.3秒
      if (now - seqTimer >= 300) {
        seqStep = 2;
        seqTimer = now;
        digitalWrite(seq2, HIGH);
        digitalWrite(accel, HIGH);
      }
      break;

    case 2:   // D7 + D12 → 2秒
      if (now - seqTimer >= 2000) {
        digitalWrite(seq2, LOW);
        digitalWrite(accel, LOW);
        seqStep = 3;
        seqTimer = now;
      }
      break;

    case 3:   // 休止 0.3秒
      if (now - seqTimer >= 300) {
        seqStep = 4;
        seqTimer = now;
        digitalWrite(seq3, HIGH);
        digitalWrite(accel, HIGH);
      }
      break;

    case 4:   // D8 + D12 → 2秒
      if (now - seqTimer >= 2000) {
        digitalWrite(seq3, LOW);
        digitalWrite(accel, LOW);
        seqStep = 5;
        seqTimer = now;
      }
      break;

    case 5:   // 休止 0.3秒
      if (now - seqTimer >= 300) {
        seqStep = 6;
        seqTimer = now;
        digitalWrite(seq4, HIGH);
        digitalWrite(accel, HIGH);
      }
      break;

    case 6:   // D9 + D12 → 2秒
      if (now - seqTimer >= 2000) {
        digitalWrite(seq4, LOW);
        digitalWrite(accel, LOW);
        seqRunning = false;
        seqPaused = false;
      }
      break;
  }
}
