
#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

struct Indicators {
    float kHeading;
    float kPitch;
    float kRoll;
    char kHeadingStatus;
    float kQuaternion[4];
    float kTemperature;
    bool kDistortion;
    bool kCalStatus;
    float kAccelX;
    float kAccelY;
    float kAccelZ;
    float kMagX;
    float kMagY;
    float kMagZ;
    float kGyroX;
    float kGyroY;
    float kGyroZ;
};

enum Name {
    kHeading=5,
    kPitch=24,
    kRoll=25,
    kHeadingStatus=79,
    kQuaternion=77,
    kTemperature=7,
    kDistortion=8,
    kCalStatus=9,
    kAccelX=21,
    kAccelY=22,
    kAccelZ=23,
    kMagX=27,
    kMagY=28,
    kMagZ=29,
    kGyroX=74,
    kGyroY=75,
    kGyroZ=76
};

class Parser {

public:
    Parser() = delete;
    Parser(const unsigned char * obj);
    virtual ~Parser() = default;

private:
    Name name;
    Indicators rov{};
    unsigned int data{};
};

float ChartoFloat (const unsigned char * str);


#endif //PARSER_PARSER_H
