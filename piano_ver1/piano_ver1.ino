const double epsilon = 0.1;
const double MAX = 5.0;
const int OUT = 3;

enum noteFreq {
  DO  = 262,
  RE  = 294,
  MI  = 330,
  FA  = 349,
  SOL = 392,
  LA  = 440,
  SI  = 494, 
};

class voltage {
protected:
  double value = 0.0;

public:
  voltage(const double value_): value(value_) {}
  voltage() = default;
  voltage(const voltage&) = default;
  ~voltage() = default;

  bool operator==(const voltage& obj) const {
    return abs(this->value - obj.value) <= epsilon;
  }

  bool operator!=(const voltage& obj) const {
    return !(*this == obj);
  }

  bool operator<=(const voltage& obj) const {
    return this->value <= obj.value;
  }

  bool operator<(const voltage& obj) const {
    return this->value < obj.value;
  }

  bool operator>=(const voltage& obj) const {
    return this->value >= obj.value;
  }

  bool operator>(const voltage& obj) const {
    return this->value > obj.value;
  }

  double get_val() const {
    return value;
  }
};

double get_voltage(const double val) {
  return (val / 1024) * 5;
}

bool stop_sound(const voltage& v_Do, const voltage& v_Re, const voltage& v_Mi, const voltage& v_Fa, const voltage& v_Sol, const voltage& v_La, const voltage& v_Si) {
  return ((v_Do != MAX) && (v_Re != MAX) && (v_Mi != MAX) && (v_Fa != MAX) && (v_Sol != MAX) && (v_La != MAX) && (v_Si != MAX));
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  pinMode(2, INPUT);

  pinMode(OUT, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  voltage v_Do(get_voltage(analogRead(A0)));
  voltage v_Re(get_voltage(analogRead(A1)));
  voltage v_Mi(get_voltage(analogRead(A2)));
  voltage v_Fa(get_voltage(analogRead(A3)));
  voltage v_Sol(get_voltage(analogRead(A4)));
  voltage v_La(get_voltage(analogRead(A5)));
  voltage v_Si(digitalRead(2) * MAX);

  //Serial.println(v_Si.get_val());

  if (v_Do == MAX) {
    tone(OUT, DO);
    
  } else if (v_Re == MAX) {
    tone(OUT, RE);
    
  } else if (v_Mi == MAX) {
    tone(OUT, MI);
    
  } else if (v_Fa == MAX) {
    tone(OUT, FA);
    
  } else if (v_Sol == MAX) {
    tone(OUT, SOL);
    
  } else if (v_La == MAX) {
    tone(OUT, LA);
    
  } else if (v_Si == MAX) {
    tone (OUT, SI);
  }

  if (stop_sound(v_Do, v_Re, v_Mi, v_Fa, v_Sol, v_La, v_Si)) {
    noTone(OUT);
  }

}
