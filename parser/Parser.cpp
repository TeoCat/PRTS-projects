
#include "Parser.h"
#include <iostream>


float ChartoFloat(const unsigned char *str) {
    unsigned char fourByte[sizeof(float)];
    char byte[]="   ";
    for (int i=0;i<sizeof(float);i++){
        memcpy (byte, str + 6 - i*2, 2);
        fourByte [i] = strtol(byte, nullptr,  16);
    }
    float value = 0;
    float * ptrV = &value;
    memcpy (ptrV, fourByte, 4);
    return value;
}

Parser::Parser(const unsigned char *obj) {
    char byte[]="   ";
    while(*obj != NULL){
        memcpy (byte, obj, 2);
        data = strtol(byte, nullptr,  16);
        obj = obj + 2;
        name = static_cast<Name>(data);
        switch (name) {
            case kHeading:{
                rov.kHeading=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kHeading : " << rov.kHeading << " grad" << std::endl;
                break;
            }
            case kPitch:{
                rov.kPitch=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kPitch : " << rov.kPitch << " grad" << std::endl;
                break;
            }
            case kRoll:{
                rov.kRoll=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kRoll : " << rov.kRoll << " grad" << std::endl;
                break;
            }
            case kHeadingStatus:{
                memcpy (byte, obj, 2);
                rov.kHeadingStatus = strtol(byte, nullptr,  16);
                std::cout << "kHeadingStatus : " << (int)rov.kHeadingStatus << std::endl;
                obj = obj + 2;
                break;
            }
            case kQuaternion:{
                for (int k = 0; k<sizeof(float);k++){
                    rov.kQuaternion[k]=ChartoFloat(obj);
                    std::cout << "kQuaternion " << k <<" : "<< rov.kQuaternion[k] << std::endl;
                    obj = obj+8;
                }
                break;
            }
            case kTemperature:{
                rov.kTemperature=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kTemperature : " << rov.kTemperature << " grad*s" << std::endl;
                break;
            }
            case kDistortion:{
                memcpy (byte, obj, 2);
                rov.kDistortion = strtol(byte, nullptr,  16);
                std::cout << "kDistortion : " << (rov.kDistortion ? "true" : "false") << std::endl;
                obj = obj + 2;
                break;
            }
            case kCalStatus:{
                memcpy (byte, obj, 2);
                rov.kCalStatus = strtol(byte, nullptr,  16);
                std::cout << "kCalStatus : " << (rov.kCalStatus ? "true" : "false") << std::endl;
                obj = obj + 2;
                break;
            }
            case kAccelX:{
                rov.kAccelX=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kAccelX : " << rov.kAccelX << " g" << std::endl;
                break;
            }
            case kAccelY:{
                rov.kAccelY=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kAccelY : " << rov.kAccelY << " g" << std::endl;
                break;
            }
            case kAccelZ:{
                rov.kAccelZ=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kAccelZ : " << rov.kAccelZ << " g" << std::endl;
                break;
            }
            case kMagX:{
                rov.kMagX=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kMagX : " << rov.kMagX << " mT" << std::endl;
                break;
            }
            case kMagY:{
                rov.kMagY=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kMagY : " << rov.kMagY << " mT" << std::endl;
                break;
            }
            case kMagZ:{
                rov.kMagZ=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kMagZ : " << rov.kMagZ << " mT" << std::endl;
                break;
            }
            case kGyroX:{
                rov.kGyroX=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kGyroX : " << rov.kGyroX << " rad/sec" << std::endl;
                break;
            }
            case kGyroY:{
                rov.kGyroY=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kGyroY : " << rov.kGyroY << " rad/sec" << std::endl;
                break;
            }
            case kGyroZ: {
                rov.kGyroZ=ChartoFloat(obj);
                obj = obj + 8;
                std::cout << "kGyroZ : " << rov.kGyroZ << " rad/sec" << std::endl;
                break;
            }
            default:
                break;
        }
    }
    std::cout << ""<<std::endl;
}