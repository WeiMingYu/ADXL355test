#define X_PIN A1
#define Y_PIN A2
#define Z_PIN A3

void setup(){
  Serial.begin(19200);
  //當不下任何的analogRefernce() 指令時 AREF 類比輸入參考電壓值會用預設電壓值為基準 目前看起來是 5V
 analogReference(EXTERNAL);   //使用AREF腳位輸入之電壓為基本值 晶片內阻值32K 歐姆
  //analogReference(DEFAULT); // 依據接的腳位 提供5V 或是 3.3V on arduino boards
}

// 將類比輸入的值轉成g  AREF 值為3.3V 時公式如下
// -3g是0V、0g是1.65V、3g是3.3V。v會是介於0~1023的值（對應代表0V~3.3V）。 V * 6 / 1023後轉成0~6g，-3後得到-3g~3g的值。
//當AREF 值為5V 時 公式要變更為  V*9.08/1023    ,輸出電壓 值最高為3.3V 其V值 是675.839  所以要改成9.8 去乘後會轉成0~6g 
float toG(float v){
  return v * 6 / 1023 - 3;
 //	return v *9.08/1023-3;
}

void loop(){
  int x  = analogRead(X_PIN);
  int y  = analogRead(Y_PIN);
  int z  = analogRead(Z_PIN);
  
 // Serial.print("X: "); 為了配合 GUI 的程式 逗號要當分格數
  Serial.print(x);
  Serial.print(",");
  Serial.print(toG(x));
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(toG(y));
  Serial.print(",");
  Serial.print(z);
  Serial.print(",");
  Serial.print(toG(z));
  Serial.println();
 // Serial.println("g");
  delay(100);
}
