#include <I2Cdev.h>
#include <MPU6050.h>
#include <Servo.h>
#include <Wire.h>

#define SERVO_PITCH 10
#define SERVO_ROLL 9

#define CENTRO_PITCH 90
#define CENTRO_ROLL 90

#define PITCH_MAX_DESCIDA 25
#define PITCH_TOLERANCIA 10

MPU6050 mpu;

Servo servoPitch;  // Servo eixo Y
Servo servoRoll;   // Servo eixo X

int16_t ax, ay, az, gx, gy, gz;

unsigned long lastTime;

float pitch = 0;
float roll = 0;
bool holdPitch = false;
int heldPitchAngle = 90;

void setup() {
    Serial.begin(9600);
    Wire.begin();

    mpu.initialize();
    delay(1000);  // Tempo para estabilizar

    if (!mpu.testConnection()) {
        Serial.println("Erro ao conectar MPU6050!");
        while (1);
    }

    servoPitch.attach(SERVO_PITCH);
    servoRoll.attach(SERVO_ROLL);

    lastTime = micros();
}

void loop() {
    // =====================================================================
    //                        LEITURA PITCH E ROLL
    // =====================================================================
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    unsigned long now = micros();
    float dt = (now - lastTime) / 1000000.0;
    lastTime = now;

    float gyroX = gx / 131.0;
    float gyroY = gy / 131.0;

    float accPitch = atan2(ay, az) * 180 / PI;
    float accRoll = atan2(ax, az) * 180 / PI;

    float alpha = 0.96;

    pitch = alpha * (pitch + gyroX * dt) + (1 - alpha) * accPitch;
    roll = alpha * (roll - gyroY * dt) + (1 - alpha) * accRoll;

    // =====================================================================
    //                CONTROLE DO PITCH (LIMITACAO NA DESCIDA)
    // =====================================================================

    // Verifica se precisa travar
    if (pitch > PITCH_MAX_DESCIDA && !holdPitch) {
        holdPitch = true;
        heldPitchAngle = servoPitch.read();
    }

    // Destrava com tolerancia
    if (pitch < (PITCH_MAX_DESCIDA - PITCH_TOLERANCIA) && holdPitch) {
        holdPitch = false;
    }

    // Controla movimento do pitch
    if (holdPitch) {
        servoPitch.write(heldPitchAngle);  // Nao mexe mas deixa a colher firme
    } else {
        float Kp = 1.0;
        int servoPitchOutput = CENTRO_PITCH - pitch * Kp;
        servoPitchOutput = constrain(servoPitchOutput, 0, 180);
        servoPitch.write(servoPitchOutput);
    }

    // =====================================================================
    //                          CONTROLE DO ROLL
    // =====================================================================

    // Controla o movimento do roll
    float Kr = 1.0;
    int servoRollOutput = CENTRO_ROLL - roll * Kr;
    servoRollOutput = constrain(servoRollOutput, 0, 180);
    servoRoll.write(servoRollOutput);

    // =====================================================================
    //                            DEBUG
    // =====================================================================

    Serial.print("Pitch: ");
    Serial.print(pitch);

    Serial.print(" | Roll: ");
    Serial.print(roll);

    Serial.print(" | HOLD: ");
    Serial.println(holdPitch);
}
